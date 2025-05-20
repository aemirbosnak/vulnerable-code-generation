//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    char name[50];
    int quantity;
    float price;
};

struct medicine *stock;
int num_medicines;

void add_medicine() {
    printf("Enter the name of the medicine: ");
    scanf("%s", stock[num_medicines].name);
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &stock[num_medicines].quantity);
    printf("Enter the price of the medicine: ");
    scanf("%f", &stock[num_medicines].price);
    num_medicines++;
}

void remove_medicine() {
    int i;
    char name[50];
    printf("Enter the name of the medicine to remove: ");
    scanf("%s", name);
    for (i = 0; i < num_medicines; i++) {
        if (strcmp(stock[i].name, name) == 0) {
            num_medicines--;
            for (; i < num_medicines; i++) {
                stock[i] = stock[i + 1];
            }
            printf("Medicine successfully removed.\n");
            return;
        }
    }
    printf("Medicine not found.\n");
}

void update_medicine() {
    int i;
    char name[50];
    printf("Enter the name of the medicine to update: ");
    scanf("%s", name);
    for (i = 0; i < num_medicines; i++) {
        if (strcmp(stock[i].name, name) == 0) {
            printf("Enter the new quantity of the medicine: ");
            scanf("%d", &stock[i].quantity);
            printf("Enter the new price of the medicine: ");
            scanf("%f", &stock[i].price);
            printf("Medicine successfully updated.\n");
            return;
        }
    }
    printf("Medicine not found.\n");
}

void display_stock() {
    int i;
    printf("Here's the current stock:\n");
    for (i = 0; i < num_medicines; i++) {
        printf("%s\t%d\t%.2f\n", stock[i].name, stock[i].quantity, stock[i].price);
    }
}

void search_medicine() {
    int i;
    char name[50];
    printf("Enter the name of the medicine to search for: ");
    scanf("%s", name);
    for (i = 0; i < num_medicines; i++) {
        if (strcmp(stock[i].name, name) == 0) {
            printf("Medicine found:\n%s\t%d\t%.2f\n", stock[i].name, stock[i].quantity, stock[i].price);
            return;
        }
    }
    printf("Medicine not found.\n");
}

int main() {
    int choice;
    stock = (struct medicine *)malloc(sizeof(struct medicine));
    num_medicines = 0;
    do {
        printf("1. Add a new medicine\n");
        printf("2. Remove a medicine\n");
        printf("3. Update a medicine\n");
        printf("4. Display the current stock\n");
        printf("5. Search for a medicine\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                remove_medicine();
                break;
            case 3:
                update_medicine();
                break;
            case 4:
                display_stock();
                break;
            case 5:
                search_medicine();
                break;
            case 6:
                printf("Thank you for using the Medical Store Management System. Have a nice day!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);
    free(stock);
    return 0;
}