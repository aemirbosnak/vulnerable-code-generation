//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_DATA_LENGTH 1000
#define MAX_NUM_RECORDS 1000

// Node structure for linked list
typedef struct node {
    char key[MAX_KEY_LENGTH];
    char data[MAX_DATA_LENGTH];
    struct node *next;
} Node;

// Linked list structure
Node *head = NULL;

// Function to add a record to the linked list
void addRecord(char *key, char *data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->key, key);
    strcpy(newNode->data, data);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to search for a record in the linked list
int searchRecord(char *key) {
    Node *temp = head;
    while (temp!= NULL) {
        if (strcmp(temp->key, key) == 0) {
            printf("%s\n", temp->data);
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

// Function to delete a record from the linked list
void deleteRecord(char *key) {
    Node *temp = head;
    Node *prev = NULL;

    while (temp!= NULL) {
        if (strcmp(temp->key, key) == 0) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
}

// Function to create a hash table
void createHashTable() {
    int i, j;
    for (i = 0; i < MAX_NUM_RECORDS; i++) {
        head = NULL;
        for (j = 0; j < 26; j++) {
            Node *temp = head;
            while (temp!= NULL) {
                if (temp->key[0] == (char)('a' + j)) {
                    break;
                }
                temp = temp->next;
            }
            if (temp == NULL) {
                addRecord("", "");
            }
            temp = temp->next;
        }
    }
}

// Function to index the database
void indexDatabase() {
    int i, j;
    for (i = 0; i < MAX_NUM_RECORDS; i++) {
        head = NULL;
        for (j = 0; j < 26; j++) {
            Node *temp = head;
            while (temp!= NULL) {
                if (temp->key[0] == (char)('a' + j)) {
                    break;
                }
                temp = temp->next;
            }
            if (temp!= NULL) {
                printf("%c\n", (char)('a' + j));
                temp = temp->next;
                while (temp!= NULL) {
                    printf("%s\n", temp->data);
                    temp = temp->next;
                }
            }
        }
    }
}

// Main function
int main() {
    createHashTable();
    indexDatabase();
    return 0;
}