//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for storing medicine information
typedef struct {
    int medID;  // unique identifier for medicine
    char medName[50];  // name of the medicine
    double medPrice;  // price of the medicine
    int medQty;  // quantity of medicine in stock
} Medicine;

// Define the structure for storing equipment information
typedef struct {
    int equipID;  // unique identifier for equipment
    char equipName[50];  // name of the equipment
    double equipPrice;  // price of the equipment
    int equipQty;  // quantity of equipment in stock
} Equipment;

// Define the structure for storing sales information
typedef struct {
    int saleID;  // unique identifier for sale
    char saleType[50];  // type of sale (medicine or equipment)
    char saleName[50];  // name of the item sold
    int saleQty;  // quantity of item sold
    double salePrice;  // price of item sold
} Sale;

// Function to display menu options
void displayMenu() {
    printf("\n--- Medical Store Management System ---\n");
    printf("1. Add medicine\n");
    printf("2. Add equipment\n");
    printf("3. Sell medicine\n");
    printf("4. Sell equipment\n");
    printf("5. Display medicine inventory\n");
    printf("6. Display equipment inventory\n");
    printf("7. Display sales records\n");
    printf("8. Exit\n");
}

// Function to add medicine to inventory
void addMedicine(Medicine *medPtr, int *medCount) {
    printf("\n--- Add Medicine to Inventory ---\n");
    printf("Enter medicine name: ");
    scanf("%s", medPtr[*medCount].medName);
    printf("Enter medicine price: ");
    scanf("%lf", &medPtr[*medCount].medPrice);
    printf("Enter medicine quantity: ");
    scanf("%d", &medPtr[*medCount].medQty);
    medPtr[*medCount].medID = *medCount + 1;
    printf("Medicine added successfully!\n");
    (*medCount)++;
}

// Function to add equipment to inventory
void addEquipment(Equipment *equipPtr, int *equipCount) {
    printf("\n--- Add Equipment to Inventory ---\n");
    printf("Enter equipment name: ");
    scanf("%s", equipPtr[*equipCount].equipName);
    printf("Enter equipment price: ");
    scanf("%lf", &equipPtr[*equipCount].equipPrice);
    printf("Enter equipment quantity: ");
    scanf("%d", &equipPtr[*equipCount].equipQty);
    equipPtr[*equipCount].equipID = *equipCount + 1;
    printf("Equipment added successfully!\n");
    (*equipCount)++;
}

// Function to sell medicine
void sellMedicine(Medicine *medPtr, int medCount, Sale *salePtr, int *saleCount) {
    int medID, medIndex, saleQty;
    printf("\n--- Sell Medicine ---\n");
    printf("Enter medicine ID: ");
    scanf("%d", &medID);
    medIndex = medID - 1;
    printf("Enter quantity: ");
    scanf("%d", &saleQty);
    if (saleQty > medPtr[medIndex].medQty) {
        printf("Error: Quantity exceeds stock!\n");
    }
    else {
        medPtr[medIndex].medQty -= saleQty;
        salePtr[*saleCount].saleID = *saleCount + 1;
        salePtr[*saleCount].saleType[0] = 'M';
        strcpy(salePtr[*saleCount].saleName, medPtr[medIndex].medName);
        salePtr[*saleCount].saleQty = saleQty;
        salePtr[*saleCount].salePrice = medPtr[medIndex].medPrice * saleQty;
        printf("Sale successful!\n");
        (*saleCount)++;
    }
}

// Function to sell equipment
void sellEquipment(Equipment *equipPtr, int equipCount, Sale *salePtr, int *saleCount) {
    int equipID, equipIndex, saleQty;
    printf("\n--- Sell Equipment ---\n");
    printf("Enter equipment ID: ");
    scanf("%d", &equipID);
    equipIndex = equipID - 1;
    printf("Enter quantity: ");
    scanf("%d", &saleQty);
    if (saleQty > equipPtr[equipIndex].equipQty) {
        printf("Error: Quantity exceeds stock!\n");
    }
    else {
        equipPtr[equipIndex].equipQty -= saleQty;
        salePtr[*saleCount].saleID = *saleCount + 1;
        salePtr[*saleCount].saleType[0] = 'E';
        strcpy(salePtr[*saleCount].saleName, equipPtr[equipIndex].equipName);
        salePtr[*saleCount].saleQty = saleQty;
        salePtr[*saleCount].salePrice = equipPtr[equipIndex].equipPrice * saleQty;
        printf("Sale successful!\n");
        (*saleCount)++;
    }
}

// Function to display medicine inventory
void displayMedicineInventory(Medicine *medPtr, int medCount) {
    printf("\n--- Medicine Inventory ---\n");
    printf("ID\tName\tPrice\tQuantity\n");
    for (int i = 0; i < medCount; i++) {
        printf("%d\t%s\t%.2lf\t%d\n", medPtr[i].medID, medPtr[i].medName, medPtr[i].medPrice, medPtr[i].medQty);
    }
}

// Function to display equipment inventory
void displayEquipmentInventory(Equipment *equipPtr, int equipCount) {
    printf("\n--- Equipment Inventory ---\n");
    printf("ID\tName\tPrice\tQuantity\n");
    for (int i = 0; i < equipCount; i++) {
        printf("%d\t%s\t%.2lf\t%d\n", equipPtr[i].equipID, equipPtr[i].equipName, equipPtr[i].equipPrice, equipPtr[i].equipQty);
    }
}

// Function to display sales records
void displaySalesRecords(Sale *salePtr, int saleCount) {
    printf("\n--- Sales Records ---\n");
    printf("ID\tType\tName\tQuantity\tPrice\n");
    for (int i = 0; i < saleCount; i++) {
        printf("%d\t%c\t%s\t%d\t%.2lf\n", salePtr[i].saleID, salePtr[i].saleType[0], salePtr[i].saleName, salePtr[i].saleQty, salePtr[i].salePrice);
    }
}

int main() {
    Medicine medicine[50];
    Equipment equipment[50];
    Sale sales[100];
    int medCount = 0;
    int equipCount = 0;
    int saleCount = 0;
    int choice = 0;

    while (choice != 8) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine(medicine, &medCount);
                break;
            case 2:
                addEquipment(equipment, &equipCount);
                break;
            case 3:
                sellMedicine(medicine, medCount, sales, &saleCount);
                break;
            case 4:
                sellEquipment(equipment, equipCount, sales, &saleCount);
                break;
            case 5:
                displayMedicineInventory(medicine, medCount);
                break;
            case 6:
                displayEquipmentInventory(equipment, equipCount);
                break;
            case 7:
                displaySalesRecords(sales, saleCount);
                break;
            case 8:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please enter a number from 1-8.\n");
                break;
        }
    }

    return 0;
}