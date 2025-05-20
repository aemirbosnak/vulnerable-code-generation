//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STORE_CAPACITY 1000

typedef struct{
    char medicineName[30];
    int medicinePrice;
}Medicine;

Medicine store[MAX_STORE_CAPACITY];
int size = 0;  

void addMedicine()
{
    if(size <= MAX_STORE_CAPACITY){
        printf("Enter Medicine Name: ");
        scanf("%s", &store[size].medicineName);
        printf("Enter Medicine Price: ");
        scanf("%d", &store[size].medicinePrice);
        size++;
        printf("\nMedicine has been Added Successfully!\n");
    } 
    else{
        printf("\nStore is already full!\n");
    }
}

void displayMedicine()
{
    if (size == 0){
        printf("\nThere is no medicine in the store!\n");
    }
    else{
        printf("\nAll Medicines in the store: \n");
        printf("----------------------------\n");
        for(int i=0; i<size; i++){
            printf("Medicine Name: %s \n", store[i].medicineName);
            printf("Medicine Price: %d \n", store[i].medicinePrice);
            printf("----------------------------\n");
        }
    }
}

void searchMedicine(){
    if (size == 0){
        printf("\nThere is no medicine in the store!\n");
    }
    else{
        char searchMedicineName[30];
        printf("Enter Medicine Name to search: ");
        scanf("%s", &searchMedicineName);
        int found = 0;
        printf("\nSearch Result: \n");
        printf("------------------------------\n");
        for(int i=0; i<size; i++){
            if(strcmp(store[i].medicineName, searchMedicineName) == 0){
               printf("Medicine Name: %s \n", store[i].medicineName);
               printf("Medicine Price: %d \n", store[i].medicinePrice);
               printf("------------------------------\n");
               found = 1;
               break;
            }
        }
        if(!found){
            printf("No medicine found for %s\n", searchMedicineName);
        }
    }
}

int main(){
    int choice;
    while(1){
        printf("\nWelcome to XYZ Medical Store\n");
        printf("\n1. Add Medicine\n");
        printf("2. Display Medicine\n");
        printf("3. Search Medicine\n");
        printf("4. Exit\n");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                addMedicine();
                break;
            case 2:
                displayMedicine();
                break;
            case 3:
                searchMedicine();
                break;
            case 4:
                return 0;
            default:
                printf("\nInvalid Input!! Please try again!\n");
        }
    }
 
    return 0;
}