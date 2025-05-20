//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

typedef struct {
    char name[50];
    float price;
    int quantity;
} Medicine;

typedef struct {
    Medicine medicines[MAX_MEDICINES];
    int count;
} MedicalStore;

void addMedicine(MedicalStore *store) {
    if (store->count == MAX_MEDICINES) {
        printf("Alas! The store is filled. No more medicines can be added.\n");
        return;
    }

    Medicine newMed;
    printf("Enter the name of the medicine: ");
    scanf(" %[^\n]%*c", newMed.name);
    printf("Enter the price of the medicine: ");
    scanf("%f", &newMed.price);
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &newMed.quantity);

    store->medicines[store->count++] = newMed;
    printf("O joyous day! %s has been added to the apothecary!\n", newMed.name);
}

void removeMedicine(MedicalStore *store) {
    char name[50];
    printf("Which medicine dost thou wish to remove? Enter the name: ");
    scanf(" %[^\n]%*c", name);

    for (int i = 0; i < store->count; i++) {
        if (strcmp(store->medicines[i].name, name) == 0) {
            store->medicines[i] = store->medicines[store->count - 1];
            store->count--;
            printf("Farewell, dear %s! Thou art removed from our stock.\n", name);
            return;
        }
    }
    printf("Alas! No such medicine found in the store.\n");
}

void displayMedicines(MedicalStore *store) {
    if (store->count == 0) {
        printf("O woe! No medicines available in the store.\n");
        return;
    }

    printf("List of medicines in our store:\n");
    for (int i = 0; i < store->count; i++) {
        printf("%d. %s - Price: %.2f, Quantity: %d\n", i + 1, store->medicines[i].name, store->medicines[i].price, store->medicines[i].quantity);
    }
}

void purchaseMedicine(MedicalStore *store) {
    char name[50];
    printf("What dost thou wish to purchase? Speak the name of the medicine: ");
    scanf(" %[^\n]%*c", name);

    for (int i = 0; i < store->count; i++) {
        if (strcmp(store->medicines[i].name, name) == 0) {
            if (store->medicines[i].quantity > 0) {
                store->medicines[i].quantity--;
                printf("Thou hast purchased %s for %.2f! Only %d left in stock.\n", name, store->medicines[i].price, store->medicines[i].quantity);
                return;
            } else {
                printf("O dear! %s is no longer in stock.\n", name);
                return;
            }
        }
    }
    printf("O sorrow! No such medicine in our store.\n");
}

int main() {
    MedicalStore store;
    store.count = 0;
    int choice;

    do {
        printf("\nWelcome to the Apothecary of Verona\n");
        printf("1. Add Medicine\n");
        printf("2. Remove Medicine\n");
        printf("3. Display Medicines\n");
        printf("4. Purchase Medicine\n");
        printf("5. Exit\n");
        printf("Choose thy fate: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine(&store);
                break;
            case 2:
                removeMedicine(&store);
                break;
            case 3:
                displayMedicines(&store);
                break;
            case 4:
                purchaseMedicine(&store);
                break;
            case 5:
                printf("Goodbye, dear patron! Until we meet again!\n");
                break;
            default:
                printf("O vexing choice! Please choose a valid option.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}