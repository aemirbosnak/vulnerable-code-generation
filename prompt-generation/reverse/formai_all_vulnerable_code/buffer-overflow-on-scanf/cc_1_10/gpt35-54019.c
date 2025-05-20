//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct medicine {
    char name[100];
    int quantity;
    float price;
    struct medicine *next;
} Medicine;

void addMedicine(Medicine **inventory) {
    Medicine *newMedicine = (Medicine*) malloc(sizeof(Medicine));
    printf("Enter name of medicine: ");
    scanf("%s", newMedicine->name);
    printf("Enter quantity of medicine: ");
    scanf("%d", &newMedicine->quantity);
    printf("Enter price of medicine: ");
    scanf("%f", &newMedicine->price);
    newMedicine->next = NULL;

    if (*inventory == NULL) {
        *inventory = newMedicine;
    } else {
        Medicine *currMedicine = *inventory;
        while (currMedicine->next != NULL) {
            currMedicine = currMedicine->next;
        }
        currMedicine->next = newMedicine;
    }
    printf("\nNew medicine added successfully.\n\n");
}

void viewInventory(Medicine *inventory) {
    printf("Current inventory:\n\n");
    if (inventory == NULL) {
        printf("No medicines found.\n");
    } else {
        printf("Name\tQuantity\tPrice\n");
        printf("-----------------------------\n");
        Medicine *currMedicine = inventory;
        while (currMedicine != NULL) {
            printf("%s\t%d\t%.2f\n", currMedicine->name, currMedicine->quantity, currMedicine->price);
            currMedicine = currMedicine->next;
        }
    }
    printf("\n");
}

void sellMedicine(Medicine **inventory) {
    char medicineName[100];
    printf("Enter the name of medicine to be sold: ");
    scanf("%s", medicineName);
    int medicineQuantity;
    printf("Enter the quantity of medicine to be sold: ");
    scanf("%d", &medicineQuantity);
    Medicine *currMedicine = *inventory;
    while (currMedicine != NULL) {
        if (strcmp(currMedicine->name, medicineName) == 0) {
            if (currMedicine->quantity < medicineQuantity) {
                printf("Error: Insufficient quantity of medicine.\n\n");
                return;
            }
            currMedicine->quantity -= medicineQuantity;
            float totalPrice = medicineQuantity * currMedicine->price;
            printf("%s sold successfully: %d x %.2f = %.2f\n\n", currMedicine->name, medicineQuantity, currMedicine->price, totalPrice);
            return;
        }
        currMedicine = currMedicine->next;
    }
    printf("Error: Medicine not found.\n\n");
}

void menu() {
    printf("Welcome to Medical Store Management System!\n");
    printf("============================================\n");
    printf("1. Add new medicine\n");
    printf("2. View inventory\n");
    printf("3. Sell medicine\n");
    printf("4. Exit\n\n");
}

int main() {
    Medicine *inventory = NULL;
    int choice;
    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice) {
            case 1:
                addMedicine(&inventory);
                break;
            case 2:
                viewInventory(inventory);
                break;
            case 3:
                sellMedicine(&inventory);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n\n");
        }
    } while (choice != 4);
    return 0;
}