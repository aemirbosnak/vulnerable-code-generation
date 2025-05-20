//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct Medicine {
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Medicine;

// Declarations of functions for our sweet lovers' tale
void addMedicine(Medicine *store, int *count);
void displayMedicines(Medicine *store, int count);
void searchMedicine(Medicine *store, int count);
void loveLament();

int main() {
    Medicine store[MAX_PRODUCTS];
    int count = 0;
    int choice;
    
    while (1) {
        printf("O, gentle traveler! What dost thou wish?\n");
        printf("1. Add Medicine\n2. Display Medicines\n3. Search Medicine\n4. Exit\n");
        printf("Enter thy choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine(store, &count);
                break;
            case 2:
                displayMedicines(store, count);
                break;
            case 3:
                searchMedicine(store, count);
                break;
            case 4:
                printf("Parting is such sweet sorrow! Exiting...\n");
                return 0;
            default:
                loveLament(); // Let the lament for invalid choice begin!
        }
    }
    return 0;
}

void addMedicine(Medicine *store, int *count) {
    if (*count >= MAX_PRODUCTS) {
        printf("Thou hast reached maximum capacity of medicines in thy store!\n");
        return;
    }
    
    printf("Enter the name of the medicine: ");
    scanf("%s", store[*count].name);
    printf("Enter its quantity: ");
    scanf("%d", &store[*count].quantity);
    printf("Enter its price: ");
    scanf("%f", &store[*count].price);
    
    (*count)++;
    printf("Ah, a new medicine hath been added! %s, quantity: %d, price: %.2f\n",
           store[*count - 1].name, store[*count - 1].quantity, store[*count - 1].price);
}

void displayMedicines(Medicine *store, int count) {
    if (count == 0) {
        printf("Alas! There are no medicines to display in this fair store.\n");
        return;
    }
    printf("Here lie the treasures of our apothecary:\n");
    for (int i = 0; i < count; i++) {
        printf("Medicine: %s, Quantity: %d, Price: %.2f\n",
               store[i].name, store[i].quantity, store[i].price);
    }
}

void searchMedicine(Medicine *store, int count) {
    char query[NAME_LENGTH];
    printf("What potion dost thou seek? ");
    scanf("%s", query);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(store[i].name, query) == 0) {
            printf("Behold! Thy sought-after medicine: %s, Quantity: %d, Price: %.2f\n",
                   store[i].name, store[i].quantity, store[i].price);
            return;
        }
    }
    printf("O cruel fate! The medicine %s is not in our store.\n", query);
}

void loveLament() {
    printf("O, what misfortune hath befallen us? Choose wisely, dear friend!\n");
}