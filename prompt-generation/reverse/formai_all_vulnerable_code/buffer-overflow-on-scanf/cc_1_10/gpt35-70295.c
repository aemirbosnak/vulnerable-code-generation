//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    char name[50];
    char manufacturer[50];
    int quantity;
    float price;
};

void add_medicine(struct medicine *meds, int size) {
    printf("\nEnter medicine details:\n");
    printf("Name: ");
    scanf("%s", meds[size].name);
    printf("Manufacturer: ");
    scanf("%s", meds[size].manufacturer);
    printf("Quantity: ");
    scanf("%d", &meds[size].quantity);
    printf("Price: ");
    scanf("%f", &meds[size].price);
}

void display_medicines(struct medicine *meds, int size) {
    printf("\nMedicine details:\n");
    printf("%-20s%-20s%-15s%-15s\n", "Name", "Manufacturer", "Quantity", "Price");
    for (int i=0; i<size; i++) {
        printf("%-20s%-20s%-15d%-15.2f\n", meds[i].name, meds[i].manufacturer, meds[i].quantity, meds[i].price);
    }
}

void search_medicine(struct medicine *meds, int size) {
    char search_name[50];
    printf("\nEnter medicine name: ");
    scanf("%s", search_name);
    for (int i=0; i<size; i++) {
        if (strcmp(meds[i].name, search_name) == 0) {
            printf("\nMedicine details:\n");
            printf("%-20s%-20s%-15s%-15s\n", "Name", "Manufacturer", "Quantity", "Price");
            printf("%-20s%-20s%-15d%-15.2f\n", meds[i].name, meds[i].manufacturer, meds[i].quantity, meds[i].price);
            return;
        }
    }
    printf("\nMedicine not found!\n");
}

void sell_medicine(struct medicine *meds, int size) {
    char sell_name[50];
    int sell_qty;
    printf("\nEnter medicine name: ");
    scanf("%s", sell_name);
    for (int i=0; i<size; i++) {
        if (strcmp(meds[i].name, sell_name) == 0) {
            printf("\nEnter quantity to sell: ");
            scanf("%d", &sell_qty);
            if (sell_qty <= meds[i].quantity) {
                meds[i].quantity -= sell_qty;
                printf("\nSold %d x %s for %.2f\n", sell_qty, meds[i].name, (meds[i].price * sell_qty));
                return;
            } else {
                printf("\nInsufficient quantity of %s!\n", sell_name);
                return;
            }
        }
    }
    printf("\nMedicine not found!\n");
}

int main() {
    struct medicine *meds = malloc(sizeof(struct medicine));
    int choice, size=0;
    do {
        printf("\nMenu:");
        printf("\n1. Add medicine");
        printf("\n2. Display medicines");
        printf("\n3. Search medicine");
        printf("\n4. Sell medicine");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf ("%d", &choice);
        switch (choice) {
            case 1:
                size++;
                meds = realloc(meds, sizeof(struct medicine) * (size+1));
                add_medicine(meds, size-1);
                break;
            case 2:
                display_medicines(meds, size);
                break;
            case 3:
                search_medicine(meds, size);
                break;
            case 4:
                sell_medicine(meds, size);
                break;
            case 5:
                free(meds);
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    } while (choice != 5);
    return 0;
}