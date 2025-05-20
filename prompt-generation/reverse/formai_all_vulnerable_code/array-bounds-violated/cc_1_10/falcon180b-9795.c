//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (100 * 1024 * 1024) // 100 MB

typedef struct {
    char magic[4];
    int version;
    int num_entries;
    char entries[0];
} DirectoryEntry;

typedef struct {
    FILE *file;
    DirectoryEntry *entries;
    int num_entries;
} FileSystem;

void read_entry(DirectoryEntry *entry, FILE *file) {
    fseek(file, 0, SEEK_SET);
    fread(entry, sizeof(DirectoryEntry), 1, file);
}

void write_entry(DirectoryEntry *entry, FILE *file) {
    fseek(file, 0, SEEK_SET);
    fwrite(entry, sizeof(DirectoryEntry), 1, file);
}

int compare_entries(const void *a, const void *b) {
    const DirectoryEntry *e1 = a;
    const DirectoryEntry *e2 = b;

    if (e1->version == e2->version) {
        return strcmp(e1->entries, e2->entries);
    } else {
        return e1->version - e2->version;
    }
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <image.img>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb+");
    if (!file) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    FileSystem fs = { file, NULL, 0 };
    DirectoryEntry root_entry = { "ROOT", 1, 0 };
    root_entry.entries[0] = '\0';

    write_entry(&root_entry, fs.file);

    qsort(fs.entries, fs.num_entries, sizeof(DirectoryEntry), compare_entries);

    printf("File system:\n");
    for (int i = 0; i < fs.num_entries; i++) {
        printf("%s\n", fs.entries[i].entries);
    }

    fclose(fs.file);
    return 0;
}