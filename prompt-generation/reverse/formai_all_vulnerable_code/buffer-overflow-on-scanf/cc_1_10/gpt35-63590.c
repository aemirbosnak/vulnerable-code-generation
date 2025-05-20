//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_MANUFACTURER_LENGTH 30
#define MAX_STOCKS 1000

// Struct for storing information about a medical item
struct MedicalItem {
    char name[MAX_NAME_LENGTH];
    char manufacturer[MAX_MANUFACTURER_LENGTH];
    double price;
    int stocks;
};

// Global variables
struct MedicalItem medical_items[MAX_ITEMS];
int num_items = 0;

// Function to add a new medical item
void add_medical_item() {
    if (num_items >= MAX_ITEMS) {
        printf("Error: Maximum limit of medical items reached.\n");
        return;
    }
    printf("Enter name of the medical item: ");
    fgets(medical_items[num_items].name, MAX_NAME_LENGTH, stdin);
    medical_items[num_items].name[strcspn(medical_items[num_items].name, "\n")] = 0;
    printf("Enter manufacturer of the medical item: ");
    fgets(medical_items[num_items].manufacturer, MAX_MANUFACTURER_LENGTH, stdin);
    medical_items[num_items].manufacturer[strcspn(medical_items[num_items].manufacturer, "\n")] = 0;
    printf("Enter price of the medical item: ");
    scanf("%lf", &medical_items[num_items].price);
    printf("Enter number of stocks of the medical item: ");
    scanf("%d", &medical_items[num_items].stocks);
    num_items++;
}

// Function to list all medical items
void list_medical_items() {
    printf("Name\t\tManufacturer\t\tPrice\t\tStocks\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t\t%s\t\t%.2f\t\t%d\n", medical_items[i].name, 
            medical_items[i].manufacturer, medical_items[i].price, medical_items[i].stocks);
    }
}

// Function to search for a medical item by name
void search_medical_item() {
    char name[MAX_NAME_LENGTH];
    printf("Enter name of the medical item to search: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0;
    for (int i = 0; i < num_items; i++) {
        if (strcmp(name, medical_items[i].name) == 0) {
            printf("Name\t\tManufacturer\t\tPrice\t\tStocks\n");
            printf("%s\t\t%s\t\t%.2f\t\t%d\n", medical_items[i].name, 
                medical_items[i].manufacturer, medical_items[i].price, medical_items[i].stocks);
            return;
        }
    }
    printf("Medical item not found.\n");
}

// Function to update stocks of a medical item
void update_medical_item_stocks() {
    char name[MAX_NAME_LENGTH];
    printf("Enter name of the medical item to update stocks: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0;
    for (int i = 0; i < num_items; i++) {
        if (strcmp(name, medical_items[i].name) == 0) {
            printf("Current stocks: %d\n", medical_items[i].stocks);
            printf("Enter additional stocks: ");
            int stocks_to_add;
            scanf("%d", &stocks_to_add);
            medical_items[i].stocks += stocks_to_add;
            printf("Stocks updated successfully.\n");
            return;
        }
    }
    printf("Medical item not found.\n");
}

// Main function
int main() {
    int option;
    do {
        printf("\nMedical Store Management System\n");
        printf("1. Add new medical item\n");
        printf("2. List all medical items\n");
        printf("3. Search for a medical item\n");
        printf("4. Update stocks of a medical item\n");
        printf("0. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);
        getchar(); // Consume remaining newline character from scanf input
        switch (option) {
            case 1:
                add_medical_item();
                break;
            case 2:
                list_medical_items();
                break;
            case 3:
                search_medical_item();
                break;
            case 4:
                update_medical_item_stocks();
                break;
            case 0:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (1);
    return 0;
}