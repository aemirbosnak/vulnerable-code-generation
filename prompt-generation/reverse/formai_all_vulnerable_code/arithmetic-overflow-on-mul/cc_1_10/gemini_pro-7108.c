//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#define SECTOR_SIZE 512

typedef struct {
  unsigned char jump_instruction[3];
  unsigned char oem_identifier[8];
  unsigned short bytes_per_sector;
  unsigned char sectors_per_cluster;
  unsigned short reserved_sectors;
  unsigned char number_of_fats;
  unsigned short maximum_root_directory_entries;
  unsigned short total_sectors;
  unsigned char media_descriptor;
  unsigned short sectors_per_fat;
  unsigned short sectors_per_track;
  unsigned short number_of_heads;
  unsigned int hidden_sectors;
  unsigned int large_sectors;
} __attribute__((packed)) boot_sector;

typedef struct {
  unsigned char filename[8];
  unsigned char extension[3];
  unsigned char attributes;
  unsigned short reserved;
  unsigned short creation_time;
  unsigned short creation_date;
  unsigned short last_access_date;
  unsigned short first_cluster_high;
  unsigned short first_cluster_low;
  unsigned short file_size;
} __attribute__((packed)) directory_entry;

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <image file>\n", argv[0]);
    return 1;
  }

  FILE *image = fopen(argv[1], "rb");
  if (image == NULL) {
    perror("fopen");
    return 1;
  }

  boot_sector boot;
  fread(&boot, sizeof(boot), 1, image);

  if (boot.jump_instruction[0] != 0xEB && boot.jump_instruction[1] != 0x3C && boot.jump_instruction[2] != 0x90) {
    fprintf(stderr, "Invalid boot sector\n");
    fclose(image);
    return 1;
  }

  unsigned int fat_offset = boot.reserved_sectors * SECTOR_SIZE;
  unsigned int root_dir_offset = fat_offset + boot.sectors_per_fat * SECTOR_SIZE * boot.number_of_fats;
  unsigned int data_area_offset = root_dir_offset + (boot.maximum_root_directory_entries >> 4) * SECTOR_SIZE;

  directory_entry entry;
  fseek(image, root_dir_offset, SEEK_SET);
  while (fread(&entry, sizeof(entry), 1, image) == 1) {
    if (entry.filename[0] == 0xE5 || entry.filename[0] == 0x00) {
      continue;
    }

    unsigned char *filename = malloc(12);
    sprintf(filename, "%8s.%3s", entry.filename, entry.extension);

    unsigned int first_cluster = entry.first_cluster_high << 16 | entry.first_cluster_low;
    unsigned int file_size = entry.file_size;

    printf("%s (%d bytes)\n", filename, file_size);

    unsigned char *buffer = malloc(file_size);
    fseek(image, data_area_offset + (first_cluster - 2) * SECTOR_SIZE, SEEK_SET);
    fread(buffer, file_size, 1, image);

    FILE *file = fopen(filename, "wb");
    fwrite(buffer, file_size, 1, file);
    fclose(file);

    free(buffer);
    free(filename);
  }

  fclose(image);
  return 0;
}