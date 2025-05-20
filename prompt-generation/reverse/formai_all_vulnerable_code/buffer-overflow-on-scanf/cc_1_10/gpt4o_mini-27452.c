//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

// Structure to hold medicine details
struct Medicine {
    char name[50];
    float price;
    int quantity;
};

// Function prototypes
void addMedicine(struct Medicine medicines[], int *count);
void displayMedicines(struct Medicine medicines[], int count);
void searchMedicine(struct Medicine medicines[], int count);
void updateMedicineQuantity(struct Medicine medicines[], int count);
void deleteMedicine(struct Medicine medicines[], int *count);
void displayMenu();

int main() {
    struct Medicine medicines[MAX_MEDICINES];
    int count = 0;
    int choice;

    printf("🎉 Welcome to the C Medical Store Management System! 🎉\n");

    do {
        displayMenu();
        printf("Please enter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine(medicines, &count);
                break;
            case 2:
                displayMedicines(medicines, count);
                break;
            case 3:
                searchMedicine(medicines, count);
                break;
            case 4:
                updateMedicineQuantity(medicines, count);
                break;
            case 5:
                deleteMedicine(medicines, &count);
                break;
            case 6:
                printf("Exiting the system... Goodbye! 👋\n");
                break;
            default:
                printf("😕 Invalid choice! Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}

void displayMenu() {
    printf("\n🌈 Menu 🌈\n");
    printf("1. Add Medicine\n");
    printf("2. Display Medicines\n");
    printf("3. Search Medicine\n");
    printf("4. Update Medicine Quantity\n");
    printf("5. Delete Medicine\n");
    printf("6. Exit\n");
}

void addMedicine(struct Medicine medicines[], int *count) {
    if (*count >= MAX_MEDICINES) {
        printf("😢 Sorry, can't add more medicines. The inventory is full!\n");
        return;
    }

    printf("Enter medicine name: ");
    scanf(" %[^\n]", medicines[*count].name);
    printf("Enter price: ");
    scanf("%f", &medicines[*count].price);
    printf("Enter quantity: ");
    scanf("%d", &medicines[*count].quantity);
    (*count)++;

    printf("✨ Medicine '%s' added successfully! 🎊\n", medicines[*count - 1].name);
}

void displayMedicines(struct Medicine medicines[], int count) {
    if (count == 0) {
        printf("😮 No medicines available in the inventory!\n");
        return;
    }

    printf("\n📋 Medicines in Inventory 📋\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Name: %s | Price: $%.2f | Quantity: %d\n", 
               i + 1, medicines[i].name, medicines[i].price, medicines[i].quantity);
    }
}

void searchMedicine(struct Medicine medicines[], int count) {
    char name[50];
    printf("Enter medicine name to search: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            printf("🎉 Found Medicine: %s | Price: $%.2f | Quantity: %d\n", 
                   medicines[i].name, medicines[i].price, medicines[i].quantity);
            return;
        }
    }
    printf("😔 Medicine '%s' not found!\n", name);
}

void updateMedicineQuantity(struct Medicine medicines[], int count) {
    char name[50];
    printf("Enter medicine name to update quantity: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            int newQuantity;
            printf("Current quantity: %d. Enter new quantity: ", medicines[i].quantity);
            scanf("%d", &newQuantity);
            medicines[i].quantity = newQuantity;
            printf("✨ Quantity for '%s' updated to %d! 🎉\n", medicines[i].name, newQuantity);
            return;
        }
    }
    printf("😔 Medicine '%s' not found for updating!\n", name);
}

void deleteMedicine(struct Medicine medicines[], int *count) {
    char name[50];
    printf("Enter medicine name to delete: ");
    scanf(" %[^\n]", name);
    
    for (int i = 0; i < *count; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            for (int j = i; j < *count - 1; j++) {
                medicines[j] = medicines[j + 1];
            }
            (*count)--;
            printf("🗑️ Medicine '%s' deleted successfully! 🎉\n", name);
            return;
        }
    }
    printf("😔 Medicine '%s' not found for deletion!\n", name);
}