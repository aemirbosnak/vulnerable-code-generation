//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_MED 100
#define MAX_STR 30

/* Structure to hold medicine records */
typedef struct {
    char name[MAX_STR];
    int quantity;
    float price;
} Medicine;

/* Global array to hold available medicines */
Medicine medicines[MAX_MED];

/* Function to add a new medicine to the store */
void addMedicine(int medCount)
{
    if(medCount>=MAX_MED){
        printf("Medicine store is full!\n");
        return;
    }
    // Get details of the new medicine
    printf("Enter medicine name:");
    scanf("%s", medicines[medCount].name);
    printf("Enter medicine quantity:");
    scanf("%d", &medicines[medCount].quantity);
    printf("Enter medicine price:");
    scanf("%f", &medicines[medCount].price);
    printf("%s added to medicine store!\n", medicines[medCount].name);
}

/* Function to search for a medicine in the store */
void searchMedicine(int medCount, char* search)
{
    // Check if medicine exists in store
    int found = 0;
    for(int i=0;i<medCount;i++){
        if(!strcmp(medicines[i].name, search)){
            found = 1;
            printf("Medicine: %s\nQuantity: %d\nPrice: %.2f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
            break;
        }
    }
    if(!found){
        printf("%s not found in medicine store!\n", search);
    }
}

/* Function to update quantity of existing medicine in store */
void updateMedicine(int medCount, char* medicine, int qty)
{
    // Check if medicine exists in store
    int found = 0;
    for(int i=0;i<medCount;i++){
        if(!strcmp(medicines[i].name, medicine)){
            found = 1;
            medicines[i].quantity += qty;
            printf("%s quantity updated to %d!\n", medicines[i].name, medicines[i].quantity);
            break;
        }
    }
    if(!found){
        printf("%s not found in medicine store!\n", medicine);
    }
}

/* Function to display all the medicines in the store */
void displayMedicines(int medCount)
{
    printf("Medicine Name\t\tQuantity\tPrice\n");
    for(int i=0;i<medCount;i++){
        printf("%-20s\t\t%-8d\t%.2f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
    }
}

int main()
{
    int medCount = 0;
    int choice, qty;
    char search[MAX_STR], medicine[MAX_STR];

    // Display menu and take user input
    while(1){
        printf("\n******** Medical Store Management System ********\n");
        printf("1. Add a new medicine\n");
        printf("2. Search for a medicine\n");
        printf("3. Update medicine quantity\n");
        printf("4. Display all medicines\n");
        printf("5. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch(choice){
            case 1: 
                addMedicine(medCount);
                medCount++;
                break;
            case 2:
                printf("Enter medicine name to search:");
                scanf("%s", search);
                searchMedicine(medCount, search);
                break;
            case 3:
                printf("Enter medicine name to update:");
                scanf("%s", medicine);
                printf("Enter quantity to add/remove:");
                scanf("%d", &qty);
                updateMedicine(medCount, medicine, qty);
                break;
            case 4:
                displayMedicines(medCount);
                break;
            case 5:
                printf("Exiting Medical Store Management System...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}