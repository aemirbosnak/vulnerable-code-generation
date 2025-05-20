//FormAI DATASET v1.0 Category: Linked list operations ; Style: happy
#include<stdio.h>
#include<stdlib.h>

/* create the structure of linked list node */
struct Node {
    int num;
    struct Node* Next;
};

/* function declaration */
void printLinkedList(struct Node* nodePtr);
void addNodeAtBeginning(int num);
void addNodeAtEnd(int num);
void addNodeAfter(int num, int newNodeNum);
void deleteNode(int num);

/* initialize the head node */
struct Node* Head = NULL;

/* main function */
int main() {
    int option, num, newNodeNum;

    do {
        /* print menu */
        printf("\n\nWelcome to Happy Linked List Operations!\n");
        printf("\n1. Print Linked List");
        printf("\n2. Add node at beginning");
        printf("\n3. Add node at end");
        printf("\n4. Add node after a node");
        printf("\n5. Delete a node");
        printf("\n6. Exit");
        printf("\n\n Please enter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                /* print linked list */
                printLinkedList(Head);
                break;
            case 2:
                /* add node at beginning */
                printf("\nEnter the number to add: ");
                scanf("%d", &num);
                addNodeAtBeginning(num);
                printf("\nNode added to the beginning! Happy!!\n");
                break;
            case 3:
                /* add node at end */
                printf("\nEnter the number to add: ");
                scanf("%d", &num);
                addNodeAtEnd(num);
                printf("\nNode added to the end, Yay!!\n");
                break;
            case 4:
                /* add node after a node */
                printf("\nEnter the number to add: ");
                scanf("%d", &num);
                printf("Enter the number of node after which you want to add: ");
                scanf("%d", &newNodeNum);
                addNodeAfter(num, newNodeNum);
                printf("\nNode added successfully, Let's celebrate!!\n");
                break;
            case 5:
                /* delete a node */
                printf("\nEnter the number to delete: ");
                scanf("%d", &num);
                deleteNode(num);
                printf("\nNode deleted successfully, Keep up the good work!!\n");
                break;
            case 6:
                exit(0);
            default:
                printf("\nInvalid option, Please choose a valid option :)\n");
        }
    } while(1);

    return 0;
}

/* function to print linked list */
void printLinkedList(struct Node* nodePtr) {
    if(nodePtr == NULL) {
        printf("\nLinked List is Empty, So Sad :(\n");
    }
    else {
        printf("\n Linked List Content: ");
        while(nodePtr != NULL) {
            printf("%d ", nodePtr->num);
            nodePtr = nodePtr->Next;
        }
        printf("\n");
    }
}

/* function to add node at beginning */
void addNodeAtBeginning(int num) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->num = num;

    newNode->Next = Head;
    Head = newNode;
}

/* function to add node at end */
void addNodeAtEnd(int num) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* nodePtr = Head;

    newNode->num = num;
    newNode->Next = NULL;

    if(Head == NULL) {
        Head = newNode;
        return;
    }

    while(nodePtr->Next != NULL) {
        nodePtr = nodePtr->Next;
    }
    nodePtr->Next = newNode;
}

/* function to add node after a node */
void addNodeAfter(int num, int newNodeNum) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* nodePtr = Head;

    newNode->num = newNodeNum;

    while(nodePtr != NULL) {
        if(nodePtr->num == num) {
            newNode->Next = nodePtr->Next;
            nodePtr->Next = newNode;
            return;
        }
        nodePtr = nodePtr->Next;
    }
    printf("\n%d not found, Cannot add node after this number :(\n", num);
}

/* function to delete a node */
void deleteNode(int num) {
    struct Node* temp = Head, *prev;

    if(temp != NULL && temp->num == num) {
        Head = temp->Next;
        free(temp);
        return;
    }

    while(temp != NULL && temp->num != num) {
        prev = temp;
        temp = temp->Next;
    }

    if (temp == NULL) {
        printf("\n%d not found, Cannot delete node with this number :(\n", num);
        return;
    }

    prev->Next = temp->Next;
    free(temp);
}