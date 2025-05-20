//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_DRUGS 50
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    float price;
    int stock;
} Product;

typedef struct {
    char prescriptionName[NAME_LENGTH];
    float dosage;
    int quantity;
    char notes[100];
} Prescription;

typedef struct {
    Product products[MAX_PRODUCTS];
    int productCount;
    Prescription prescriptions[MAX_DRUGS];
    int prescriptionCount;
} MedicalStore;

void addProduct(MedicalStore* store) {
    if (store->productCount < MAX_PRODUCTS) {
        printf("Enter product name: ");
        scanf("%s", store->products[store->productCount].name);
        printf("Enter product price: ");
        scanf("%f", &store->products[store->productCount].price);
        printf("Enter stock quantity: ");
        scanf("%d", &store->products[store->productCount].stock);
        store->productCount++;
        printf("Product added successfully!\n");
    } else {
        printf("Product list is full!\n");
    }
}

void listProducts(MedicalStore* store) {
    if (store->productCount > 0) {
        printf("Available Products:\n");
        for (int i = 0; i < store->productCount; i++) {
            printf("%d. %s - $%.2f (Stock: %d)\n", i + 1, 
                   store->products[i].name, 
                   store->products[i].price, 
                   store->products[i].stock);
        }
    } else {
        printf("No products available in the store.\n");
    }
}

void sellProduct(MedicalStore* store) {
    int choice, quantity;
    listProducts(store);
    if (store->productCount > 0) {
        printf("Select product to sell (1-%d): ", store->productCount);
        scanf("%d", &choice);
        if (choice < 1 || choice > store->productCount) {
            printf("Invalid choice. Returning to main menu.\n");
            return;
        }
        printf("Enter quantity to sell: ");
        scanf("%d", &quantity);
        if (quantity > store->products[choice - 1].stock) {
            printf("Not enough stock available!\n");
            return;
        }
        store->products[choice - 1].stock -= quantity;
        printf("Sold %d units of %s\n", quantity, store->products[choice - 1].name);
    }
}

void addPrescription(MedicalStore* store) {
    if (store->prescriptionCount < MAX_DRUGS) {
        printf("Enter prescription name: ");
        scanf("%s", store->prescriptions[store->prescriptionCount].prescriptionName);
        printf("Enter dosage (mg): ");
        scanf("%f", &store->prescriptions[store->prescriptionCount].dosage);
        printf("Enter quantity: ");
        scanf("%d", &store->prescriptions[store->prescriptionCount].quantity);
        printf("Enter any notes: ");
        scanf(" %[^\n]", store->prescriptions[store->prescriptionCount].notes);
        store->prescriptionCount++;
        printf("Prescription added successfully!\n");
    } else {
        printf("Prescription list is full!\n");
    }
}

void listPrescriptions(MedicalStore* store) {
    if (store->prescriptionCount > 0) {
        printf("Prescriptions:\n");
        for (int i = 0; i < store->prescriptionCount; i++) {
            printf("%d. %s - %.2f mg (Qty: %d) - Notes: %s\n", 
                   i + 1, 
                   store->prescriptions[i].prescriptionName, 
                   store->prescriptions[i].dosage, 
                   store->prescriptions[i].quantity, 
                   store->prescriptions[i].notes);
        }
    } else {
        printf("No prescriptions available.\n");
    }
}

void printMenu() {
    printf("Medical Store Management System\n");
    printf("1. Add Product\n");
    printf("2. List Products\n");
    printf("3. Sell Product\n");
    printf("4. Add Prescription\n");
    printf("5. List Prescriptions\n");
    printf("6. Quit\n");
}

int main() {
    MedicalStore store;
    store.productCount = 0;
    store.prescriptionCount = 0;
    int choice;

    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addProduct(&store);
                break;
            case 2:
                listProducts(&store);
                break;
            case 3:
                sellProduct(&store);
                break;
            case 4:
                addPrescription(&store);
                break;
            case 5:
                listPrescriptions(&store);
                break;
            case 6:
                printf("Exiting the system. Thank you!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}