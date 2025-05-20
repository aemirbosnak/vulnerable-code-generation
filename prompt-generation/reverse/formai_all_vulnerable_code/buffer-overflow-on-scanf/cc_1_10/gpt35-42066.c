//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define constants
#define MAX_SIZE 100
#define MAX_MED_NAME 25
#define MAX_COMPANY_NAME 20

// Define structures
typedef struct{
    char med_name[MAX_MED_NAME];
    char company_name[MAX_COMPANY_NAME];
    int stock;
    float price;
} medicine;

// Declare global variables
medicine med[MAX_SIZE];
int med_count = 0;

// Declare functions
void add_medicine();
void remove_medicine();
void update_medicine();
void display_medicine();

int main(){
    int choice;
    while(1){
        printf("\n=======Medical Store Management System=======\n");
        printf("1. Add medicine\n");
        printf("2. Remove medicine\n");
        printf("3. Update medicine\n");
        printf("4. Display medicine\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                add_medicine();
                break;
            case 2:
                remove_medicine();
                break;
            case 3:
                update_medicine();
                break;
            case 4:
                display_medicine();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid choice.\n");
        }
    }
    return 0;
}

void add_medicine(){
    if(med_count == MAX_SIZE){
        printf("Sorry, the medicine store is full!\n");
        return;
    }
    printf("\nEnter medicine name: ");
    scanf("%s", med[med_count].med_name);
    printf("Enter company name: ");
    scanf("%s", med[med_count].company_name);
    printf("Enter stock: ");
    scanf("%d", &med[med_count].stock);
    printf("Enter price: ");
    scanf("%f", &med[med_count].price);
    med_count++;
    printf("\nMedicine added successfully!\n");
}

void remove_medicine(){
    char med_name[MAX_MED_NAME];
    printf("\nEnter medicine name to be removed: ");
    scanf("%s", med_name);
    int i;
    for(i=0; i<med_count; i++){
        if(strcmp(med_name, med[i].med_name) == 0){
            med[i] = med[med_count-1];
            med_count--;
            printf("\nMedicine removed successfully!\n");
            return;
        }
    }
    printf("\nMedicine with name %s not found!\n", med_name);
}

void update_medicine(){
    char med_name[MAX_MED_NAME];
    printf("\nEnter medicine name to be updated: ");
    scanf("%s", med_name);
    int i;
    for(i=0; i<med_count; i++){
        if(strcmp(med_name, med[i].med_name) == 0){
            printf("\nEnter updated stock: ");
            scanf("%d", &med[i].stock);
            printf("Enter updated price: ");
            scanf("%f", &med[i].price);
            printf("\nMedicine updated successfully!\n");
            return;
        }
    }
    printf("\nMedicine with name %s not found!\n", med_name);
}

void display_medicine(){
    if(med_count == 0){
        printf("\nNo medicine found in the store!\n");
        return;
    }
    printf("\nMedicine details:\n");
    printf("==============================================================================================\n");
    printf("Sr. No.\t\tMedicine Name\t\tCompany Name\t\t\tStock\t\tPrice (per unit)\n");
    printf("==============================================================================================\n");
    int i;
    for(i=0; i<med_count; i++){
        printf("%d\t\t%s\t\t\t%s\t\t\t\t%d\t\t%.2f\n", i+1, med[i].med_name, med[i].company_name, med[i].stock, med[i].price);
    }
    printf("==============================================================================================\n");
}