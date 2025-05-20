//FormAI DATASET v1.0 Category: File system simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_FILE_SIZE 1024

typedef struct {
    char file_name[20];
    int start_address;
    int file_size;
} File;

typedef struct {
    char disk_name[20];
    int disk_size;
    int block_size;
    int num_blocks;
    int *free_list;
    File *file_list;
    int curr_dir;
} Disk;

// function prototypes
void create_disk(Disk *d);
void create_file(Disk *d, char *name, int size);
void print_files(Disk *d);
void delete_file(Disk *d, char *name);
void change_dir(Disk *d, char *name);
void print_current_dir(Disk *d);

int main() {
    Disk d;
    create_disk(&d);
    char command[20];
    char name[20];
    int size;
    while (1) {
        printf("\nEnter a command > ");
        scanf("%s", command);
        if (strcmp(command, "create") == 0) {
            scanf("%s %d", name, &size);
            create_file(&d, name, size);
        }
        else if (strcmp(command, "delete") == 0) {
            scanf("%s", name);
            delete_file(&d, name);
        }
        else if (strcmp(command, "cd") == 0) {
            scanf("%s", name);
            change_dir(&d, name);
        }
        else if (strcmp(command, "dir") == 0)
            print_files(&d);
        else if (strcmp(command, "pwd") == 0)
            print_current_dir(&d);
        else if (strcmp(command, "exit") == 0)
            break;
        else
            printf("\nInvalid command. Try again.");
    }
    return 0;
}

// create a new disk
void create_disk(Disk *d) {
    printf("\nEnter a name for the disk > ");
    scanf("%s", d->disk_name);
    printf("\nEnter the size of the disk in blocks > ");
    scanf("%d", &d->disk_size);
    printf("\nEnter the size of each block in bytes > ");
    scanf("%d", &d->block_size);
    d->num_blocks = d->disk_size / d->block_size;
    d->free_list = (int*) malloc(d->num_blocks * sizeof(int));
    for (int i = 0; i < d->num_blocks; i++)
        d->free_list[i] = 1; // mark all blocks as free
    d->file_list = (File*) malloc(MAX_FILE_SIZE * sizeof(File));
    strcpy(d->file_list[0].file_name, "/");
    d->file_list[0].start_address = -1;
    d->file_list[0].file_size = 0;
    d->curr_dir = 0; // current directory is root
    printf("\nDisk created successfully.");
}

// create a new file
void create_file(Disk *d, char *name, int size) {
    if (strcmp(name, "") == 0 || size <= 0) {
        printf("\nInvalid file name or size. Try again.");
        return;
    }
    // check if file already exists
    for (int i = 1; i <= d->file_list[0].file_size; i++) {
        if (strcmp(d->file_list[i].file_name, name) == 0) {
            printf("\nFile with this name already exists. Try again.");
            return;
        }
    }
    int start = -1;
    int num_blocks = size / d->block_size + (size % d->block_size == 0 ? 0 : 1);
    int cnt = 0;
    for (int i = 0; i < d->num_blocks; i++) {
        if (d->free_list[i] == 1) {
            if (start == -1)
                start = i;
            cnt++;
            if (cnt == num_blocks)
                break;
        }
        else {
            start = -1;
            cnt = 0;
        }
    }
    if (start == -1) {
        printf("\nDisk is full. Cannot create file.");
        return;
    }
    // mark blocks as used
    for (int i = start; i < start + num_blocks; i++)
        d->free_list[i] = 0;
    // add file to file list
    int index = ++(d->file_list[0].file_size);
    strcpy(d->file_list[index].file_name, name);
    d->file_list[index].start_address = start;
    d->file_list[index].file_size = size;
    printf("\nFile created successfully.");
}

// print all files and directories
void print_files(Disk *d) {
    printf("\nDirectory of %s", d->disk_name);
    printf("\n\t. (curr dir)\n");
    for (int i = 1; i <= d->file_list[0].file_size; i++)
        printf("\t%s\n", d->file_list[i].file_name);
}

// delete a file
void delete_file(Disk *d, char *name) {
    // check if file exists
    int i;
    for (i = 1; i <= d->file_list[0].file_size; i++) {
        if (strcmp(d->file_list[i].file_name, name) == 0)
            break;
    }
    if (i == d->file_list[0].file_size + 1) {
        printf("\nFile not found. Try again.");
        return;
    }
    int start = d->file_list[i].start_address;
    int num_blocks = d->file_list[i].file_size / d->block_size + (d->file_list[i].file_size % d->block_size == 0 ? 0 : 1);
    // mark blocks as free
    for (int j = start; j < start + num_blocks; j++)
        d->free_list[j] = 1;
    // remove file from file list
    for (int j = i; j < d->file_list[0].file_size; j++)
        d->file_list[j] = d->file_list[j + 1];
    d->file_list[0].file_size--;
    printf("\nFile deleted successfully.");
}

// change current directory
void change_dir(Disk *d, char *name) {
    if (strcmp(name, "..") == 0) {
        if (d->curr_dir != 0) {
            d->curr_dir = d->file_list[d->curr_dir].start_address;
            printf("\nDirectory changed to %s", d->file_list[d->curr_dir].file_name);
        }
        else
            printf("\nAlready at root directory.");
    }
    else {
        int i;
        for (i = 1; i <= d->file_list[0].file_size; i++) {
            if (strcmp(d->file_list[i].file_name, name) == 0 && d->file_list[i].file_size == 0)
                break;
        }
        if (i == d->file_list[0].file_size + 1) {
            printf("\nDirectory not found. Try again.");
            return;
        }
        d->curr_dir = d->file_list[i].start_address;
        printf("\nDirectory changed to %s", d->file_list[i].file_name);
    }
}

// print current directory
void print_current_dir(Disk *d) {
    printf("\nCurrent directory: %s", d->file_list[d->curr_dir].file_name);
}