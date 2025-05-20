//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define SECTOR_SIZE 512

typedef struct {
    uint32_t lba;
    uint16_t sectors;
    uint16_t hidden_sectors;
    uint8_t drive_number;
} MBR_Entry;

typedef struct {
    uint64_t lba;
    uint64_t size;
    uint8_t type;
} Partition_Entry;

int main() {
    FILE *disk_image;

    // Open the disk image file
    disk_image = fopen("disk.img", "rb");
    if (disk_image == NULL) {
        perror("Error opening disk image");
        return EXIT_FAILURE;
    }

    // Read the MBR
    MBR_Entry mbr;
    fseek(disk_image, 0, SEEK_SET);
    fread(&mbr, sizeof(MBR_Entry), 1, disk_image);

    // Check if the MBR is valid
    if (mbr.lba != 0 || mbr.sectors != 1 || mbr.hidden_sectors != 0) {
        fprintf(stderr, "Error: Invalid MBR\n");
        fclose(disk_image);
        return EXIT_FAILURE;
    }

    // Read the partition table
    Partition_Entry partition_table[4];
    fseek(disk_image, mbr.lba * SECTOR_SIZE, SEEK_SET);
    fread(partition_table, sizeof(Partition_Entry), 4, disk_image);

    // Find the first FAT partition
    int fat_partition_index = -1;
    for (int i = 0; i < 4; i++) {
        if (partition_table[i].type == 0x06 || partition_table[i].type == 0x0E) {
            fat_partition_index = i;
            break;
        }
    }

    // Check if a FAT partition was found
    if (fat_partition_index == -1) {
        fprintf(stderr, "Error: No FAT partition found\n");
        fclose(disk_image);
        return EXIT_FAILURE;
    }

    // Read the FAT
    uint32_t *fat = malloc(partition_table[fat_partition_index].size * sizeof(uint32_t));
    fseek(disk_image, partition_table[fat_partition_index].lba * SECTOR_SIZE, SEEK_SET);
    fread(fat, sizeof(uint32_t), partition_table[fat_partition_index].size, disk_image);

    // Search for lost files
    for (uint32_t lba = 2; lba < partition_table[fat_partition_index].size; lba++) {
        // Check if the FAT entry is free
        if (fat[lba] == 0x00000000) {
            continue;
        }

        // Check if the FAT entry is the last entry in a cluster
        if (fat[lba] & 0x0FFFFFFF) {
            continue;
        }

        // Read the data from the cluster
        uint8_t data[SECTOR_SIZE * (fat[lba] & 0x0FFFFFFF)];
        fseek(disk_image, (lba * SECTOR_SIZE) + partition_table[fat_partition_index].lba * SECTOR_SIZE, SEEK_SET);
        fread(data, sizeof(uint8_t), SECTOR_SIZE * (fat[lba] & 0x0FFFFFFF), disk_image);

        // Search for a valid file signature
        char signature[8] = {0};
        for (int i = 0; i < SECTOR_SIZE * (fat[lba] & 0x0FFFFFFF); i++) {
            if (memcmp(data + i, "MZ", 2) == 0) {
                // A valid file signature was found.
                // Print the file name and size.
                char filename[12] = {0};
                memcpy(filename, data + i + 18, 12);
                uint32_t filesize = *(uint32_t *)(data + i + 28);
                printf("Found lost file: %s (%d bytes)\n", filename, filesize);

                // Save the file to disk
                FILE *output_file;
                output_file = fopen(filename, "wb");
                if (output_file == NULL) {
                    perror("Error opening output file");
                    fclose(disk_image);
                    free(fat);
                    return EXIT_FAILURE;
                }
                fwrite(data + i, sizeof(uint8_t), filesize, output_file);
                fclose(output_file);
            }
        }
    }

    // Free the FAT
    free(fat);

    // Close the disk image file
    fclose(disk_image);

    return EXIT_SUCCESS;
}