//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdint.h>

#define SECTOR_SIZE 512

typedef struct {
    uint32_t signature;
    uint8_t num_heads;
    uint32_t num_sectors;
    uint32_t num_cylinders;
    uint16_t reserved;
    uint8_t fat_entries;
    uint16_t root_entry_count;
    uint16_t total_sectors_short;
    uint8_t media_descriptor;
    uint16_t sectors_per_fat;
    uint16_t sectors_per_track;
    uint16_t num_fats;
    uint32_t sectors_per_drive;
    uint32_t num_reserve_sectors;
    uint8_t num_hidden_sectors;
} __attribute__((packed)) boot_sector;

typedef struct {
    uint8_t filename[8];
    uint8_t extension[3];
    uint8_t attributes;
    uint8_t reserved;
    uint8_t create_time_tenth;
    uint16_t create_time;
    uint16_t create_date;
    uint16_t last_access_date;
    uint16_t high_first_cluster;
    uint16_t first_cluster;
    uint32_t file_size;
} __attribute__((packed)) directory_entry;

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *image = fopen(argv[1], "rb");
    if (image == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    boot_sector bs;
    fread(&bs, sizeof(boot_sector), 1, image);

    uint32_t fat_start = bs.num_reserve_sectors * SECTOR_SIZE;
    uint32_t root_dir_start = fat_start + bs.num_fats * bs.sectors_per_fat * SECTOR_SIZE;

    fseek(image, root_dir_start, SEEK_SET);

    directory_entry de;
    while (fread(&de, sizeof(directory_entry), 1, image) == 1) {
        if (de.attributes & 0x0F) {
            char filename[12];
            strncpy(filename, de.filename, 8);
            filename[8] = '.';
            strncpy(filename + 9, de.extension, 3);
            filename[12] = '\0';

            printf("%s (%u bytes)\n", filename, de.file_size);
        }
    }

    fclose(image);

    return EXIT_SUCCESS;
}