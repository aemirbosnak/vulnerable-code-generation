//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} Medicine;

void displayMenu();
void addMedicine(Medicine medicines[], int *count);
void viewMedicine(Medicine medicines[], int count);
void searchMedicine(Medicine medicines[], int count);

int main() {
    int count = 0, choice;
    char exitChoice;

    Medicine medicines[10];

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addMedicine(medicines, &count);
                break;
            case 2:
                viewMedicine(medicines, count);
                break;
            case 3:
                searchMedicine(medicines, count);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\nInvalid choice! Please choose options 1-4.");
        }

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &exitChoice);

    } while(exitChoice == 'y' || exitChoice == 'Y');

    return 0;
}

void displayMenu() {
    printf("\n==========\n");
    printf("MENU\n");
    printf("==========\n");
    printf("1. Add Medicine\n");
    printf("2. View Medicine\n");
    printf("3. Search Medicine\n");
    printf("4. Exit\n");
}

void addMedicine(Medicine medicines[], int *count) {
    int quantity;
    float price;
    char name[50];

    printf("\nEnter the name of the medicine: ");
    scanf(" %[^\n]s", name);
    printf("Enter the quantity: ");
    scanf("%d", &quantity);
    printf("Enter the price: ");
    scanf("%f", &price);

    Medicine med;
    strcpy(med.name, name);
    med.quantity = quantity;
    med.price = price;

    medicines[*count] = med;
    *count = *count + 1;

    printf("\nMedicine added successfully!");
}

void viewMedicine(Medicine medicines[], int count) {
    if(count == 0) {
        printf("\nNo medicines added yet!");
        return;
    }

    printf("\n%-50s | %-10s | %-10s\n", "Name", "Quantity", "Price");
    printf("-----------------------------------------------------------\n");

    for(int i = 0; i < count; i++) {
        printf("%-50s | %-10d | $%-10.2f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
    }
}

void searchMedicine(Medicine medicines[], int count) {
    if(count == 0) {
        printf("\nNo medicines added yet!");
        return;
    }

    char searchName[50];
    int found = 0;

    printf("\nEnter the name of the medicine to search: ");
    scanf(" %[^\n]s", searchName);

    for(int i = 0; i < count; i++) {
        if(strcmp(searchName, medicines[i].name) == 0) {
            printf("\n%50s | %10s | %10s\n", "Name", "Quantity", "Price");
            printf("----------------------------------------------------\n");
            printf("%-50s | %-10d | $%-10.2f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("\nMedicine not found!");
    }
}