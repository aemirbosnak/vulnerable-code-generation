//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Define a structure to represent a baggage
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
        // Allocate memory for a new baggage
        baggage* new_baggage = (baggage*)malloc(sizeof(baggage));

        // Get the baggage name and weight
        printf("Enter baggage name: ");
        scanf("%s", new_baggage->name);

        printf("Enter baggage weight: ");
        scanf("%d", &new_baggage->weight);

        // Add the baggage to the linked list
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
    printf("List of baggage:\n");
    while (current)
    {
        printf("%s (%.2f kg)\n", current->name, current->weight);
        current = current->next;
    }

    // Simulate baggage handling
    time_t start_time = time(NULL);
    for (int i = 0; i < 5; i++)
    {
        // Randomly select a baggage
        int random_index = rand() % 10;

        // Move the selected baggage to the conveyor belt
        printf("Moving baggage %s to the conveyor belt...\n", head->name);

        // Simulate processing time
        sleep(1);
    }

    // Print the end time
    time_t end_time = time(NULL);
    printf("End time: %.2f seconds\n", end_time - start_time);

    return 0;
}