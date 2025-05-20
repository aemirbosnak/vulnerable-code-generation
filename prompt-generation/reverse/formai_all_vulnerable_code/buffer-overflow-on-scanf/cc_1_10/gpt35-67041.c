//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Defining a structure for medicines
typedef struct medicine{
    int id;
    char name[20];
    float price;
    int quantity;
} Medicine;

// Function prototypes
void addMedicine();
void searchMedicine();
void updateMedicine();
void deleteMedicine();
void displayAllMedicines();

// Global variables
Medicine medicines[100];
int count = 0;

// Function to add medicine to the store
void addMedicine(){
    printf("\nEnter details of medicine:");
    printf("\nID: ");
    scanf("%d", &medicines[count].id);
    printf("\nName of medicine: ");
    scanf("%s", medicines[count].name);
    printf("\nPrice of medicine: ");
    scanf("%f", &medicines[count].price);
    printf("\nQuantity of medicine: ");
    scanf("%d", &medicines[count].quantity);
    count++;
}

// Function to search for a medicine in the store
void searchMedicine(){
    int medId, i;
    printf("\nEnter the id of the medicine you want to search for: ");
    scanf("%d", &medId);
    for(i=0; i<count; i++){
        if(medicines[i].id == medId){
            printf("\nMedicine found!\nDetails of medicine: ");
            printf("\nID: %d", medicines[i].id);
            printf("\nName of medicine: %s", medicines[i].name);
            printf("\nPrice of medicine: %.2f", medicines[i].price);
            printf("\nQuantity of medicine: %d\n", medicines[i].quantity);
            return;
        }
    }
    printf("\nMedicine not found!\n");
}

// Function to update a medicine in the store
void updateMedicine(){
    int medId, i;
    printf("\nEnter the id of the medicine you want to update: ");
    scanf("%d", &medId);
    for(i=0; i<count; i++){
        if(medicines[i].id == medId){
            printf("\nEnter new details of medicine:");
            printf("\nName of medicine: ");
            scanf("%s", medicines[i].name);
            printf("\nPrice of medicine: ");
            scanf("%f", &medicines[i].price);
            printf("\nQuantity of medicine: ");
            scanf("%d", &medicines[i].quantity);
            printf("\nMedicine updated successfully!\n");
            return;
        }
    }
    printf("\nMedicine not found!\n");
}

// Function to delete a medicine from the store
void deleteMedicine(){
    int medId, i, j;
    printf("\nEnter the id of the medicine you want to delete: ");
    scanf("%d", &medId);
    for(i=0; i<count; i++){
        if(medicines[i].id == medId){
            for(j=i; j<count-1; j++){
                medicines[j] = medicines[j+1];
            }
            count--;
            printf("\nMedicine deleted successfully!\n");
            return;
        }
    }
    printf("\nMedicine not found!\n");
}

// Function to display all medicines in the store
void displayAllMedicines(){
    int i;
    printf("\nDetails of all medicines:");
    for(i=0; i<count; i++){
        printf("\n\nMedicine %d:", i+1);
        printf("\nID: %d", medicines[i].id);
        printf("\nName of medicine: %s", medicines[i].name);
        printf("\nPrice of medicine: %.2f", medicines[i].price);
        printf("\nQuantity of medicine: %d", medicines[i].quantity);
    }
    printf("\n");
}

// Main function
int main(){
    int choice;
    do{
        printf("\n\n*** MEDICAL STORE MANAGEMENT SYSTEM ***\n");
        printf("\nPlease select an option:\n");
        printf("1. Add a new medicine\n");
        printf("2. Search for a medicine\n");
        printf("3. Update a medicine\n");
        printf("4. Delete a medicine\n");
        printf("5. Display all medicines\n");
        printf("6. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: addMedicine(); break;
            case 2: searchMedicine(); break;
            case 3: updateMedicine(); break;
            case 4: deleteMedicine(); break;
            case 5: displayAllMedicines(); break;
            case 6: exit(0);
            default: printf("\nInvalid choice, please try again...\n");
        }
    }while(choice != 6);
    return 0;
}