//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define a baggage handling structure
    typedef struct baggage
    {
        char name[20];
        int weight;
        struct baggage* next;
    } baggage;

    // Create a baggage handling linked list
    baggage* head = NULL;

    // Simulate baggage arrivals
    for (int i = 0; i < 10; i++)
    {
        // Allocate a new baggage node
        baggage* new_baggage = malloc(sizeof(baggage));

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

    // Simulate baggage departures
    for (int i = 0; i < 5; i++)
    {
        // Get the baggage name
        printf("Enter baggage name: ");
        char name[20];
        scanf("%s", name);

        // Find the baggage node
        baggage* current_baggage = head;
        while (current_baggage && strcmp(current_baggage->name, name) != 0)
        {
            current_baggage = current_baggage->next;
        }

        // If the baggage node is found, remove it from the linked list
        if (current_baggage)
        {
            current_baggage->next = current_baggage->next->next;
            free(current_baggage);
        }
    }

    // Print the remaining baggage
    baggage* current_baggage = head;
    while (current_baggage)
    {
        printf("Name: %s, Weight: %d\n", current_baggage->name, current_baggage->weight);
        current_baggage = current_baggage->next;
    }

    return 0;
}