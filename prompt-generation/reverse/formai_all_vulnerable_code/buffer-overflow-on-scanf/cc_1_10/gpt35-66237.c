//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    char name[50];
    int quantity;
    float price;
};

struct medicine inventory[100];
int num_medicines = 0;

void add_medicine(char *name, int quantity, float price) {
    if(num_medicines < 100) {
        strcpy(inventory[num_medicines].name, name);
        inventory[num_medicines].quantity = quantity;
        inventory[num_medicines].price = price;
        num_medicines++;
        printf("Medicine added successfully!\n");
    } else {
        printf("Cannot add more medicines to inventory!\n");
    }
}

void display_inventory() {
    printf("Inventory:\n");
    for(int i = 0; i < num_medicines; i++) {
        printf("%d. %s - %d units - $%.2f each\n", i+1, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void search_medicine(char *name) {
    for(int i = 0; i < num_medicines; i++) {
        if(strcmp(inventory[i].name, name) == 0) {
            printf("Medicine found: %s - %d units - $%.2f each\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("Medicine not found!\n");
}

void sell_medicine(char *name, int quantity) {
    for(int i = 0; i < num_medicines; i++) {
        if(strcmp(inventory[i].name, name) == 0) {
            if(inventory[i].quantity >= quantity) {
                inventory[i].quantity -= quantity;
                printf("%d units of %s sold for $%.2f each!\n", quantity, inventory[i].name, inventory[i].price);
                return;
            } else {
                printf("Insufficient stock of %s!\n", inventory[i].name);
                return;
            }
        }
    }
    printf("Medicine not found!\n");
}

int main() {
    int choice;
    char name[50];
    int quantity;
    float price;
    while(1) {
        printf("\nMedical Store Management System\n");
        printf("1. Add medicine\n");
        printf("2. Display inventory\n");
        printf("3. Search medicine\n");
        printf("4. Sell medicine\n");
        printf("5. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter name of medicine: ");
                scanf("%s", name);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                printf("Enter price: $");
                scanf("%f", &price);
                add_medicine(name, quantity, price);
                break;
            case 2:
                display_inventory();
                break;
            case 3:
                printf("Enter name of medicine: ");
                scanf("%s", name);
                search_medicine(name);
                break;
            case 4:
                printf("Enter name of medicine: ");
                scanf("%s", name);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                sell_medicine(name, quantity);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}