//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Node structure for linked list
struct node {
    char data;
    struct node* next;
};

// Function to create a new node
struct node* createNode(char data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to search for a character in a linked list
int search(struct node* head, char ch) {
    struct node* temp = head;
    int count = 0;
    while (temp!= NULL) {
        if (temp->data == ch) {
            count++;
        }
        temp = temp->next;
    }
    return count;
}

// Function to print a linked list
void printList(struct node* head) {
    struct node* temp = head;
    while (temp!= NULL) {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    char str[MAX_SIZE];
    printf("Enter a string: ");
    scanf("%s", str);
    int len = strlen(str);
    struct node* head = NULL;
    struct node* tail = NULL;
    int i;
    for (i = 0; i < len; i++) {
        char ch = str[i];
        if (head == NULL) {
            head = createNode(ch);
            tail = head;
        }
        else {
            tail->next = createNode(ch);
            tail = tail->next;
        }
    }
    printf("Linked list: ");
    printList(head);
    int searchResult = search(head, 'a');
    printf("Number of occurrences of 'a': %d\n", searchResult);
    return 0;
}