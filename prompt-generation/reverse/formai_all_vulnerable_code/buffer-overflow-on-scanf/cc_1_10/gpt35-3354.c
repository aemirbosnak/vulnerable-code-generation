//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

//Defining a structure to store medicine details
struct medicine {
    char name[25];
    int id;
    float price;
    int quantity;
};

//Global variables
int count = 0;
struct medicine med[MAX];

//Function to add a new medicine
void addMedicine() {
    int id, quantity;
    float price;
    char name[25];
    //Inputting Details of medicine
    printf("\nNew Medicine Details:-");
    printf("\nEnter Medicine ID: ");
    scanf("%d", &id);
    printf("\nEnter Medicine Name: ");
    scanf("%s", name);
    printf("\nEnter Medicine Price: ");
    scanf("%f", &price);
    printf("\nEnter Quantity: ");
    scanf("%d", &quantity);
    //Adding medicine to the system
    med[count].id = id;
    strcpy(med[count].name, name);
    med[count].price = price;
    med[count].quantity = quantity;
    count++;
    printf("\nMedicine added successfully!");
}

//Function to display the list of medicines
void displayMedicines() {
    printf("\nMedicine List:\n");
    printf(" ID  | NAME\t\t| PRICE\t\t| QUANTITY\n");
    printf("-----|---------------|-------------|---------\n");
    for(int i = 0; i < count; i++) {
        printf(" %d\t| %s\t\t| %.2f\t\t| %d\n", med[i].id, med[i].name, med[i].price, med[i].quantity);
    }
}

//Function to search for a medicine by name and update its details
void updateMedicine() {
    char name[25];
    int id, quantity;
    float price;
    int flag = 0;
    printf("\nEnter Medicine Name to be updated: ");
    scanf("%s", name);
    //Searching for the medicine
    for(int i = 0; i < count; i++) {
        if(strcmp(med[i].name, name) == 0) {
            flag = 1;
            printf("\nEnter New Details for Medicine ID %d:", med[i].id);
            printf("\nEnter Medicine Name: ");
            scanf("%s", name);
            printf("\nEnter Medicine Price: ");
            scanf("%f", &price);
            printf("\nEnter Quantity: ");
            scanf("%d", &quantity);
            //Updating medicine details
            med[i].price = price;
            med[i].quantity = quantity;
            strcpy(med[i].name, name);
            break;
        }
    }
    if(flag == 0) {
        printf("\nMedicine not found!");
    } else {
        printf("\nMedicine updated successfully!");
    }
}

//Function to search for a medicine by name and delete it from the system
void deleteMedicine() {
    char name[25];
    int flag = 0;
    printf("\nEnter Medicine Name to be deleted: ");
    scanf("%s", name);
    //Searching for the medicine
    for(int i = 0; i < count; i++) {
        if(strcmp(med[i].name, name) == 0) {
            flag = 1;
            //Deleting the medicine
            for(int j = i; j < count - 1; j++) {
                med[j] = med[j + 1];
            }
            count--;
            break;
        }
    }
    if(flag == 0) {
        printf("\nMedicine not found!");
    } else {
        printf("\nMedicine deleted successfully!");
    }
}

//Main function
int main() {
    int choice;
    printf("Welcome to the Medical Store Management System!\n\n");
    //Displaying menu
    do {
        printf("\n\n1. Add Medicine\n2. Display Medicines\n3. Update Medicine\n4. Delete Medicine\n5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: addMedicine();
                    break;
            case 2: displayMedicines();
                    break;
            case 3: updateMedicine();
                    break;
            case 4: deleteMedicine();
                    break;
            case 5: printf("\nThank you for using the system!");
                    exit(0);
                    break;
            default: printf("\nInvalid choice! Please try again.");
        }
    } while(choice != 5);
    return 0;
}