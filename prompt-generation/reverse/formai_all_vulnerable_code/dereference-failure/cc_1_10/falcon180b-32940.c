//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

struct node {
    char *data;
    struct node *next;
};

struct node *head = NULL;

void add_node(char *data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    new_node->data = (char *)malloc(strlen(data) + 1);
    if (new_node->data == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    strcpy(new_node->data, data);
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

void search_node(char *search_data) {
    struct node *temp = head;
    while (temp!= NULL) {
        if (strcmp(temp->data, search_data) == 0) {
            printf("Data found!\n");
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Data not found.\n");
    }
}

int main() {
    char input[MAX_LINE_LENGTH];
    printf("Enter data to add: ");
    fgets(input, MAX_LINE_LENGTH, stdin);
    add_node(input);
    printf("Enter data to search: ");
    fgets(input, MAX_LINE_LENGTH, stdin);
    search_node(input);
    return 0;
}