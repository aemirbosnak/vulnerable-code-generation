//FormAI DATASET v1.0 Category: Data recovery tool ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

// Define the struct for partition table entry
typedef struct __attribute__((__packed__)) PartitionEntry {
    unsigned char status;
    unsigned char chs_start[3];
    unsigned char type;
    unsigned char chs_end[3];
    unsigned int lba_start;
    unsigned int num_sectors;
} PartitionEntry;

// Define the struct to hold file info
typedef struct FileInfo {
    char name[100];
    unsigned int size;
    unsigned int offset;
} FileInfo;

int main() {
    FILE *disk = fopen("disk.img", "rb");
    if (!disk) {
        printf("Error: Unable to open disk image.\n");
        exit(1);
    }

    // Read the Master Boot Record
    unsigned char buffer[BLOCK_SIZE];
    fseek(disk, 0, SEEK_SET);
    fread(buffer, BLOCK_SIZE, 1, disk);

    // Check the signature bytes to make sure this is a valid MBR
    if (buffer[0x1fe] != 0x55 || buffer[0x1ff] != 0xaa) {
        printf("Error: Invalid MBR signature.\n");
        exit(1);
    }

    // Parse the partition table
    PartitionEntry *partitionTable = (PartitionEntry*)(buffer + 0x1be);
    unsigned int numPartitions = 0;
    for (int i = 0; i < 4; i++) {
        if (partitionTable[i].type == 0x0) {
            break;
        }
        numPartitions++;
    }

    // Create an array to hold the file info
    FileInfo files[10];
    int numFiles = 0;

    // Read each partition to look for deleted files
    for (int i = 0; i < numPartitions; i++) {
        unsigned int start = partitionTable[i].lba_start;
        unsigned int numSectors = partitionTable[i].num_sectors;

        // Read the first sector of the partition to check for the FAT type
        fseek(disk, start * BLOCK_SIZE, SEEK_SET);
        fread(buffer, BLOCK_SIZE, 1, disk);

        unsigned int fatStart = 0;
        unsigned int rootDirStart = 0;
        unsigned int dataStart = 0;
        if (buffer[0x36] == 0x28 || buffer[0x52] == 0x29) {
            // This is a FAT12 or FAT16 partition
            fatStart = start;
            rootDirStart = start + (((buffer[0x0f] << 8) | buffer[0x0e]) * buffer[0x10]);
            dataStart = rootDirStart + ((buffer[0x11] * 32) / 512);
        } else if (buffer[0x52] == 0x28 || buffer[0x62] == 0x29) {
            // This is a FAT32 partition
            fatStart = start;
            rootDirStart = start + ((buffer[0x2c] + (buffer[0x2d] << 8) + (buffer[0x2e] << 16) + (buffer[0x2f] << 24)) / BLOCK_SIZE);
            dataStart = start + ((buffer[0x0f] + (buffer[0x10] << 8)) / BLOCK_SIZE);
        } else {
            // Unsupported partition type
            continue;
        }

        // Read the FAT to look for deleted clusters
        fseek(disk, fatStart * BLOCK_SIZE, SEEK_SET);
        fread(buffer, BLOCK_SIZE, 1, disk);

        for (int j = 0; j < numSectors; j++) {
            for (int k = 0; k < (BLOCK_SIZE / 2); k++) {
                unsigned int entry = ((buffer[k * 2 + 1] << 8) | buffer[k * 2]);
                if (entry == 0x00) {
                    // This cluster is unused
                    continue;
                } else if (entry == 0xff7) {
                    // This cluster is bad
                    continue;
                } else if (entry >= 0xfff8) {
                    // This cluster is an end-of-chain marker
                    continue;
                }

                // Check if this cluster was recently deleted
                fseek(disk, (dataStart + entry - 2) * BLOCK_SIZE, SEEK_SET);
                fread(buffer, BLOCK_SIZE, 1, disk);
                if (buffer[0] == 0xe5 || buffer[0] == 0x05) {
                    // This file was recently deleted or renamed
                    FileInfo file;
                    file.offset = (dataStart + entry - 2) * BLOCK_SIZE;
                    file.size = 0;
                    memset(file.name, 0, sizeof(file.name));
                    for (int l = 0; l < 8; l++) {
                        if (buffer[l] == ' ') {
                            break;
                        }
                        file.name[l] = buffer[l];
                    }
                    if (buffer[8] != ' ') {
                        strcat(file.name, ".");
                        strcat(file.name, buffer + 8);
                    }
                    // Add the file to the list
                    files[numFiles] = file;
                    numFiles++;
                }
            }

            // Read the next block of the FAT
            if (buffer[0x0f] == 0xf8) {
                // FAT12
                fatStart += 1;
            } else if (buffer[0x0f] == 0xf0) {
                // FAT16
                fatStart += 1;
            } else if (buffer[0x0f] == 0xff) {
                // FAT32
                fatStart = ((buffer[0x0e] << 16) | (buffer[0x0d] << 8) | buffer[0x0c]);
            }

            // Stop reading the FAT if we hit the end of the partition
            if (fatStart >= (dataStart - 1)) {
                break;
            }

            fseek(disk, fatStart * BLOCK_SIZE, SEEK_SET);
            fread(buffer, BLOCK_SIZE, 1, disk);
        }
    }

    // Print the list of deleted files
    if (numFiles == 0) {
        printf("No deleted files found.\n");
    } else {
        printf("Deleted files:\n");
        for (int i = 0; i < numFiles; i++) {
            printf("%s (offset=%u, size=%u)\n", files[i].name, files[i].offset, files[i].size);
        }
    }

    fclose(disk);
    return 0;
}