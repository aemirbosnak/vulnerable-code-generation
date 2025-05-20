//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000 // Maximum size of the file (in bytes)

struct node {
    char filename[50];
    int size;
    char content[MAX_FILE_SIZE];
    struct node *next;
};

struct node *head = NULL;

void push(char filename[], int size, char content[]) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    strcpy(newnode->filename, filename);
    newnode->size = size;
    strcpy(newnode->content, content);
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        struct node *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void pop() {
    if (head == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
}

void display() {
    struct node *temp = head;
    while (temp!= NULL) {
        printf("%s\n", temp->filename);
        printf("%d\n", temp->size);
        printf("%s\n\n", temp->content);
        temp = temp->next;
    }
}

int main() {
    FILE *fp;
    char filename[50];
    char ch;
    int size = 0;
    int i = 0;

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("File does not exist\n");
        return 0;
    }

    while ((ch = fgetc(fp))!= EOF) {
        filename[i] = ch;
        i++;
        size++;
    }

    fclose(fp);

    push(filename, size, "");

    printf("File backed up successfully\n");

    return 0;
}