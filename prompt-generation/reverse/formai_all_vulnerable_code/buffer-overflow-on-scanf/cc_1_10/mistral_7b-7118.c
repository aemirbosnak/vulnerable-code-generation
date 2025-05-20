//MISTRAL-7B DATASET v1.0 Category: Medical Store Management System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

typedef struct {
    char name[50];
    float price;
    int quantity;
} Medicine;

Medicine inventory[MAX_MEDICINES];
int num_medicines = 0;

void add_medicine(char name[], float price, int quantity) {
    if (num_medicines < MAX_MEDICINES) {
        strcpy(inventory[num_medicines].name, name);
        inventory[num_medicines].price = price;
        inventory[num_medicines].quantity = quantity;
        num_medicines++;
    } else {
        printf("Inventory is full.\n");
    }
}

void delete_medicine(char name[]) {
    int i;
    for (i = 0; i < num_medicines; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < num_medicines - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            num_medicines--;
            printf("Medicine deleted successfully.\n");
            return;
        }
    }
    printf("Medicine not found.\n");
}

void view_inventory() {
    int i;
    printf("\nCurrent Inventory:\n");
    for (i = 0; i < num_medicines; i++) {
        printf("%s\t%.2f\t%d\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

void search_medicine(char name[]) {
    int i;
    for (i = 0; i < num_medicines; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("\nMedicine found:\n");
            printf("%s\t%.2f\t%d\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
            return;
        }
    }
    printf("Medicine not found.\n");
}

int main() {
    char command[20], name[50];
    float price;
    int choice, quantity;

    while (1) {
        printf("\nMedical Store Management System\n");
        printf("1. Add Medicine\n");
        printf("2. Delete Medicine\n");
        printf("3. View Inventory\n");
        printf("4. Search Medicine\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter medicine name: ");
                scanf("%s", name);
                printf("Enter medicine price: ");
                scanf("%f", &price);
                printf("Enter medicine quantity: ");
                scanf("%d", &quantity);
                add_medicine(name, price, quantity);
                break;
            case 2:
                printf("Enter medicine name to delete: ");
                scanf("%s", name);
                delete_medicine(name);
                break;
            case 3:
                view_inventory();
                break;
            case 4:
                printf("Enter medicine name to search: ");
                scanf("%s", name);
                search_medicine(name);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}