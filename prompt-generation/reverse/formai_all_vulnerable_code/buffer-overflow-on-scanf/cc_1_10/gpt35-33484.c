//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Sherlock Holmes
/*THE ADVENTURE OF MEDICAL STORE MANAGEMENT SYSTEM*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define MAX_NAME_LENGTH 20

//defining the medicine structure
typedef struct 
{
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Medicine;

//function to display available medicines
void display(Medicine medicine[], int count)
{
    printf("The following medicines are available:\n");
    printf("============================================================\n");
    printf("Medicine\t\tQuantity\tPrice\n");
    printf("============================================================\n");
    for (int i = 0; i < count; i++)
    {
        printf("%-25s %-15d $%.2f\n", medicine[i].name, medicine[i].quantity, medicine[i].price);
    }
    printf("============================================================\n");
}

//function to add medicine
void addMedicine(Medicine medicine[], int* count)
{
    printf("Enter details of new medicine:\n");
    printf("Name: ");
    scanf("%s", medicine[*count].name);
    printf("Quantity: ");
    scanf("%d", &medicine[*count].quantity);
    printf("Price: ");
    scanf("%f", &medicine[*count].price);
    (*count)++;
    printf("New medicine added successfully!\n");
    printf("============================================================\n");
}

//function to search medicine by name
void searchByName(Medicine medicine[], int count)
{
    char name[MAX_NAME_LENGTH];
    printf("Enter medicine name to search: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(medicine[i].name, name) == 0)
        {
            printf("Details of %s:\n", name);
            printf("==============================\n");
            printf("Quantity: %d\n", medicine[i].quantity);
            printf("Price: $%.2f\n", medicine[i].price);
            printf("==============================\n");
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Sorry, %s not found in store.\n", name);
    }
    printf("============================================================\n");
}

//function to sell medicine
void sellMedicine(Medicine medicine[], int count)
{
    char name[MAX_NAME_LENGTH];
    printf("Enter name of medicine to sell: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(medicine[i].name, name) == 0)
        {
            found = 1;
            int quantity;
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            if (quantity > medicine[i].quantity)
            {
                printf("Sorry, only %d units of %s available in store\n", medicine[i].quantity, medicine[i].name);
            }
            else
            {
                medicine[i].quantity -= quantity;
                printf("Total cost: $%.2f\n", medicine[i].price * quantity);
                printf("%d units of %s sold successfully!\n", quantity, medicine[i].name);
            }
            break;
        }
    }
    if (!found)
    {
        printf("Sorry, %s not found in store.\n", name);
    }
    printf("============================================================\n");
}

int main()
{
    printf("Welcome to the Medical Store Management System!\n");
    printf("============================================================\n");

    Medicine medicine[MAX_MEDICINES];
    int count = 0;
    int choice;

    do
    {
        printf("Enter 1 to display available medicines\n");
        printf("Enter 2 to add new medicine\n");
        printf("Enter 3 to search medicine by name\n");
        printf("Enter 4 to sell medicine\n");
        printf("Enter 0 to exit\n");
        printf("Your choice: ");

        scanf("%d", &choice);

        printf("============================================================\n");

        switch (choice)
        {
            case 1:
                display(medicine, count);
                break;
            case 2:
                addMedicine(medicine, &count);
                break;
            case 3:
                searchByName(medicine, count);
                break;
            case 4:
                sellMedicine(medicine, count);
                break;
            case 0:
                printf("Thank you for using the Medical Store Management System!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}