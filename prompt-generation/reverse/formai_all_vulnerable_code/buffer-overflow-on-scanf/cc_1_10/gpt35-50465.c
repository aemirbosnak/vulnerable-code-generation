//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure to hold medicine information
struct Medicine {
    char name[50];
    char manufacturer[50];
    float price;
    int quantity;
};

// function to add medicine to inventory
void addMedicine(struct Medicine inventory[], int *count)
{
    printf("\nEnter medicine name: ");
    scanf("%s", inventory[*count].name);

    printf("Enter manufacturer name: ");
    scanf("%s", inventory[*count].manufacturer);

    printf("Enter price per unit: ");
    scanf("%f", &(inventory[*count].price));

    printf("Enter quantity: ");
    scanf("%d", &(inventory[*count].quantity));

    (*count)++;
    printf("\nMedicine added successfully!\n");
}

// function to search for medicine in inventory
void searchMedicine(struct Medicine inventory[], int count)
{
    char name[50];
    int found = 0;

    printf("\nEnter medicine name: ");
    scanf("%s", name);

    for (int i=0; i<count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("\nMedicine Found!\n");
            printf("Name: %s\n", inventory[i].name);
            printf("Manufacturer: %s\n", inventory[i].manufacturer);
            printf("Price per unit: %.2f\n", inventory[i].price);
            printf("Quantity: %d\n", inventory[i].quantity);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nMedicine not found in inventory!\n");
    }
}

// function to update medicine information in inventory
void updateMedicine(struct Medicine inventory[], int count)
{
    char name[50];
    int found = 0;

    printf("\nEnter medicine name: ");
    scanf("%s", name);

    for (int i=0; i<count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("\nMedicine Found!\n");
            printf("Enter new value for:\n");
            printf("Name (or enter '.' to keep current value): ");
            scanf("%s", inventory[i].name);

            printf("Manufacturer (or enter '.' to keep current value): ");
            scanf("%s", inventory[i].manufacturer);

            printf("Price per unit (or enter -1 to keep current value): ");
            scanf("%f", &(inventory[i].price));

            printf("Quantity (or enter -1 to keep current value): ");
            scanf("%d", &(inventory[i].quantity));

            found = 1;
            printf("\nMedicine information updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("\nMedicine not found in inventory!\n");
    }
}

// function to remove medicine from inventory
void removeMedicine(struct Medicine inventory[], int *count)
{
    char name[50];
    int found = 0;

    printf("\nEnter medicine name: ");
    scanf("%s", name);

    for (int i=0; i<*count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            found = 1;
            for (int j=i; j<((*count)-1); j++) {
                inventory[j] = inventory[j+1];
            }
            (*count)--;
            printf("\nMedicine removed successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("\nMedicine not found in inventory!\n");
    }
}

int main()
{
    struct Medicine inventory[100];
    int count = 0;
    int choice;

    do {
        printf("\n\n1. Add medicine to inventory");
        printf("\n2. Search medicine in inventory");
        printf("\n3. Update medicine information in inventory");
        printf("\n4. Remove medicine from inventory");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine(inventory, &count);
                break;
            case 2:
                searchMedicine(inventory, count);
                break;
            case 3:
                updateMedicine(inventory, count);
                break;
            case 4:
                removeMedicine(inventory, &count);
                break;
            case 5:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    } while (choice != 5);

    return 0;
}