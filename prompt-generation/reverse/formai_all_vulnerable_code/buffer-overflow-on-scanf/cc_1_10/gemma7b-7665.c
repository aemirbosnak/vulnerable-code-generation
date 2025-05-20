//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct Medicine
{
    char name[20];
    int quantity;
    float price;
};

struct Medicine med[MAX];

void addMedicine()
{
    struct Medicine newMedicine;
    printf("Enter medicine name: ");
    scanf("%s", newMedicine.name);
    printf("Enter quantity: ");
    scanf("%d", &newMedicine.quantity);
    printf("Enter price: ");
    scanf("%f", &newMedicine.price);

    for (int i = 0; i < MAX; i++)
    {
        if (med[i].name[0] == '\0')
        {
            med[i] = newMedicine;
            break;
        }
    }
}

void displayMedicine()
{
    for (int i = 0; i < MAX; i++)
    {
        if (med[i].name[0] != '\0')
        {
            printf("Name: %s, Quantity: %d, Price: %.2f\n", med[i].name, med[i].quantity, med[i].price);
        }
    }
}

int main()
{
    int choice;

    printf("Welcome to the Medical Store Management System!\n");
    printf("1. Add Medicine\n");
    printf("2. Display Medicine\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            addMedicine();
            break;
        case 2:
            displayMedicine();
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}