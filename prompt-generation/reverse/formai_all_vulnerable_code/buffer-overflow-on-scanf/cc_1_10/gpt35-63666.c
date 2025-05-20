//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_MEDICINES 100

typedef struct {
    char name[50];
    int quantity;
    float price;
} Medicine;

Medicine medicines[MAX_MEDICINES];
int numMedicines;

void menu();
void addMedicine();
void searchMedicine();
void updateMedicine();
void deleteMedicine();
void displayMedicines();

void menu() {

    printf("\n\t\t\t\t1. Add Medicine\n");
    printf("\t\t\t\t2. Search Medicine\n");
    printf("\t\t\t\t3. Update Medicine\n");
    printf("\t\t\t\t4. Delete Medicine\n");
    printf("\t\t\t\t5. Display Medicines\n");
    printf("\t\t\t\t6. Quit\n\n");
    printf("\t\t\tEnter your choice (1-6): ");

}

void addMedicine() {

    if(numMedicines >= MAX_MEDICINES) {
        printf("\n\n\t\t\t\tNo more medicines can be added.\n\n");
        return;
    }

    Medicine med;

    printf("\n\t\t\t\tEnter the name of the medicine: ");
    scanf("%s", med.name);

    printf("\n\t\t\t\tEnter the quantity of the medicine: ");
    scanf("%d", &med.quantity);

    printf("\n\t\t\t\tEnter the price of the medicine: ");
    scanf("%f", &med.price);

    medicines[numMedicines++] = med;

    printf("\n\n\t\t\t\tMedicine added successfully!\n\n");

}

void searchMedicine() {

    char name[50];
    int found = 0;

    printf("\n\t\t\t\tEnter the name of the medicine to search: ");
    scanf("%s", name);

    for(int i = 0; i < numMedicines; i++) {
        if(strcmp(medicines[i].name, name) == 0) {
            printf("\n\t\t\t\tName: %s\n", medicines[i].name);
            printf("\n\t\t\t\tQuantity: %d\n", medicines[i].quantity);
            printf("\n\t\t\t\tPrice: $%.2f\n\n", medicines[i].price);
            found = 1;
        }
    }

    if(!found) {
        printf("\n\n\t\t\t\tMedicine not found!\n\n");
    }

}

void updateMedicine() {

    char name[50];
    int found = 0;

    printf("\n\t\t\t\tEnter the name of the medicine to update: ");
    scanf("%s", name);

    for(int i = 0; i < numMedicines; i++) {
        if(strcmp(medicines[i].name, name) == 0) {

            printf("\n\t\t\t\tName: %s\n", medicines[i].name);
            printf("\t\t\t\tQuantity: %d\n", medicines[i].quantity);
            printf("\t\t\t\tPrice: $%.2f\n\n", medicines[i].price);

            printf("\t\t\t\tEnter the updated name of the medicine: ");
            scanf("%s", medicines[i].name);

            printf("\n\t\t\t\tEnter the updated quantity of the medicine: ");
            scanf("%d", &medicines[i].quantity);

            printf("\n\t\t\t\tEnter the updated price of the medicine: ");
            scanf("%f", &medicines[i].price);

            printf("\n\t\t\t\tMedicine updated successfully!\n\n");

            found = 1;
        }
    }

    if(!found) {
        printf("\n\n\t\t\t\tMedicine not found!\n\n");
    }

}

void deleteMedicine() {

    char name[50];
    int found = 0;

    printf("\n\t\t\t\tEnter the name of the medicine to delete: ");
    scanf("%s", name);

    for(int i = 0; i < numMedicines; i++) {
        if(strcmp(medicines[i].name, name) == 0) {
            for(int j = i; j < numMedicines - 1; j++) {
                medicines[j] = medicines[j+1];
            }
            numMedicines--;
            printf("\n\n\t\t\t\tMedicine deleted successfully!\n\n");
            found = 1;
        }
    }

    if(!found) {
        printf("\n\n\t\t\t\tMedicine not found!\n\n");
    }

}

void displayMedicines() {

    if(numMedicines == 0) {
        printf("\n\n\t\t\t\tNo medicines found!\n\n");
    } else {
        printf("\n\n\t\t\t\tMedicine Name\t\tQuantity\t\tPrice\n\n");
        for(int i = 0; i < numMedicines; i++) {
            printf("\t\t\t\t%s\t\t\t%d\t\t\t$%.2f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
        }
        printf("\n\n");
    }

}

int main() {

    int choice;

    do {
        menu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                searchMedicine();
                break;
            case 3:
                updateMedicine();
                break;
            case 4:
                deleteMedicine();
                break;
            case 5:
                displayMedicines();
                break;
            case 6:
                printf("\n\n\t\t\t\tGoodbye!\n\n");
                break;
            default:
                printf("\n\n\t\t\t\tInvalid choice! Please try again.\n\n");
        }
    } while(choice != 6);

    return 0;

}