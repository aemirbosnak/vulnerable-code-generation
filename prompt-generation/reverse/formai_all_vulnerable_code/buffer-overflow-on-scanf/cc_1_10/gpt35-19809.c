//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>

struct Medicine {
    char name[50];
    float price;
    int quantity;
};

void addMedicine(struct Medicine m[]) {
    printf("\nEnter the details of the new medicine:\n");
    printf("Name: ");
    scanf("%s", m->name);
    printf("Price: ");
    scanf("%f", &m->price);
    printf("Quantity: ");
    scanf("%d", &m->quantity);
    printf("\nMedicine added successfully!\n");
}

void updateMedicine(struct Medicine m[]) {
    char searchName[50];
    int i, found = 0;
    printf("\nEnter the name of the medicine to update: ");
    scanf("%s", &searchName);

    for (i = 0; i < 10; i++) {
        if (strcmp(m[i].name, searchName) == 0) {
            found = 1;
            printf("\nEnter the new price: ");
            scanf("%f", &m[i].price);
            printf("\nEnter the new quantity: ");
            scanf("%d", &m[i].quantity);
            printf("\nMedicine updated successfully!\n");
        }
    }
    if (!found) {
        printf("\nNo medicine found with that name.\n");
    }
}

void displayMedicine(struct Medicine m[]) {
    int i;
    printf("\nMedicine List:\n");
    printf("|  Name             |  Price       |  Quantity    |\n");
    for (i = 0; i < 10; i++) {
        printf("|%-20s|%-13.2f|%-14d|\n", m[i].name, m[i].price, m[i].quantity);
    }
    printf("\n");
}

void removeMedicine(struct Medicine m[]) {
    char searchName[50];
    int i, found = 0;
    printf("\nEnter the name of the medicine to remove: ");
    scanf("%s", &searchName);

    for (i = 0; i < 10; i++) {
        if (strcmp(m[i].name, searchName) == 0) {
            found = 1;
            strcpy(m[i].name, "");
            m[i].price = 0.0;
            m[i].quantity = 0;
            printf("\nMedicine removed successfully!\n");
        }
    }
    if (!found) {
        printf("\nNo medicine found with that name.\n");
    }
}

int main() {
    struct Medicine med[10];
    int choice;

    printf("Welcome to the Medical Store Management System!\n");
    printf("Please select an option:\n");

    do {
        printf("\n1. Add new medicine\n2. Update medicine\n3. Display all medicine\n4. Remove medicine\n5. Exit program\n\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine(med);
                break;
            case 2:
                updateMedicine(med);
                break;
            case 3:
                displayMedicine(med);
                break;
            case 4:
                removeMedicine(med);
                break;
            case 5:
                printf("\nThank you for using the Medical Store Management System!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}