//FormAI DATASET v1.0 Category: File system simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100 // Maximum number of files the system can hold
#define BLOCK_SIZE 512 // Block size in bytes

// Structure to hold file information
struct file {
    int block_number; // Starting block number of the file
    int block_count; // Number of blocks occupied by the file
    char *name; // Name of the file
};

struct file files[MAX_FILES]; // Array to hold file information
char blocks[MAX_FILES * BLOCK_SIZE]; // Array to hold file data
int block_data_starts_at[MAX_FILES]; // Array to hold starting location of each file data

int get_available_block() { // Function to get an available block
    for (int i = 0; i < MAX_FILES; i++) {
        if (files[i].name == NULL) {
            return i;
        }
    }
    return -1;
}

void create_file() { // Function to create a new file
    int index = get_available_block();

    if (index == -1) {
        printf("Error: Maximum number of files reached!\n");
        return;
    }

    int block_count;
    char name[20];

    printf("Enter file name: ");
    scanf("%s", name);
    printf("Enter block count: ");
    scanf("%d", &block_count);

    files[index].name = (char *) malloc(sizeof(char) * strlen(name)); // Allocate memory for the name
    strcpy(files[index].name, name);
    files[index].block_count = block_count;

    for (int i = 0; i < block_count; i++) { // Allocate blocks for the file
        int block_index = get_available_block();

        if (block_index == -1) {
            printf("Error: Maximum number of files reached!\n");
            return;
        }

        files[block_index].name = (char *) malloc(sizeof(name));
        files[block_index].block_count = 1;
        files[block_index].block_number = block_index;
        block_data_starts_at[block_index] = block_index * BLOCK_SIZE;
    }

    printf("File created successfully!\n");
}

void delete_file() { // Function to delete a file
    char name[20];
    printf("Enter file name: ");
    scanf("%s", name);

    for (int i = 0; i < MAX_FILES; i++) {
        if (files[i].name != NULL && strcmp(files[i].name, name) == 0) { // If file found
            int block_count = files[i].block_count;
            int block_number = files[i].block_number;

            for (int j = 0; j < block_count; j++) {
                files[block_number + j].name = NULL; // Free blocks occupied by the file
            }

            printf("File deleted successfully!\n");
            return;
        }
    }

    printf("Error: File not found!\n");
}

void write_to_file() { // Function to write data to a file
    char name[20];
    printf("Enter file name: ");
    scanf("%s", name);

    for (int i = 0; i < MAX_FILES; i++) {
        if (files[i].name != NULL && strcmp(files[i].name, name) == 0) { // If file found
            int block_count = files[i].block_count;
            int block_number = files[i].block_number;

            for (int j = 0; j < block_count; j++) {
                printf("Enter data for block %d: ", block_number + j);
                scanf("%s", &blocks[block_data_starts_at[block_number + j]]); // Get data from user and store in blocks array
            }

            printf("Data written successfully!\n");
            return;
        }
    }

    printf("Error: File not found!\n");
}

void read_from_file() { // Function to read data from a file
    char name[20];
    printf("Enter file name: ");
    scanf("%s", name);

    for (int i = 0; i < MAX_FILES; i++) {
        if (files[i].name != NULL && strcmp(files[i].name, name) == 0) { // If file found
            int block_count = files[i].block_count;
            int block_number = files[i].block_number;

            for (int j = 0; j < block_count; j++) {
                printf("Data from block %d: %s\n", block_number + j, &blocks[block_data_starts_at[block_number + j]]); // Print data stored in blocks array
            }

            return;
        }
    }

    printf("Error: File not found!\n");
}

int main() {
    char choice;

    while (1) {
        printf("1. Create file\n2. Delete file\n3. Write to file\n4. Read from file\n5. Exit\nEnter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                create_file();
                break;
            case '2':
                delete_file();
                break;
            case '3':
                write_to_file();
                break;
            case '4':
                read_from_file();
                break;
            case '5':
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}