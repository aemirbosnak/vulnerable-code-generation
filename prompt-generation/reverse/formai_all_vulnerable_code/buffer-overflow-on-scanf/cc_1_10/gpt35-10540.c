//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

struct medicine {
    char name[50];
    int qty;
    float price;
};

struct medicine inventory[MAX_MEDICINES];
int total_medicines = 0;

void add_medicine() {
    if (total_medicines == MAX_MEDICINES) {
        printf("Maximum number of medicines reached. Cannot add more.\n");
        return;
    }

    printf("Enter medicine name: ");
    scanf("%s", inventory[total_medicines].name);
    printf("Enter quantity: ");
    scanf("%d", &inventory[total_medicines].qty);
    printf("Enter price: ");
    scanf("%f", &inventory[total_medicines].price);

    total_medicines++;
    printf("Medicine added successfully!\n");
}

void view_medicine() {
    if (total_medicines == 0) {
        printf("No medicines found in inventory.\n");
        return;
    }

    printf("Name\tQuantity\tPrice\n");
    for (int i = 0; i < total_medicines; i++) {
        printf("%s\t%d\t\t%.2f\n", inventory[i].name, inventory[i].qty, inventory[i].price);
    }
}

void sell_medicine() {
    if (total_medicines == 0) {
        printf("No medicines found in inventory.\n");
        return;
    }

    char name[50];
    printf("Enter medicine name to sell: ");
    scanf("%s", name);

    for (int i = 0; i < total_medicines; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Enter quantity to sell: ");
            int sell_qty;
            scanf("%d", &sell_qty);

            if (sell_qty > inventory[i].qty) {
                printf("Not enough stock for sale.\n");
                return;
            }

            inventory[i].qty -= sell_qty;
            printf("Medicine sold successfully!\n");
            return;
        }
    }

    printf("Medicine not found.\n");
}

int main() {
    int choice = 0;

    while (1) {
        printf("\n***** Medical Store Management System *****\n");
        printf("1. Add Medicine\n");
        printf("2. View Medicines\n");
        printf("3. Sell Medicine\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                view_medicine();
                break;
            case 3:
                sell_medicine();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}