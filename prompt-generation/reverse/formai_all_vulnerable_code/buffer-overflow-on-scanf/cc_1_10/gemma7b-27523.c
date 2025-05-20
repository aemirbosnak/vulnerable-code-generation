//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define a structure to represent a baggage item
    typedef struct baggage_item
    {
        char name[20];
        int weight;
        struct baggage_item* next;
    } baggage_item;

    // Create a linked list of baggage items
    baggage_item* head = NULL;

    // Simulate baggage handling operations
    while (1)
    {
        // Get the item name and weight
        char item_name[20];
        int item_weight;
        printf("Enter item name: ");
        scanf("%s", item_name);

        printf("Enter item weight: ");
        scanf("%d", &item_weight);

        // Create a new baggage item
        baggage_item* new_item = (baggage_item*)malloc(sizeof(baggage_item));
        strcpy(new_item->name, item_name);
        new_item->weight = item_weight;
        new_item->next = NULL;

        // Add the new item to the linked list
        if (head == NULL)
        {
            head = new_item;
        }
        else
        {
            new_item->next = head;
            head = new_item;
        }

        // Print the list of baggage items
        printf("List of baggage items:\n");
        baggage_item* current_item = head;
        while (current_item)
        {
            printf("%s (%d) ", current_item->name, current_item->weight);
            current_item = current_item->next;
            printf("\n");
        }

        // Break out of the loop
        if (strcmp(item_name, "quit") == 0)
        {
            break;
        }
    }

    return 0;
}