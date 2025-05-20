//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct node {
    char data;
    int count;
    struct node *next;
};

struct node *root = NULL;

void insert(char c) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    new_node->data = c;
    new_node->count = 1;
    new_node->next = NULL;
    if (root == NULL) {
        root = new_node;
    } else {
        struct node *temp = root;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void search(char c) {
    struct node *temp = root;
    while (temp!= NULL) {
        if (temp->data == c) {
            printf("Character found, count = %d\n", temp->count);
            return;
        }
        temp = temp->next;
    }
    printf("Character not found\n");
}

void delete(char c) {
    struct node *temp = root;
    if (temp == NULL) {
        printf("Tree is empty\n");
        return;
    }
    if (temp->data == c) {
        root = temp->next;
        free(temp);
        return;
    }
    struct node *prev = NULL;
    while (temp!= NULL && temp->data!= c) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Character not found\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

int main() {
    char str[MAX_SIZE];
    printf("Enter a string: ");
    scanf("%s", str);
    int i;
    for (i = 0; i < strlen(str); i++) {
        insert(str[i]);
    }
    printf("Enter a character to search: ");
    char c = getchar();
    search(c);
    printf("Enter a character to delete: ");
    c = getchar();
    delete(c);
    return 0;
}