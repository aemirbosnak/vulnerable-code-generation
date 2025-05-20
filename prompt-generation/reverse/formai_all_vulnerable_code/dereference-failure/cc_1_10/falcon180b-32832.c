//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_LENGTH 50

// Node structure for linked list implementation of file system
typedef struct node {
    char file_name[MAX_FILE_NAME_LENGTH];
    int file_size;
    char file_data[MAX_FILE_NAME_LENGTH];
    struct node* next;
} Node;

// Linked list for file system
Node* file_system = NULL;

// Function to create a new file
void create_file(char* file_name, int file_size, char* file_data) {
    Node* new_file = (Node*)malloc(sizeof(Node));
    strcpy(new_file->file_name, file_name);
    new_file->file_size = file_size;
    strcpy(new_file->file_data, file_data);
    new_file->next = NULL;

    if (file_system == NULL) {
        file_system = new_file;
    } else {
        Node* temp = file_system;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_file;
    }
}

// Function to read a file
void read_file(char* file_name) {
    Node* current_file = file_system;
    while (current_file!= NULL) {
        if (strcmp(current_file->file_name, file_name) == 0) {
            printf("File name: %s\nFile size: %d\nFile data: %s\n", current_file->file_name, current_file->file_size, current_file->file_data);
            return;
        }
        current_file = current_file->next;
    }
    printf("File not found.\n");
}

// Function to delete a file
void delete_file(char* file_name) {
    Node* current_file = file_system;
    Node* previous_file = NULL;

    while (current_file!= NULL) {
        if (strcmp(current_file->file_name, file_name) == 0) {
            if (previous_file == NULL) {
                file_system = current_file->next;
            } else {
                previous_file->next = current_file->next;
            }
            free(current_file);
            return;
        }
        previous_file = current_file;
        current_file = current_file->next;
    }
    printf("File not found.\n");
}

// Main function
int main() {
    create_file("test.txt", 10, "Hello, world!");
    read_file("test.txt");
    delete_file("test.txt");
    return 0;
}