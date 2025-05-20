//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: irregular
#include<stdio.h>
#include<stdlib.h>

struct medicine {
    char name[50];
    float price;
    int quantity;
};

typedef struct medicine Medicine;

Medicine* createMedicine(char* name, float price, int quantity) {
    Medicine* newMedicine = (Medicine*) malloc(sizeof(Medicine));
    strcpy(newMedicine->name, name);
    newMedicine->price = price;
    newMedicine->quantity = quantity;
    return newMedicine;
}

void printMedicine(Medicine* med) {
    printf("%s - Rs. %.2f, %d in stock\n", med->name, med->price, med->quantity);
}

void addMedicine(Medicine** inventory, int* size) {
    char name[50];
    float price;
    int quantity;

    printf("\nEnter medicine name: ");
    scanf("%s", name);
    printf("Enter medicine price: Rs. ");
    scanf("%f", &price);
    printf("Enter medicine quantity: ");
    scanf("%d", &quantity);

    inventory[*size] = createMedicine(name, price, quantity);
    (*size)++;

    printf("\nMedicine added successfully!\n");
}

void sellMedicine(Medicine** inventory, int* size) {
    char name[50];
    int quantity;

    printf("\nEnter medicine name: ");
    scanf("%s", name);

    for(int i = 0; i < *size; i++) {
        if(strcmp(inventory[i]->name, name) == 0) {
            printf("Enter quantity: ");
            scanf("%d", &quantity);

            if(inventory[i]->quantity >= quantity) {
                inventory[i]->quantity -= quantity;

                printf("\nTotal cost: Rs. %.2f\n", quantity * inventory[i]->price);
                printf("Medicine sold successfully!\n");

                if(inventory[i]->quantity == 0) {
                    free(inventory[i]);
                    for(int j = i; j < *size - 1; j++) {
                        inventory[j] = inventory[j+1];
                    }
                    (*size)--;
                }
                return;
            }
            else {
                printf("\nInsufficient quantity in stock.\n");
                return;
            }
        }
    }

    printf("\nMedicine not found in inventory.\n");
}

int main() {
    Medicine* inventory[100];
    int size = 0;

    int choice;
    do {
        printf("\n--------------------------------------------------\n");
        printf("-------------------MEDICAL STORE------------------\n");
        printf("--------------------------------------------------\n");
        printf("\n1. Add Medicine\n2. Sell Medicine\n3. View Inventory\n4. Exit\n");
        printf("\nChoice: ");
        scanf("%d", &choice);
        printf("\n");

        switch(choice) {
            case 1:
                addMedicine(inventory, &size);
                break;
            case 2:
                sellMedicine(inventory, &size);
                break;
            case 3:
                if(size == 0) {
                    printf("\nInventory is empty.\n");
                }
                else {
                    printf("\nInventory:\n");
                    for(int i = 0; i < size; i++) {
                        printMedicine(inventory[i]);
                    }
                }
                break;
            case 4:
                printf("\nThank you for using the Medical Store Management System!\n");
                break;
            default:
                printf("\nInvalid choice.\n");
        }

    } while(choice != 4);

    return 0;
}