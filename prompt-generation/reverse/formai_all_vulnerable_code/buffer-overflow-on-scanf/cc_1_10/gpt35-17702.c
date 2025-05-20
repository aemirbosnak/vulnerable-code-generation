//FormAI DATASET v1.0 Category: Linked list operations ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node* createNode(int data) {
    Node *new = (Node*)malloc(sizeof(Node));
    new->data = data;
    new->next = NULL;
    return new;
}

void insertAtBeginning(Node **head, int data) {
    Node *new = createNode(data);
    new->next = *head;
    *head = new;
    printf("[+] New node added at the beginning of the list.\n");
}

void insertAtEnd(Node **head, int data) {
    Node *new = createNode(data);
    Node *temp = *head;
    if(*head == NULL) {
        *head = new;
    }
    else {
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new;
    }
    printf("[+] New node added at the end of the list.\n");
}

void deleteNode(Node **head, int data) {
    Node *temp = *head;
    Node *prev = NULL;
    if(temp != NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        printf("[-] Node with data %d deleted from the list.\n", data);
        return;
    }
    while(temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("[-] Node with data %d not found in the list.\n", data);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("[-] Node with data %d deleted from the list.\n", data);
}

void displayList(Node *head) {
    if(head == NULL) {
        printf("[_] List is empty.\n");
    }
    else {
        printf("[+] List contains: ");
        while(head != NULL) {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
}

int main() {
    printf("[#] Welcome to the Cyberpunk Linked List Operations Program!\n");
    Node *head = NULL;
    int choice = 0, data = 0;
    while(1) {
        printf("\n[?] What operation do you want to perform?\n");
        printf("[1] Insert a node at the beginning of the list.\n");
        printf("[2] Insert a node at the end of the list.\n");
        printf("[3] Delete a node.\n");
        printf("[4] Display the list.\n");
        printf("[5] Exit the program.\n");
        printf("[+] Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: printf("[+] Enter the data to be inserted at the beginning of the list: ");
                    scanf("%d", &data);
                    insertAtBeginning(&head, data);
                    break;
            case 2: printf("[+] Enter the data to be inserted at the end of the list: ");
                    scanf("%d", &data);
                    insertAtEnd(&head, data);
                    break;
            case 3: printf("[+] Enter the data of the node to be deleted: ");
                    scanf("%d", &data);
                    deleteNode(&head, data);
                    break;
            case 4: displayList(head);
                    break;
            case 5: printf("\n[#] Thank you for using the Cyberpunk Linked List Operations Program!\n");
                    exit(0);
            default:printf("[_] Invalid choice! Try again.\n"); 
        }
    }
    return 0;
}