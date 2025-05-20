//FormAI DATASET v1.0 Category: Database Indexing System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int key;
    char value[20];
    struct node* next;
} node;

node* head = NULL;
int size = 0;

void insert(int key, char value[]) {
    node* new_node = (node*) malloc(sizeof(node));
    new_node->key = key;
    strcpy(new_node->value, value);
    new_node->next = NULL;
    size++;

    if (head == NULL) {
        head = new_node;
        return;
    }

    node* curr = head;
    node* prev = NULL;

    while (curr != NULL && curr->key < new_node->key) {
        prev = curr;
        curr = curr->next;
    }

    if (prev == NULL) {
        new_node->next = head;
        head = new_node;
    } else {
        prev->next = new_node;
        new_node->next = curr;
    }
}

void search(int key) {
    int found = 0;
    node* curr = head;

    while (curr != NULL) {
        if (curr->key == key) {
            printf("Key: %d Value: %s\n", curr->key, curr->value);
            found = 1;
        }
        curr = curr->next;
    }

    if (!found) {
        printf("Key not found.\n");
    }
}

int main() {
    printf("Welcome to the C Database Indexing System\n");
    printf("========================================\n");
    printf("Enter number of entries: ");
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter key and value for entry %d: ", i+1);
        int key;
        char value[20];
        scanf("%d %s", &key, value);
        insert(key, value);
    }

    printf("\nIndexing complete.\n");

    while (1) {
        printf("\nEnter key to search (0 to exit): ");
        int key;
        scanf("%d", &key);
        if (key == 0) break;
        search(key);
    }

    printf("\nTotal entries: %d\n", size);
    printf("Thank you for using the C Database Indexing System.");
    return 0;
}