//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct medical_store{
    char name[30], address[100], medicine[50];
    int quantity, cost;
    struct medical_store* next;
} store;

store* head = NULL;

void insert_medical_store(store** head_ref)
{
    store* new_store = (store*)malloc(sizeof(store));
    printf("\nEnter the name of the medical store: ");
    scanf("%s", new_store->name);
    printf("Enter the address of the medical store: ");
    scanf("%s", new_store->address);
    printf("Enter the name of the medicine: ");
    scanf("%s", new_store->medicine);
    printf("Enter the quantity of medicine available: ");
    scanf("%d", &new_store->quantity);
    printf("Enter the cost of the medicine: ");
    scanf("%d", &new_store->cost);
    new_store->next = (*head_ref);
    (*head_ref) = new_store;
}

void display_medical_store(store* node)
{
    if(node == NULL)
    {
        return;
    }
    printf("\nName of the medical store: %s\n", node->name);
    printf("Address of the medical store: %s\n", node->address);
    printf("Name of the medicine: %s\n", node->medicine);
    printf("Quantity of medicine available: %d\n", node->quantity);
    printf("Cost of the medicine: %d\n", node->cost);
    display_medical_store(node->next);
}

int main()
{
    int choice;
    while(1)
    {
        printf("\n---- MENU ----\n1. Insert medical store details\n2. Display medical store details\n3. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                insert_medical_store(&head);
                break;
            case 2:
                display_medical_store(head);
                break;
            case 3:
                return 0;
            default:
                printf("\nInvalid choice! Please enter again.");
        }
    }
    return 0;
}