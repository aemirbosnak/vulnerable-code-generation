//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Struct for medical items
struct MedicalItem {
    char name[MAX_SIZE];
    int quantity;
    float price;
};

// Function to display menu and get user's choice
int getMenuChoice() {
    int choice;
    printf("\n\n");
    printf("1. Add new item\n");
    printf("2. Update existing item\n");
    printf("3. Delete item\n");
    printf("4. List all items\n");
    printf("5. Search item\n");
    printf("6. Exit\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to add new item
void addItem(struct MedicalItem *items, int *count) {
    char name[MAX_SIZE];
    int quantity;
    float price;

    printf("Enter name of item: ");
    scanf("%s", name);
    printf("\nEnter quantity of item: ");
    scanf("%d", &quantity);
    printf("\nEnter price of item: ");
    scanf("%f", &price);

    strcpy(items[*count].name, name);
    items[*count].quantity = quantity;
    items[*count].price = price;

    (*count)++;
}

// Function to update existing item
void updateItem(struct MedicalItem *items, int count) {
    char name[MAX_SIZE];
    int index = -1;

    printf("Enter name of item to update: ");
    scanf("%s", name);

    // Find item with given name
    for (int i = 0; i < count; i++) {
        if (strcmp(items[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("\nItem not found!\n");
        return;
    }

    // Get new quantity and price
    int quantity;
    float price;

    printf("\nEnter new quantity of item: ");
    scanf("%d", &quantity);
    printf("\nEnter new price of item: ");
    scanf("%f", &price);

    // Update item
    items[index].quantity = quantity;
    items[index].price = price;

    printf("\nItem updated successfully!\n");
}

// Function to delete item
void deleteItem(struct MedicalItem *items, int *count) {
    char name[MAX_SIZE];
    int index = -1;

    printf("Enter name of item to delete: ");
    scanf("%s", name);

    // Find item with given name
    for (int i = 0; i < *count; i++) {
        if (strcmp(items[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("\nItem not found!\n");
        return;
    }

    // Shift all items to left to fill the gap
    for (int i = index; i < *count - 1; i++) {
        strcpy(items[i].name, items[i+1].name);
        items[i].quantity = items[i+1].quantity;
        items[i].price = items[i+1].price;
    }

    (*count)--;

    printf("\nItem deleted successfully!\n");
}

// Function to list all items
void listItems(struct MedicalItem *items, int count) {
    printf("\nName\t\tQuantity\t\tPrice\n");

    for (int i = 0; i < count; i++) {
        printf("%s\t\t%d\t\t%.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

// Function to search for item
void searchItem(struct MedicalItem *items, int count) {
    char name[MAX_SIZE];
    int index = -1;

    printf("Enter name of item to search: ");
    scanf("%s", name);

    // Find item with given name
    for (int i = 0; i < count; i++) {
        if (strcmp(items[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("\nItem not found!\n");
        return;
    }

    printf("\nName\t\tQuantity\t\tPrice\n");
    printf("%s\t\t%d\t\t%.2f\n", items[index].name, items[index].quantity, items[index].price);
}

// Main function
int main() {
    struct MedicalItem items[MAX_SIZE];
    int count = 0;
    int choice;

    while (1) {
        choice = getMenuChoice();

        switch (choice) {
            case 1:
                addItem(items, &count);
                break;

            case 2:
                updateItem(items, count);
                break;

            case 3:
                deleteItem(items, &count);
                break;

            case 4:
                listItems(items, count);
                break;

            case 5:
                searchItem(items, count);
                break;

            case 6:
                printf("\nExiting program...");
                exit(0);

            default:
                printf("\nInvalid choice, try again!\n");
                break;
        }
    }

    return 0;
}