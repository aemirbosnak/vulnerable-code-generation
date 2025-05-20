//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: funny
#include<stdio.h>
#include<stdlib.h>

// Function for displaying the main menu
void displayMainMenu(){
    printf("\nWelcome to the Medical Store Management System\n");
    printf("1. Add Medicine\n");
    printf("2. View Medicine\n");
    printf("3. Update Medicine\n");
    printf("4. Delete Medicine\n");
    printf("5. Search Medicine\n");
    printf("6. Exit\n");
}

// Function for adding a new medicine to the inventory
void addMedicine(){
    printf("Let's add a new medicine to the inventory\n");
    // some funny code here....
    printf("What's the name of the medicine?\n");
    // some more funny code...
}

// Function for viewing medicines in the inventory
void viewMedicine(){
    printf("Let's view all available medicines\n");
    // some more funny code...
}

// Function for updating a medicine in the inventory
void updateMedicine(){
    printf("Let's update a medicine in the inventory\n");
    // more funny code...
}

// Function for deleting a medicine from the inventory
void deleteMedicine(){
    printf("Let's delete a medicine from the inventory\n");
    // even more funny code...
}

// Function for searching a medicine by name or ID
void searchMedicine(){
    printf("Let's search for a medicine by name or ID\n");
    // some more funny code...
}

int main(){
    int choice;
    do{
        displayMainMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                addMedicine();
                break;
            case 2:
                viewMedicine();
                break;
            case 3:
                updateMedicine();
                break;
            case 4:
                deleteMedicine();
                break;
            case 5:
                searchMedicine();
                break;
            case 6:
                printf("Goodbye! Have a nice day :)\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }while(choice!=6);
    return 0;
}