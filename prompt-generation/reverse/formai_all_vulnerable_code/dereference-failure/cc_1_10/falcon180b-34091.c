//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024 * 1024 * 10 // 10 MB

typedef struct {
    char magic[2]; // file signature
    int version; // file format version
    int num_entries; // number of directory entries
} DirectoryHeader;

typedef struct {
    char name[256]; // file/directory name
    int size; // file size in bytes
    int type; // 0 for file, 1 for directory
} DirectoryEntry;

void read_file(char* filename, void* buffer) {
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int filesize = ftell(fp);
    if (filesize > MAX_FILE_SIZE) {
        printf("Error: file is too large.\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_SET);
    fread(buffer, 1, filesize, fp);
    fclose(fp);
}

int main() {
    char* filename = "example.bin";
    void* buffer = malloc(MAX_FILE_SIZE);

    read_file(filename, buffer);

    DirectoryHeader* header = (DirectoryHeader*)buffer;
    if (header->magic[0]!= 'A' || header->magic[1]!= 'T') {
        printf("Error: invalid file signature.\n");
        exit(1);
    }

    int num_entries = header->num_entries;
    DirectoryEntry* entries = (DirectoryEntry*)(buffer + sizeof(DirectoryHeader));

    for (int i = 0; i < num_entries; i++) {
        DirectoryEntry* entry = &entries[i];

        if (entry->type == 0) { // file
            printf("File: %s, Size: %d bytes\n", entry->name, entry->size);
        } else if (entry->type == 1) { // directory
            printf("Directory: %s\n", entry->name);
        }
    }

    free(buffer);
    return 0;
}