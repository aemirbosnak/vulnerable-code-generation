//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to store medicine details
struct medicine {
    char name[50];
    char manufacturer[50];
    int stock;
    float price;
};

// Function to add medicine to the store
void addMedicine(struct medicine *store, int *count) {
    printf("Enter medicine name: ");
    scanf("%s", store[*count].name);
    printf("Enter manufacturer name: ");
    scanf("%s", store[*count].manufacturer);
    printf("Enter medicine stock: ");
    scanf("%d", &store[*count].stock);
    printf("Enter medicine price: ");
    scanf("%f", &store[*count].price);
    (*count)++;
    printf("Medicine added successfully!\n");
}

// Function to display all medicines in the store
void displayMedicine(struct medicine *store, int count) {
    printf("Medicine Name\tManufacturer\tStock\tPrice\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t\t%s\t\t%d\t%.2f\n", store[i].name, store[i].manufacturer, store[i].stock, store[i].price);
    }
}

// Function to search for a medicine by name
void searchMedicine(struct medicine *store, int count) {
    char name[50];
    printf("Enter name of medicine to search: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(store[i].name, name) == 0) {
            printf("Medicine Name\tManufacturer\tStock\tPrice\n");
            printf("%s\t\t%s\t\t%d\t%.2f\n", store[i].name, store[i].manufacturer, store[i].stock, store[i].price);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Medicine not found!\n");
    }
}

// Function to sell medicine
void sellMedicine(struct medicine *store, int count) {
    char name[50];
    printf("Enter name of medicine to sell: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(store[i].name, name) == 0) {
            if (store[i].stock == 0) {
                printf("Medicine out of stock!\n");
            } else {
                printf("Medicine found! Price: %.2f\n", store[i].price);
                store[i].stock--;
                printf("Medicine sold successfully!\n");
            }
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Medicine not found!\n");
    }
}

// Main function
int main() {
    struct medicine store[100];
    int count = 0;
    int choice;
    do {
        printf("\n-----Menu-----\n");
        printf("1. Add medicine\n");
        printf("2. Display all medicines\n");
        printf("3. Search for a medicine\n");
        printf("4. Sell medicine\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addMedicine(store, &count);
                break;
            case 2:
                if (count == 0) {
                    printf("No medicines found!\n");
                } else {
                    displayMedicine(store, count);
                }
                break;
            case 3:
                if (count == 0) {
                    printf("No medicines found!\n");
                } else {
                    searchMedicine(store, count);
                }
                break;
            case 4:
                if (count == 0) {
                    printf("No medicines found!\n");
                } else {
                    sellMedicine(store, count);
                }
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);
    return 0;
}