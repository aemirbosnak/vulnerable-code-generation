//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

typedef struct {
    char magic[2];
    int version;
    int num_inodes;
    int block_size;
    int num_blocks;
    int free_blocks;
    int free_inodes;
    int first_data_block;
} SuperBlock;

typedef struct {
    int inode_num;
    int size;
    int num_blocks;
    int block_pointers[12];
} Inode;

void print_inode(Inode inode) {
    printf("Inode number: %d\n", inode.inode_num);
    printf("Size: %d bytes\n", inode.size);
    printf("Number of blocks: %d\n", inode.num_blocks);
    printf("Block pointers:\n");
    for (int i = 0; i < inode.num_blocks; i++) {
        printf("%d ", inode.block_pointers[i]);
    }
    printf("\n");
}

void print_superblock(SuperBlock superblock) {
    printf("Magic number: %c%c\n", superblock.magic[0], superblock.magic[1]);
    printf("Version: %d\n", superblock.version);
    printf("Number of inodes: %d\n", superblock.num_inodes);
    printf("Block size: %d bytes\n", superblock.block_size);
    printf("Number of blocks: %d\n", superblock.num_blocks);
    printf("Number of free blocks: %d\n", superblock.free_blocks);
    printf("Number of free inodes: %d\n", superblock.free_inodes);
    printf("First data block: %d\n", superblock.first_data_block);
}

int main(int argc, char *argv[]) {
    FILE *disk;
    SuperBlock superblock;
    Inode inode;
    char filename[100];
    int i;

    if (argc!= 2) {
        printf("Usage: %s <disk image>\n", argv[0]);
        return 1;
    }

    disk = fopen(argv[1], "rb");
    if (disk == NULL) {
        printf("Could not open disk image.\n");
        return 1;
    }

    fread(&superblock, sizeof(SuperBlock), 1, disk);
    printf("Superblock:\n");
    print_superblock(superblock);

    for (i = 0; i < superblock.num_inodes; i++) {
        fseek(disk, i * sizeof(Inode), SEEK_SET);
        fread(&inode, sizeof(Inode), 1, disk);
        printf("Inode %d:\n", i);
        print_inode(inode);
    }

    fclose(disk);

    return 0;
}