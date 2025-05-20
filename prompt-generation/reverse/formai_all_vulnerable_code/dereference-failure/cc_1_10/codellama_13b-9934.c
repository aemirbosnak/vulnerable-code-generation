//Code Llama-13B DATASET v1.0 Category: File handling ; Style: decentralized
// File handling example program in a decentralized style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct File {
    char name[100];
    char content[1000];
    struct File *next;
};

struct File *head;

void addFile(char *name, char *content) {
    struct File *newFile = malloc(sizeof(struct File));
    strcpy(newFile->name, name);
    strcpy(newFile->content, content);
    newFile->next = head;
    head = newFile;
}

void readFile(char *name) {
    struct File *curr = head;
    while (curr != NULL) {
        if (strcmp(curr->name, name) == 0) {
            printf("%s\n", curr->content);
            break;
        }
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("File not found\n");
    }
}

void writeFile(char *name, char *content) {
    struct File *curr = head;
    while (curr != NULL) {
        if (strcmp(curr->name, name) == 0) {
            strcpy(curr->content, content);
            break;
        }
        curr = curr->next;
    }
    if (curr == NULL) {
        addFile(name, content);
    }
}

void deleteFile(char *name) {
    struct File *curr = head;
    struct File *prev = NULL;
    while (curr != NULL) {
        if (strcmp(curr->name, name) == 0) {
            if (prev == NULL) {
                head = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("File not found\n");
    }
}

int main() {
    addFile("hello.txt", "Hello, world!");
    addFile("goodbye.txt", "Goodbye, world!");
    readFile("hello.txt");
    writeFile("hello.txt", "Hello, again!");
    readFile("hello.txt");
    deleteFile("goodbye.txt");
    readFile("goodbye.txt");
    return 0;
}