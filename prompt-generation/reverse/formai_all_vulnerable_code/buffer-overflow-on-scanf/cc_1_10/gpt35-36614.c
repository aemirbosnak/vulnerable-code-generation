//FormAI DATASET v1.0 Category: Data recovery tool ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_SIZE 100
#define MAX_DATA_SIZE 10000

typedef struct Node {
    int val;
    struct Node *next;
} Node;

// Function to create and return a new node
Node *createNode(int val) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of linked list
Node *insertNode(Node *head, int val) {
    Node *newNode = createNode(val);
    if (head == NULL) {
        head = newNode;
    } else {
        Node *curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    return head;
}

// Function to traverse and print the linked list
void printLinkedList(Node *head) {
    Node *curr = head;
    while (curr != NULL) {
        printf("%d ", curr->val);
        curr = curr->next;
    }
}

// Function to recover the data from a file
void recoverDataFromFile(char *filename) {
    FILE *fp;
    if ((fp = fopen(filename, "r")) == NULL) {
        printf("Error! File not found\n");
        exit(1);
    }

    char buffer[MAX_DATA_SIZE];
    char *token;
    Node *head = NULL;

    while (fgets(buffer, MAX_DATA_SIZE, fp) != NULL) {
        token = strtok(buffer, ",");
        while (token != NULL) {
            head = insertNode(head, atoi(token));
            token = strtok(NULL, ",");
        }
    }

    printf("Recovered data from file:\n");
    printLinkedList(head);

    fclose(fp);
}

int main() {
    char filename[MAX_FILE_NAME_SIZE];
    printf("Enter the name of the file to recover data from: ");
    scanf("%s", filename);

    recoverDataFromFile(filename);

    return 0;
}