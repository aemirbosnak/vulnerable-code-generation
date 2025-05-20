//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MAX_STR_LEN 50
#define MAX_MEDICINES 100

typedef struct {
    char name[MAX_STR_LEN];
    int quantity;
    float price;
} Medicine;

Medicine medicines[MAX_MEDICINES];
int numMedicines = 0;

bool authenticate() {
    char username[MAX_STR_LEN], password[MAX_STR_LEN];
    printf("Please enter your username: ");
    scanf("%s", username);
    printf("Please enter your password: ");
    scanf("%s", password);

    // Check if the username and password match
    if (strcmp(username, "admin") == 0 && strcmp(password, "pass123") == 0) {
        printf("Authentication successful!\n");
        return true;
    }
    printf("Authentication failed!\n");
    return false;
}

void addMedicine() {
    if (numMedicines == MAX_MEDICINES) {
        printf("Max capacity reached! Cannot add more medicines.\n");
        return;
    }

    char name[MAX_STR_LEN];
    int quantity;
    float price;
    printf("Please enter medicine name: ");
    scanf("%s", name);
    printf("Please enter medicine quantity: ");
    scanf("%d", &quantity);
    printf("Please enter medicine price: ");
    scanf("%f", &price);

    Medicine newMedicine = {0};
    strcpy(newMedicine.name, name);
    newMedicine.quantity = quantity;
    newMedicine.price = price;

    medicines[numMedicines++] = newMedicine;
    printf("Medicine added successfully!\n");
}

void removeMedicine() {
    char name[MAX_STR_LEN];
    printf("Please enter medicine name to remove: ");
    scanf("%s", name);

    for (int i = 0; i < numMedicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            // Medicine found, remove it
            for (int j = i; j < numMedicines - 1; j++) {
                medicines[j] = medicines[j+1];
            }
            numMedicines--;
            printf("Medicine removed successfully!\n");
            return;
        }
    }

    printf("Medicine not found!\n");
}

void viewMedicines() {
    printf("------------------------------\n");
    printf("Name\t\tQty\tPrice\n");
    printf("------------------------------\n");
    for (int i = 0; i < numMedicines; i++) {
        printf("%s\t\t%d\t%.2f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
    }
    printf("------------------------------\n");
}

void sellMedicine() {
    char name[MAX_STR_LEN];
    printf("Please enter medicine name to sell: ");
    scanf("%s", name);

    for (int i = 0; i < numMedicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            // Medicine found, sell it
            int quantity;
            printf("Please enter quantity to sell: ");
            scanf("%d", &quantity);

            if (quantity > medicines[i].quantity) {
                printf("Not enough quantity available!\n");
                return;
            }

            // Update medicine quantity and display invoice
            medicines[i].quantity -= quantity;
            printf("------------------------------\n");
            printf("Invoice\n");
            printf("------------------------------\n");
            printf("Name\t\tQty\tPrice\tTotal\n");
            printf("%s\t\t%d\t%.2f\t%.2f\n", medicines[i].name, quantity, medicines[i].price, medicines[i].price*quantity);
            printf("------------------------------\n");
            printf("Total\t\t\t\t%.2f\n", medicines[i].price*quantity);
            printf("------------------------------\n");
            return;
        }
    }

    printf("Medicine not found!\n");
}

void showMenu() {
    printf("\n1. Add medicine\n");
    printf("2. Remove medicine\n");
    printf("3. View medicines\n");
    printf("4. Sell medicine\n");
    printf("5. Exit\n");
    printf("Please enter your choice: ");
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    printf("Welcome to Paranoid's Medical Store Management System!\n");

    if (!authenticate()) {
        printf("Goodbye!\n");
        return 0;
    }

    int choice;
    while (true) {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                removeMedicine();
                break;
            case 3:
                viewMedicines();
                break;
            case 4:
                sellMedicine();
                break;
            case 5:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}