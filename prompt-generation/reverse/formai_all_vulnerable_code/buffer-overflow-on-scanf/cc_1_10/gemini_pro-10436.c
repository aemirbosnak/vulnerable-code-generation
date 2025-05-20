//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

typedef struct {
    int id;
    char name[51];
    float price;
    int quantity;
} Medicine;

Medicine medicines[MAX_MEDICINES];
int num_medicines = 0;

void add_medicine() {
    if (num_medicines == MAX_MEDICINES) {
        printf("Medicine store is full! Cannot add more medicines.\n");
        return;
    }

    printf("Enter medicine ID: ");
    scanf("%d", &medicines[num_medicines].id);

    printf("Enter medicine name: ");
    scanf(" %[^\n]", medicines[num_medicines].name);

    printf("Enter medicine price: ");
    scanf("%f", &medicines[num_medicines].price);

    printf("Enter medicine quantity: ");
    scanf("%d", &medicines[num_medicines].quantity);

    num_medicines++;
}

void display_medicines() {
    printf("\nMedicine Store Management System\n");
    printf("--------------------------------\n");
    printf("ID\tName\t\tPrice\tQuantity\n");
    printf("--------------------------------\n");
    for (int i = 0; i < num_medicines; i++) {
        printf("%d\t%-20s\t%.2f\t%d\n", medicines[i].id, medicines[i].name, medicines[i].price, medicines[i].quantity);
    }
    printf("\n");
}

void search_medicine() {
    int id;
    printf("Enter medicine ID to search: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < num_medicines; i++) {
        if (medicines[i].id == id) {
            printf("\nMedicine found:\n");
            printf("ID: %d\n", medicines[i].id);
            printf("Name: %s\n", medicines[i].name);
            printf("Price: %.2f\n", medicines[i].price);
            printf("Quantity: %d\n", medicines[i].quantity);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Medicine not found!\n");
    }
}

void update_medicine() {
    int id;
    printf("Enter medicine ID to update: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < num_medicines; i++) {
        if (medicines[i].id == id) {
            printf("Enter new medicine name: ");
            scanf(" %[^\n]", medicines[i].name);

            printf("Enter new medicine price: ");
            scanf("%f", &medicines[i].price);

            printf("Enter new medicine quantity: ");
            scanf("%d", &medicines[i].quantity);

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Medicine not found!\n");
    }
}

void delete_medicine() {
    int id;
    printf("Enter medicine ID to delete: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < num_medicines; i++) {
        if (medicines[i].id == id) {
            for (int j = i; j < num_medicines - 1; j++) {
                medicines[j] = medicines[j + 1];
            }
            num_medicines--;
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Medicine not found!\n");
    }
}

int main() {
    int choice;

    do {
        printf("\n**Medicine Store Management System**\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Update Medicine\n");
        printf("5. Delete Medicine\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                display_medicines();
                break;
            case 3:
                search_medicine();
                break;
            case 4:
                update_medicine();
                break;
            case 5:
                delete_medicine();
                break;
        }
    } while (choice != 6);

    printf("\nThank you for using Medicine Store Management System!\n");

    return 0;
}