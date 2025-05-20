//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    // Baggage Handling Simulation

    // Define a structure to store baggage information
    typedef struct baggage
    {
        char name[20];
        int weight;
        struct baggage* next;
    } baggage;

    // Create a linked list of baggage
    baggage* head = NULL;

    // Simulate baggage check-in
    for (int i = 0; i < 10; i++)
    {
        // Allocate memory for a new baggage node
        baggage* new_baggage = (baggage*)malloc(sizeof(baggage));

        // Get the baggage name and weight
        printf("Enter baggage name: ");
        scanf("%s", new_baggage->name);

        printf("Enter baggage weight: ");
        scanf("%d", &new_baggage->weight);

        // Insert the new baggage node into the linked list
        if (head == NULL)
        {
            head = new_baggage;
        }
        else
        {
            new_baggage->next = head;
            head = new_baggage;
        }
    }

    // Print the baggage list
    baggage* current = head;
    while (current)
    {
        printf("%s (%d) ", current->name, current->weight);
        current = current->next;
    }

    // Calculate the total weight of the baggage
    int total_weight = 0;
    current = head;
    while (current)
    {
        total_weight += current->weight;
        current = current->next;
    }

    // Print the total weight
    printf("\nTotal weight: %d", total_weight);

    // Free the baggage memory
    current = head;
    while (current)
    {
        free(current);
        current = current->next;
    }

    return 0;
}