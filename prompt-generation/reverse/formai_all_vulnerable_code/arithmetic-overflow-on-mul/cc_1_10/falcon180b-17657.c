//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (1024 * 1024 * 100) // 100MB

typedef struct {
    char magic[2];
    int version;
    int num_entries;
    struct entry {
        int inode_num;
        int size;
        char name[256];
    } entries[100];
} ext2_superblock;

typedef struct {
    int inode_num;
    int size;
    char name[256];
} directory_entry;

void read_ext2_superblock(FILE *fp, ext2_superblock *sb) {
    fseek(fp, 1024, SEEK_SET);
    fread(sb, sizeof(ext2_superblock), 1, fp);
}

void read_directory(FILE *fp, directory_entry *de, int inode_num) {
    char buffer[1024];
    fseek(fp, inode_num * 1024, SEEK_SET);
    fread(buffer, 1024, 1, fp);
    memcpy(de, buffer, sizeof(directory_entry));
}

void recover_files(FILE *fp, ext2_superblock *sb) {
    directory_entry de;
    for (int i = 0; i < sb->num_entries; i++) {
        read_directory(fp, &de, sb->entries[i].inode_num);
        printf("File name: %s\nFile size: %d bytes\n", de.name, de.size);
    }
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    ext2_superblock sb;
    read_ext2_superblock(fp, &sb);

    recover_files(fp, &sb);

    fclose(fp);
    return 0;
}