//FormAI DATASET v1.0 Category: File system simulation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define FILENAME_LEN 20
#define DATA_LEN 100

typedef struct file {
    char name[FILENAME_LEN];
    char data[DATA_LEN];
} File;

int num_files = 0;
File files[MAX_FILES];

void create_file() {
    if (num_files < MAX_FILES) {
        printf("Enter file name: ");
        scanf("%s", files[num_files].name);
        strcpy(files[num_files].data, "");
        num_files++;
        printf("File created.\n");
    } else {
        printf("Cannot create file. Maximum number of files reached.\n");
    }
}

void write_to_file() {
    char filename[FILENAME_LEN];
    printf("Enter file name: ");
    scanf("%s", filename);
    int index = -1;
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, filename) == 0) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        printf("Enter data: ");
        scanf("%s", files[index].data);
        printf("Data written to file.\n");
    } else {
        printf("File not found.\n");
    }
}

void read_from_file() {
    char filename[FILENAME_LEN];
    printf("Enter file name: ");
    scanf("%s", filename);
    int index = -1;
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, filename) == 0) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        printf("Data in file: %s\n", files[index].data);
    } else {
        printf("File not found.\n");
    }
}

void delete_file() {
    char filename[FILENAME_LEN];
    printf("Enter file name: ");
    scanf("%s", filename);
    int index = -1;
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, filename) == 0) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < num_files - 1; i++) {
            strcpy(files[i].name, files[i + 1].name);
            strcpy(files[i].data, files[i + 1].data);
        }
        num_files--;
        printf("File deleted.\n");
    } else {
        printf("File not found.\n");
    }
}

void print_menu() {
    printf("File System Simulation Example\n");
    printf("------------------------------\n");
    printf("1. Create file\n");
    printf("2. Write to file\n");
    printf("3. Read from file\n");
    printf("4. Delete file\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    do {
        print_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create_file();
                break;
            case 2:
                write_to_file();
                break;
            case 3:
                read_from_file();
                break;
            case 4:
                delete_file();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 5);
    return 0;
}