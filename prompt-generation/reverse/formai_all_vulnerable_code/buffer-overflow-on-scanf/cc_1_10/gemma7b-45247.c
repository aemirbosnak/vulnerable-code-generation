//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define a structure to represent a baggage item
    typedef struct BaggageItem
    {
        char name[50];
        int weight;
        struct BaggageItem* next;
    } BaggageItem;

    // Create a linked list of baggage items
    BaggageItem* head = NULL;

    // Simulate baggage handling operations
    while (1)
    {
        // Get the baggage item name and weight from the user
        char name[50];
        int weight;
        printf("Enter the name of the baggage item: ");
        scanf("%s", name);

        printf("Enter the weight of the baggage item (in kilograms): ");
        scanf("%d", &weight);

        // Create a new baggage item
        BaggageItem* newItem = (BaggageItem*)malloc(sizeof(BaggageItem));
        strcpy(newItem->name, name);
        newItem->weight = weight;
        newItem->next = NULL;

        // If the list is empty, make the new item the head
        if (head == NULL)
        {
            head = newItem;
        }
        // Otherwise, add the new item to the end of the list
        else
        {
            head->next = newItem;
            head = newItem;
        }

        // Check if the user wants to continue
        char continue_or_not;
        printf("Do you want to continue? (Y/N): ");
        scanf("%c", &continue_or_not);

        // If the user does not want to continue, break out of the loop
        if (continue_or_not == 'N')
        {
            break;
        }
    }

    // Print the list of baggage items
    printf("Here is your list of baggage items:\n");
    for (BaggageItem* item = head; item != NULL; item = item->next)
    {
        printf("%s (%d kg)\n", item->name, item->weight);
    }

    return 0;
}