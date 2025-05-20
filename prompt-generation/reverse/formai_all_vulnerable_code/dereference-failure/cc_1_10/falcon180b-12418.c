//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct node {
    char data[MAX_SIZE];
    int size;
    struct node *next;
};

struct node *head = NULL;

void insert(char *str) {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    int i = 0;
    while (str[i]!= '\0') {
        new_node->data[i] = str[i];
        i++;
    }
    new_node->size = i;
    new_node->next = head;
    head = new_node;
}

void search(char *str) {
    struct node *temp = head;
    int i = 0;
    while (temp!= NULL) {
        if (strcmp(temp->data, str) == 0) {
            printf("Found %s at position %d\n", str, temp->size);
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element not found\n");
    }
}

int main() {
    char input[MAX_SIZE];
    printf("Enter the string: ");
    scanf("%s", input);
    insert(input);
    printf("Enter the string to search: ");
    scanf("%s", input);
    search(input);
    return 0;
}