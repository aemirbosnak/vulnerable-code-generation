//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME 100
#define MAX_FILE_SIZE 1000

// Node structure for linked list
typedef struct node {
    char name[MAX_FILE_NAME];
    int size;
    char data[MAX_FILE_SIZE];
    struct node *next;
} Node;

// Linked list to store files
Node *head = NULL;

// Function to create a new file
void create_file(char *name) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->size = 0;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    }
    else {
        Node *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Function to open a file
Node *open_file(char *name) {
    Node *temp = head;
    while (temp!= NULL) {
        if (strcmp(temp->name, name) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    printf("File not found.\n");
    return NULL;
}

// Function to write to a file
void write_file(Node *file_node, char *data) {
    int i = 0;
    while (i < strlen(data)) {
        if (file_node->size >= MAX_FILE_SIZE) {
            printf("File is full.\n");
            return;
        }
        file_node->data[file_node->size] = data[i];
        i++;
        file_node->size++;
    }
}

// Function to read from a file
void read_file(Node *file_node) {
    int i = 0;
    while (i < file_node->size) {
        printf("%c", file_node->data[i]);
        i++;
    }
}

// Function to display all files in the linked list
void display_files() {
    Node *temp = head;
    while (temp!= NULL) {
        printf("%s (%d bytes)\n", temp->name, temp->size);
        temp = temp->next;
    }
}

int main() {
    create_file("test.txt");
    open_file("test.txt");
    write_file(head, "Hello, world!");
    display_files();
    read_file(head);
    return 0;
}