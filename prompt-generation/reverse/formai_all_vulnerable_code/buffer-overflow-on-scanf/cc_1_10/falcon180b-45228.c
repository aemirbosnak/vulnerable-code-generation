//Falcon-180B DATASET v1.0 Category: Educational ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} node;

node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    if (!newNode) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addNode(node** head, int data) {
    node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void printList(node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    FILE* fp;
    char ch;
    int i = 0;
    int j;
    char filename[20];

    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("File not found\n");
        exit(1);
    }

    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            printf("%c", ch);
        }
        else if (isdigit(ch)) {
            printf("%d", ch - '0');
        }
        else if (ch == '\n') {
            printf("\n");
        }
    }

    fclose(fp);

    return 0;
}