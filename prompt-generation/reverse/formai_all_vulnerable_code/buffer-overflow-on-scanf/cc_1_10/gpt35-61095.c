//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100 // Maximum number of medicines that can be stored
#define MAX_NAME_LENGTH 50 // Maximum length of medicine name
#define MAX_COMPANY_LENGTH 30 // Maximum length of company name

typedef struct medicine {
    char name[MAX_NAME_LENGTH];
    char company[MAX_COMPANY_LENGTH];
    int price;
    int quantity;
} Medicine;

// Function to add a new medicine to the inventory
void addMedicine(Medicine medicines[], int *count) {
    if (*count >= MAX_MEDICINES) {
        printf("Medicine store is full.\n");
        return;
    }

    printf("Enter medicine name: ");
    scanf("%s", medicines[*count].name);

    printf("Enter company name: ");
    scanf("%s", medicines[*count].company);

    printf("Enter price: ");
    scanf("%d", &medicines[*count].price);

    printf("Enter quantity: ");
    scanf("%d", &medicines[*count].quantity);

    (*count)++;
}

// Function to display the list of medicines in the inventory
void displayMedicines(Medicine medicines[], int count) {
    if (count == 0) {
        printf("Medicine store is empty.\n");
        return;
    }

    printf("\nName\t\tCompany\t\tPrice\tQuantity\n");
    printf("-------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%s\t%s\t%d\t%d\n", medicines[i].name, medicines[i].company, medicines[i].price, medicines[i].quantity);
    }

    printf("-------------------------------------------------------\n");
}

// Function to search for a medicine in the inventory by name
void searchMedicine(Medicine medicines[], int count) {
    printf("Enter medicine name to search: ");

    char query[MAX_NAME_LENGTH];
    scanf("%s", query);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strstr(medicines[i].name, query) != NULL) {
            printf("%s\t%s\t%d\t%d\n", medicines[i].name, medicines[i].company, medicines[i].price, medicines[i].quantity);
            found = 1;
        }
    }

    if (!found) {
        printf("Medicine not found.\n");
    }
}

// Main function
int main() {
    Medicine medicines[MAX_MEDICINES];
    int count = 0;

    while (1) {
        printf("\n\n");
        printf("=============== Medicine Store Management System ===============\n");
        printf("1. Add medicine\n");
        printf("2. Display medicines\n");
        printf("3. Search medicine\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: addMedicine(medicines, &count); break;
            case 2: displayMedicines(medicines, count); break;
            case 3: searchMedicine(medicines, count); break;
            case 4: return 0; // Exit
            default: printf("Invalid choice.\n"); break;
        }
    }

    return 0;
}