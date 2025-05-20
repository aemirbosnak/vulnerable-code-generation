//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: happy
#include <stdio.h>
#include <string.h>

#define MAX_MEDICINES 100

typedef struct {
    char name[50];
    int quantity;
    float price;
} Medicine;

Medicine inventory[MAX_MEDICINES];
int medicineCount = 0;

void addMedicine() {
    if (medicineCount >= MAX_MEDICINES) {
        printf("Oh no! The inventory is full. Can't add more medicines.\n");
        return;
    }

    Medicine newMedicine;
    printf("🎉 Enter medicine name: ");
    scanf("%s", newMedicine.name);
    printf("🎉 Enter quantity: ");
    scanf("%d", &newMedicine.quantity);
    printf("🎉 Enter price: ");
    scanf("%f", &newMedicine.price);

    inventory[medicineCount] = newMedicine;
    medicineCount++;
    printf("🌟 Medicine added successfully! We now have %d medicines in inventory.\n", medicineCount);
}

void viewMedicines() {
    if (medicineCount == 0) {
        printf("😞 The inventory is empty! Add some medicines to see them here.\n");
        return;
    }

    printf("📦 Current Inventory:\n");
    for (int i = 0; i < medicineCount; i++) {
        printf("Name: %s | Quantity: %d | Price: $%.2f\n", 
                inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void searchMedicine() {
    char searchName[50];
    printf("🔍 Enter medicine name to search: ");
    scanf("%s", searchName);

    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(inventory[i].name, searchName) == 0) {
            printf("🎯 Found! Name: %s | Quantity: %d | Price: $%.2f\n", 
                    inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }

    printf("🙁 Sorry, medicine '%s' not found in inventory.\n", searchName);
}

void menu() {
    printf("🎈 Welcome to the Medical Store Management System 🎈\n");
    printf("1. Add Medicine\n");
    printf("2. View Medicines\n");
    printf("3. Search Medicine\n");
    printf("4. Exit\n");
}

int main() {
    int choice;

    while (1) {
        menu();
        printf("🌟 Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                viewMedicines();
                break;
            case 3:
                searchMedicine();
                break;
            case 4:
                printf("🎉 Thank you for using the Medical Store Management System! Bye! 🎉\n");
                return 0;
            default:
                printf("❌ Invalid choice! Please try again.\n");
        }
    }

    return 0;
}