//Code Llama-13B DATASET v1.0 Category: Medical Store Management System ; Style: satisfied
/*
 * C Medical Store Management System
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Medicine {
    char name[50];
    int quantity;
    float price;
};

void add_medicine(struct Medicine* medicine) {
    printf("Enter the name of the medicine: ");
    scanf("%s", medicine->name);
    printf("Enter the quantity: ");
    scanf("%d", &medicine->quantity);
    printf("Enter the price: ");
    scanf("%f", &medicine->price);
}

void display_medicine(struct Medicine* medicine) {
    printf("Medicine Name: %s\n", medicine->name);
    printf("Quantity: %d\n", medicine->quantity);
    printf("Price: %.2f\n", medicine->price);
}

void modify_medicine(struct Medicine* medicine) {
    int quantity, price;
    char name[50];

    printf("Enter the name of the medicine: ");
    scanf("%s", name);
    printf("Enter the new quantity: ");
    scanf("%d", &quantity);
    printf("Enter the new price: ");
    scanf("%f", &price);

    if (strcmp(name, medicine->name) == 0) {
        medicine->quantity = quantity;
        medicine->price = price;
    }
}

void delete_medicine(struct Medicine* medicine) {
    int i, j;
    char name[50];

    printf("Enter the name of the medicine to be deleted: ");
    scanf("%s", name);

    for (i = 0; i < 10; i++) {
        if (strcmp(name, medicine[i].name) == 0) {
            for (j = i; j < 10; j++) {
                medicine[j] = medicine[j + 1];
            }
            break;
        }
    }
}

int main() {
    struct Medicine medicine[10];
    int choice, i;

    printf("1. Add Medicine\n");
    printf("2. Display Medicine\n");
    printf("3. Modify Medicine\n");
    printf("4. Delete Medicine\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            add_medicine(&medicine[0]);
            break;
        case 2:
            display_medicine(&medicine[0]);
            break;
        case 3:
            modify_medicine(&medicine[0]);
            break;
        case 4:
            delete_medicine(&medicine[0]);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}