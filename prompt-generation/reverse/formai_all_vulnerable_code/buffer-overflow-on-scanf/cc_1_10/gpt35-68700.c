//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

//Struct to represent a medicine
struct Medicine {
    char name[20];
    char manufacturer[20];
    float price;
    int quantity;
};

//Function to add a new medicine to the stock
void addMedicine(struct Medicine stock[], int* pIndex) {
    if(*pIndex >= MAX_SIZE) {
        printf("\nSorry, stock is full.\n");
        return;
    }
    struct Medicine newMedicine;
    printf("\nEnter medicine name: ");
    scanf("%s", newMedicine.name);
    printf("\nEnter manufacturer name: ");
    scanf("%s", newMedicine.manufacturer);
    printf("\nEnter price: ");
    scanf("%f", &newMedicine.price);
    printf("\nEnter quantity: ");
    scanf("%d", &newMedicine.quantity);
    stock[*pIndex] = newMedicine;
    *pIndex += 1;
    printf("\nMedicine added successfully!\n");
}

//Function to search for a medicine by name
void searchMedicine(struct Medicine stock[], int index) {
    char medicineName[20];
    printf("\nEnter medicine name: ");
    scanf("%s", medicineName);
    for(int i=0; i<index; i++) {
        if(strcmp(stock[i].name, medicineName) == 0) {
            printf("\nName: %s\nManufacturer: %s\nPrice: %.2f\nQuantity: %d\n", stock[i].name, stock[i].manufacturer, stock[i].price, stock[i].quantity);
            return;
        }
    }
    printf("\nMedicine not found!\n");
}

//Function to update a medicine's quantity
void updateMedicine(struct Medicine stock[], int index) {
    char medicineName[20];
    printf("\nEnter medicine name: ");
    scanf("%s", medicineName);
    for(int i=0; i<index; i++) {
        if(strcmp(stock[i].name, medicineName) == 0) {
            int newQuantity;
            printf("\nEnter new quantity: ");
            scanf("%d", &newQuantity);
            stock[i].quantity = newQuantity;
            printf("\nQuantity updated successfully!\n");
            return;
        }
    }
    printf("\nMedicine not found!\n");
}

//Function to display all medicines in the stock
void displayStock(struct Medicine stock[], int index) {
    printf("\n");
    printf("---------------------------------------------------\n");
    printf("| Name                 | Manufacturer | Price    |\n");
    printf("---------------------------------------------------\n");
    for(int i=0; i<index; i++) {
        printf("| %-20s | %-12s | %-8.2f |\n", stock[i].name, stock[i].manufacturer, stock[i].price);
    }
    printf("---------------------------------------------------\n");
}

//Main function to show menu options to the user and control the flow of the program
int main() {
    struct Medicine stock[MAX_SIZE];
    int index = 0;
    int choice;
    while(1) {
        printf("\n1. Add Medicine\n");
        printf("2. Search Medicine\n");
        printf("3. Update Medicine Quantity\n");
        printf("4. Display All Medicines\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addMedicine(stock, &index);
                break;
            case 2:
                searchMedicine(stock, index);
                break;
            case 3:
                updateMedicine(stock, index);
                break;
            case 4:
                displayStock(stock, index);
                break;
            case 5:
                printf("\nExiting program...\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }
    return 0;
}