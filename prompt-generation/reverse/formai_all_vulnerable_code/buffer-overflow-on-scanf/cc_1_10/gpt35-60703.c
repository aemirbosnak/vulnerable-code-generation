//FormAI DATASET v1.0 Category: Data recovery tool ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

typedef struct {
    unsigned char data[BLOCK_SIZE];
} Block;

typedef struct {
    Block blocks[1000];
} Disk;

int recover_file(char *filename, Disk *disk) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        printf("Error: cannot create file %s\n", filename);
        return -1;
    }

    int block_count = 0;
    while (disk->blocks[block_count].data[0] != 0) {
        fwrite(disk->blocks[block_count].data, sizeof(disk->blocks[block_count].data), 1, fp);
        block_count++;
    }

    fclose(fp);
    return block_count;
}

void print_blocks(Disk *disk) {
    for (int i = 0; i < 1000; i++) {
        if (disk->blocks[i].data[0] != 0) {
            printf("Block %d: %s\n", i, disk->blocks[i].data);
        }
    }
}

int main() {
    Disk disk;
    memset(&disk, 0, sizeof(Disk));

    printf("Enter file name: ");
    char filename[50];
    scanf("%s", filename);

    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error: cannot open file %s\n", filename);
        return -1;
    }

    int block_count = 0;
    while (1) {
        Block block;
        int bytes_read = fread(block.data, sizeof(block.data), 1, fp);
        if (!bytes_read) {
            break;
        }
        disk.blocks[block_count] = block;
        block_count++;
    }

    fclose(fp);

    printf("Recovered file %s:\n", filename);
    int recovered_blocks = recover_file(filename, &disk);
    printf("Recovered %d blocks.\n", recovered_blocks);

    printf("Contents of disk:\n");
    print_blocks(&disk);

    return 0;
}