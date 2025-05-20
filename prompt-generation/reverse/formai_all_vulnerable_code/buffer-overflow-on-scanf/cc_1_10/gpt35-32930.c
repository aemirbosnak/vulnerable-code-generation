//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} medicine;

void displayMenu();
void addMedicine(medicine[], int*);
void sellMedicine(medicine[], int*);
void updateMedicine(medicine[], int*);

int main() {
    int choice, count = 0;
    medicine meds[100];

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine(meds, &count);
                break;
            case 2:
                sellMedicine(meds, &count);
                break;
            case 3:
                updateMedicine(meds, &count);
                break;
            case 4:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    printf("\nMedical Store Management System\n");
    printf("--------------------------------\n");
    printf("1. Add medicine\n");
    printf("2. Sell medicine\n");
    printf("3. Update medicine\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
}

void addMedicine(medicine meds[], int *count) {
    if (*count == 100) {
        printf("\nCannot add more medicine. Maximum limit reached.\n");
        return;
    }

    printf("\nEnter name of medicine: ");
    scanf("%s", meds[*count].name);
    printf("Enter quantity: ");
    scanf("%d", &meds[*count].quantity);
    printf("Enter price: ");
    scanf("%f", &meds[*count].price);

    (*count)++;
    printf("\nMedicine added successfully.\n");
}

void sellMedicine(medicine meds[], int *count) {
    char name[50];
    int quantity, i;

    printf("\nEnter name of medicine: ");
    scanf("%s", name);

    for (i = 0; i < *count; i++) {
        if (strcmp(meds[i].name, name) == 0) {
            printf("Enter quantity to sell: ");
            scanf("%d", &quantity);

            if (quantity > meds[i].quantity) {
                printf("\nInsufficient stock. Available stock is %d.\n", meds[i].quantity);
            } else {
                meds[i].quantity -= quantity;
                printf("\nSale successful. Total cost is %0.2f.\n", quantity * meds[i].price);

                if (meds[i].quantity == 0) {
                    printf("Stock empty. Removing medicine from inventory.\n");
                    *count -= 1;
                    meds[i] = meds[*count];
                }

                return;
            }
        }
    }

    printf("\nMedicine not found in inventory. Please try again.\n");
}

void updateMedicine(medicine meds[], int *count) {
    char name[50];
    int choice, i;

    printf("\nEnter name of medicine: ");
    scanf("%s", name);

    for (i = 0; i < *count; i++) {
        if (strcmp(meds[i].name, name) == 0) {
            printf("1. Update quantity\n");
            printf("2. Update price\n");
            printf("Enter choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    printf("Enter new quantity: ");
                    scanf("%d", &meds[i].quantity);
                    printf("\nQuantity updated successfully.\n");
                    break;
                case 2:
                    printf("Enter new price: ");
                    scanf("%f", &meds[i].price);
                    printf("\nPrice updated successfully.\n");
                    break;
                default:
                    printf("\nInvalid choice. Please try again.\n");
                    break;
            }

            return;
        }
    }

    printf("\nMedicine not found in inventory. Please try again.\n");
}