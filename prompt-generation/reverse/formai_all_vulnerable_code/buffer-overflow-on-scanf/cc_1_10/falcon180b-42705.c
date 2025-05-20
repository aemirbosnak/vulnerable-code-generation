//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Node structure for linked list of words
typedef struct node {
    char word[100];
    int count;
    struct node* next;
} Node;

// Function prototypes
void addWord(Node** head, char* word);
void printList(Node* head);
void deleteList(Node** head);
void searchWord(Node* head, char* word);

int main() {
    Node* head = NULL;
    char input[100];

    while (true) {
        printf("Enter a command (add, print, delete, search, quit): ");
        scanf("%s", input);

        if (strcmp(input, "add") == 0) {
            char word[100];
            printf("Enter a word to add: ");
            scanf("%s", word);
            addWord(&head, word);
        } else if (strcmp(input, "print") == 0) {
            printList(head);
        } else if (strcmp(input, "delete") == 0) {
            deleteList(&head);
        } else if (strcmp(input, "search") == 0) {
            char word[100];
            printf("Enter a word to search for: ");
            scanf("%s", word);
            searchWord(head, word);
        } else if (strcmp(input, "quit") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}

// Function to add a word to the linked list
void addWord(Node** head, char* word) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->word, word);
    newNode->count = 1;
    newNode->next = *head;
    *head = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    while (head!= NULL) {
        printf("%s: %d\n", head->word, head->count);
        head = head->next;
    }
}

// Function to delete the linked list
void deleteList(Node** head) {
    Node* temp = *head;
    while (temp!= NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    *head = NULL;
}

// Function to search for a word in the linked list
void searchWord(Node* head, char* word) {
    while (head!= NULL) {
        if (strcmp(head->word, word) == 0) {
            printf("%s found with count %d\n", word, head->count);
        }
        head = head->next;
    }
}