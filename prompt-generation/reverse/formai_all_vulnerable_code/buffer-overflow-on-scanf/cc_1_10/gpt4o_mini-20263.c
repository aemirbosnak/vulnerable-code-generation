//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Medicine;

typedef struct {
    Medicine medicines[MAX_MEDICINES];
    int count;
} MedicalStore;

void initializeStore(MedicalStore *store) {
    store->count = 0;
}

void addMedicine(MedicalStore *store) {
    if (store->count < MAX_MEDICINES) {
        Medicine med;
        printf("Enter the name of the medicine ( dreamy whispers evade reality ): ");
        scanf(" %[^\n]%*c", med.name);
        printf("Enter the quantity (where numbers dance in unison): ");
        scanf("%d", &med.quantity);
        printf("Enter the price (as the stars whisper their secrets): ");
        scanf("%f", &med.price);
        store->medicines[store->count++] = med;
        printf("The medicine floats into existence, shimmering like an ethereal mist.\n");
    } else {
        printf("The store is filled with medicines, like dreams that never fade.\n");
    }
}

void displayMedicines(const MedicalStore *store) {
    if (store->count == 0) {
        printf("The shelves are barren, draped in the thin veil of forgotten memories.\n");
        return;
    }
    printf("Medicines in the store:\n");
    for (int i = 0; i < store->count; i++) {
        printf("%d. %s - Qty: %d, Price: %.2f\n", i + 1, store->medicines[i].name,
               store->medicines[i].quantity, store->medicines[i].price);
    }
    printf("They shimmer like the residual sparks of a shooting star...\n");
}

void sellMedicine(MedicalStore *store) {
    char medName[NAME_LENGTH];
    printf("Enter the name of the medicine you wish to purchase (as time unveils its treasures): ");
    scanf(" %[^\n]%*c", medName);
    for (int i = 0; i < store->count; i++) {
        if (strcmp(store->medicines[i].name, medName) == 0) {
            int quantity;
            printf("Whisper the quantity you desire: ");
            scanf("%d", &quantity);
            if (quantity <= store->medicines[i].quantity) {
                store->medicines[i].quantity -= quantity;
                float total = quantity * store->medicines[i].price;
                printf("You have purchased %d of %s for a total of %.2f... the universe thanks you.\n",
                       quantity, store->medicines[i].name, total);
                return;
            } else {
                printf("The cosmos is unkind! Insufficient quantity for %s.\n", medName);
                return;
            }
        }
    }
    printf("The medicine seems to dissolve into the ether... not found.\n");
}

void queryMedicine(MedicalStore *store) {
    char medName[NAME_LENGTH];
    printf("Inquire about the elusive medicine's essence: ");
    scanf(" %[^\n]%*c", medName);
    for (int i = 0; i < store->count; i++) {
        if (strcmp(store->medicines[i].name, medName) == 0) {
            printf("%s exists with quantity %d and price %.2f, like an echo of a distant memory.\n",
                   store->medicines[i].name, store->medicines[i].quantity, store->medicines[i].price);
            return;
        }
    }
    printf("What is lost is seldom found... %s is not part of this reality.\n", medName);
}

void surrealMenu() {
    printf("\nWelcome to the Surreal Medical Store!\n");
    printf("1. Add Medicine\n");
    printf("2. Display Medicines\n");
    printf("3. Sell Medicine\n");
    printf("4. Query Medicine\n");
    printf("5. Exit into oblivion\n");
}

int main() {
    MedicalStore store;
    initializeStore(&store);
    int choice;

    while (1) {
        surrealMenu();
        printf("Enter your choice (as the mind wanders): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine(&store);
                break;
            case 2:
                displayMedicines(&store);
                break;
            case 3:
                sellMedicine(&store);
                break;
            case 4:
                queryMedicine(&store);
                break;
            case 5:
                printf("As you exit, the echoes of your choices linger... goodbye!\n");
                return 0;
            default:
                printf("The path is unclear, choose again...\n");
        }
    }

    return 0;
}