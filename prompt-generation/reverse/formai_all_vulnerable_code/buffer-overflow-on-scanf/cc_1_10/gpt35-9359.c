//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int quantity;
    float price;
} medicine;

void clearInput(){
    while(getchar() != '\n');
}

void displayMenu(){
    printf("************** WELCOME TO MEDICAL STORE MANAGEMENT SYSTEM **************\n");
    printf("1. Add Medicine\n");
    printf("2. Remove Medicine\n");
    printf("3. Update Medicine\n");
    printf("4. Search Medicine\n");
    printf("5. Display Medicine\n");
    printf("6. Exit\n");
}

int getMenuChoice(){
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    clearInput();
    return choice;
}

void addMedicine(medicine *medicines, int *count){
    printf("Enter Medicine Name: ");
    gets(medicines[*count].name);
    printf("Enter Quantity: ");
    scanf("%d", &medicines[*count].quantity);
    printf("Enter Price: ");
    scanf("%f", &medicines[*count].price);
    clearInput();
    (*count)++;
}

void removeMedicine(medicine *medicines, int *count){
    char name[20];
    printf("Enter Medicine Name: ");
    gets(name);
    for(int i=0;i<*count;i++){
        if(strcmp(medicines[i].name, name) == 0){
            for(int j=i+1;j<*count;j++){
                strcpy(medicines[j-1].name, medicines[j].name);
                medicines[j-1].quantity = medicines[j].quantity;
                medicines[j-1].price = medicines[j].price;
            }
            (*count)--;
            printf("Medicine Removed Successfully!\n");
            return;
        }
    }
    printf("Medicine Not Found!\n");
}

void updateMedicine(medicine *medicines, int count){
    char name[20];
    printf("Enter Medicine Name: ");
    gets(name);
    for(int i=0;i<count;i++){
        if(strcmp(medicines[i].name, name) == 0){
            printf("Enter Quantity: ");
            scanf("%d", &medicines[i].quantity);
            printf("Enter Price: ");
            scanf("%f", &medicines[i].price);
            clearInput();
            printf("Medicine Updated Successfully!\n");
            return;
        }
    }
    printf("Medicine Not Found!\n");
}

void searchMedicine(medicine *medicines, int count){
    char name[20];
    printf("Enter Medicine Name: ");
    gets(name);
    for(int i=0;i<count;i++){
        if(strcmp(medicines[i].name, name) == 0){
            printf("Name: %s\n", medicines[i].name);
            printf("Quantity: %d\n", medicines[i].quantity);
            printf("Price: %.2f\n", medicines[i].price);
            return;
        }
    }
    printf("Medicine Not Found!\n");
}

void displayMedicine(medicine *medicines, int count){
    if(count == 0){
        printf("No Medicine Found!\n");
        return;
    }
    printf("--------------------------------------------------\n");
    printf("|                      MEDICINES                 |\n");
    printf("--------------------------------------------------\n");
    for(int i=0;i<count;i++){
        printf("%-20s %-10d %-10.2f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
    }
    printf("--------------------------------------------------\n");

}

int main(){
    int count = 0;
    medicine medicines[100];
    displayMenu();
    while(1){
        int choice = getMenuChoice();
        switch(choice){
            case 1:
                addMedicine(medicines, &count);
                break;
            case 2:
                removeMedicine(medicines, &count);
                break;
            case 3:
                updateMedicine(medicines, count);
                break;
            case 4:
                searchMedicine(medicines, count);
                break;
            case 5:
                displayMedicine(medicines, count);
                break;
            case 6:
                printf("Thank You for using Medical Store Management System!\n");
                exit(0);
            default:
                printf("Invalid Choice! Try Again.\n");
        }
        displayMenu();
    }
    return 0;
}