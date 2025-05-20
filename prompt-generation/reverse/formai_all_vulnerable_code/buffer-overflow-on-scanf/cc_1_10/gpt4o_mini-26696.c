//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

typedef struct {
    char name[50];
    char company[50];
    float price;
    int quantity;
} Medicine;

void addMedicine(Medicine medicines[], int *count) {
    printf("Enter medicine name: ");
    scanf("%s", medicines[*count].name);
    printf("Enter company name: ");
    scanf("%s", medicines[*count].company);
    printf("Enter price: ");
    scanf("%f", &medicines[*count].price);
    printf("Enter quantity: ");
    scanf("%d", &medicines[*count].quantity);
    (*count)++;
    printf("Medicine added successfully!\n\n");
}

void viewMedicines(Medicine medicines[], int count) {
    if (count == 0) {
        printf("No medicines available!\n\n");
        return;
    }
    printf("Available Medicines:\n");
    printf("------------------------------------------------------------\n");
    printf("%-20s %-20s %-10s %-10s\n", "Name", "Company", "Price", "Quantity");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-20s %-20s %-10.2f %-10d\n",
                medicines[i].name,
                medicines[i].company,
                medicines[i].price,
                medicines[i].quantity);
    }
    printf("------------------------------------------------------------\n\n");
}

void sellMedicine(Medicine medicines[], int count) {
    char name[50];
    printf("Enter medicine name to sell: ");
    scanf("%s", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            int quantity;
            printf("Enter quantity to sell: ");
            scanf("%d", &quantity);
            if (quantity > medicines[i].quantity) {
                printf("Not enough quantity available!\n\n");
            } else {
                medicines[i].quantity -= quantity;
                float totalPrice = quantity * medicines[i].price;
                printf("Sold %d x %s for a total of %.2f\n\n", quantity, medicines[i].name, totalPrice);
            }
            return;
        }
    }
    printf("Medicine not found!\n\n");
}

void menu() {
    printf("Welcome to the Medical Store Management System\n");
    printf("1. Add Medicine\n");
    printf("2. View Medicines\n");
    printf("3. Sell Medicine\n");
    printf("4. Exit\n");
    printf("Please choose an option: ");
}

int main() {
    Medicine medicines[MAX_MEDICINES];
    int count = 0;
    int option;

    while (1) {
        menu();
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                if (count < MAX_MEDICINES) {
                    addMedicine(medicines, &count);
                } else {
                    printf("Medicine limit reached!\n\n");
                }
                break;
            case 2:
                viewMedicines(medicines, count);
                break;
            case 3:
                sellMedicine(medicines, count);
                break;
            case 4:
                printf("Exiting the program. Thank you!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n\n");
        }
    }

    return 0;
}