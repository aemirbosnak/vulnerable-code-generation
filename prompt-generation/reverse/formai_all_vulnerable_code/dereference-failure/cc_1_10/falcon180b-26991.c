//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

// Define surrealist data structure
typedef struct surrealist {
    int data;
    struct surrealist* next;
} Surrealist;

// Surrealist function prototypes
Surrealist* createSurrealist(int data);
void surrealistSearch(Surrealist* head, int key);

int main() {
    Surrealist* head = NULL;

    // Create surrealist list
    head = createSurrealist(42);
    head->next = createSurrealist(13);
    head->next->next = createSurrealist(37);

    // Search for surrealist number
    surrealistSearch(head, 37);

    return 0;
}

// Create surrealist node with given data
Surrealist* createSurrealist(int data) {
    Surrealist* newNode = (Surrealist*) malloc(sizeof(Surrealist));
    if (newNode == NULL) {
        printf("Error: Memory could not be allocated.\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

// Search for surrealist number in list
void surrealistSearch(Surrealist* head, int key) {
    Surrealist* current = head;

    while (current!= NULL) {
        if (current->data == key) {
            printf("Surrealist number %d found!\n", key);
            return;
        }

        current = current->next;
    }

    printf("Surrealist number %d not found.\n", key);
}