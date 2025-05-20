//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Node structure for linked list
struct node {
    char data;
    struct node* next;
};

// Function to create a new node with given data
struct node* newNode(char data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    if (node == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node at the end of the list
void push(struct node** head_ref, char new_data) {
    struct node* new_node = newNode(new_data);
    struct node* last = *head_ref;

    if (*head_ref == NULL) {
        new_node->next = NULL;
        *head_ref = new_node;
        return;
    }

    while (last->next!= NULL)
        last = last->next;

    last->next = new_node;

    return;
}

// Function to search for a character in the linked list
int search(struct node* head, char x) {
    struct node* current = head;

    while (current!= NULL) {
        if (current->data == x)
            return 1;
        current = current->next;
    }

    return 0;
}

// Function to print the linked list
void printList(struct node* node) {
    while (node!= NULL) {
        printf("%c ", node->data);
        node = node->next;
    }
}

int main() {
    struct node* head = NULL;
    int i, n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Insert elements into the linked list
    for (i = 0; i < n; i++) {
        char c;
        printf("Enter element %d: ", i+1);
        scanf("%c", &c);
        push(&head, c);
    }

    // Print the linked list
    printf("\nLinked list: ");
    printList(head);

    // Search for a character in the linked list
    char search_char;
    printf("\nEnter the character to search: ");
    scanf("%c", &search_char);

    if (search(head, search_char))
        printf("\n%c found in the linked list.\n", search_char);
    else
        printf("\n%c not found in the linked list.\n", search_char);

    return 0;
}