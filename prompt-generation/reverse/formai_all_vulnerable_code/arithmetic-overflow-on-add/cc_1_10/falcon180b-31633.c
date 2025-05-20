//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 10000000 // 10 MB

typedef struct {
    char magic[2];
    int version;
    int num_entries;
    struct entry {
        int inode;
        int size;
        int offset;
    } entries[100];
} ext2_superblock;

typedef struct {
    int inode;
    int size;
    int blocks[15];
} ext2_inode;

int main() {
    FILE *disk;
    ext2_superblock sb;
    ext2_inode inode;
    char buffer[MAX_FILE_SIZE];

    disk = fopen("disk.img", "rb");
    if (disk == NULL) {
        printf("Error: Could not open disk image file.\n");
        exit(1);
    }

    // Read superblock
    fseek(disk, 1024, SEEK_SET);
    fread(&sb, sizeof(ext2_superblock), 1, disk);

    // Print superblock info
    printf("Superblock info:\n");
    printf("Magic: %c%c\n", sb.magic[0], sb.magic[1]);
    printf("Version: %d\n", sb.version);
    printf("Num entries: %d\n", sb.num_entries);

    // Loop through inodes
    for (int i = 1; i <= sb.num_entries; i++) {
        // Read inode
        fseek(disk, (i * 128) + 1024, SEEK_SET);
        fread(&inode, sizeof(ext2_inode), 1, disk);

        // Print inode info
        printf("Inode %d info:\n", inode.inode);
        printf("Size: %d\n", inode.size);

        // Read file contents
        int file_size = inode.size;
        int num_blocks = (file_size + 511) / 512;
        int block_size = 512;
        for (int j = 0; j < num_blocks; j++) {
            int block_num = inode.blocks[j];
            fseek(disk, block_num * block_size, SEEK_SET);
            fread(buffer, block_size, 1, disk);
            printf("%s", buffer);
        }
    }

    fclose(disk);
    return 0;
}