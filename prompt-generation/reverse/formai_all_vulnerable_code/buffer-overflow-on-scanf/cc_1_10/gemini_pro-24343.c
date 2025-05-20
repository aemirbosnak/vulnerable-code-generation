//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

typedef struct {
    char name[50];
    float price;
    int quantity;
} Medicine;

Medicine medicines[MAX_MEDICINES];
int num_medicines = 0;

void add_medicine() {
    if (num_medicines >= MAX_MEDICINES) {
        printf("Error: Medicine list is full.\n");
        return;
    }

    char name[50];
    float price;
    int quantity;

    printf("Enter medicine name: ");
    scanf(" %s", name);

    printf("Enter medicine price: ");
    scanf(" %f", &price);

    printf("Enter medicine quantity: ");
    scanf(" %d", &quantity);

    strcpy(medicines[num_medicines].name, name);
    medicines[num_medicines].price = price;
    medicines[num_medicines].quantity = quantity;

    num_medicines++;
}

void delete_medicine() {
    if (num_medicines == 0) {
        printf("Error: Medicine list is empty.\n");
        return;
    }

    char name[50];

    printf("Enter medicine name to delete: ");
    scanf(" %s", name);

    int i;
    for (i = 0; i < num_medicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            break;
        }
    }

    if (i == num_medicines) {
        printf("Error: Medicine not found.\n");
        return;
    }

    for (; i < num_medicines - 1; i++) {
        medicines[i] = medicines[i + 1];
    }

    num_medicines--;
}

void update_medicine() {
    if (num_medicines == 0) {
        printf("Error: Medicine list is empty.\n");
        return;
    }

    char name[50];

    printf("Enter medicine name to update: ");
    scanf(" %s", name);

    int i;
    for (i = 0; i < num_medicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            break;
        }
    }

    if (i == num_medicines) {
        printf("Error: Medicine not found.\n");
        return;
    }

    float price;
    int quantity;

    printf("Enter new medicine price: ");
    scanf(" %f", &price);

    printf("Enter new medicine quantity: ");
    scanf(" %d", &quantity);

    medicines[i].price = price;
    medicines[i].quantity = quantity;
}

void list_medicines() {
    if (num_medicines == 0) {
        printf("Error: Medicine list is empty.\n");
        return;
    }

    printf("Medicine List:\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("| %-5s | %-20s | %-10s | %-10s |\n", "ID", "Name", "Price", "Quantity");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < num_medicines; i++) {
        printf("| %-5d | %-20s | %-10.2f | %-10d |\n", i + 1, medicines[i].name, medicines[i].price, medicines[i].quantity);
    }

    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nMedical Store Management System\n");
        printf("-----------------------------------\n");
        printf("1. Add Medicine\n");
        printf("2. Delete Medicine\n");
        printf("3. Update Medicine\n");
        printf("4. List Medicines\n");
        printf("5. Exit\n");
        printf("-----------------------------------\n");
        printf("Enter your choice: ");
        scanf(" %d", &choice);

        switch (choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                delete_medicine();
                break;
            case 3:
                update_medicine();
                break;
            case 4:
                list_medicines();
                break;
            case 5:
                exit(0);
            default:
                printf("Error: Invalid choice.\n");
        }
    }

    return 0;
}