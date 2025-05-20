//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 512
#define MAX_FILES 100

typedef struct {
    char filename[256];
    int filesize;
    int startsector;
    int sectorsused;
} FileEntry;

void read_directory(FILE *disk, FileEntry entries[]) {
    char buffer[BUFFER_SIZE];
    int i = 0;

    while (fread(buffer, 1, BUFFER_SIZE, disk)!= 0) {
        if (i >= MAX_FILES) {
            printf("Directory is full!\n");
            break;
        }

        if (buffer[0] == 0xE5) { // Start of a directory entry
            char filename[256];
            int filesize, startsector, sectorsused;

            memcpy(filename, buffer + 26, 11);
            filename[11] = '\0';

            filesize = *(int *)(buffer + 0x1C);
            startsector = *(int *)(buffer + 0x1A);
            sectorsused = *(int *)(buffer + 0x1E);

            strcpy(entries[i].filename, filename);
            entries[i].filesize = filesize;
            entries[i].startsector = startsector;
            entries[i].sectorsused = sectorsused;

            i++;
        }
    }
}

void recover_files(FILE *disk, FileEntry entries[]) {
    char buffer[BUFFER_SIZE];
    int i, j, k;

    for (i = 0; i < MAX_FILES; i++) {
        if (entries[i].filename[0] == '\0')
            break;

        printf("Recovering %s...\n", entries[i].filename);

        for (j = 0; j < entries[i].sectorsused; j++) {
            int sector = entries[i].startsector + j;

            fseek(disk, sector * 512, SEEK_SET);
            fread(buffer, 1, 512, disk);

            char filename[256];
            strcpy(filename, entries[i].filename);
            strcat(filename, ".recovered");

            FILE *output = fopen(filename, "wb");

            if (output == NULL) {
                printf("Error creating output file!\n");
                return;
            }

            fwrite(buffer, 1, 512, output);

            fclose(output);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <disk image>\n", argv[0]);
        return 1;
    }

    FILE *disk = fopen(argv[1], "rb");

    if (disk == NULL) {
        printf("Error opening disk image!\n");
        return 1;
    }

    FileEntry entries[MAX_FILES];

    read_directory(disk, entries);
    recover_files(disk, entries);

    fclose(disk);

    return 0;
}