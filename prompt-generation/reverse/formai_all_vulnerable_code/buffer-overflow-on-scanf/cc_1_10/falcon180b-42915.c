//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LENGTH 100

// Node structure for linked list
typedef struct node {
    char file_name[MAX_FILE_NAME_LENGTH];
    time_t backup_time;
    struct node* next;
} Node;

// Linked list structure
Node* head = NULL;

// Function to create a new node
Node* create_node(char* file_name) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    strcpy(new_node->file_name, file_name);
    new_node->backup_time = time(NULL);
    new_node->next = NULL;
    return new_node;
}

// Function to add a node to the end of the list
void add_node(char* file_name) {
    Node* new_node = create_node(file_name);
    if (head == NULL) {
        head = new_node;
    } else {
        Node* temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Function to search for a file in the list
Node* search_file(char* file_name) {
    Node* temp = head;
    while (temp!= NULL) {
        if (strcmp(temp->file_name, file_name) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to backup a file
void backup_file(char* file_name) {
    Node* temp = search_file(file_name);
    if (temp == NULL) {
        add_node(file_name);
    } else {
        temp->backup_time = time(NULL);
    }
}

// Function to print the list
void print_list() {
    Node* temp = head;
    printf("File Backup System:\n");
    while (temp!= NULL) {
        printf("%s - Last backup: %s\n", temp->file_name, ctime(&temp->backup_time));
        temp = temp->next;
    }
}

int main() {
    char file_name[MAX_FILE_NAME_LENGTH];
    printf("Enter file name: ");
    scanf("%s", file_name);
    backup_file(file_name);
    print_list();
    return 0;
}