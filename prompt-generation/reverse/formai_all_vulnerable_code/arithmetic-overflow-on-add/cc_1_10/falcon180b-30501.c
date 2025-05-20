//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (1024*1024*100) // 100MB
#define HEADER_SIZE 512

typedef struct {
    char magic[2];
    int version;
    int num_entries;
    int entry_size;
    struct {
        int inode;
        int size;
        char name[256];
    } entries[1000];
} Directory;

void read_header(FILE *fp, Directory *dir) {
    fseek(fp, 0, SEEK_SET);
    fread(dir, sizeof(Directory), 1, fp);
}

int find_entry(Directory *dir, char *name) {
    int i;
    for (i = 0; i < dir->num_entries; i++) {
        if (strcmp(dir->entries[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void recover_file(FILE *src, FILE *dest, Directory *dir, int entry_index) {
    int inode = dir->entries[entry_index].inode;
    int size = dir->entries[entry_index].size;
    char *buffer = malloc(size);

    fseek(src, HEADER_SIZE + inode * dir->entry_size, SEEK_SET);
    fread(buffer, size, 1, src);

    fwrite(buffer, size, 1, dest);
    free(buffer);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    FILE *src = fopen(argv[1], "rb");
    if (src == NULL) {
        printf("Error: Could not open source file.\n");
        return 1;
    }

    FILE *dest = fopen(argv[2], "wb");
    if (dest == NULL) {
        printf("Error: Could not open destination file.\n");
        fclose(src);
        return 1;
    }

    Directory dir;
    read_header(src, &dir);

    if (dir.num_entries == 0) {
        printf("Error: No files found in source file.\n");
        fclose(src);
        fclose(dest);
        return 1;
    }

    char name[256];
    while (fgets(name, sizeof(name), stdin)!= NULL) {
        int entry_index = find_entry(&dir, name);
        if (entry_index == -1) {
            printf("File not found: %s\n", name);
        } else {
            recover_file(src, dest, &dir, entry_index);
        }
    }

    fclose(src);
    fclose(dest);
    return 0;
}