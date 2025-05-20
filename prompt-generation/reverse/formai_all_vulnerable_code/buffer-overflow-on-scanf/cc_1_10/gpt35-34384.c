//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Defining MAX to set maximum length of the medicine name*/
#define MAX 50

// Declaration of Medicine struct
typedef struct Medicine{
    char name[MAX]; // Name of the medicine
    int quantity;   // Quantity of the medicine available in the store
    float price;    // Price of the medicine per unit
} Medicine;

// Declaration of function prototypes
void addMedicine();
void searchMedicine();
void updateMedicine();
void deleteMedicine();

// Defining main function
int main(){
    int choice;
    // Printing menu for the user to select an operation
    while(1){
        printf("\n\t************ Medical Store Management System ************\t");
        printf("\n\n\t[1] Add Medicine \n\t[2] Search Medicine \n\t[3] Update Medicine \n\t[4] Remove Medicine \n\t[5] Exit");
        printf("\n\n\tEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                // Adding a new medicine to the store
                addMedicine();
                break;
            case 2:
                // Searching for a medicine in the store
                searchMedicine();
                break;
            case 3:
                // Updating the medicine details in the store
                updateMedicine();
                break;
            case 4:
                // Removing the medicine from the store
                deleteMedicine();
                break;
            case 5:
                // Exiting the program
                printf("\n\t************ Thank you for using Medical Store Management System ************\t");
                exit(0);
            default:
                // Handling wrong input from user
                printf("\n\tInvalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to add a new medicine to the store
void addMedicine(){
    // Initializing a new medicine struct object
    Medicine newMedicine;
    printf("\n\tPlease enter the following details of Medicine: \n");
    printf("\n\tName: ");
    scanf("%s", newMedicine.name);
    printf("\n\tQuantity: ");
    scanf("%d", &newMedicine.quantity);
    printf("\n\tPrice: ");
    scanf("%f", &newMedicine.price);

    // Opening the file for writing medicine details
    FILE *fp;
    fp = fopen("medicine.dat", "ab");
    if(fp == NULL){
        printf("\n\tError in opening the file.");
    }
    // Writing the medicine details in the file
    fwrite(&newMedicine, sizeof(newMedicine), 1, fp);
    // Closing the file
    fclose(fp);
    printf("\n\tMedicine successfully added to the store.");
}

// Function to search for a medicine in the store
void searchMedicine(){
    // Reading a medicine name entered by the user for search operation
    char search[MAX];
    printf("\n\tPlease enter the name of Medicine to search: ");
    scanf("%s", search);

    // Initializing a medicine struct object for reading from file
    Medicine med;
    int flag = 0;
    // Opening the file for reading medicine details
    FILE *fp;
    fp = fopen("medicine.dat", "rb");
    if(fp == NULL){
        printf("\n\tError in opening the file.");
    }
    // Reading the medicine details from the file
    while(fread(&med, sizeof(med), 1, fp) == 1){
        // Checking if medicine name matches with the search name
        if(strcmp(med.name, search) == 0){
            // Displaying the medicine details
            printf("\n\tName: %s\n\tQuantity: %d\n\tPrice: %.2f\n", med.name, med.quantity, med.price);
            flag = 1;
            break;
        }
    }
    // Closing the file
    fclose(fp);
    // Displaying message if medicine not found in store
    if(flag == 0){
        printf("\n\tMedicine not found in the store.");
    }
}

// Function to update the details of a medicine in the store
void updateMedicine(){
    // Reading a medicine name entered by the user for update operation
    char update[MAX];
    printf("\n\tPlease enter the name of Medicine to update: ");
    scanf("%s", update);

    // Initializing a medicine struct object for reading from file
    Medicine med;
    int flag = 0;
    // Opening the file for reading and writing medicine details
    FILE *fp;
    fp = fopen("medicine.dat", "r+b");
    if(fp == NULL){
        printf("\n\tError in opening the file.");
    }
    // Reading the medicine details from the file
    while(fread(&med, sizeof(med), 1, fp) == 1){
        // Checking if medicine name matches with the update name
        if(strcmp(med.name, update) == 0){
            // Updating the medicine details
            printf("\n\tPlease enter the new details: \n");
            printf("\n\tName: ");
            scanf("%s", med.name);
            printf("\n\tQuantity: ");
            scanf("%d", &med.quantity);
            printf("\n\tPrice: ");
            scanf("%f", &med.price);
            // Moving the file pointer to the current medicine details position and writing the updated details
            fseek(fp, -(long)sizeof(med), SEEK_CUR);
            fwrite(&med, sizeof(med), 1, fp);
            flag = 1;
            printf("\n\tMedicine details successfully updated.");
            break;
        }
    }
    // Closing the file
    fclose(fp);
    // Displaying message if medicine not found in store
    if(flag == 0){
        printf("\n\tMedicine not found in the store.");
    }
}

// Function to remove a medicine from the store
void deleteMedicine(){
    // Reading a medicine name entered by the user for delete operation
    char delete[MAX];
    printf("\n\tPlease enter the name of Medicine to delete: ");
    scanf("%s", delete);

    // Initializing a medicine struct object for reading from file
    Medicine med;
    int flag = 0;
    // Opening the file for reading and writing medicine details
    FILE *fp, *temp;
    fp = fopen("medicine.dat", "rb");
    temp = fopen("temp.dat", "wb");
    if(fp == NULL || temp == NULL){
        printf("\n\tError in opening the file.");
    }
    // Reading the medicine details from the file and writing to a temporary file except the medicine to be deleted
    while(fread(&med, sizeof(med), 1, fp) == 1){
        // Checking if medicine name matches with the delete name
        if(strcmp(med.name, delete) == 0){
            flag = 1;
        } else{
            fwrite(&med, sizeof(med), 1, temp);
        }
    }
    // Closing the files
    fclose(fp);
    fclose(temp);
    // Removing the original file and renaming the temporary file as original
    remove("medicine.dat");
    rename("temp.dat", "medicine.dat");
    if(flag == 1){
        printf("\n\tMedicine details successfully deleted.");
    } else{
        printf("\n\tMedicine not found in the store.");
    }
}