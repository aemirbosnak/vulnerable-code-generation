//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure definition
typedef struct node {
    char name[20];
    int size;
    struct node* next;
} node;

// Function to create a new node
node* createNode(char* name, int size) {
    node* newNode = (node*) malloc(sizeof(node));
    strcpy(newNode->name, name);
    newNode->size = size;
    newNode->next = NULL;
    return newNode;
}

// Function to display the contents of a directory
void displayDirectory(node* head) {
    node* current = head;
    printf("Directory Contents:\n");
    while (current!= NULL) {
        printf("%s (%d bytes)\n", current->name, current->size);
        current = current->next;
    }
}

// Function to search for a file in the directory
node* searchFile(node* head, char* name) {
    node* current = head;
    while (current!= NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to delete a file from the directory
void deleteFile(node** head, char* name) {
    node* current = *head;
    node* previous = NULL;
    while (current!= NULL && strcmp(current->name, name)!= 0) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("File not found.\n");
    } else {
        if (previous == NULL) {
            *head = current->next;
        } else {
            previous->next = current->next;
        }
        free(current);
        printf("File deleted.\n");
    }
}

// Function to rename a file in the directory
void renameFile(node** head, char* oldName, char* newName) {
    node* current = searchFile(*head, oldName);
    if (current == NULL) {
        printf("File not found.\n");
    } else {
        strcpy(current->name, newName);
        printf("File renamed.\n");
    }
}

// Function to create a new file in the directory
void createFile(node** head, char* name, int size) {
    node* newFile = createNode(name, size);
    if (*head == NULL) {
        *head = newFile;
    } else {
        node* current = *head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = newFile;
    }
    printf("File created.\n");
}

int main() {
    node* head = NULL;

    // Create some files
    createFile(&head, "file1.txt", 100);
    createFile(&head, "file2.txt", 200);
    createFile(&head, "file3.txt", 300);

    // Display directory contents
    displayDirectory(head);

    // Rename a file
    renameFile(&head, "file1.txt", "newfile1.txt");

    // Display directory contents
    displayDirectory(head);

    // Delete a file
    deleteFile(&head, "file2.txt");

    // Display directory contents
    displayDirectory(head);

    return 0;
}