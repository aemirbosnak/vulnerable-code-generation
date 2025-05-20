//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for a medicine with name, price, and quantity

struct Medicine {
    char name[50];
    float price;
    int quantity;
};

// Define function to add new medicine to inventory

void addMedicine(struct Medicine *inventory, int *count) {
    fflush(stdin);
    printf("Enter name of medicine: ");
    fgets(inventory[*count].name, 50, stdin);
    strtok(inventory[*count].name, "\n");
    printf("Enter price of medicine: ");
    scanf("%f", &inventory[*count].price);
    printf("Enter quantity of medicine: ");
    scanf("%d", &inventory[*count].quantity);
    *count += 1;
    printf("Medicine added to inventory.\n");
}

// Define function to search inventory for medicine by name

void searchMedicine(struct Medicine *inventory, int count) {
    char name[50];
    int flag = 0;
    fflush(stdin);
    printf("Enter name of medicine: ");
    fgets(name, 50, stdin);
    strtok(name, "\n");
    for (int i = 0; i < count; i++) {
        if (strcmp(name, inventory[i].name) == 0) {
            printf("Medicine found:\n");
            printf("Name: %s\n", inventory[i].name);
            printf("Price: %.2f\n", inventory[i].price);
            printf("Quantity: %d\n", inventory[i].quantity);
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        printf("Medicine not found in inventory.\n");
    }
}

// Define function to update medicine in inventory by name

void updateMedicine(struct Medicine *inventory, int count) {
    char name[50];
    int flag = 0;
    fflush(stdin);
    printf("Enter name of medicine: ");
    fgets(name, 50, stdin);
    strtok(name, "\n");
    for (int i = 0; i < count; i++) {
        if (strcmp(name, inventory[i].name) == 0) {
            printf("Enter new price of medicine: ");
            scanf("%f", &inventory[i].price);
            printf("Enter new quantity of medicine: ");
            scanf("%d", &inventory[i].quantity);
            printf("Medicine updated in inventory.\n");
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        printf("Medicine not found in inventory.\n");
    }
}

// Define function to delete medicine from inventory by name

void deleteMedicine(struct Medicine *inventory, int *count) {
    char name[50];
    int flag = 0;
    fflush(stdin);
    printf("Enter name of medicine: ");
    fgets(name, 50, stdin);
    strtok(name, "\n");
    for (int i = 0; i < *count; i++) {
        if (strcmp(name, inventory[i].name) == 0) {
            for (int j = i; j < (*count - 1); j++) {
                strcpy(inventory[j].name, inventory[j+1].name);
                inventory[j].price = inventory[j+1].price;
                inventory[j].quantity = inventory[j+1].quantity;
            }
            *count -= 1;
            printf("Medicine deleted from inventory.\n");
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        printf("Medicine not found in inventory.\n");
    }
}

// Define main function

int main() {
    int choice, count = 0;
    struct Medicine inventory[100];
    printf("***Medical Store Management System***\n");
    do {
        printf("Enter 1 to add medicine to inventory.\n");
        printf("Enter 2 to search for medicine in inventory.\n");
        printf("Enter 3 to update medicine in inventory.\n");
        printf("Enter 4 to delete medicine from inventory.\n");
        printf("Enter 5 to exit.\n");
        printf("Your choice: ");
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
                deleteMedicine(inventory, &count);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 5);
    return 0;
}