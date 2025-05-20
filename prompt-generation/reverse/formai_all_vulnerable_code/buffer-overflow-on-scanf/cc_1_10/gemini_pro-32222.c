//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char brand[50];
    int quantity;
    float price;
} medicine;

void addMedicine(medicine *m) {
    printf("Enter medicine name: ");
    scanf(" %s", m->name);
    printf("Enter medicine brand: ");
    scanf(" %s", m->brand);
    printf("Enter quantity: ");
    scanf(" %d", &m->quantity);
    printf("Enter price: ");
    scanf(" %f", &m->price);
}

void displayMedicine(medicine *m) {
    printf("Name: %s\n", m->name);
    printf("Brand: %s\n", m->brand);
    printf("Quantity: %d\n", m->quantity);
    printf("Price: %f\n", m->price);
}

void searchMedicine(medicine *m, char *name) {
    if (strcmp(m->name, name) == 0) {
        printf("Medicine found:\n");
        displayMedicine(m);
    } else {
        printf("Medicine not found.\n");
    }
}

void updateMedicine(medicine *m) {
    char choice;
    do {
        printf("What do you want to update?\n");
        printf("1. Name\n");
        printf("2. Brand\n");
        printf("3. Quantity\n");
        printf("4. Price\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                printf("Enter new name: ");
                scanf(" %s", m->name);
                break;
            case '2':
                printf("Enter new brand: ");
                scanf(" %s", m->brand);
                break;
            case '3':
                printf("Enter new quantity: ");
                scanf(" %d", &m->quantity);
                break;
            case '4':
                printf("Enter new price: ");
                scanf(" %f", &m->price);
                break;
            case '5':
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != '5');
}

void deleteMedicine(medicine *m) {
    strcpy(m->name, "");
    strcpy(m->brand, "");
    m->quantity = 0;
    m->price = 0.0;
}

int main() {
    medicine m;
    char name[50];
    char choice;
    do {
        printf("Medical Store Management System\n");
        printf("1. Add medicine\n");
        printf("2. Display medicine\n");
        printf("3. Search medicine\n");
        printf("4. Update medicine\n");
        printf("5. Delete medicine\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                addMedicine(&m);
                break;
            case '2':
                displayMedicine(&m);
                break;
            case '3':
                printf("Enter medicine name to search: ");
                scanf(" %s", name);
                searchMedicine(&m, name);
                break;
            case '4':
                updateMedicine(&m);
                break;
            case '5':
                deleteMedicine(&m);
                break;
            case '6':
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != '6');
    return 0;
}