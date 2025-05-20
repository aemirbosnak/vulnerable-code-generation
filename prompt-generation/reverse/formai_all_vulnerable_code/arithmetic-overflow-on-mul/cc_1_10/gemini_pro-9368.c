//GEMINI-pro DATASET v1.0 Category: System boot optimizer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Define the boot sector structure
typedef struct {
    unsigned char boot_jmp[3];          // Jump instruction to boot loader
    unsigned char oem_id[8];            // OEM identifier
    unsigned short sector_size;        // Size of a sector in bytes
    unsigned char sectors_per_cluster;  // Number of sectors per cluster
    unsigned short reserved_sectors;    // Number of reserved sectors
    unsigned char num_fats;            // Number of FATs
    unsigned short root_dir_entries;    // Number of root directory entries
    unsigned short total_sectors_16;    // Total number of sectors in the volume (16-bit)
    unsigned char media_descriptor_type; // Media descriptor type
    unsigned short sectors_per_fat;      // Number of sectors per FAT
    unsigned short sectors_per_track;   // Number of sectors per track
    unsigned short num_heads;           // Number of heads
    unsigned long hidden_sectors;       // Number of hidden sectors
    unsigned long total_sectors_32;    // Total number of sectors in the volume (32-bit)
    unsigned char drive_number;        // Drive number
    unsigned char current_head;        // Current head position
    unsigned char signature;           // Signature byte (0x28)
    unsigned short volume_serial;      // Volume serial number
    unsigned char volume_label[11];     // Volume label
    unsigned char file_system_type[8];  // File system type
} __attribute__((packed)) boot_sector_t;

// Define the partition table structure
typedef struct {
    unsigned char boot_indicator;       // Boot indicator
    unsigned char starting_head;      // Starting head
    unsigned char starting_sector;     // Starting sector
    unsigned char starting_cylinder;   // Starting cylinder
    unsigned char system_type;         // System type
    unsigned char ending_head;        // Ending head
    unsigned char ending_sector;       // Ending sector
    unsigned char ending_cylinder;     // Ending cylinder
    unsigned long starting_lba;        // Starting LBA
    unsigned long sector_count;        // Sector count
} __attribute__((packed)) partition_table_entry_t;

// Define the main function
int main(int argc, char *argv[]) {
    // Check if the user provided a boot sector file
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <boot sector file>\n", argv[0]);
        return 1;
    }

    // Open the boot sector file
    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    // Read the boot sector
    boot_sector_t boot_sector;
    if (fread(&boot_sector, sizeof(boot_sector), 1, fp) != 1) {
        perror("fread");
        fclose(fp);
        return 1;
    }

    // Check if the boot sector is valid
    if (boot_sector.signature != 0x28) {
        fprintf(stderr, "Invalid boot sector signature\n");
        fclose(fp);
        return 1;
    }

    // Print the boot sector information
    printf("Boot sector information:\n\n");
    printf("Jump instruction: 0x%02X 0x%02X 0x%02X\n", boot_sector.boot_jmp[0], boot_sector.boot_jmp[1], boot_sector.boot_jmp[2]);
    printf("OEM identifier: %.8s\n", boot_sector.oem_id);
    printf("Sector size: %d bytes\n", boot_sector.sector_size);
    printf("Sectors per cluster: %d\n", boot_sector.sectors_per_cluster);
    printf("Reserved sectors: %d\n", boot_sector.reserved_sectors);
    printf("Number of FATs: %d\n", boot_sector.num_fats);
    printf("Root directory entries: %d\n", boot_sector.root_dir_entries);
    printf("Total sectors (16-bit): %d\n", boot_sector.total_sectors_16);
    printf("Media descriptor type: 0x%02X\n", boot_sector.media_descriptor_type);
    printf("Sectors per FAT: %d\n", boot_sector.sectors_per_fat);
    printf("Sectors per track: %d\n", boot_sector.sectors_per_track);
    printf("Number of heads: %d\n", boot_sector.num_heads);
    printf("Hidden sectors: %d\n", boot_sector.hidden_sectors);
    printf("Total sectors (32-bit): %d\n", boot_sector.total_sectors_32);
    printf("Drive number: 0x%02X\n", boot_sector.drive_number);
    printf("Current head position: 0x%02X\n", boot_sector.current_head);
    printf("Signature: 0x%02X\n", boot_sector.signature);
    printf("Volume serial: 0x%04X\n", boot_sector.volume_serial);
    printf("Volume label: %.11s\n", boot_sector.volume_label);
    printf("File system type: %.8s\n\n", boot_sector.file_system_type);

    // Read the partition table
    partition_table_entry_t partition_table[4];
    if (fseek(fp, boot_sector.reserved_sectors * boot_sector.sector_size, SEEK_SET) != 0) {
        perror("fseek");
        fclose(fp);
        return 1;
    }
    if (fread(partition_table, sizeof(partition_table), 1, fp) != 1) {
        perror("fread");
        fclose(fp);
        return 1;
    }

    // Print the partition table information
    printf("Partition table information:\n\n");
    for (int i = 0; i < 4; i++) {
        printf("Partition %d:\n", i + 1);
        printf("Boot indicator: 0x%02X\n", partition_table[i].boot_indicator);
        printf("Starting head: 0x%02X\n", partition_table[i].starting_head);
        printf("Starting sector: 0x%02X\n", partition_table[i].starting_sector);
        printf("Starting cylinder: 0x%02X\n", partition_table[i].starting_cylinder);
        printf("System type: 0x%02X\n", partition_table[i].system_type);
        printf("Ending head: 0x%02X\n", partition_table[i].ending_head);
        printf("Ending sector: 0x%02X\n", partition_table[i].ending_sector);
        printf("Ending cylinder: 0x%02X\n", partition_table[i].ending_cylinder);
        printf("Starting LBA: %d\n", partition_table[i].starting_lba);
        printf("Sector count: %d\n\n", partition_table[i].sector_count);
    }

    // Close the boot sector file
    fclose(fp);

    return 0;
}