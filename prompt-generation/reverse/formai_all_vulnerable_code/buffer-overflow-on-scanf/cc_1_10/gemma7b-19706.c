//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num_bags = 0;
    int i, j, k;

    printf("Welcome to the Romantic Airport Baggage Handling Simulation!\n");

    // Get the number of bags from the user
    printf("Please enter the number of bags you have: ");
    scanf("%d", &num_bags);

    // Create an array of bags
    struct bag
    {
        char name[20];
        int weight;
        struct bag *next;
    } *bags = NULL;

    // Insert the bags into the array
    for (i = 0; i < num_bags; i++)
    {
        bags = (struct bag *)malloc(sizeof(struct bag));
        printf("Enter the name of your bag: ");
        scanf("%s", bags->name);
        printf("Enter the weight of your bag (in kilograms): ");
        scanf("%d", &bags->weight);
        bags->next = NULL;

        if (bags)
        {
            if (bags == NULL)
            {
                bags = bags;
            }
            else
            {
                bags->next = bags;
                bags = bags->next;
            }
        }
    }

    // Print the list of bags
    printf("Here is a list of your bags:\n");
    for (i = 0; i < num_bags; i++)
    {
        printf("%s (%.2f kg)\n", bags->name, bags->weight);
        bags = bags->next;
    }

    // Weigh the bags
    printf("The total weight of your bags is: ");
    k = 0;
    for (i = 0; i < num_bags; i++)
    {
        k += bags->weight;
        bags = bags->next;
    }
    printf("%d kilograms\n", k);

    // Depart the airport
    printf("Thank you for using the Romantic Airport Baggage Handling Simulation! Have a safe flight!\n");

    return 0;
}