//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure Definition for Medicine Details
struct Medicine{
    int id;
    char name[50];
    char company[50];
    float price;
    int quantity;
};

struct Sales {
    char name[50];
    int quantity;
};

//Function to add new Medicine to Inventory
void addNewMedicine(struct Medicine *arr, int *totalMedicines, int *id){
    printf("Enter Name of Medicine: ");
    getchar();
    fgets((arr+(*totalMedicines))->name, 50, stdin);
    printf("Enter Company Name: ");
    fgets((arr+(*totalMedicines))->company, 50, stdin);
    printf("Enter Price of Medicine: ");
    scanf("%f", &(arr+(*totalMedicines))->price);
    printf("Enter Quantity of Medicine: ");
    scanf("%d", &(arr+(*totalMedicines))->quantity);
    (*totalMedicines)++;
    (arr+(*totalMedicines))->id = *id;
    (*id)++;
}

//Function to Search for Medicine in Inventory
void searchMedicine(struct Medicine *arr, int *totalMedicines){
    char name[50];
    printf("Enter Name of Medicine to Search: ");
    getchar();
    fgets(name, 50, stdin);
    for(int i = 0; i < *totalMedicines; i++){
        if(strcmp((arr+i)->name, name) == 0){
            printf("\nMedicine Found!\n");
            printf("ID: %d\nName: %sCompany: %sPrice: %.2f\nQuantity: %d\n", (arr+i)->id, (arr+i)->name, (arr+i)->company, (arr+i)->price, (arr+i)->quantity);
            return;
        }
    }
    printf("\nMedicine Not Found!\n");
}

//Function to update Medicine in Inventory
void updateMedicine(struct Medicine *arr, int *totalMedicines){
    int id;
    printf("Enter ID of Medicine to Update: ");
    scanf("%d", &id);
    for(int i = 0; i < *totalMedicines; i++){
        if((arr+i)->id == id){
            printf("Enter Name of Medicine: ");
            getchar();
            fgets((arr+i)->name, 50, stdin);
            printf("Enter Company Name: ");
            fgets((arr+i)->company, 50, stdin);
            printf("Enter Price of Medicine: ");
            scanf("%f", &(arr+i)->price);
            printf("Enter Quantity of Medicine: ");
            scanf("%d", &(arr+i)->quantity);
            printf("\nMedicine Updated!\n");
            return;
        }
    }
    printf("\nID Not Found!\n");
}

//Function to Display Inventory
void displayInventory(struct Medicine *arr, int *totalMedicines){
    printf("\nMedicine Inventory:\n");
    for(int i = 0; i < *totalMedicines; i++){
        printf("ID: %d\nName: %sCompany: %sPrice: %.2f\nQuantity: %d\n", (arr+i)->id, (arr+i)->name, (arr+i)->company, (arr+i)->price, (arr+i)->quantity);
    }
}

//Function to Make Sales
void makeSales(struct Medicine *arr, int *totalMedicines, struct Sales *salesArr, int *totalSales){
    char name[50];
    int quantity;
    printf("\nEnter Name of Medicine to Sale: ");
    getchar();
    fgets(name, 50, stdin);
    for(int i = 0; i < *totalMedicines; i++){
        if(strcmp((arr+i)->name, name) == 0){
            printf("Enter Quantity of Medicine to Sale: ");
            scanf("%d", &quantity);
            if((arr+i)->quantity >= quantity){
                (arr+i)->quantity -= quantity;
                strcpy((salesArr+(*totalSales))->name, name);
                (salesArr+(*totalSales))->quantity = quantity;
                (*totalSales)++;
                printf("\nSale Completed!\n");
                return;
            }
            else{
                printf("\nInsufficient Quantity in Inventory!\n");
                return;
            }
        }
    }
    printf("\nMedicine Not Found!\n");
}

void displaySales(struct Sales *salesArr, int *totalSales){
    printf("\nSales Inventory:\n");
    for(int i = 0; i < *totalSales; i++){
        printf("Name: %sQuantity: %d\n", (salesArr+i)->name, (salesArr+i)->quantity);
    }
}

int main(){
    //Variable Initialization
    struct Medicine medicineArr[100];
    struct Sales salesArr[100];
    int totalMedicines = 0, totalSales = 0, id = 1, choice;
    
    do{
        printf("\n-----------Medical Store Management System-----------\n");
        printf("1. Add New Medicine\n");
        printf("2. Search Medicine\n");
        printf("3. Update Medicine\n");
        printf("4. Display Inventory\n");
        printf("5. Make Sales\n");
        printf("6. Display Sales\n");
        printf("7. Exit\n");

        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: addNewMedicine(medicineArr, &totalMedicines, &id);
                    break;
            case 2: searchMedicine(medicineArr, &totalMedicines);
                    break;
            case 3: updateMedicine(medicineArr, &totalMedicines);
                    break;
            case 4: displayInventory(medicineArr, &totalMedicines);
                    break;
            case 5: makeSales(medicineArr, &totalMedicines, salesArr, &totalSales);
                    break;
            case 6: displaySales(salesArr, &totalSales);
                    break;
            case 7: exit(0);
            default: printf("\nInvalid Choice!\n");
        }
    }while(choice != 7);

    return 0;
}