//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define a structure to store baggage information
    typedef struct Baggage
    {
        char* name;
        int weight;
        struct Baggage* next;
    } Baggage;

    // Create a linked list of baggage
    Baggage* head = NULL;

    // Simulate baggage check-in
    printf("Enter baggage name: ");
    char* name = malloc(20);
    scanf("%s", name);

    printf("Enter baggage weight (in kg): ");
    int weight = atoi(malloc(20));

    Baggage* new_baggage = malloc(sizeof(Baggage));
    new_baggage->name = name;
    new_baggage->weight = weight;
    new_baggage->next = NULL;

    if (head == NULL)
    {
        head = new_baggage;
    }
    else
    {
        head->next = new_baggage;
        head = new_baggage;
    }

    // Simulate baggage handling
    printf("Baggage name: %s\n", head->name);
    printf("Baggage weight: %d kg\n", head->weight);

    // Calculate baggage total weight
    int total_weight = 0;
    for (Baggage* current = head; current != NULL; current = current->next)
    {
        total_weight += current->weight;
    }

    // Print baggage total weight
    printf("Total baggage weight: %d kg\n", total_weight);

    // Free baggage memory
    free(name);
    free(new_baggage);

    return 0;
}