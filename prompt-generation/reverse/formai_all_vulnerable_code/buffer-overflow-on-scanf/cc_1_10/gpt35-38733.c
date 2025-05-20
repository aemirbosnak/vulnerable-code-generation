//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Medicine{
    char name[50];
    int quantity;
    float price;
    char expiry_date[15];
};

void addMedicine(struct Medicine* med, int n);
void displayInventory(struct Medicine* med, int n);
void searchMedicine(struct Medicine* med, int n, char* name);

int main(){

    printf("Welcome to the Medical Store Management System!\n");
    printf("Please choose an option:\n");
    printf("1. Add a medicine to inventory\n");
    printf("2. Display inventory\n");
    printf("3. Search for a medicine by name\n");
    printf("4. Exit\n");

    int option, num_medicines = 0;
    struct Medicine* medicines = NULL;
    char search_name[50];

    while(1){
        printf("\nEnter option (1-4): ");
        scanf("%d", &option);
        switch(option){
            case 1:
                addMedicine(medicines, num_medicines);
                num_medicines++;
                break;
            case 2:
                displayInventory(medicines, num_medicines);
                break;
            case 3:
                printf("\nEnter name of medicine to search: ");
                scanf("%s", search_name);
                searchMedicine(medicines, num_medicines, search_name);
                break;
            case 4:
                printf("\nThank you for using the Medical Store Management System!");
                exit(0);
            default:
                printf("\nInvalid option. Please choose an option between 1-4.");
        }
    }

    return 0;
}

void addMedicine(struct Medicine* med, int n){
    printf("\nEnter details of medicine:\n");
    med = (struct Medicine*)realloc(med, (n+1)*sizeof(struct Medicine));
    printf("Name: ");
    scanf("%s", (med+n)->name);
    printf("Quantity: ");
    scanf("%d", &(med+n)->quantity);
    printf("Price: ");
    scanf("%f", &(med+n)->price);
    printf("Expiry date (dd-mm-yyyy): ");
    scanf("%s", (med+n)->expiry_date);
    printf("Medicine added to inventory successfully!\n");
}

void displayInventory(struct Medicine* med, int n){
    printf("\nInventory:\n");
    printf("%-20s%-10s%-10s%-15s\n", "Name", "Quantity", "Price", "Expiry Date");
    for(int i=0; i<n; i++){
        printf("%-20s%-10d%-10.2f%-15s\n", (med+i)->name, (med+i)->quantity, (med+i)->price, (med+i)->expiry_date);
    }
}

void searchMedicine(struct Medicine* med, int n, char* name){
    for(int i=0; i<n; i++){
        if(strcmp((med+i)->name, name) == 0){
            printf("\nMedicine found!\n");
            printf("%-20s%-10s%-10s%-15s\n", "Name", "Quantity", "Price", "Expiry Date");
            printf("%-20s%-10d%-10.2f%-15s\n", (med+i)->name, (med+i)->quantity, (med+i)->price, (med+i)->expiry_date);
            return;
        }
    }
    printf("\nMedicine not found!");
}