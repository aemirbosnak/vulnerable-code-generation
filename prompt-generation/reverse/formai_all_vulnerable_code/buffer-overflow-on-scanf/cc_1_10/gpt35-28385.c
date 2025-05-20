//FormAI DATASET v1.0 Category: Data recovery tool ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct file_data {
    char name[50];
    int size;
    char *content;
} FileData;

typedef struct node {
    FileData file;
    struct node *next;
} Node;

Node *head = NULL;

// function to create a new file
void createFile(char *name, int size, char *content) {
    FileData newFile;
    strcpy(newFile.name, name);
    newFile.size = size;
    newFile.content = (char*) malloc(size * sizeof(char));
    strcpy(newFile.content, content);
    
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->file = newFile;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode;
    } else {
        Node *temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// function to list all files
void listFiles() {
    if (head == NULL) {
        printf("No files found!\n");
    } else {
        Node *temp = head;
        printf("Files:\n");
        while(temp != NULL) {
            printf("%s\n", temp->file.name);
            temp = temp->next;
        }
    }
}

// function to read the content of a file
void readFile(char *name) {
    if (head == NULL) {
        printf("No files found!\n");
    } else {
        Node *temp = head;
        int found = 0;
        while(temp != NULL) {
            if (strcmp(temp->file.name, name) == 0) {
                printf("File content:\n%s\n", temp->file.content);
                found = 1;
                break;
            }
            temp = temp->next;
        }
        if (found == 0) {
            printf("File not found!\n");
        }
    }
}

int main() {
    int choice;
    char name[50], content[500];
    int size;
    
    while(1) {
        printf("\n1. Create a file\n");
        printf("2. List all files\n");
        printf("3. Read a file\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            
            case 1:
                printf("Enter file name: ");
                scanf("%s", &name);
                printf("Enter file size: ");
                scanf("%d", &size);
                printf("Enter file content: ");
                scanf("%s", &content);
                createFile(name, size, content);
                printf("File created successfully!\n");
                break;
                
            case 2:
                listFiles();
                break;
                
            case 3:
                printf("Enter file name: ");
                scanf("%s", &name);
                readFile(name);
                break;
                
            case 4:
                exit(0);
            
            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    }
    
    return 0;
}