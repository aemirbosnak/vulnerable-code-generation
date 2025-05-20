//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define constants
#define MAX_MEDICINES 100
#define MAX_LENGTH 50
#define MAX_QTY 1000

// define structure for medicine details
struct Medicine
{
    char name[MAX_LENGTH];
    int quantity;
    float price;
};

// function to display main menu
void displayMainMenu()
{
    printf("\n\n-- Medical Store Management System --\n\n");
    printf("1. Add Medicine\n");
    printf("2. Update Medicine\n");
    printf("3. Delete Medicine\n");
    printf("4. Find Medicine\n");
    printf("5. Display All Medicines\n");
    printf("6. Exit\n\n");
}

// function to add medicine
void addMedicine(struct Medicine* medicines, int* count)
{
    // check if max limit has been reached
    if (*count >= MAX_MEDICINES)
    {
        printf("Medicine limit reached!\n");
        return;
    }

    // get medicine details from user
    struct Medicine newMedicine;
    printf("Enter name of medicine: ");
    scanf("%s", newMedicine.name);
    printf("Enter quantity: ");
    scanf("%d", &newMedicine.quantity);
    printf("Enter price: ");
    scanf("%f", &newMedicine.price);

    // add medicine to array
    medicines[*count] = newMedicine;
    (*count)++;

    printf("Medicine added successfully!\n");
}

// function to update medicine
void updateMedicine(struct Medicine* medicines, int count)
{
    // check if array is empty
    if (count == 0)
    {
        printf("No medicines found!\n");
        return;
    }

    // get name of medicine to update
    char name[MAX_LENGTH];
    printf("Enter name of medicine to update: ");
    scanf("%s", name);

    // search for medicine and update details if found
    int i;
    for (i = 0; i < count; i++)
    {
        if (strcmp(medicines[i].name, name) == 0)
        {
            printf("Enter new quantity: ");
            scanf("%d", &medicines[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &medicines[i].price);
            printf("Medicine updated successfully!\n");
            return;
        }
    }

    printf("Medicine not found!\n");
}

// function to delete medicine
void deleteMedicine(struct Medicine* medicines, int* count)
{
    // check if array is empty
    if (*count == 0)
    {
        printf("No medicines found!\n");
        return;
    }

    // get name of medicine to delete
    char name[MAX_LENGTH];
    printf("Enter name of medicine to delete: ");
    scanf("%s", name);

    // search for medicine and delete if found
    int i;
    for (i = 0; i < *count; i++)
    {
        if (strcmp(medicines[i].name, name) == 0)
        {
            (*count)--;
            while (i < *count)
            {
                medicines[i] = medicines[i+1];
                i++;
            }
            printf("Medicine deleted successfully!\n");
            return;
        }
    }

    printf("Medicine not found!\n");
}

// function to find medicine
void findMedicine(struct Medicine* medicines, int count)
{
    // check if array is empty
    if (count == 0)
    {
        printf("No medicines found!\n");
        return;
    }

    // get name of medicine to find
    char name[MAX_LENGTH];
    printf("Enter name of medicine to find: ");
    scanf("%s", name);

    // search for medicine and display details if found
    int i;
    for (i = 0; i < count; i++)
    {
        if (strcmp(medicines[i].name, name) == 0)
        {
            printf("Name: %s\n", medicines[i].name);
            printf("Quantity: %d\n", medicines[i].quantity);
            printf("Price: %0.2f\n", medicines[i].price);
            return;
        }
    }

    printf("Medicine not found!\n");
}

// function to display all medicines
void displayAllMedicines(struct Medicine* medicines, int count)
{
    // check if array is empty
    if (count == 0)
    {
        printf("No medicines found!\n");
        return;
    }

    // display all medicines in array
    int i;
    for (i = 0; i < count; i++)
    {
        printf("Name: %s\n", medicines[i].name);
        printf("Quantity: %d\n", medicines[i].quantity);
        printf("Price: %0.2f\n", medicines[i].price);
        printf("\n");
    }
}

int main()
{
    // initialize variables
    struct Medicine medicines[MAX_MEDICINES];
    int count = 0;
    int choice;

    // display main menu and get user choice
    do
    {
        displayMainMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addMedicine(medicines, &count);
                break;
            case 2:
                updateMedicine(medicines, count);
                break;
            case 3:
                deleteMedicine(medicines, &count);
                break;
            case 4:
                findMedicine(medicines, count);
                break;
            case 5:
                displayAllMedicines(medicines, count);
                break;
            case 6:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid choice.\n");
        }
    } while (choice != 6);

    return 0;
}