//FormAI DATASET v1.0 Category: File system simulation ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_FILE_NAME_LENGTH 50
#define BLOCK_SIZE 4096
#define MAX_BLOCKS 1024

struct file{
    char name[MAX_FILE_NAME_LENGTH];
    int size;
    int block_no;
};

struct fs_block{
    char data[BLOCK_SIZE];
};

struct fs{
    struct fs_block blocks[MAX_BLOCKS];
    int bitmap[MAX_BLOCKS]; // 1 if block is occupied, 0 otherwise
    struct file files[MAX_BLOCKS];
    int num_files;
};

void initialize_fs(struct fs *filesystem){
    FILE *fp;
    fp = fopen("filesystem", "w");
    if(fp == NULL){
        perror("Filesystem could not be created.\n");
        exit(1);
    }
    fclose(fp);
    memset(filesystem->bitmap, 0, MAX_BLOCKS * sizeof(int));
    filesystem->num_files = 0;
}

int get_free_block(struct fs *filesystem){
    int i;
    for(i = 0; i < MAX_BLOCKS; i++){
        if(!filesystem->bitmap[i]){
            filesystem->bitmap[i] = 1; // Marking the block as occupied
            return i;
        }
    }
    return -1; // No free blocks available
}

void write_to_block(FILE *fp, int block_no, struct fs_block *block){
    fseek(fp, block_no * BLOCK_SIZE, SEEK_SET); // Seeking to the block in the filesystem
    fwrite(block->data, BLOCK_SIZE, 1, fp); // Writing the data to the block
}

void read_from_block(FILE *fp, int block_no, struct fs_block *block){
    fseek(fp, block_no * BLOCK_SIZE, SEEK_SET); // Seeking to the block in the filesystem
    fread(block->data, BLOCK_SIZE, 1, fp); // Reading the data from the block
}

void write_file_to_fs(struct fs *filesystem, char *filename){
    FILE *fp, *fs_fp;
    struct fs_block block;
    struct file new_file;
    int block_no, num_bytes_read;

    fp = fopen(filename, "r");
    if(fp == NULL){
        perror("File could not be opened.\n");
        return;
    }

    block_no = get_free_block(filesystem);
    if(block_no == -1){
        perror("No free space available in filesystem.\n");
        fclose(fp);
        return;
    }

    fs_fp = fopen("filesystem", "r+");
    if(fs_fp == NULL){
        perror("Filesystem could not be opened.\n");
        fclose(fp);
        return;
    }

    num_bytes_read = fread(block.data, 1, BLOCK_SIZE, fp);
    while(num_bytes_read > 0){
        write_to_block(fs_fp, block_no, &block);
        new_file.block_no = block_no;
        new_file.size += num_bytes_read;
        strcpy(new_file.name, filename);
        filesystem->files[filesystem->num_files] = new_file;
        filesystem->num_files++;
        block_no = get_free_block(filesystem); // Getting new block for next read operation
        if(block_no == -1){
            perror("All blocks in filesystem are occupied.\n");
            break;
        }
        num_bytes_read = fread(block.data, 1, BLOCK_SIZE, fp); // Reading next block from the file
    }
    fclose(fp);
    fclose(fs_fp);
}

void list_files_in_fs(struct fs *filesystem){
    int i;
    printf("Name\tSize\n");
    for(i = 0; i < filesystem->num_files; i++){
        printf("%s\t%d\n", filesystem->files[i].name, filesystem->files[i].size);
    }
}

int main(){
    struct fs filesystem;
    char choice, filename[MAX_FILE_NAME_LENGTH];

    initialize_fs(&filesystem);

    printf("Filesystem initialized. Choose an option:\n");
    printf("1) Add a file\n");
    printf("2) List files in filesystem\n");
    printf("3) Exit\n");

    while(1){
        scanf("%c", &choice);
        switch(choice){
            case '1':
                printf("Enter filename: ");
                scanf("%s", filename);
                write_file_to_fs(&filesystem, filename);
                printf("File added to filesystem successfully.\n");
                break;
            case '2':
                list_files_in_fs(&filesystem);
                break;
            case '3':
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
        while(getchar() != '\n'); // Clearing the input buffer
        printf("Choose an option: ");
    }
}