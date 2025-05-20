//FormAI DATASET v1.0 Category: Linked list operations ; Style: Romeo and Juliet
/* A Linked List Operations Program in Romeo and Juliet Style */

#include <stdio.h>
#include <stdlib.h>

/* Structure of the Linked List Node */
struct Node {
    int data;
    struct Node* next;
};

/* Function to create a new Node with the given data */
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

/* Function to insert a new Node at the beginning of the List */
void insertAtBeginning(struct Node** head_ref, int data) {
    struct Node* node = newNode(data);
    node->next = *head_ref;
    *head_ref = node;
    printf("Ah, fair maiden! A new knight has joined the fray!\n");
}

/* Function to insert a new Node at the end of the List */
void insertAtEnd(struct Node** head_ref, int data) {
    struct Node* node = newNode(data);
    if (*head_ref == NULL) {
        *head_ref = node;
        printf("My love, thou art the first knight of this quest.\n");
        return;
    }
    struct Node* temp = *head_ref;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = node;
    printf("Hark! Another knight hath joined our noble court!\n");
}

/* Function to delete the first occurrence of a Node with the given data */
void deleteNode(struct Node** head_ref, int data) {
    struct Node* temp = *head_ref, *prev;
    if (temp != NULL && temp->data == data) {
        *head_ref = temp->next;
        free(temp);
        printf("Alas! The valiant knight hath been slain!\n");
        return;
    }
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        printf("Wherefore art thou, my love? The knight is not in our court!\n");
    else {
        prev->next = temp->next;
        free(temp);
        printf("Cometh, let us mourn the loss of a noble warrior!\n");
    }
}

/* Function to display the Linked List elements */
void displayList(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("No knights in our court, my love!\n");
        return;
    }
    printf("All ye noble knights, hail!\n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

/* Main Function */
int main() {
    struct Node* head = NULL;
    printf("My love, shall we start our quest for noble knights?\n");
    int choice, data, delData;
    do {
        printf("\nChoose one:\n1. Add a new knight to the Court\n2. Remove a knight from the Court\n3. Display the Court\n4. Exit the Court\nYour choice, my love: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Enter the noble knight's value: ");
                    scanf("%d", &data);
                    insertAtEnd(&head, data);
                    break;
            case 2: printf("Enter the value of the slain knight: ");
                    scanf("%d", &delData);
                    deleteNode(&head, delData);
                    break;
            case 3: displayList(head);
                    break;
            case 4: printf("Farewell, my love. May ye live long and prosper!\n");
                    break;
            default: printf("Enter a valid choice, my love!\n");
                     break;
        }
    } while (choice != 4);
    return 0;
}