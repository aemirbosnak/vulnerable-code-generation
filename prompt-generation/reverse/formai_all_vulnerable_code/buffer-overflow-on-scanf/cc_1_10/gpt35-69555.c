//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Sherlock Holmes
/* It was a dark and stormy night at the medical store. The shelves were filled with various medicines, and the owner was counting the stock while sitting at his desk. Suddenly, there was a loud noise, and an intruder broke into the store. The owner quickly activated his computerized Medical Store Management System to catch the thief. */

#include <stdio.h>
#include <string.h>

struct medicine {
    char name[20];
    int quantity;
    float price;
};

void add_medicine(struct medicine* med, int size) {
    printf("Enter medicine name: ");
    scanf("%s", med[size].name);
    printf("Enter medicine quantity: ");
    scanf("%d", &med[size].quantity);
    printf("Enter medicine price: ");
    scanf("%f", &med[size].price);
    printf("\nMedicine added successfully!\n");
}

void display_medicine(struct medicine* med, int size) {
    if (size == 0) {
        printf("\nNo medicine found!\n");
    }
    else {
        printf("\n%-20s %-10s %-10s\n", "Medicine", "Quantity", "Price");
        for (int i = 0; i < size; i++) {
            printf("%-20s %-10d %-10.2f\n", med[i].name, med[i].quantity, med[i].price);
        }
    }
}

int search_medicine(struct medicine* med, int size, char* name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(med[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void update_medicine(struct medicine* med, int size, char* name) {
    int i = search_medicine(med, size, name);
    if (i == -1) {
        printf("\nMedicine not found!\n");
    }
    else {
        printf("Enter medicine quantity: ");
        scanf("%d", &med[i].quantity);
        printf("Enter medicine price: ");
        scanf("%f", &med[i].price);
        printf("\nMedicine updated successfully!\n");
    }
}

void delete_medicine(struct medicine* med, int* size, char* name) {
    int i = search_medicine(med, *size, name);
    if (i == -1) {
        printf("\nMedicine not found!\n");
    }
    else {
        for (int j = i; j < *size-1; j++) {
            med[j] = med[j+1];
        }
        (*size)--;
        printf("\nMedicine deleted successfully!\n");
    }
}

int main() {
    printf("Welcome to Medical Store Management System!\n");

    int size = 0;
    struct medicine med[100];

    int choice;
    char name[20];

    do {
        printf("\n1. Add Medicine\n");
        printf("2. Display Medicine\n");
        printf("3. Update Medicine\n");
        printf("4. Delete Medicine\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_medicine(med, size);
                size++;
                break;
            case 2:
                display_medicine(med, size);
                break;
            case 3:
                printf("Enter medicine name: ");
                scanf("%s", name);
                update_medicine(med, size, name);
                break;
            case 4:
                printf("Enter medicine name: ");
                scanf("%s", name);
                delete_medicine(med, &size, name);
                break;
            case 5:
                printf("\nThank you for using Medical Store Management System!\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}