//FormAI DATASET v1.0 Category: File system simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 4096
#define BLOCK_NUM 500

typedef struct inode {
    int file_size;
    int block_index[BLOCK_NUM];
} Inode;

typedef struct superblock {
    int total_blocks;
    int free_blocks;
    int root_index;
} Superblock;

typedef struct file_dir {
    char name[32];
    int inode_index;
} File_Dir;

void init_fs(FILE *fp) {
    Superblock sb;
    Inode root_inode;
    File_Dir root_dir[2];

    sb.total_blocks = BLOCK_NUM;
    sb.free_blocks = BLOCK_NUM;
    sb.root_index = 0;

    root_inode.file_size = 0;
    memset(root_inode.block_index, -1, sizeof(root_inode.block_index));

    root_dir[0].inode_index = 1;
    strcpy(root_dir[0].name, ".");
    root_dir[1].inode_index = 1;
    strcpy(root_dir[1].name, "..");

    fseek(fp, 0, SEEK_SET);
    fwrite(&sb, sizeof(sb), 1, fp);

    fseek(fp, BLOCK_SIZE, SEEK_SET);
    fwrite(&root_inode, sizeof(root_inode), 1, fp);

    fseek(fp, BLOCK_SIZE * 2, SEEK_SET);
    fwrite(&root_dir, sizeof(root_dir), 1, fp);
}

int find_free_block(FILE *fp) {
    Superblock sb;
    int i, block;
    fseek(fp, 0, SEEK_SET);
    fread(&sb, sizeof(sb), 1, fp);

    if (sb.free_blocks == 0) {
        return -1;
    }

    for (i = 3; i < BLOCK_NUM; i++) {
        fseek(fp, i * BLOCK_SIZE, SEEK_SET);
        fread(&block, sizeof(block), 1, fp);
        if (block == -1) {
            fseek(fp, i * BLOCK_SIZE, SEEK_SET);
            return i;
        }
    }

    return -1;
}

int create_file(FILE *fp, char *file_path) {
    Superblock sb;
    Inode inode;
    File_Dir file_dir;
    int free_block, dir_block_idx, i, j, len;
    char *split_path, *dir_name;
    int path_size;

    fseek(fp, 0, SEEK_SET);
    fread(&sb, sizeof(sb), 1, fp);

    split_path = strtok(file_path, "/");
    dir_block_idx = sb.root_index;

    while (split_path != NULL) {
        fseek(fp, dir_block_idx * BLOCK_SIZE, SEEK_SET);
        fread(&file_dir, sizeof(file_dir), 1, fp);

        path_size = strlen(split_path) + 1;
        if (strcmp(file_dir.name, split_path) == 0) {
            dir_block_idx = file_dir.inode_index;
            split_path = strtok(NULL, "/");
        } else {
            free_block = find_free_block(fp);
            if (free_block == -1) {
                return -1;
            }

            fseek(fp, free_block * BLOCK_SIZE, SEEK_SET);

            inode.file_size = 0;
            memset(inode.block_index, -1, sizeof(inode.block_index));
            fwrite(&inode, sizeof(inode), 1, fp);

            file_dir.inode_index = free_block;
            strncpy(file_dir.name, split_path, path_size);
            fwrite(&file_dir, sizeof(file_dir), 1, fp);

            fseek(fp, dir_block_idx * BLOCK_SIZE + sizeof(file_dir), SEEK_SET);
            fwrite(&file_dir, sizeof(file_dir), 1, fp);

            dir_block_idx = free_block;
            split_path = strtok(NULL, "/");
        }
    }

    return 1;
}

int main(int argc, char **argv) {
    FILE *fp;
    char *file_path = "/dir1/dir2/file.txt";

    fp = fopen("filesystem.bin", "wb+");

    init_fs(fp);
    create_file(fp, file_path);

    fclose(fp);
    return 0;
}