//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Structure to define the node of the queue
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add an element to the queue
void enqueue(struct Node** frontRef, struct Node** rearRef, int data) {
    struct Node* newNode = createNode(data);
    if (*frontRef == NULL) {
        *frontRef = newNode;
        *rearRef = newNode;
        return;
    }
    (*rearRef)->next = newNode;
    *rearRef = newNode;
}

// Function to remove an element from the queue
int dequeue(struct Node** frontRef, struct Node** rearRef) {
    if (*frontRef == NULL)
        return -1;
    struct Node* temp = *frontRef;
    *frontRef = (*frontRef)->next;
    int data = temp->data;
    free(temp);
    return data;
}

// Function to display the elements in the queue
void display(struct Node* front) {
    printf("Queue elements are: ");
    while (front!= NULL) {
        printf("%d ", front->data);
        front = front->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Node* front = NULL;
    struct Node* rear = NULL;
    int choice, data;

    do {
        printf("\n\n***** Menu *****\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to be added: ");
                scanf("%d", &data);
                enqueue(&front, &rear, data);
                break;
            case 2:
                data = dequeue(&front, &rear);
                if (data!= -1)
                    printf("The dequeued element is %d\n", data);
                break;
            case 3:
                display(front);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);

    return 0;
}