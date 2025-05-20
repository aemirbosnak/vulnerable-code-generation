//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct medicine{
    char name[50];
    float price;
    int quantity;
};

// Function to add medicine to the inventory
void addMedicine(struct medicine *medicines, int *numMedicines){
    printf("Enter name of medicine: ");
    scanf("%s", medicines[*numMedicines].name);
    printf("Enter price of medicine: ");
    scanf("%f", &medicines[*numMedicines].price);
    printf("Enter quantity of medicine: ");
    scanf("%d", &medicines[*numMedicines].quantity);

    (*numMedicines)++;
}

// Function to display all medicines in inventory
void displayMedicines(struct medicine *medicines, int numMedicines){
    printf("All Medicines in Inventory:\n");
    for(int i=0; i<numMedicines; i++){
        printf("Name: %s\nPrice: %.2f\nQuantity: %d\n\n", medicines[i].name, medicines[i].price, medicines[i].quantity);
    }
}

// Function to search for medicine in inventory by name
void searchMedicine(struct medicine *medicines, int numMedicines){
    char name[50];
    printf("Enter name of medicine to search: ");
    scanf("%s", name);

    int found = 0;
    for(int i=0; i<numMedicines; i++){
        if(strcmp(medicines[i].name, name) == 0){
            printf("\nName: %s\nPrice: %.2f\nQuantity: %d\n\n", medicines[i].name, medicines[i].price, medicines[i].quantity);
            found = 1;
        }
    }

    if(!found){
        printf("Medicine not found in inventory.\n");
    }
}

// Function to update stock of medicine in inventory
void updateStock(struct medicine *medicines, int numMedicines){
    char name[50];
    printf("Enter name of medicine to update stock: ");
    scanf("%s", name);

    int found = 0;
    for(int i=0; i<numMedicines; i++){
        if(strcmp(medicines[i].name, name) == 0){
            printf("Enter new quantity of medicine: ");
            scanf("%d", &medicines[i].quantity);
            found = 1;
        }
    }

    if(!found){
        printf("Medicine not found in inventory.\n");
    }
}

// Main function to manage inventory
int main(){
    int choice, numMedicines = 0;
    struct medicine *medicines = malloc(sizeof(struct medicine));

    while(1){
        printf("\nMedical Store Management System Menu:\n");
        printf("1. Add medicine to inventory\n");
        printf("2. Display all medicines in inventory\n");
        printf("3. Search for medicine in inventory\n");
        printf("4. Update stock of medicine in inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: // Add medicine to inventory
                addMedicine(medicines, &numMedicines);
                break;
            case 2: // Display all medicines in inventory
                displayMedicines(medicines, numMedicines);
                break;
            case 3: // Search for medicine in inventory
                searchMedicine(medicines, numMedicines);
                break;
            case 4: // Update stock of medicine in inventory
                updateStock(medicines, numMedicines);
                break;
            case 5: // Exit
                printf("Thank you for using Medical Store Management System!\n");
                free(medicines);
                return 0;
            default: // Invalid input
                printf("Invalid input, please try again.\n");
        }
    }
    return 0;
}