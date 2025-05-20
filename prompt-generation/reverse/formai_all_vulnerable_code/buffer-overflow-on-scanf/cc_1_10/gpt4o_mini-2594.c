//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DRUGS 100
#define MAX_NAME_LENGTH 50
#define MAX_LOCATION_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
    char location[MAX_LOCATION_LENGTH];
} Drug;

Drug drugStore[MAX_DRUGS];
int drugCount = 0;

// Function Prototypes
void addDrug();
void viewDrugs();
void restockDrug();
void searchDrug();
void useDrug();
void displayMenu();

int main() {
    int choice;

    printf("Welcome to the Post-Apocalyptic Medical Store Management System\n");
    printf("In this harsh world, every medicine is a treasure!\n");

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addDrug();
                break;
            case 2:
                viewDrugs();
                break;
            case 3:
                restockDrug();
                break;
            case 4:
                searchDrug();
                break;
            case 5:
                useDrug();
                break;
            case 6:
                printf("Stay safe out there! Closing the system...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n--- Menu ---\n");
    printf("1. Add new drug\n");
    printf("2. View all drugs\n");
    printf("3. Restock a drug\n");
    printf("4. Search for a drug\n");
    printf("5. Use a drug\n");
    printf("6. Exit\n");
}

void addDrug() {
    if (drugCount >= MAX_DRUGS) {
        printf("The store is full! Cannot add more drugs.\n");
        return;
    }

    Drug newDrug;
    printf("Enter drug name: ");
    scanf("%s", newDrug.name);
    printf("Enter quantity: ");
    scanf("%d", &newDrug.quantity);
    printf("Enter price: ");
    scanf("%f", &newDrug.price);
    printf("Enter storage location: ");
    scanf("%s", newDrug.location);

    drugStore[drugCount] = newDrug;
    drugCount++;
    printf("Drug added successfully!\n");
}

void viewDrugs() {
    if (drugCount == 0) {
        printf("No drugs available in the store!\n");
        return;
    }

    printf("\n--- Drug Inventory ---\n");
    for (int i = 0; i < drugCount; i++) {
        printf("Name: %s, Quantity: %d, Price: %.2f, Location: %s\n", 
               drugStore[i].name, drugStore[i].quantity, drugStore[i].price, drugStore[i].location);
    }
}

void restockDrug() {
    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the drug to restock: ");
    scanf("%s", name);

    for (int i = 0; i < drugCount; i++) {
        if (strcmp(drugStore[i].name, name) == 0) {
            int additionalQuantity;
            printf("Enter quantity to add: ");
            scanf("%d", &additionalQuantity);
            drugStore[i].quantity += additionalQuantity;
            printf("Drug restocked successfully! New quantity: %d\n", drugStore[i].quantity);
            return;
        }
    }

    printf("Drug not found!\n");
}

void searchDrug() {
    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the drug to search for: ");
    scanf("%s", name);

    for (int i = 0; i < drugCount; i++) {
        if (strcmp(drugStore[i].name, name) == 0) {
            printf("Drug found! Name: %s, Quantity: %d, Price: %.2f, Location: %s\n", 
                   drugStore[i].name, drugStore[i].quantity, drugStore[i].price, drugStore[i].location);
            return;
        }
    }

    printf("Drug not found!\n");
}

void useDrug() {
    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the drug to use: ");
    scanf("%s", name);

    for (int i = 0; i < drugCount; i++) {
        if (strcmp(drugStore[i].name, name) == 0) {
            int useQuantity;
            printf("Enter quantity to use: ");
            scanf("%d", &useQuantity);

            if (useQuantity > drugStore[i].quantity) {
                printf("Not enough quantity available! Available: %d\n", drugStore[i].quantity);
                return;
            }

            drugStore[i].quantity -= useQuantity;
            printf("Drug used successfully! Remaining quantity: %d\n", drugStore[i].quantity);
            
            // If quantity reaches zero, remove the drug from the inventory
            if (drugStore[i].quantity == 0) {
                for (int j = i; j < drugCount - 1; j++) {
                    drugStore[j] = drugStore[j + 1];
                }
                drugCount--;
                printf("Drug depleted! Removed from inventory.\n");
            }
            return;
        }
    }

    printf("Drug not found!\n");
}