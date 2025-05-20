//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

typedef struct {
    char name[50];
    int quantity;
    float price;
} Medicine;

Medicine inventory[MAX_MEDICINES];
int count = 0;

void addMedicine() {
    if (count >= MAX_MEDICINES) {
        printf("\033[31m[ERROR]\033[0m Inventory full! Can't add more medicines.\n");
        return;
    }

    Medicine med;
    printf("Enter medicine name: ");
    scanf("%s", med.name);
    printf("Enter quantity: ");
    scanf("%d", &med.quantity);
    printf("Enter price: ");
    scanf("%f", &med.price);

    inventory[count] = med;
    count++;
    printf("\033[32m[SUCCESS]\033[0m Medicine added successfully.\n");
}

void removeMedicine() {
    char name[50];
    printf("Enter medicine name to remove: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < count - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            count--;
            printf("\033[32m[SUCCESS]\033[0m Medicine removed successfully.\n");
            return;
        }
    }
    printf("\033[31m[ERROR]\033[0m Medicine not found in inventory.\n");
}

void listMedicines() {
    printf("\033[1;34m==================== MEDICINE LIST ====================\033[0m\n");
    for (int i = 0; i < count; i++) {
        printf("\033[35m%s\033[0m - Quantity: \033[33m%d\033[0m, Price: \033[36m%.2f\033[0m\n",
               inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    printf("\033[1;34m=======================================================\033[0m\n");
}

void displayMenu() {
    printf("\n\033[1;32m======= MEDICAL STORE MANAGEMENT SYSTEM =======\033[0m\n");
    printf("1. Add Medicine\n");
    printf("2. Remove Medicine\n");
    printf("3. List Medicines\n");
    printf("4. Exit\n");
    printf( "\033[1;32m==========================================\033[0m\n");
    printf("Enter your choice: ");
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
                removeMedicine();
                break;
            case 3:
                listMedicines();
                break;
            case 4:
                printf("\033[31mExiting the system...\033[0m\n");
                break;
            default:
                printf("\033[31m[ERROR]\033[0m Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}