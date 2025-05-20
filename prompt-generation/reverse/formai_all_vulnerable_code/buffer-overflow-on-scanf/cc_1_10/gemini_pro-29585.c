//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

typedef struct {
    char name[50];
    char brand[50];
    float price;
    int quantity;
    int reorder_level;
} medicine;

medicine medicines[MAX_MEDICINES];
int num_medicines = 0;

void add_medicine() {
    if (num_medicines >= MAX_MEDICINES) {
        printf("Medicine database is full!\n");
        return;
    }

    printf("Enter medicine name: ");
    scanf(" %[^\n]s", medicines[num_medicines].name);

    printf("Enter medicine brand: ");
    scanf(" %[^\n]s", medicines[num_medicines].brand);

    printf("Enter medicine price: ");
    scanf("%f", &medicines[num_medicines].price);

    printf("Enter medicine quantity: ");
    scanf("%d", &medicines[num_medicines].quantity);

    printf("Enter medicine reorder level: ");
    scanf("%d", &medicines[num_medicines].reorder_level);

    num_medicines++;
}

void delete_medicine() {
    char name[50];

    printf("Enter medicine name to delete: ");
    scanf(" %[^\n]s", name);

    int i;
    for (i = 0; i < num_medicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            break;
        }
    }

    if (i == num_medicines) {
        printf("Medicine not found!\n");
        return;
    }

    for (; i < num_medicines - 1; i++) {
        medicines[i] = medicines[i + 1];
    }

    num_medicines--;
}

void edit_medicine() {
    char name[50];

    printf("Enter medicine name to edit: ");
    scanf(" %[^\n]s", name);

    int i;
    for (i = 0; i < num_medicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            break;
        }
    }

    if (i == num_medicines) {
        printf("Medicine not found!\n");
        return;
    }

    printf("Enter new medicine name: ");
    scanf(" %[^\n]s", medicines[i].name);

    printf("Enter new medicine brand: ");
    scanf(" %[^\n]s", medicines[i].brand);

    printf("Enter new medicine price: ");
    scanf("%f", &medicines[i].price);

    printf("Enter new medicine quantity: ");
    scanf("%d", &medicines[i].quantity);

    printf("Enter new medicine reorder level: ");
    scanf("%d", &medicines[i].reorder_level);
}

void view_medicines() {
    int i;

    printf("------------------------------------------------------------------------\n");
    printf("| %-20s | %-20s | %-10s | %-10s | %-15s |\n", "Name", "Brand", "Price", "Quantity", "Reorder Level");
    printf("------------------------------------------------------------------------\n");
    for (i = 0; i < num_medicines; i++) {
        printf("| %-20s | %-20s | %-10.2f | %-10d | %-15d |\n", medicines[i].name, medicines[i].brand, medicines[i].price, medicines[i].quantity, medicines[i].reorder_level);
    }
    printf("------------------------------------------------------------------------\n");
}

int main() {
    int choice;

    do {
        printf("\n-------- Medical Store Management System --------\n");
        printf("1. Add a medicine\n");
        printf("2. Delete a medicine\n");
        printf("3. Edit a medicine\n");
        printf("4. View all medicines\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                delete_medicine();
                break;
            case 3:
                edit_medicine();
                break;
            case 4:
                view_medicines();
                break;
        }
    } while (choice != 0);

    return 0;
}