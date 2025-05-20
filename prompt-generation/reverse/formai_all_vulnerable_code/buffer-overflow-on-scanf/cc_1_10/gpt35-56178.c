//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct medicine{
    char name[50];
    int quantity;
    float price;
};

typedef struct medicine Medicine;

//function to add medicine details
void addMedicine(Medicine *medicineInventory, int n){
    printf("Enter the name of the medicine: ");
    scanf("%s", medicineInventory[n].name);
    printf("Enter the quantity: ");
    scanf("%d", &medicineInventory[n].quantity);
    printf("Enter the price of one unit: ");
    scanf("%f", &medicineInventory[n].price);
    printf("\nMedicine added successfully!\n\n");
}

//function to update medicine details
void updateMedicine(Medicine *medicineInventory, int n){
    printf("Enter the name of the medicine: ");
    char name[50];
    scanf("%s", name);
    int found = 0;
    for(int i=0; i<n; i++){
        if(strcmp(medicineInventory[i].name, name) == 0){
            printf("Enter the new quantity: ");
            scanf("%d", &medicineInventory[i].quantity);
            printf("Enter the new price of one unit: ");
            scanf("%f", &medicineInventory[i].price);
            found = 1;
            printf("\nMedicine details updated successfully!\n\n");
            break;
        }
    }
    if(found == 0){
        printf("\nMedicine not found!\n\n");
    }
}

//function to search for medicine details
void searchMedicine(Medicine *medicineInventory, int n){
    printf("Enter the name of the medicine: ");
    char name[50];
    scanf("%s", name);
    int found = 0;
    for(int i=0; i<n; i++){
        if(strcmp(medicineInventory[i].name, name) == 0){
            printf("\nMedicine Name: %s\n", medicineInventory[i].name);
            printf("Quantity: %d\n", medicineInventory[i].quantity);
            printf("Price of one unit: %.2f\n\n", medicineInventory[i].price);
            found = 1;
            break;
        }
    }
    if(found == 0){
        printf("\nMedicine not found!\n\n");
    }
}

//function to display medicine inventory
void displayInventory(Medicine *medicineInventory, int n){
    printf("Medicine Inventory:\n\n");
    for(int i=0; i<n; i++){
        printf("Medicine Name: %s\n", medicineInventory[i].name);
        printf("Quantity: %d\n", medicineInventory[i].quantity);
        printf("Price of one unit: %.2f\n\n", medicineInventory[i].price);
    }
}

int main(){
    int n = 0;
    int choice = 0;
    Medicine *medicineInventory = NULL;

    do{
        printf("-------Medical Store Management System-------\n");
        printf("1. Add medicine details\n");
        printf("2. Update medicine details\n");
        printf("3. Search for medicine details\n");
        printf("4. Display medicine inventory\n");
        printf("5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                n++;
                medicineInventory = (Medicine*) realloc(medicineInventory, n*sizeof(Medicine));
                addMedicine(medicineInventory, n-1);
                break;

            case 2:
                updateMedicine(medicineInventory, n);
                break;

            case 3:
                searchMedicine(medicineInventory, n);
                break;

            case 4:
                displayInventory(medicineInventory, n);
                break;

            case 5:
                printf("Thank you for using Medical Store Management System!\n");
                break;

            default:
                printf("Invalid choice! Try again.\n\n");
                break;
        }
    }while(choice != 5);

    free(medicineInventory);
    medicineInventory = NULL;

    return 0;
}