//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: authentic
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Define the baggage handling area
#define baggage_area_size 10

// Define the baggage handling structure
typedef struct baggage {
    char *name;
    int weight;
    struct baggage *next;
} baggage_t;

// Function to add a baggage to the area
void add_baggage(baggage_t **head) {
    // Allocate memory for the new baggage
    baggage_t *new_baggage = malloc(sizeof(baggage_t));

    // Get the name, weight, and next baggage of the new baggage
    printf("Enter baggage name: ");
    scanf("%s", new_baggage->name);

    printf("Enter baggage weight: ");
    scanf("%d", &new_baggage->weight);

    new_baggage->next = NULL;

    // If the head of the baggage area is NULL, make the new baggage the head
    if (*head == NULL) {
        *head = new_baggage;
    } else {
        // Traverse the baggage area to the end and add the new baggage there
        baggage_t *curr_baggage = *head;
        while (curr_baggage->next != NULL) {
            curr_baggage = curr_baggage->next;
        }
        curr_baggage->next = new_baggage;
    }
}

// Function to remove a baggage from the area
void remove_baggage(baggage_t **head) {
    // Get the name of the baggage to be removed
    printf("Enter baggage name: ");
    char *baggage_name = malloc(20);
    scanf("%s", baggage_name);

    // Traverse the baggage area to find the baggage to be removed
    baggage_t *curr_baggage = *head;
    baggage_t *prev_baggage = NULL;
    while (curr_baggage && strcmp(curr_baggage->name, baggage_name) != 0) {
        prev_baggage = curr_baggage;
        curr_baggage = curr_baggage->next;
    }

    // If the baggage to be removed is found, remove it from the area
    if (curr_baggage) {
        // If the baggage to be removed is the head of the baggage area, make the next baggage the head
        if (prev_baggage == NULL) {
            *head = curr_baggage->next;
        } else {
            // Traverse the baggage area to the end of the baggage to be removed and remove it
            prev_baggage->next = curr_baggage->next;
        }

        // Free the memory allocated for the baggage
        free(curr_baggage->name);
        free(curr_baggage);
    }
}

// Function to list all baggage in the area
void list_baggage(baggage_t *head) {
    // Traverse the baggage area and print the name and weight of each baggage
    baggage_t *curr_baggage = head;
    while (curr_baggage) {
        printf("Name: %s, Weight: %d\n", curr_baggage->name, curr_baggage->weight);
        curr_baggage = curr_baggage->next;
    }
}

int main() {
    // Create a linked list to store the baggage
    baggage_t *head = NULL;

    // Add some baggage to the area
    add_baggage(&head);
    add_baggage(&head);
    add_baggage(&head);

    // List all baggage in the area
    list_baggage(head);

    // Remove some baggage from the area
    remove_baggage(&head);

    // List all baggage in the area after removing baggage
    list_baggage(head);

    return 0;
}