//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DRUGS 100

typedef struct {
    char name[50];
    int quantity;
    float price;
} Drug;

Drug drugStore[MAX_DRUGS];
int drugCount = 0;

void addDrug() {
    if (drugCount < MAX_DRUGS) {
        printf("Enter drug name: ");
        scanf("%s", drugStore[drugCount].name);
        printf("Enter drug quantity: ");
        scanf("%d", &drugStore[drugCount].quantity);
        printf("Enter drug price: ");
        scanf("%f", &drugStore[drugCount].price);
        drugCount++;
        printf("Drug added successfully!\n");
    } else {
        printf("Drug store is full, cannot add more drugs.\n");
    }
}

void viewDrugs() {
    if (drugCount == 0) {
        printf("No drugs available in the store.\n");
    } else {
        printf("\nAvailable Drugs:\n");
        printf("--------------------------------------\n");
        printf("| %-20s | %-10s | %-10s |\n", "Drug Name", "Quantity", "Price");
        printf("--------------------------------------\n");
        for (int i = 0; i < drugCount; i++) {
            printf("| %-20s | %-10d | %-10.2f |\n", drugStore[i].name, drugStore[i].quantity, drugStore[i].price);
        }
        printf("--------------------------------------\n");
    }
}

void updateDrug() {
    char drugName[50];
    printf("Enter the name of the drug to update: ");
    scanf("%s", drugName);

    for (int i = 0; i < drugCount; i++) {
        if (strcmp(drugStore[i].name, drugName) == 0) {
            printf("Updating details for %s\n", drugStore[i].name);
            printf("Enter new quantity: ");
            scanf("%d", &drugStore[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &drugStore[i].price);
            printf("Drug details updated successfully!\n");
            return;
        }
    }
    printf("Drug not found in the store.\n");
}

void deleteDrug() {
    char drugName[50];
    printf("Enter the name of the drug to delete: ");
    scanf("%s", drugName);
    
    for (int i = 0; i < drugCount; i++) {
        if (strcmp(drugStore[i].name, drugName) == 0) {
            for (int j = i; j < drugCount - 1; j++) {
                drugStore[j] = drugStore[j + 1];
            }
            drugCount--;
            printf("Drug deleted successfully!\n");
            return;
        }
    }
    printf("Drug not found in the store.\n");
}

void searchDrug() {
    char drugName[50];
    printf("Enter the name of the drug to search: ");
    scanf("%s", drugName);

    for (int i = 0; i < drugCount; i++) {
        if (strcmp(drugStore[i].name, drugName) == 0) {
            printf("Drug found: %s, Quantity: %d, Price: %.2f\n", drugStore[i].name, drugStore[i].quantity, drugStore[i].price);
            return;
        }
    }
    printf("Drug not found in the store.\n");
}

int main() {
    int choice;
    do {
        printf("\n--- Medical Store Management System ---\n");
        printf("1. Add Drug\n");
        printf("2. View Drugs\n");
        printf("3. Update Drug\n");
        printf("4. Delete Drug\n");
        printf("5. Search Drug\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addDrug(); break;
            case 2: viewDrugs(); break;
            case 3: updateDrug(); break;
            case 4: deleteDrug(); break;
            case 5: searchDrug(); break;
            case 6: printf("Exiting the system. Goodbye!\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}