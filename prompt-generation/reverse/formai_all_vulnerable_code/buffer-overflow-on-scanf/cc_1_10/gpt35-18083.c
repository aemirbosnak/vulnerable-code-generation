//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure to hold medicine information */
typedef struct {
    char name[100];
    int quantity;
    float price;
} Medicine;

/* Function to add medicine to inventory */
void add_medicine(Medicine inventory[], int *inventory_count)
{
    printf("Enter medicine name: ");
    scanf("%s", inventory[*inventory_count].name);
    printf("Enter quantity: ");
    scanf("%d", &inventory[*inventory_count].quantity);
    printf("Enter price: ");
    scanf("%f", &inventory[*inventory_count].price);

    (*inventory_count)++;
}

/* Function to display inventory */
void display_inventory(Medicine inventory[], int inventory_count)
{
    printf("%-20s %-10s %-10s\n", "Name", "Quantity", "Price");
    for (int i = 0; i < inventory_count; i++) {
        printf("%-20s %-10d %-10.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

/* Function to search for medicine by name */
void search_medicine(Medicine inventory[], int inventory_count)
{
    char search_term[100];
    printf("Enter search term: ");
    scanf("%s", search_term);

    int found = 0;
    for (int i = 0; i < inventory_count; i++) {
        if (strcmp(inventory[i].name, search_term) == 0) {
            printf("Name: %s\nQuantity: %d\nPrice: %.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Medicine not found in inventory.\n");
    }
}

/* Main function */
int main()
{
    Medicine inventory[100];
    int inventory_count = 0;
    int choice;

    do {
        printf("1. Add medicine\n2. Display inventory\n3. Search medicine\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_medicine(inventory, &inventory_count);
                break;
            case 2:
                display_inventory(inventory, inventory_count);
                break;
            case 3:
                search_medicine(inventory, inventory_count);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}