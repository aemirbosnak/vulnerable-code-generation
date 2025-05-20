//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct node {
    char *data;
    struct node *next;
};

struct node *head = NULL;

void insert_node(char *data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        struct node *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void traverse_list() {
    struct node *temp = head;
    while (temp!= NULL) {
        printf("%s ", temp->data);
        temp = temp->next;
    }
}

int main() {
    char *data[MAX_SIZE];
    int i = 0;

    printf("Enter data to be inserted: ");
    scanf("%s", data[i]);
    insert_node(data[i]);

    for (i = 1; i < MAX_SIZE; i++) {
        printf("Enter data to be inserted: ");
        scanf("%s", data[i]);
        insert_node(data[i]);
    }

    printf("Data in linked list:\n");
    traverse_list();

    return 0;
}