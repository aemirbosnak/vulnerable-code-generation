//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define NAME_LEN 50
#define DESC_LEN 200

typedef struct {
    char name[NAME_LEN];
    char description[DESC_LEN];
    float price;
    int quantity;
} Medicine;

Medicine store[MAX_MEDICINES];
int count = 0;

void addMedicine() {
    if (count >= MAX_MEDICINES) {
        printf("The horizon is filled; no more stars can shine.\n");
        return;
    }

    Medicine m;
    printf("A swirling whisper beckons you to input the name of the medicine: ");
    scanf(" %[^\n]%*c", m.name);
    printf("A kaleidoscope of thoughts entwines around its description: ");
    scanf(" %[^\n]%*c", m.description);
    printf("Now, let the number dance as you enter the price: ");
    scanf("%f", &m.price);
    printf("Finally, how many dreams dwell in this bottle? Enter the quantity: ");
    scanf("%d", &m.quantity);
    
    store[count++] = m;
    printf("The elixir is trapped in the ether, awaiting its time.\n\n");
}

void viewMedicines() {
    if (count == 0) {
        printf("The shelves are barren, echoing the silence of forgotten dreams.\n");
        return;
    }

    printf("\n--- Dance of Medicines ---\n");
    for (int i = 0; i < count; i++) {
        printf("Medicine %d: %s\n", i + 1, store[i].name);
        printf("Description: %s\n", store[i].description);
        printf("Price: %.2f\n", store[i].price);
        printf("Quantity: %d\n\n", store[i].quantity);
    }
}

void searchMedicine() {
    char name[NAME_LEN];
    printf("Name the medicine that lingers in the shadows: ");
    scanf(" %[^\n]%*c", name);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(store[i].name, name) == 0) {
            printf("Ah! You found it, a jewel in the mist of existence!\n");
            printf("Description: %s\n", store[i].description);
            printf("Price: %.2f\n", store[i].price);
            printf("Quantity: %d\n\n", store[i].quantity);
            return;
        }
    }
    printf("The medicine dances just out of reach, lost to the fog.\n");
}

void purchaseMedicine() {
    char name[NAME_LEN];
    printf("Speak the name of the medicine you wish to summon: ");
    scanf(" %[^\n]%*c", name);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(store[i].name, name) == 0) {
            int qty;
            printf("How many doses of this potion shall you take? ");
            scanf("%d", &qty);
            if (qty <= store[i].quantity) {
                store[i].quantity -= qty;
                printf("A transaction in the cosmos! You purchased %d of %s.\n", qty, store[i].name);
                printf("Remainings are but whispers now: %d left.\n\n", store[i].quantity);
                return;
            } else {
                printf("An abyss of desires unfurls: insufficient quantity.\n");
                return;
            }
        }
    }
    printf("The medicine slips through your fingers like sand.\n");
}

void menu() {
    printf("Welcome to the embrace of the Medical Store Management System.\n");
    printf("1. Add Medicine\n");
    printf("2. View Medicines\n");
    printf("3. Search Medicine\n");
    printf("4. Purchase Medicine\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    do {
        menu();
        printf("Your choice echoes in the void: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: addMedicine(); break;
            case 2: viewMedicines(); break;
            case 3: searchMedicine(); break;
            case 4: purchaseMedicine(); break;
            case 5: printf("The curtain closes; may the dreams continue.\n"); break;
            default: printf("In the labyrinth of choices, this path is unknown.\n"); break;
        }
    } while (choice != 5);
    
    return 0;
}