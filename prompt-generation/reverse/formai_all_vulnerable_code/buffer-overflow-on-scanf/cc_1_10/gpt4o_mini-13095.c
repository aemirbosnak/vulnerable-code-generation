//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
    double price;
} Medicine;

Medicine medicines[MAX_MEDICINES];
int medicine_count = 0;

void addMedicine();
void displayMedicines();
void searchMedicine();
void clearScreen();

int main() {
    int choice;

    do {
        clearScreen();
        printf("Welcome to the Medical Store Management System!\n");
        printf("1. Add Medicine\n");
        printf("2. Display All Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                displayMedicines();
                break;
            case 3:
                searchMedicine();
                break;
            case 4:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }

        if (choice != 4) {
            printf("Press Enter to continue...");
            getchar(); // to consume the newline after choice
            getchar(); // waiting for the user to press Enter
        }

    } while (choice != 4);

    return 0;
}

void addMedicine() {
    if (medicine_count >= MAX_MEDICINES) {
        printf("Unable to add more medicines. Maximum limit reached!\n");
        return;
    }

    Medicine new_medicine;

    printf("Enter medicine name: ");
    getchar(); // to consume the newline character
    fgets(new_medicine.name, NAME_LENGTH, stdin);
    new_medicine.name[strcspn(new_medicine.name, "\n")] = 0; // Remove newline

    printf("Enter quantity: ");
    scanf("%d", &new_medicine.quantity);

    printf("Enter price: ");
    scanf("%lf", &new_medicine.price);

    medicines[medicine_count++] = new_medicine;
    printf("Medicine added successfully!\n");
}

void displayMedicines() {
    if (medicine_count == 0) {
        printf("No medicines available!\n");
        return;
    }

    printf("\nList of Medicines:\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < medicine_count; i++) {
        printf("Medicine %d:\n", i + 1);
        printf("Name: %s\n", medicines[i].name);
        printf("Quantity: %d\n", medicines[i].quantity);
        printf("Price: $%.2f\n", medicines[i].price);
        printf("------------------------------------------------\n");
    }
}

void searchMedicine() {
    if (medicine_count == 0) {
        printf("No medicines available to search.\n");
        return;
    }

    char search_name[NAME_LENGTH];
    printf("Enter the name of the medicine to search: ");
    getchar(); // to consume the newline character
    fgets(search_name, NAME_LENGTH, stdin);
    search_name[strcspn(search_name, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < medicine_count; i++) {
        if (strcasecmp(medicines[i].name, search_name) == 0) {
            printf("Medicine Found:\n");
            printf("Name: %s\n", medicines[i].name);
            printf("Quantity: %d\n", medicines[i].quantity);
            printf("Price: $%.2f\n", medicines[i].price);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Medicine '%s' not found!\n", search_name);
    }
}

void clearScreen() {
    printf("\033[H\033[J"); // ANSI escape code to clear the screen
}