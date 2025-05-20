//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    char compName[NAME_LENGTH];
    float price;
    int quantity;
} Medicine;

void addMedicine(Medicine* medicines, int* count) {
    if (*count < MAX_MEDICINES) {
        printf("Enter medicine name: ");
        scanf("%s", medicines[*count].name);
        printf("Enter company name: ");
        scanf("%s", medicines[*count].compName);
        printf("Enter medicine price: ");
        scanf("%f", &medicines[*count].price);
        printf("Enter quantity available: ");
        scanf("%d", &medicines[*count].quantity);
        (*count)++;
        printf("Medicine added successfully!\n");
    } else {
        printf("Medicine limit reached! Cannot add more.\n");
    }
}

void viewMedicines(Medicine* medicines, int count) {
    if (count == 0) {
        printf("No medicines available.\n");
        return;
    }
    printf("\nList of Medicines:\n");
    printf("-----------------------------------------------------------\n");
    printf("Name\t\tCompany\t\tPrice\tQuantity\n");
    printf("-----------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t\t%s\t\t%.2f\t%d\n", medicines[i].name, medicines[i].compName, medicines[i].price, medicines[i].quantity);
    }
    printf("-----------------------------------------------------------\n");
}

void searchMedicine(Medicine* medicines, int count) {
    char name[NAME_LENGTH];
    printf("Enter medicine name to search: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcasecmp(medicines[i].name, name) == 0) {
            printf("Medicine found!\n");
            printf("Name: %s, Company: %s, Price: %.2f, Quantity: %d\n", medicines[i].name, medicines[i].compName, medicines[i].price, medicines[i].quantity);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Medicine not found!\n");
    }
}

void displayMenu() {
    printf("\n--- Medical Store Management System ---\n");
    printf("1. Add Medicine\n");
    printf("2. View All Medicines\n");
    printf("3. Search Medicine\n");
    printf("4. Exit\n");
    printf("-----------------------------------------\n");
}

int main() {
    Medicine medicines[MAX_MEDICINES];
    int count = 0;
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addMedicine(medicines, &count);
                break;
            case 2:
                viewMedicines(medicines, count);
                break;
            case 3:
                searchMedicine(medicines, count);
                break;
            case 4:
                printf("Exiting the program. Thank you!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}