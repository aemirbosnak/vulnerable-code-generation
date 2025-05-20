//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: relaxed
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
} Superblock;

typedef struct {
    int inode_num;
    int size;
    int num_blocks;
    int block_indices[12];
} Inode;

void print_inode(Inode inode) {
    printf("Inode %d:\n", inode.inode_num);
    printf("Size: %d\n", inode.size);
    printf("Num blocks: %d\n", inode.num_blocks);
    printf("Block indices:\n");
    for (int i = 0; i < inode.num_blocks; i++) {
        printf("%d ", inode.block_indices[i]);
    }
    printf("\n");
}

int main() {
    FILE *disk;
    Superblock superblock;
    Inode inode;
    disk = fopen("disk.img", "rb");
    if (disk == NULL) {
        printf("Error opening disk image.\n");
        exit(1);
    }
    fseek(disk, 0, SEEK_SET);
    fread(&superblock, sizeof(Superblock), 1, disk);
    printf("Superblock:\n");
    printf("Magic: %s\n", superblock.magic);
    printf("Version: %d\n", superblock.version);
    printf("Num inodes: %d\n", superblock.num_inodes);
    printf("Block size: %d\n", superblock.block_size);
    printf("Num blocks: %d\n", superblock.num_blocks);
    printf("Free blocks: %d\n", superblock.free_blocks);
    printf("Free inodes: %d\n", superblock.free_inodes);
    printf("\n");
    for (int i = 0; i < superblock.num_inodes; i++) {
        fseek(disk, i * sizeof(Inode), SEEK_SET);
        fread(&inode, sizeof(Inode), 1, disk);
        print_inode(inode);
    }
    fclose(disk);
    return 0;
}