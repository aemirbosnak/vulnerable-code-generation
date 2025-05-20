//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Maximum number of medicines a store can have.
#define MAX_MEDICINES 1000

// A structure to represent medicine in the store.
typedef struct {
    char name[50];
    int quantity;
    float price;
} Medicine;

// The medicine store.
Medicine medicines[MAX_MEDICINES];

// The total number of medicines present in the store.
int totalMedicines = 0;

// Function to add a medicine to the store.
void addMedicine(char* name, int quantity, float price) {
    if(totalMedicines >= MAX_MEDICINES) {
        printf("Sorry, the store is full and cannot add any more medicines.\n");
    } else {
        Medicine* medicine = &medicines[totalMedicines];
        strcpy(medicine->name, name);
        medicine->quantity = quantity;
        medicine->price = price;
        totalMedicines++;
        printf("New medicine %s added to the store.\n", name);
    }
}

// Function to search for a medicine by name.
Medicine* findMedicine(char* name) {
    for(int i=0; i<totalMedicines; i++) {
        Medicine* medicine = &medicines[i];
        if(strcmp(medicine->name, name) == 0) {
            return medicine;
        }
    }
    return NULL;
}

// Function to sell a medicine.
void sellMedicine(char* name, int quantity) {
    Medicine* medicine = findMedicine(name);
    if(medicine == NULL) {
        printf("Sorry, medicine %s is not available in the store.\n", name);
    } else if(medicine->quantity < quantity) {
        printf("Sorry, only %d quantities of medicine %s are available in the store.\n", medicine->quantity, name);
    } else {
        medicine->quantity -= quantity;
        float cost = medicine->price * quantity;
        printf("Sold %d quantities of medicine %s for %0.2f $\n", quantity, name, cost);
    }
}

// Function to display all medicines in the store.
void displayAllMedicines() {
    printf("Name\tQuantity\tPrice ($)\n");
    for(int i=0; i<totalMedicines; i++) {
        Medicine* medicine = &medicines[i];
        printf("%s\t%d\t\t%0.2f\n", medicine->name, medicine->quantity, medicine->price);
    }
}

int main() {
    printf("Welcome to the Medical Store Management System!!!\n");
    while(1) {
        printf("\n");
        printf("Press 1 to add a medicine to the store.\n");
        printf("Press 2 to sell a medicine from the store.\n");
        printf("Press 3 to display all medicines in the store.\n");
        printf("Press 4 to exit.\n");
        printf("\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                printf("\n");
                printf("Enter name of the medicine: ");
                char name[50];
                scanf("%s", name);
                printf("Enter quantity of the medicine: ");
                int quantity;
                scanf("%d", &quantity);
                printf("Enter price of the medicine: ");
                float price;
                scanf("%f", &price);
                addMedicine(name, quantity, price);
                break;
            }
            case 2: {
                printf("\n");
                printf("Enter name of the medicine: ");
                char name[50];
                scanf("%s", name);
                printf("Enter quantity of the medicine: ");
                int quantity;
                scanf("%d", &quantity);
                sellMedicine(name, quantity);
                break;
            }
            case 3: {
                printf("\n");
                displayAllMedicines();
                break;
            }
            case 4: {
                printf("\n");
                printf("Goodbye!!!\n");
                exit(0);
            }
            default: {
                printf("\n");
                printf("Invalid choice, please try again!!!\n");
                break;
            }
        }
    }
    return 0;
}