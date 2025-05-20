//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    long size;
    long offset;
} file_entry;

int main() {
    // Open the disk image
    FILE *disk = fopen("disk.img", "rb");
    if (disk == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Read the partition table
    char partition_table[512];
    fread(partition_table, 512, 1, disk);

    // Find the first partition
    int partition_offset = 512;
    for (int i = 0; i < 4; i++) {
        if (partition_table[partition_offset + 0x1C] & 0x80) {
            break;
        }
        partition_offset += 16;
    }

    // Read the FAT
    int fat_offset = partition_table[partition_offset + 0x1C] | (partition_table[partition_offset + 0x1D] << 8);
    fseek(disk, partition_offset + fat_offset, SEEK_SET);
    char fat[128 * 512];
    fread(fat, 128 * 512, 1, disk);

    // Read the root directory
    int root_offset = partition_table[partition_offset + 0x20] | (partition_table[partition_offset + 0x21] << 8);
    fseek(disk, partition_offset + root_offset, SEEK_SET);
    char root_dir[128 * 512];
    fread(root_dir, 128 * 512, 1, disk);

    // Parse the root directory
    file_entry files[32];
    int num_files = 0;
    for (int i = 0; i < 128 * 512; i += 32) {
        if (root_dir[i + 0] != 0xE5) {
            continue;
        }

        files[num_files].name = malloc(12);
        strncpy(files[num_files].name, root_dir + i + 1, 11);
        files[num_files].name[11] = '\0';
        files[num_files].size = (root_dir[i + 28] | (root_dir[i + 29] << 8) | (root_dir[i + 30] << 16) | (root_dir[i + 31] << 24));
        files[num_files].offset = (root_dir[i + 20] | (root_dir[i + 21] << 8) | (root_dir[i + 22] << 16) | (root_dir[i + 23] << 24)) * 512;
        num_files++;
    }

    // Print the list of files
    for (int i = 0; i < num_files; i++) {
        printf("%s %ld\n", files[i].name, files[i].size);
    }

    // Free the memory
    for (int i = 0; i < num_files; i++) {
        free(files[i].name);
    }

    // Close the disk image
    fclose(disk);

    return EXIT_SUCCESS;
}