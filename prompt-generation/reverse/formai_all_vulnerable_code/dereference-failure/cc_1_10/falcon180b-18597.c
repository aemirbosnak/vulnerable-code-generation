//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

//Node structure for the linked list
struct node {
    char data[MAX_SIZE];
    struct node *next;
};

//Function to create a new node
struct node *createNode(char *data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

//Function to add a node to the end of the list
void addNode(struct node **head, char *data) {
    struct node *newNode = createNode(data);
    struct node *temp = *head;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

//Function to search for a node in the list
struct node *searchNode(struct node *head, char *data) {
    struct node *temp = head;
    while (temp!= NULL) {
        if (strcmp(temp->data, data) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

//Function to print the list
void printList(struct node *head) {
    struct node *temp = head;
    while (temp!= NULL) {
        printf("%s\n", temp->data);
        temp = temp->next;
    }
}

//Main function
int main() {
    struct node *head = NULL;
    char input[MAX_SIZE];

    //Prompt user for input
    printf("Enter a string: ");
    scanf("%s", input);

    //Add node to the end of the list
    addNode(&head, input);

    //Search for a node in the list
    struct node *result = searchNode(head, input);
    if (result!= NULL) {
        printf("Node found!\n");
    } else {
        printf("Node not found.\n");
    }

    //Print the list
    printf("List:\n");
    printList(head);

    return 0;
}