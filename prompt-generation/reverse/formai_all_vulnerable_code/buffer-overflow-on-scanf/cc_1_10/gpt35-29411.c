//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Medicine {
    char name[100];
    int stock;
    float price;
};

void printMedicine(struct Medicine med) {
    printf("\n %s \t\t %d \t\t $%.2f",med.name, med.stock, med.price);
}

void addNewMedicine(struct Medicine *med, int n) {
    for(int i=0;i<n;i++) {
        printf("\nEnter name of medicine: ");
        scanf("%s",(med+i)->name);
        printf("Enter stock of medicine: ");
        scanf("%d",&(med+i)->stock);
        printf("Enter price of medicine: ");
        scanf("%f",&(med+i)->price);
    }
}

void displayMedicine(struct Medicine *med, int n) {
    printf("\n\nName\t\tStock\t\tPrice");
    for(int i=0;i<n;i++) {
        printMedicine(*(med+i));
    }
    printf("\n");
}

void searchMedicine(struct Medicine *med, int n, char name[100]) {
    printf("\n\nName\t\tStock\t\tPrice");
    for(int i=0;i<n;i++) {
        if(strcmp((med+i)->name,name)==0) {
            printMedicine(*(med+i));
            return;
        }
    }
    printf("\n\nSorry!! Medicine with name \"%s\" not found in stock",name);
}

void decreaseStock(struct Medicine *med, int n, char name[100], int quantity) {
    for(int i=0;i<n;i++) {
        if(strcmp((med+i)->name,name)==0) {
            if(quantity>=(med+i)->stock) {
                printf("\n\nSorry, we only have %d stock of %s.\n", (med+i)->stock, name);
                (med+i)->stock = 0;
            } else {
                (med+i)->stock -= quantity;
                printf("\n\nSuccessfully decreased %d stock of %s.\n", quantity, name);
            }
            return;
        }
    }
    printf("\n\nSorry!! Medicine with name \"%s\" not found in stock",name);
}

void increaseStock(struct Medicine *med, int n, char name[100], int quantity) {
    for(int i=0;i<n;i++) {
        if(strcmp((med+i)->name,name)==0) {
            (med+i)->stock += quantity;
            printf("\n\nSuccessfully increased %d stock of %s.\n", quantity, name);
            return;
        }
    }
    printf("\n\nSorry!! Medicine with name \"%s\" not found in stock",name);
}

int main() {
    int n, choice, quantity;
    char name[100];
    struct Medicine *med;
    
    printf("Enter number of medicines in stock: ");
    scanf("%d",&n);
    
    //allocate memory to store medicine data
    med = (struct Medicine*)malloc(n*sizeof(struct Medicine));
    
    //add medicine to stock
    addNewMedicine(med,n);
    
    do {
        printf("\n\n---------- MEDICAL STORE MANAGEMENT SYSTEM ----------");
        printf("\n1. Display all medicines.");
        printf("\n2. Search medicine by name.");
        printf("\n3. Decrease stock.");
        printf("\n4. Increase stock.");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        
        switch(choice) {
            case 1:
                //display all medicines
                displayMedicine(med,n);
                break;
            case 2:
                //search medicine by name
                printf("\nEnter medicine name to search: ");
                scanf("%s",name);
                searchMedicine(med,n,name);
                break;
            case 3:
                //decrease stock
                printf("\nEnter medicine name for which stock needs to decrease: ");
                scanf("%s",name);
                printf("Enter quantity: ");
                scanf("%d",&quantity);
                decreaseStock(med,n,name,quantity);
                break;
            case 4:
                //increase stock
                printf("\nEnter medicine name for which stock needs to increase: ");
                scanf("%s",name);
                printf("Enter quantity: ");
                scanf("%d",&quantity);
                increaseStock(med,n,name,quantity);
                break;
            case 0:
                //exit
                free(med);
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice...Please enter a valid choice!!!");
        }
    }while(choice!=0);
    return 0;
}