//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define STORES 3
#define GENRES 4

void inputInventory(int inventory[STORES][GENRES]);
void displayInventory(int inventory[STORES][GENRES]);
void updateInventory(int inventory[STORES][GENRES]);
void totalBooksByGenre(int inventory[STORES][GENRES]);
void totalBooksByStore(int inventory[STORES][GENRES]);

int main() {
    int inventory[STORES][GENRES] = {0}; // Initialize inventory to 0
    int choice;

    while (1) {
        printf("\n--- Bookstore Inventory Management ---\n");
        printf("1. Input Inventory\n");
        printf("2. Display Inventory\n");
        printf("3. Update Inventory\n");
        printf("4. Total Books by Genre\n");
        printf("5. Total Books by Store\n");
        printf("6. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputInventory(inventory);
                break;
            case 2:
                displayInventory(inventory);
                break;
            case 3:
                updateInventory(inventory);
                break;
            case 4:
                totalBooksByGenre(inventory);
                break;
            case 5:
                totalBooksByStore(inventory);
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    return 0;
}

void inputInventory(int inventory[STORES][GENRES]) {
    printf("Input the inventory for each store and genre:\n");
    for (int i = 0; i < STORES; i++) {
        printf("Store %d:\n", i + 1);
        for (int j = 0; j < GENRES; j++) {
            printf("Enter number of books for Genre %d: ", j + 1);
            scanf("%d", &inventory[i][j]);
        }
    }
    printf("Inventory input successful!\n");
}

void displayInventory(int inventory[STORES][GENRES]) {
    printf("\nCurrent Inventory:\n");
    printf("           Genre 1  Genre 2  Genre 3  Genre 4\n");
    for (int i = 0; i < STORES; i++) {
        printf("Store %d: ", i + 1);
        for (int j = 0; j < GENRES; j++) {
            printf("%-10d ", inventory[i][j]);
        }
        printf("\n");
    }
}

void updateInventory(int inventory[STORES][GENRES]) {
    int store, genre, amount;
    printf("Enter Store Number (1-%d): ", STORES);
    scanf("%d", &store);
    printf("Enter Genre Number (1-%d): ", GENRES);
    scanf("%d", &genre);
    printf("Enter amount to add (use negative value to subtract): ");
    scanf("%d", &amount);

    if (store >= 1 && store <= STORES && genre >= 1 && genre <= GENRES) {
        inventory[store - 1][genre - 1] += amount;
        printf("Updated inventory for Store %d, Genre %d. New amount: %d\n", 
                store, genre, inventory[store - 1][genre - 1]);
    } else {
        printf("Invalid store or genre number!\n");
    }
}

void totalBooksByGenre(int inventory[STORES][GENRES]) {
    int totals[GENRES] = {0};
    printf("Total book counts by genre:\n");
    
    for (int j = 0; j < GENRES; j++) {
        for (int i = 0; i < STORES; i++) {
            totals[j] += inventory[i][j];
        }
        printf("Genre %d: %d books\n", j + 1, totals[j]);
    }
}

void totalBooksByStore(int inventory[STORES][GENRES]) {
    printf("Total book counts by store:\n");
    for (int i = 0; i < STORES; i++) {
        int total = 0;
        for (int j = 0; j < GENRES; j++) {
            total += inventory[i][j];
        }
        printf("Store %d: %d books\n", i + 1, total);
    }
}