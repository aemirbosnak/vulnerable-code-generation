//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Medicine
{
    char name[20];
    int quantity;
    float price;
} Medicine;

void manage_inventory(Medicine **medicines, int *size)
{
    int i = 0;
    printf("Enter the name of the medicine: ");
    scanf("%s", medicines[*size]->name);
    printf("Enter the quantity: ");
    scanf("%d", &medicines[*size]->quantity);
    printf("Enter the price: ");
    scanf("%f", &medicines[*size]->price);
    (*size)++;
}

void display_inventory(Medicine **medicines, int size)
{
    int i = 0;
    printf("Inventory:\n");
    for (i = 0; i < size; i++)
    {
        printf("%s - %d - %.2f\n", medicines[i]->name, medicines[i]->quantity, medicines[i]->price);
    }
}

int main()
{
    Medicine **medicines = NULL;
    int size = 0;

    char choice;

    while (1)
    {
        printf("Enter 'add' to add a medicine, 'display' to display inventory, or 'exit' to exit: ");
        scanf("%c", &choice);

        switch (choice)
        {
            case 'a':
                manage_inventory(&medicines, &size);
                break;
            case 'd':
                display_inventory(medicines, size);
                break;
            case 'e':
                exit(0);
            default:
                printf("Invalid input.\n");
        }
    }

    return 0;
}