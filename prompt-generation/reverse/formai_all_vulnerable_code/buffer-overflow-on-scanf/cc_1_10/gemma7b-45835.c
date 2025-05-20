//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Medicine
{
    char name[50];
    int quantity;
    double price;
} Medicine;

void display_medicine(Medicine *med)
{
    printf("Name: %s\n", med->name);
    printf("Quantity: %d\n", med->quantity);
    printf("Price: %.2lf\n", med->price);
}

void add_medicine(Medicine *med)
{
    printf("Enter medicine name: ");
    scanf("%s", med->name);

    printf("Enter quantity: ");
    scanf("%d", &med->quantity);

    printf("Enter price: ");
    scanf("%lf", &med->price);
}

void update_medicine(Medicine *med)
{
    printf("Enter medicine name: ");
    scanf("%s", med->name);

    printf("Enter new quantity: ");
    scanf("%d", &med->quantity);

    printf("Enter new price: ");
    scanf("%lf", &med->price);
}

void delete_medicine(Medicine *med)
{
    printf("Enter medicine name: ");
    scanf("%s", med->name);

    printf("Are you sure you want to delete? (Y/N) ");
    char answer;
    scanf("%c", &answer);

    if (answer == 'Y')
    {
        med->quantity = 0;
        med->price = 0.0;
    }
}

int main()
{
    Medicine medicines[MAX];
    int i = 0;

    while (1)
    {
        printf("1. Display Medicines\n");
        printf("2. Add Medicine\n");
        printf("3. Update Medicine\n");
        printf("4. Delete Medicine\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                display_medicine(&medicines[i]);
                break;
            case 2:
                add_medicine(&medicines[i]);
                break;
            case 3:
                update_medicine(&medicines[i]);
                break;
            case 4:
                delete_medicine(&medicines[i]);
                break;
            default:
                printf("Invalid choice\n");
        }

        i++;
    }

    return 0;
}