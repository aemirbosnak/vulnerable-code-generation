//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAG_WEIGHT 50
#define MAX_NUMBER_OF_BAGS 10

typedef struct Bag
{
    char* name;
    int weight;
    struct Bag* next;
} Bag;

void insertBag(Bag** head, char* name, int weight)
{
    Bag* newBag = (Bag*)malloc(sizeof(Bag));
    newBag->name = name;
    newBag->weight = weight;
    newBag->next = NULL;

    if (*head == NULL)
    {
        *head = newBag;
    }
    else
    {
        (*head)->next = newBag;
    }
}

void handleBaggage(Bag** head)
{
    time_t start = time(NULL);
    printf("Baggage handling started at %s\n",ctime(start));

    while (*head)
    {
        printf("Processing bag: %s (weight: %d)\n", (*head)->name, (*head)->weight);

        if ((*head)->weight > MAX_BAG_WEIGHT)
        {
            printf("Bag %s is overweight!\n", (*head)->name);
        }

        sleep(rand() % 3);
        printf("Bag %s has been processed.\n", (*head)->name);

        free((*head)->name);
        free(*head);
        *head = (*head)->next;
    }

    time_t end = time(NULL);
    printf("Baggage handling completed at %s\n",ctime(end));
    printf("Total time: %d seconds\n", end - start);
}

int main()
{
    Bag* head = NULL;
    insertBag(&head, "John Doe's bag", 25);
    insertBag(&head, "Jane Doe's bag", 30);
    insertBag(&head, "Jack Doe's bag", 40);
    insertBag(&head, "Jill Doe's bag", 20);

    handleBaggage(&head);

    return 0;
}