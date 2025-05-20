//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

struct Medicine {
    char name[50];
    float price;
    int quantity;
};

struct Medicine medicines[MAX_MEDICINES];
int num_medicines = 0;

void menu() {
    printf("Medical Store Management System\n\n");
    printf("1. Add medicine\n");
    printf("2. Remove medicine\n");
    printf("3. Update medicine\n");
    printf("4. View inventory\n");
    printf("5. Exit\n\n");
}

void add_medicine() {
    if (num_medicines >= MAX_MEDICINES) {
        printf("Inventory full\n");
        return;
    }

    struct Medicine medicine;
    printf("Enter name of medicine: ");
    scanf("%s", medicine.name);
    printf("Enter price of medicine: ");
    scanf("%f", &medicine.price);
    printf("Enter quantity of medicine: ");
    scanf("%d", &medicine.quantity);

    medicines[num_medicines] = medicine;
    num_medicines++;
}

void remove_medicine() {
    char name[50];
    printf("Enter name of medicine to remove: ");
    scanf("%s", name);

    int index = -1;
    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(name, medicines[i].name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Medicine not found\n");
        return;
    }

    for (int i = index; i < num_medicines - 1; i++) {
        medicines[i] = medicines[i + 1];
    }

    num_medicines--;
}

void update_medicine() {
    char name[50];
    printf("Enter name of medicine to update: ");
    scanf("%s", name);

    int index = -1;
    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(name, medicines[i].name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Medicine not found\n");
        return;
    }

    float new_price;
    printf("Enter new price of medicine: ");
    scanf("%f", &new_price);
    medicines[index].price = new_price;

    int new_quantity;
    printf("Enter new quantity of medicine: ");
    scanf("%d", &new_quantity);
    medicines[index].quantity = new_quantity;
}

void view_inventory() {
    printf("%-20s %-10s %s\n", "Name", "Price", "Quantity");
    for (int i = 0; i < num_medicines; i++) {
        printf("%-20s %-10.2f %d\n", medicines[i].name, medicines[i].price, medicines[i].quantity);
    }
}

int main() {
    int choice;
    do {
        menu();
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
                view_inventory();
                break;
            case 5:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 5);

    return 0;
}