//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 1000000

// Node structure for linked list
struct node {
    int data;
    int freq;
    struct node* next;
};

// Function to create a new node
struct node* newNode(int data) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->freq = 1;
    node->next = NULL;
    return node;
}

// Function to insert a node in the linked list
void insertNode(struct node** head, int data) {
    struct node* node = *head;
    if (*head == NULL) {
        *head = newNode(data);
        return;
    }
    while (node->next!= NULL) {
        if (node->next->data == data) {
            node->next->freq++;
            return;
        }
        node = node->next;
    }
    node->next = newNode(data);
}

// Function to print the linked list
void printList(struct node* head) {
    struct node* node = head;
    while (node!= NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to search for a string in the linked list
int searchString(struct node* head, char* str) {
    struct node* node = head;
    int len = strlen(str);
    while (node!= NULL) {
        if (node->freq == len) {
            int i = 0;
            while (i < len && node->data == str[i]) {
                i++;
            }
            if (i == len) {
                return 1;
            }
        }
        node = node->next;
    }
    return 0;
}

int main() {
    char str[MAX_SIZE];
    printf("Enter a string: ");
    scanf("%s", str);
    struct node* head = NULL;
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        int data = str[i];
        insertNode(&head, data);
    }
    int result = searchString(head, str);
    if (result == 1) {
        printf("String found!\n");
    } else {
        printf("String not found.\n");
    }
    return 0;
}