//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: curious
#include <stdio.h>
#include <string.h>

struct medicine {
    char name[50];
    int stock;
    float price;
};

void showMenu();
void addMedicine();
void viewMedicine();
void updateMedicine();
void deleteMedicine();

struct medicine store[100];
int medCount = 0;

int main() {
    int option;
    do {
        showMenu();
        printf("Enter your option: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                addMedicine();
                break;
            case 2:
                viewMedicine();
                break;
            case 3:
                updateMedicine();
                break;
            case 4:
                deleteMedicine();
                break;
            case 5:
                printf("Exiting the program...");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (option != 5);
    return 0;
}

void showMenu() {
    printf("Welcome to the Medical Store Management System\n");
    printf("1. Add Medicine\n");
    printf("2. View Medicine\n");
    printf("3. Update Medicine\n");
    printf("4. Delete Medicine\n");
    printf("5. Exit\n");
}

void addMedicine() {
    struct medicine med;
    printf("Enter medicine name: ");
    scanf("%s", med.name);
    printf("Enter medicine stock: ");
    scanf("%d", &med.stock);
    printf("Enter medicine price: ");
    scanf("%f", &med.price);
    store[medCount] = med;
    medCount++;
    printf("Medicine added successfully.\n");
}

void viewMedicine() {
    printf("List of medicines in the store:\n");
    printf("%-20s %-10s %-10s\n", "Name", "Stock", "Price");
    for (int i = 0; i < medCount; i++) {
        printf("%-20s %-10d %-10.2f\n", store[i].name, store[i].stock, store[i].price);
    }
}

void updateMedicine() {
    char medName[50];
    printf("Enter medicine name to update: ");
    scanf("%s", medName);
    int found = 0;
    for (int i = 0; i < medCount; i++) {
        if (strcmp(store[i].name, medName) == 0) {
            found = 1;
            int option;
            printf("What would you like to update?\n");
            printf("1. Stock\n");
            printf("2. Price\n");
            printf("Enter your option: ");
            scanf("%d", &option);
            switch(option) {
                case 1:
                    printf("Enter new stock value: ");
                    scanf("%d", &store[i].stock);
                    printf("Stock updated successfully.\n");
                    break;
                case 2:
                    printf("Enter new price value: ");
                    scanf("%f", &store[i].price);
                    printf("Price updated successfully.\n");
                    break;
                default:
                    printf("Invalid option. Please try again.\n");
                    break;
            }
            break;
        }
    }
    if (!found) {
        printf("Medicine not found in the store.\n");
    }
}

void deleteMedicine() {
    char medName[50];
    printf("Enter medicine name to delete: ");
    scanf("%s", medName);
    int found = 0;
    for (int i = 0; i < medCount; i++) {
        if (strcmp(store[i].name, medName) == 0) {
            found = 1;
            for (int j = i; j < medCount - 1; j++) {
                store[j] = store[j+1];
            }
            medCount--;
            printf("Medicine deleted successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Medicine not found in the store.\n");
    }
}