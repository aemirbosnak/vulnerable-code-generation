//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Medicine
{
    char name[50];
    int quantity;
    float price;
    struct Medicine* next;
} Medicine;

void insert_medicine(Medicine**, char*, int, float);
void search_medicine(Medicine*, char*);
void update_medicine(Medicine*, char*, int, float);
void delete_medicine(Medicine*, char*);

int main()
{
    Medicine* head = NULL;

    char name[50];
    int quantity;
    float price;

    printf("Enter the name of the medicine: ");
    scanf("%s", name);

    printf("Enter the quantity of the medicine: ");
    scanf("%d", &quantity);

    printf("Enter the price of the medicine: ");
    scanf("%f", &price);

    insert_medicine(&head, name, quantity, price);

    printf("Medicine inserted successfully!\n");

    printf("Enter the name of the medicine you want to search: ");
    scanf("%s", name);

    search_medicine(head, name);

    printf("Enter the name of the medicine you want to update: ");
    scanf("%s", name);

    printf("Enter the new quantity of the medicine: ");
    scanf("%d", &quantity);

    printf("Enter the new price of the medicine: ");
    scanf("%f", &price);

    update_medicine(head, name, quantity, price);

    printf("Medicine updated successfully!\n");

    printf("Enter the name of the medicine you want to delete: ");
    scanf("%s", name);

    delete_medicine(head, name);

    printf("Medicine deleted successfully!\n");

    return 0;
}

void insert_medicine(Medicine** head, char* name, int quantity, float price)
{
    Medicine* new_node = (Medicine*)malloc(sizeof(Medicine));

    strcpy(new_node->name, name);
    new_node->quantity = quantity;
    new_node->price = price;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        (*head)->next = new_node;
        *head = new_node;
    }
}

void search_medicine(Medicine* head, char* name)
{
    while (head)
    {
        if (strcmp(head->name, name) == 0)
        {
            printf("Name: %s\n", head->name);
            printf("Quantity: %d\n", head->quantity);
            printf("Price: %.2f\n", head->price);
            break;
        }
        head = head->next;
    }

    if (head == NULL)
    {
        printf("Medicine not found.\n");
    }
}

void update_medicine(Medicine* head, char* name, int quantity, float price)
{
    while (head)
    {
        if (strcmp(head->name, name) == 0)
        {
            head->quantity = quantity;
            head->price = price;
            break;
        }
        head = head->next;
    }

    if (head == NULL)
    {
        printf("Medicine not found.\n");
    }
}

void delete_medicine(Medicine* head, char* name)
{
    Medicine* previous = NULL;
    Medicine* current = head;

    while (current)
    {
        if (strcmp(current->name, name) == 0)
        {
            if (previous)
            {
                previous->next = current->next;
            }
            else
            {
                head = current->next;
            }
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Medicine not found.\n");
    }
}