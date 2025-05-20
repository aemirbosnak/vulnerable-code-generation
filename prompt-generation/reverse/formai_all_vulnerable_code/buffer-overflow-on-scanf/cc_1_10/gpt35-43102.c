//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100   // Maximum number of medicines the store can hold

struct Medicine
{
    char name[50];
    float price;
    int quantity;
};

struct Medicine medicines[MAX_MEDICINES];  // Array of medicines

int numMedicines = 0;   // Number of medicines in the store

void addMedicine()
{
    // Get information about the new medicine from the user
    printf("Enter name of medicine: ");
    scanf("%s", medicines[numMedicines].name);
    printf("Enter price of medicine: ");
    scanf("%f", &medicines[numMedicines].price);
    printf("Enter quantity of medicine: ");
    scanf("%d", &medicines[numMedicines].quantity);
    
    numMedicines++;   // Increase number of medicines in the store
}

void printInventory()
{
    printf("\nCurrent Inventory:\n");
    printf("=====================\n");
    printf("Name\tPrice\tQuantity\n");
    
    for(int i=0; i<numMedicines; i++)
    {
        printf("%s\t%.2f\t%d\n", medicines[i].name, medicines[i].price, medicines[i].quantity);
    }
}

void sellMedicine()
{
    char name[50];
    int quantity;
    
    // Get name of medicine to sell from the user
    printf("Enter name of medicine to sell: ");
    scanf("%s", name);
    
    for(int i=0; i<numMedicines; i++)
    {
        if(strcmp(name, medicines[i].name) == 0)   // If the medicine exists
        {
            // Get quantity of medicine to sell
            printf("Enter quantity of medicine to sell: ");
            scanf("%d", &quantity);
            
            if(quantity > medicines[i].quantity)   // If the requested quantity is not available
            {
                printf("Sorry, only %d of %s available\n", medicines[i].quantity, name);
                return;
            }
            
            // Sell the medicine and update the inventory
            medicines[i].quantity -= quantity;
            printf("%d of %s sold\n", quantity, name);
            return;
        }
    }
    
    // If the medicine was not found in the store
    printf("%s not found in store\n", name);
}

int main()
{
    int choice;
    
    while(1)
    {
        printf("\nMedical Store Management System\n");
        printf("================================\n");
        printf("1. Add Medicine\n");
        printf("2. Sell Medicine\n");
        printf("3. Print Inventory\n");
        printf("4. Exit\n");
        
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                addMedicine();
                break;
            case 2:
                sellMedicine();
                break;
            case 3:
                printInventory();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again\n");
        }
    }
    
    return 0;
}