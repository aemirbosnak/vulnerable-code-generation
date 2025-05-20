//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define constant variables */
#define MAX_MEDICINES 50
#define MAX_NAME_LEN 30
#define MAX_PRICE_LEN 10

/* Define structure for medicine */
struct Medicine {
    char name[MAX_NAME_LEN];
    float price;
};

/* Declare global variables */
struct Medicine medicines[MAX_MEDICINES];
int numMedicines = 0;

/* Define function to add medicine */
void addMedicine() {
    if (numMedicines >= MAX_MEDICINES) {
        printf("Maximum number of medicines reached!\n");
        return;
    }

    struct Medicine newMedicine;

    printf("Enter medicine name: ");
    scanf("%s", newMedicine.name);

    printf("Enter medicine price: ");
    char priceStr[MAX_PRICE_LEN];
    scanf("%s", priceStr);
    newMedicine.price = atof(priceStr);

    medicines[numMedicines] = newMedicine;
    numMedicines++;
}

/* Define function to remove medicine */
void removeMedicine() {
    if (numMedicines == 0) {
        printf("No medicines to remove!\n");
        return;
    }

    char name[MAX_NAME_LEN];
    printf("Enter medicine name to remove: ");
    scanf("%s", name);

    int foundIndex = -1;
    for (int i = 0; i < numMedicines; i++) {
        if (strcmp(name, medicines[i].name) == 0) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        printf("Medicine not found!\n");
        return;
    }

    for (int i = foundIndex; i < numMedicines - 1; i++) {
        medicines[i] = medicines[i + 1];
    }
    numMedicines--;

    printf("Medicine removed!\n");
}

/* Define function to view all medicines */
void viewMedicines() {
    if (numMedicines == 0) {
        printf("No medicines to view!\n");
        return;
    }

    printf("Medicines:\n");
    for (int i = 0; i < numMedicines; i++) {
        printf("%s - %.2f\n", medicines[i].name, medicines[i].price);
    }
}

/* Main function */
int main() {
    int choice;
    do {
        printf("\nMedical Store Management System\n");
        printf("==============================\n");
        printf("1. Add medicine\n");
        printf("2. Remove medicine\n");
        printf("3. View all medicines\n");
        printf("4. Quit\n");

        printf("\nEnter choice: ");
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
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 4);

    return 0;
}