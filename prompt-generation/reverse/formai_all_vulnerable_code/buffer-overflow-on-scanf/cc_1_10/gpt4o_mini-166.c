//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for the potion
typedef struct Potion {
    char name[50];
    int quantity;
    float price;
} Potion;

// Function to display the potions in the store
void displayPotions(Potion potions[], int count) {
    printf("\n--- Potion Shop Inventory ---\n");
    printf("Name\t\tQuantity\tPrice\n");
    printf("-------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t\t%d\t\t%.2f\n", potions[i].name, potions[i].quantity, potions[i].price);
    }
}

// Function to add a potion to the inventory
void addPotion(Potion potions[], int *count) {
    if (*count >= 100) {
        printf("Alas! The potion store is full!\n");
        return;
    }
    Potion newPotion;
    printf("Enter the name of the new potion: ");
    scanf(" %[^\n]", newPotion.name);
    printf("Enter the quantity: ");
    scanf("%d", &newPotion.quantity);
    printf("Enter the price: ");
    scanf("%f", &newPotion.price);
    
    potions[*count] = newPotion;
    (*count)++;
    printf("Potion added to the inventory!\n");
}

// Function to sell a potion
void sellPotion(Potion potions[], int count) {
    char name[50];
    printf("Enter the name of the potion to sell: ");
    scanf(" %[^\n]", name);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(potions[i].name, name) == 0) {
            if (potions[i].quantity > 0) {
                potions[i].quantity--;
                printf("Potion sold! Remaining quantity of %s: %d\n", potions[i].name, potions[i].quantity);
                return;
            } else {
                printf("Alas! There are no potions of %s left to sell.\n", potions[i].name);
                return;
            }
        }
    }
    printf("The potion \"%s\" is not found in the inventory.\n", name);
}

// Function to search for a potion
void searchPotion(Potion potions[], int count) {
    char name[50];
    printf("Enter the name of the potion to search for: ");
    scanf(" %[^\n]", name);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(potions[i].name, name) == 0) {
            printf("Potion found! Name: %s, Quantity: %d, Price: %.2f\n", potions[i].name, potions[i].quantity, potions[i].price);
            return;
        }
    }
    printf("The potion \"%s\" is not found in the inventory.\n", name);
}

// Main function to run the potion management system
int main() {
    Potion potions[100];
    int potionCount = 0;
    int choice;

    do {
        printf("\n--- Medieval Potion Shop Management System ---\n");
        printf("1. Display Potions\n");
        printf("2. Add a Potion\n");
        printf("3. Sell a Potion\n");
        printf("4. Search for a Potion\n");
        printf("5. Exit\n");
        printf("Select your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayPotions(potions, potionCount);
                break;
            case 2:
                addPotion(potions, &potionCount);
                break;
            case 3:
                sellPotion(potions, potionCount);
                break;
            case 4:
                searchPotion(potions, potionCount);
                break;
            case 5:
                printf("Farewell, merchant of potions!\n");
                break;
            default:
                printf("Alas! Thou hast entered an invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}