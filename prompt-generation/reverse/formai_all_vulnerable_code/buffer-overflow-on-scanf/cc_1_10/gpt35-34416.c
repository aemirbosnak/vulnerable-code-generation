//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing medicine details
typedef struct {
    char name[50];
    char manufacturer[50];
    char expiry_date[10];
    int quantity;
    float price;
} Medicine;

// Function for adding new medicines to the inventory
void add_medicine(Medicine *med, int *count) {
    printf("\nEnter medicine name: ");
    scanf("%s", med[*count].name);
    printf("Enter manufacturer name: ");
    scanf("%s", med[*count].manufacturer);
    printf("Enter expiry date (dd-mm-yyyy): ");
    scanf("%s", med[*count].expiry_date);
    printf("Enter quantity: ");
    scanf("%d", &med[*count].quantity);
    printf("Enter price: ");
    scanf("%f", &med[*count].price);
    (*count)++;
    printf("\nMedicine added successfully!\n");
}

// Function for displaying all medicines in the inventory
void display_medicines(Medicine *med, int count) {
    printf("\nMedicine Name\tManufacturer Name\tExpiry Date\tQuantity\tPrice\n");
    for(int i = 0; i < count; i++) {
        printf("%s\t\t%s\t\t%s\t\t%d\t\t%.2f\n", med[i].name, med[i].manufacturer, med[i].expiry_date, med[i].quantity, med[i].price);
    }
}

// Function for searching for a medicine by name in the inventory
void search_medicine(Medicine *med, int count) {
    char name[50];
    printf("\nEnter the name of the medicine you want to search: ");
    scanf("%s", name);
    for(int i = 0; i < count; i++) {
        if(strcmp(med[i].name, name) == 0) {
            printf("\nMedicine Name\tManufacturer Name\tExpiry Date\tQuantity\tPrice\n");
            printf("%s\t\t%s\t\t%s\t\t%d\t\t%.2f\n", med[i].name, med[i].manufacturer, med[i].expiry_date, med[i].quantity, med[i].price);
            return;
        }
    }
    printf("Medicine not found!\n");
}

// Function for selling a medicine
void sell_medicine(Medicine *med, int count) {
    char name[50];
    int quantity;
    printf("\nEnter the name of the medicine you want to sell: ");
    scanf("%s", name);
    for(int i = 0; i < count; i++) {
        if(strcmp(med[i].name, name) == 0) {
            printf("Available quantity: %d\n", med[i].quantity);
            printf("Enter quantity to sell: ");
            scanf("%d", &quantity);
            if(quantity > med[i].quantity) {
                printf("Only %d quantity of %s is available! Cannot sell %d quantity.\n", med[i].quantity, med[i].name, quantity);
                return;
            } else {
                med[i].quantity -= quantity;
                printf("\nSold successfully!\n");
                return;
            }
        }
    }
    printf("Medicine not found!\n");
}

int main() {
    Medicine *med = (Medicine*) malloc(sizeof(Medicine) * 100); // Maximum of 100 medicines can be stored
    int count = 0, choice;
    do {
        printf("\n-----MEDICAL STORE MANAGEMENT SYSTEM-----\n");
        printf("1. Add medicine\n");
        printf("2. Display all medicines\n");
        printf("3. Search for a medicine\n");
        printf("4. Sell a medicine\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_medicine(med, &count);
                break;
            case 2:
                display_medicines(med, count);
                break;
            case 3:
                search_medicine(med, count);
                break;
            case 4:
                sell_medicine(med, count);
                break;
            case 5:
                printf("\nThank you for using the system!\n");
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    } while(choice != 5);
    free(med);
    return 0;
}