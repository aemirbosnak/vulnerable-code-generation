//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Medicine
{
    char name[50];
    char dosage[50];
    char quantity[50];
    struct Medicine* next;
} Medicine;

void insertMedicine(Medicine** head)
{
    Medicine* newMedicine = (Medicine*)malloc(sizeof(Medicine));
    printf("Enter medicine name: ");
    scanf("%s", newMedicine->name);
    printf("Enter dosage: ");
    scanf("%s", newMedicine->dosage);
    printf("Enter quantity: ");
    scanf("%s", newMedicine->quantity);

    if (*head == NULL)
    {
        *head = newMedicine;
    }
    else
    {
        (*head)->next = newMedicine;
    }
}

void searchMedicine(Medicine* head, char* name)
{
    while (head)
    {
        if (strcmp(head->name, name) == 0)
        {
            printf("Name: %s\n", head->name);
            printf("Dosage: %s\n", head->dosage);
            printf("Quantity: %s\n", head->quantity);
            return;
        }
        head = head->next;
    }

    printf("Medicine not found.\n");
}

int main()
{
    Medicine* head = NULL;

    insertMedicine(&head);
    insertMedicine(&head);
    insertMedicine(&head);

    searchMedicine(head, "Medicine 2");

    return 0;
}