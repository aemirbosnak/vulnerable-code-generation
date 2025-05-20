//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>

void main()
{

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
    printf("Enter the name of your baggage:");
    scanf("%s", head->name);

    printf("Enter the weight of your baggage (in kilograms):");
    scanf("%d", &head->weight);

    // Insert the baggage into the linked list
    head = (baggage*)malloc(sizeof(baggage));
    head->next = NULL;

    // Repeat for other passengers
    int num_passengers = 0;
    printf("How many passengers will be checking in?:");
    scanf("%d", &num_passengers);

    for (int i = 0; i < num_passengers; i++)
    {
        printf("Enter the name of your baggage:");
        scanf("%s", head->name);

        printf("Enter the weight of your baggage (in kilograms):");
        scanf("%d", &head->weight);

        // Insert the baggage into the linked list
        head = (baggage*)malloc(sizeof(baggage));
        head->next = NULL;
    }

    // Print the baggage list
    printf("Here is your baggage list:");
    baggage* current = head;
    while (current)
    {
        printf("Name: %s, Weight: %d\n", current->name, current->weight);
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
    printf("Total weight: %d kilograms\n", total_weight);

    // Free the baggage list
    current = head;
    while (current)
    {
        free(current);
        current = current->next;
    }

    return;
}