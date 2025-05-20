//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

struct node {
    char data[MAX_SIZE];
    int length;
    struct node *next;
};

struct node *head = NULL;

void insert(char *str) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    strcpy(new_node->data, str);
    new_node->length = strlen(str);
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        return;
    }

    struct node *temp = head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }

    temp->next = new_node;
}

void search(char *str) {
    struct node *temp = head;

    while (temp!= NULL) {
        if (strcmp(temp->data, str) == 0) {
            printf("String found!\n");
            return;
        }
        temp = temp->next;
    }

    printf("String not found.\n");
}

void delete(char *str) {
    struct node *temp = head;
    struct node *prev = NULL;

    while (temp!= NULL) {
        if (strcmp(temp->data, str) == 0) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("String not found.\n");
}

int main() {
    insert("Hello world!");
    insert("Brave programmer");
    insert("C programming");

    search("Brave programmer");
    search("Java programming");

    delete("Brave programmer");
    search("Brave programmer");

    return 0;
}