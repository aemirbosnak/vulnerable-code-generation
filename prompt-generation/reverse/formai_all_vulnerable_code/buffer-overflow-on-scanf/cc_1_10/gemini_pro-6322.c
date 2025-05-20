//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define SECTOR_SIZE 512
#define MAX_SECTORS 1024
#define MAX_FILES 100

typedef struct {
    char name[32];
    uint32_t size;
    uint32_t start_sector;
} file_entry;

typedef struct {
    uint8_t sectors[MAX_SECTORS][SECTOR_SIZE];
    file_entry files[MAX_FILES];
    int num_files;
} disk_image;

disk_image disk;

void load_disk_image(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening disk image file");
        exit(1);
    }

    fread(disk.sectors, SECTOR_SIZE, MAX_SECTORS, fp);
    fclose(fp);
}

void parse_disk_image() {
    // Parse the boot sector
    uint8_t *boot_sector = disk.sectors[0];
    
    disk.num_files = boot_sector[19];
    for (int i = 0; i < disk.num_files; i++) {
        file_entry *file = &disk.files[i];

        // Copy the file name
        memcpy(file->name, boot_sector + 32 + (i * 32), 32);

        // Parse the file size
        file->size = boot_sector[52 + (i * 3)] | (boot_sector[53 + (i * 3)] << 8) | (boot_sector[54 + (i * 3)] << 16) | (boot_sector[55 + (i * 3)] << 24);

        // Parse the file start sector
        file->start_sector = boot_sector[56 + (i * 3)] | (boot_sector[57 + (i * 3)] << 8);
    }
}

void print_files() {
    for (int i = 0; i < disk.num_files; i++) {
        file_entry *file = &disk.files[i];

        printf("File: %s\n", file->name);
        printf("Size: %d bytes\n", file->size);
        printf("Start sector: %d\n", file->start_sector);
        printf("\n");
    }
}

void recover_file(char *filename, file_entry *file) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    for (int i = file->start_sector; i < file->start_sector + (file->size / SECTOR_SIZE); i++) {
        fwrite(disk.sectors[i], SECTOR_SIZE, 1, fp);
    }

    fclose(fp);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <disk image file>\n", argv[0]);
        exit(1);
    }

    load_disk_image(argv[1]);
    parse_disk_image();
    print_files();

    char filename[32];
    printf("Enter the name of the file to recover: ");
    scanf("%s", filename);

    file_entry *file = NULL;
    for (int i = 0; i < disk.num_files; i++) {
        if (strcmp(disk.files[i].name, filename) == 0) {
            file = &disk.files[i];
            break;
        }
    }

    if (file == NULL) {
        printf("File not found\n");
        exit(1);
    }

    recover_file(filename, file);

    return 0;
}