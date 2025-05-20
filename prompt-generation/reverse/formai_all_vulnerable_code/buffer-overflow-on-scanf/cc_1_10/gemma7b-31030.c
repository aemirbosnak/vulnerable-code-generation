//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Baggage Handling Simulation
    // The C Way

    // Define a struct to store baggage information
    typedef struct Baggage {
        char name[20];
        int weight;
        struct Baggage* next;
    } Baggage;

    // Create a linked list of baggage
    Baggage* head = NULL;

    // Simulate passengers checking in
    for (int i = 0; i < 10; i++) {
        // Allocate memory for a new baggage item
        Baggage* newBaggage = (Baggage*)malloc(sizeof(Baggage));

        // Get the baggage item's name and weight
        printf("Enter the name of your baggage item: ");
        scanf("%s", newBaggage->name);

        printf("Enter the weight of your baggage item (in kilograms): ");
        scanf("%d", &newBaggage->weight);

        // Add the baggage item to the linked list
        if (head == NULL) {
            head = newBaggage;
        } else {
            newBaggage->next = head;
            head = newBaggage;
        }
    }

    // Print the baggage list
    printf("Here is your baggage list:\n");
    for (Baggage* currentBaggage = head; currentBaggage != NULL; currentBaggage = currentBaggage->next) {
        printf("Name: %s, Weight: %d\n", currentBaggage->name, currentBaggage->weight);
    }

    // Calculate the total weight of the baggage
    int totalWeight = 0;
    for (Baggage* currentBaggage = head; currentBaggage != NULL; currentBaggage = currentBaggage->next) {
        totalWeight += currentBaggage->weight;
    }

    // Print the total weight of the baggage
    printf("The total weight of your baggage is: %d kilograms\n", totalWeight);

    // Free the memory allocated for the baggage items
    for (Baggage* currentBaggage = head; currentBaggage != NULL; currentBaggage = currentBaggage->next) {
        free(currentBaggage);
    }

    return 0;
}