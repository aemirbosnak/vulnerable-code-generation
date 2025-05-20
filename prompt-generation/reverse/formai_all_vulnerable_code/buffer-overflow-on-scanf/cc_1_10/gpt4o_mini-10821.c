//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} Medicine;

Medicine medicines[MAX_MEDICINES];
int medicineCount = 0;

void addMedicine() {
    if (medicineCount >= MAX_MEDICINES) {
        printf("Medicine inventory is full!\n");
        return;
    }
    Medicine newMed;
    newMed.id = medicineCount + 1; // simple ID based on count
    printf("Enter medicine name: ");
    scanf("%s", newMed.name);
    printf("Enter medicine price: ");
    scanf("%f", &newMed.price);
    printf("Enter medicine quantity: ");
    scanf("%d", &newMed.quantity);

    medicines[medicineCount] = newMed;
    medicineCount++;
    printf("Medicine added successfully!\n");
}

void listMedicines() {
    printf("\n---- List of Medicines ----\n");
    for (int i = 0; i < medicineCount; i++) {
        printf("ID: %d | Name: %s | Price: %.2f | Quantity: %d\n", 
               medicines[i].id, medicines[i].name, medicines[i].price, medicines[i].quantity);
    }
    printf("---------------------------\n");
}

void searchMedicine() {
    char name[50];
    printf("Enter medicine name to search: ");
    scanf("%s", name);
    int found = 0;
    printf("\nSearching for %s...\n", name);
    for (int i = 0; i < medicineCount; i++) {
        if (strcasecmp(medicines[i].name, name) == 0) {
            printf("Found Medicine: ID: %d | Price: %.2f | Quantity: %d\n",
                   medicines[i].id, medicines[i].price, medicines[i].quantity);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Medicine not found!\n");
    }
}

void updateMedicine() {
    int id;
    printf("Enter medicine ID to update: ");
    scanf("%d", &id);
    if (id < 1 || id > medicineCount) {
        printf("Invalid Medicine ID!\n");
        return;
    }
    Medicine *med = &medicines[id - 1];
    printf("Updating Medicine: %s\n", med->name);
    printf("Current Price: %.2f, Current Quantity: %d\n", med->price, med->quantity);
    printf("Enter new price (or -1 to keep current): ");
    float newPrice;
    scanf("%f", &newPrice);
    if (newPrice != -1) {
        med->price = newPrice;
    }
    printf("Enter new quantity (or -1 to keep current): ");
    int newQuantity;
    scanf("%d", &newQuantity);
    if (newQuantity != -1) {
        med->quantity = newQuantity;
    }
    printf("Medicine updated successfully!\n");
}

void displayMenu() {
    printf("\n--- Medical Store Management System ---\n");
    printf("1. Add Medicine\n");
    printf("2. List Medicines\n");
    printf("3. Search Medicine\n");
    printf("4. Update Medicine\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                listMedicines();
                break;
            case 3:
                searchMedicine();
                break;
            case 4:
                updateMedicine();
                break;
            case 5:
                printf("Exiting... Thank you for using the system!\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    } while (choice != 5);
    return 0;
}