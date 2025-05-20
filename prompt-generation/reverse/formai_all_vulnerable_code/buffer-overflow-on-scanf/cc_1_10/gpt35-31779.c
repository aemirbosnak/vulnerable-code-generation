//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine{
    char name[50];
    int id;
    int stockQuantity;
    float price;
};

void printMedicine(struct medicine med);
void addMedicine(struct medicine med);

int main()
{
    int choice;
    struct medicine newMedicine;
    struct medicine inventory[100];
    int inventorySize = 0;

    do {
        printf("\n*****Medical Store Management System*****\n");
        printf("\n1 - Add Medicine to Inventory");
        printf("\n2 - Remove Medicine from Inventory");
        printf("\n3 - View Inventory");
        printf("\n4 - Search for Medicine");
        printf("\n5 - Exit Program");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice)
        {
            case 1:
                addMedicine(newMedicine);
                inventory[inventorySize] = newMedicine;
                inventorySize++;
                printf("\nMedicine added to inventory.\n");
                break;

            case 2:
                // code to remove medicine from inventory
                break;

            case 3:
                for(int i = 0; i < inventorySize; i++){
                    printMedicine(inventory[i]);
                }
                break;

            case 4:
                // code to search for medicine in inventory
                break;

            case 5:
                exit(0);
                break;

            default:
                printf("Invalid choice.");
                break;
        }

    } while (choice != 5);

    return 0;
}

void printMedicine(struct medicine med){
    printf("\nMedicine Name : %s    Medicine ID : %d    Medicine Stock Quantity: %d    Medicine Price : %f\n", med.name, med.id, med.stockQuantity, med.price);
}

void addMedicine(struct medicine med){
    printf("\nEnter Medicine Name: ");
    fgets(med.name, 50, stdin);

    printf("\nEnter Medicine ID: ");
    scanf("%d", &med.id);

    printf("\nEnter Stock Quantity: ");
    scanf("%d", &med.stockQuantity);

    printf("\nEnter Price: ");
    scanf("%f", &med.price);
}