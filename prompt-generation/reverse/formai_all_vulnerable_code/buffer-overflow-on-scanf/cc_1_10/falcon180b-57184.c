//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct node {
    char data[MAX_SIZE];
    int size;
    struct node *next;
};

struct node *head = NULL;

void insertNode(char *str, int size) {
    struct node *newnode = (struct node *) malloc(sizeof(struct node));
    strcpy(newnode->data, str);
    newnode->size = size;
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

void search(char *str) {
    struct node *temp = head;
    while (temp!= NULL) {
        if (strstr(temp->data, str)!= NULL) {
            printf("Found %s in the linked list\n", str);
            return;
        }
        temp = temp->next;
    }
    printf("Not found %s in the linked list\n", str);
}

int main() {
    char str[MAX_SIZE];
    printf("Enter the strings to be inserted in the linked list\n");
    scanf("%s", str);
    insertNode(str, strlen(str));

    printf("Enter the strings to be searched in the linked list\n");
    scanf("%s", str);
    search(str);

    return 0;
}