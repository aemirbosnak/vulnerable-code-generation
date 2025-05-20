//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    char name[50];
    int quantity;
    float price;
};

void add_medicine(struct medicine[], int);
void update_medicine(struct medicine[], int);
void delete_medicine(struct medicine[], int);
void display_medicine(struct medicine[], int);

int main() {
    int option, count = 0, i;
    struct medicine inventory[50];
    do {
        printf("\nEnter your choice:\n1. Add Medicine\n2. Update Medicine\n3. Delete Medicine\n4. Display Medicine\n5. Exit\n");
        scanf("%d", &option);
        switch(option) {
            case 1:
                add_medicine(inventory, count);
                count++;
                break;
            case 2:
                update_medicine(inventory, count);
                break;
            case 3:
                delete_medicine(inventory, count);
                count--;
                break;
            case 4:
                display_medicine(inventory, count);
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please select again.\n");
        }
    } while (option != 5);
    return 0;
}

void add_medicine(struct medicine inventory[], int count) {
    printf("Enter name of medicine: ");
    scanf("%s", inventory[count].name);
    printf("Enter quantity of medicine: ");
    scanf("%d", &inventory[count].quantity);
    printf("Enter price of medicine: ");
    scanf("%f", &inventory[count].price);
    printf("Medicine added successfully!\n");
}

void update_medicine(struct medicine inventory[], int count) {
    char name[50];
    int i, quantity;
    float price;
    printf("Enter name of medicine to update: ");
    scanf("%s", name);
    for (i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Enter new quantity of medicine: ");
            scanf("%d", &quantity);
            printf("Enter new price of medicine: ");
            scanf("%f", &price);
            inventory[i].quantity = quantity;
            inventory[i].price = price;
            printf("Medicine updated successfully!\n");
            return;
        }
    }
    printf("Medicine not found.\n");
}

void delete_medicine(struct medicine inventory[], int count) {
    char name[50];
    int i, j;
    printf("Enter name of medicine to delete: ");
    scanf("%s", name);
    for (i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (j = i; j < count-1; j++) {
                inventory[j] = inventory[j+1];
            }
            printf("Medicine deleted successfully!\n");
            return;
        }
    }
    printf("Medicine not found.\n");
}

void display_medicine(struct medicine inventory[], int count) {
    int i;
    printf("Name\tQuantity\tPrice\n");
    for (i = 0; i < count; i++) {
        printf("%s\t%d\t\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}