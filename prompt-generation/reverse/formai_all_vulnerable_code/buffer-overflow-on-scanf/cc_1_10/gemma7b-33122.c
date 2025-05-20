//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Define a structure to store baggage information
    struct baggage
    {
        char name[20];
        int weight;
        struct baggage* next;
    };

    // Create a linked list of baggage
    struct baggage* head = NULL;

    // Simulate baggage check-in
    for (int i = 0; i < 10; i++)
    {
        // Allocate memory for a new baggage node
        struct baggage* new_baggage = (struct baggage*)malloc(sizeof(struct baggage));

        // Get the baggage name and weight
        printf("Enter baggage name: ");
        scanf("%s", new_baggage->name);

        printf("Enter baggage weight: ");
        scanf("%d", &new_baggage->weight);

        // Add the new baggage node to the linked list
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

    // Simulate baggage handling
    for (struct baggage* current = head; current; current = current->next)
    {
        // Print the baggage name and weight
        printf("Baggage name: %s\n", current->name);

        printf("Baggage weight: %d\n", current->weight);

        // Randomly simulate baggage handling actions
        switch (rand() % 3)
        {
            case 0:
                printf("Baggage weighed and tagged.\n");
                break;
            case 1:
                printf("Baggage transferred to another cart.\n");
                break;
            case 2:
                printf("Baggage loaded onto plane.\n");
                break;
        }
    }

    // Free the memory allocated for baggage nodes
    for (struct baggage* current = head; current; current = current->next)
    {
        free(current);
    }

    return 0;
}