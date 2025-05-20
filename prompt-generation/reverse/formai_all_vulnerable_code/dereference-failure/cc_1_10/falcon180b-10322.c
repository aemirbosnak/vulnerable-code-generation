//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

typedef struct {
    char name[11];
    int size;
    int start_block;
    int blocks;
} file_t;

void read_fat(FILE *disk, int fat_size, int *fat) {
    fseek(disk, fat_size * BLOCK_SIZE, SEEK_SET);
    fread(fat, sizeof(int), fat_size, disk);
}

int get_next_cluster(int cluster, int fat_size, int *fat) {
    if (cluster == 0 || cluster == 1)
        return -1;

    int next_cluster = fat[cluster / (fat_size / 4)] & 0x0FFFFFFF;
    if (next_cluster == 0)
        return -1;

    return next_cluster;
}

void print_file_info(file_t *file) {
    printf("Name: %s\n", file->name);
    printf("Size: %d bytes\n", file->size);
    printf("Start block: %d\n", file->start_block);
    printf("Blocks: %d\n", file->blocks);
}

int main() {
    FILE *disk = fopen("disk.img", "rb");
    if (disk == NULL) {
        printf("Error: Could not open disk image.\n");
        exit(1);
    }

    fseek(disk, 0, SEEK_SET);
    int fat_size = 0;
    fread(&fat_size, sizeof(int), 1, disk);

    int fat[fat_size / 4];
    read_fat(disk, fat_size, fat);

    int root_dir_start = fat_size * BLOCK_SIZE;
    fseek(disk, root_dir_start, SEEK_SET);

    file_t root_dir[512 / sizeof(file_t)];
    fread(root_dir, sizeof(file_t), 512 / sizeof(file_t), disk);

    for (int i = 0; i < 512 / sizeof(file_t); i++) {
        if (root_dir[i].size == 0)
            continue;

        printf("File %d:\n", i);
        print_file_info(&root_dir[i]);
    }

    fclose(disk);
    return 0;
}