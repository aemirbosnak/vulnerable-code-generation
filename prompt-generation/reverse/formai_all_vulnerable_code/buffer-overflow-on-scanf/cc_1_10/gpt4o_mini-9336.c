//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

// Defining the Node structure, where each node holds an integer treasure and a pointer to the next.
struct Node {
    int treasure;
    struct Node* next;
};

// Function declarations
struct Node* createNode(int treasure);
void addNode(struct Node** head, int treasure);
void deleteNode(struct Node** head, int treasure);
void displayList(struct Node* head);
void freeList(struct Node* head);
int listLength(struct Node* head);
int findTreasure(struct Node* head, int treasure);

int main() {
    struct Node* village = NULL; // The village starts empty.
    int choice, treasure;

    do {
        printf("\nWelcome to the Village of Nodes!\n");
        printf("1. Add a Treasure\n");
        printf("2. Delete a Treasure\n");
        printf("3. Display Treasures\n");
        printf("4. Find a Treasure\n");
        printf("5. Get Total Treasures\n");
        printf("6. Exit the Village\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter treasure to add: ");
                scanf("%d", &treasure);
                addNode(&village, treasure);
                printf("Treasure %d has been added to the village!\n", treasure);
                break;

            case 2:
                printf("Enter treasure to delete: ");
                scanf("%d", &treasure);
                deleteNode(&village, treasure);
                break;

            case 3:
                printf("Displaying all treasures in the village:\n");
                displayList(village);
                break;

            case 4:
                printf("Enter the treasure to find: ");
                scanf("%d", &treasure);
                if (findTreasure(village, treasure)) {
                    printf("Treasure %d is found in the village!\n", treasure);
                } else {
                    printf("Treasure %d is not found in the village.\n", treasure);
                }
                break;

            case 5:
                printf("Total Treasures in the village: %d\n", listLength(village));
                break;

            case 6:
                printf("Thank you for visiting the village! Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 6);

    freeList(village); // Free the village when exiting.
    return 0;
}

// Function to create a new node
struct Node* createNode(int treasure) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode != NULL) { // Check for memory allocation success.
        newNode->treasure = treasure;
        newNode->next = NULL;
    }
    return newNode;
}

// Function to add a node to the village
void addNode(struct Node** head, int treasure) {
    struct Node* newNode = createNode(treasure);
    if (*head == NULL) {
        *head = newNode; // Village was empty.
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next; // Traverse to the end.
        }
        temp->next = newNode; // Add the new treasure.
    }
}

// Function to delete a node (treasure) from the village
void deleteNode(struct Node** head, int treasure) {
    struct Node* temp = *head, *prev = NULL;

    // Finding the treasure.
    while (temp != NULL && temp->treasure != treasure) {
        prev = temp;
        temp = temp->next;
    }

    // If treasure was not found
    if (temp == NULL) {
        printf("Treasure %d not found in the village.\n", treasure);
        return;
    }

    // If the treasure is the first node
    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next; // Bypass the node to be deleted.
    }
    free(temp); // Free the lost treasure's node.
    printf("Treasure %d has been deleted from the village!\n", treasure);
}

// Function to display all nodes in the village
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The village is empty!\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("Treasure: %d\n", temp->treasure);
        temp = temp->next; // Move to the next node.
    }
}

// Function to free the entire village's memory
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Function to calculate the length of the list
int listLength(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to find a specific treasure
int findTreasure(struct Node* head, int treasure) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->treasure == treasure) {
            return 1; // Treasure found.
        }
        temp = temp->next;
    }
    return 0; // Treasure not found.
}