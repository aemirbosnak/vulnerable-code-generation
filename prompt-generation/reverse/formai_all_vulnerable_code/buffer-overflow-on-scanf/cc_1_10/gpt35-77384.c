//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure to store medicine information
typedef struct{
    char medicine_name[20];
    int quantity;
    float price;
}Medicine;

// Function to display menu
void display_menu(){
    printf("\n------- Medical Store Management System -------\n");
    printf("\nPlease enter your choice:\n");
    printf("1. Add Medicine\n");
    printf("2. Search Medicine\n");
    printf("3. Update Medicine\n");
    printf("4. Delete Medicine\n");
    printf("5. Display All Medicines\n");
    printf("6. Exit\n");
}

// Function to add medicine to the inventory
void add_medicine(Medicine* medicine, int* num_medicine){
    // Get medicine details from user input
    printf("Enter Medicine Name: ");
    scanf("%s", medicine[*num_medicine].medicine_name);
    printf("Enter Quantity: ");
    scanf("%d", &medicine[*num_medicine].quantity);
    printf("Enter Price: ");
    scanf("%f", &medicine[*num_medicine].price);
    // Increment medicine count
    (*num_medicine)++;
    printf("Medicine added successfully!\n");
}

// Function to search for medicine in the inventory
void search_medicine(Medicine* medicine, int num_medicine){
    char search_name[20];
    printf("Enter Medicine Name to search: ");
    scanf("%s", search_name);
    int found = 0;
    // Iterate through medicine list to find the medicine
    for(int i=0; i<num_medicine; i++){
        if(strcmp(medicine[i].medicine_name, search_name) == 0){
            printf("%s\t\t%d\t\t%.2f\n", medicine[i].medicine_name, medicine[i].quantity, medicine[i].price);
            found = 1;
            break;
        }
    }
    if(!found){
        printf("Medicine with name %s not found\n", search_name);
    }
}

// Function to update medicine details
void update_medicine(Medicine* medicine, int num_medicine){
    char update_name[20];
    printf("Enter Medicine Name to update: ");
    scanf("%s", update_name);
    int found = 0;
    // Iterate through medicine list to find the medicine
    for(int i=0; i<num_medicine; i++){
        if(strcmp(medicine[i].medicine_name, update_name) == 0){
            printf("Enter new quantity: ");
            scanf("%d", &medicine[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &medicine[i].price);
            printf("Medicine updated successfully!\n");
            found = 1;
            break;
        }
    }
    if(!found){
        printf("Medicine with name %s not found\n", update_name);
    }
}

// Function to delete medicine from inventory
void delete_medicine(Medicine* medicine, int* num_medicine){
    char delete_name[20];
    printf("Enter Medicine Name to delete: ");
    scanf("%s", delete_name);
    int found = 0;
    // Iterate through medicine list to find the medicine
    for(int i=0; i<*num_medicine; i++){
        if(strcmp(medicine[i].medicine_name, delete_name) == 0){
            // Shift medicines to left one position
            for(int j=i; j<*num_medicine-1; j++){
                strcpy(medicine[j].medicine_name, medicine[j+1].medicine_name);
                medicine[j].quantity = medicine[j+1].quantity;
                medicine[j].price = medicine[j+1].price;
            }
            // Decrement medicine count
            (*num_medicine)--;
            printf("Medicine deleted successfully!\n");
            found = 1;
            break;
        }
    }
    if(!found){
        printf("Medicine with name %s not found\n", delete_name);
    }
}

// Function to display all medicines in inventory
void display_medicines(Medicine* medicine, int num_medicine){
    printf("Medicine Name\tQuantity\tPrice\n");
    for(int i=0; i<num_medicine; i++){
        printf("%s\t\t%d\t\t%.2f\n", medicine[i].medicine_name, medicine[i].quantity, medicine[i].price);
    }
}

int main(){
    int num_medicine = 0; // Number of medicines in inventory
    Medicine medicine[50]; // Inventory array
    int choice; // User choice
    do{
        display_menu();
        scanf("%d", &choice);
        switch(choice){
            case 1:
                add_medicine(medicine, &num_medicine);
                break;
            case 2:
                search_medicine(medicine, num_medicine);
                break;
            case 3:
                update_medicine(medicine, num_medicine);
                break;
            case 4:
                delete_medicine(medicine, &num_medicine);
                break;
            case 5:
                display_medicines(medicine, num_medicine);
                break;
            case 6:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }while(choice != 6);
    return 0;
}