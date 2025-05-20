//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Node structure for linked list
typedef struct node {
    char *data;
    struct node *next;
} Node;

//Function prototypes
void addNode(Node** head, char* data);
void printList(Node* head);
void freeList(Node* head);

//Main function
int main() {
    FILE* fp;
    char line[100];
    char* token;
    Node* head = NULL;

    //Open input file
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    //Read each line from input file
    while (fgets(line, sizeof(line), fp)!= NULL) {
        //Tokenize each line
        token = strtok(line, " ");
        while (token!= NULL) {
            //Add each token to linked list
            addNode(&head, token);
            token = strtok(NULL, " ");
        }
    }

    //Print linked list
    printf("Linked List:\n");
    printList(head);

    //Free memory allocated for linked list
    freeList(head);

    //Close input file
    fclose(fp);

    return 0;
}

//Function to add node to linked list
void addNode(Node** head, char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error allocating memory\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

//Function to print linked list
void printList(Node* head) {
    while (head!= NULL) {
        printf("%s ", head->data);
        head = head->next;
    }
    printf("\n");
}

//Function to free memory allocated for linked list
void freeList(Node* head) {
    while (head!= NULL) {
        free(head->data);
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}