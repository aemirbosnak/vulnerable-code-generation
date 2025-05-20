//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct medicine{
    char name[50];
    int quantity;
    float price;
};

void addMedicine(struct medicine inventory[], int size);
void displayMedicine(struct medicine inventory[], int size);
void searchMedicine(struct medicine inventory[], int size);
void updateMedicine(struct medicine inventory[], int size);
void deleteMedicine(struct medicine inventory[], int size);

int main(){
    int option, size = 0;
    struct medicine inventory[100];
    do{
        printf("\n-------------- Medical Store Management System --------------\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicine\n");
        printf("3. Search Medicine\n");
        printf("4. Update Medicine\n");
        printf("5. Delete Medicine\n");
        printf("6. Exit\n");
        printf("----------------------------------------------------------------\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        switch(option){
            case 1:
                addMedicine(inventory, size);
                size++;
                break;
            case 2:
                displayMedicine(inventory, size);
                break;
            case 3:
                searchMedicine(inventory, size);
                break;
            case 4:
                updateMedicine(inventory, size);
                break;
            case 5:
                deleteMedicine(inventory, size);
                size--;
                break;
            case 6:
                printf("Exiting Program...\n\n");
                break;
            default:
                printf("Invalid option! Please enter a valid option.\n");
        }
    }while(option != 6);
    return 0;
}

void addMedicine(struct medicine inventory[], int size){
    printf("\n-------------- Add Medicine --------------\n");
    printf("Enter Medicine Name: ");
    scanf("%s", inventory[size].name);
    printf("Enter Medicine Quantity: ");
    scanf("%d", &inventory[size].quantity);
    printf("Enter Medicine Price: ");
    scanf("%f", &inventory[size].price);
    printf("\nMedicine added successfully!\n");
}

void displayMedicine(struct medicine inventory[], int size){
    printf("\n-------------- Display Medicine --------------\n");
    printf("%-30s %-15s %-10s\n", "Medicine Name", "Quantity", "Price");
    for(int i=0;i<size;i++){
        printf("%-30s %-15d %-10.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    printf("\n");
}

void searchMedicine(struct medicine inventory[], int size){
    char searchingName[50];
    int found = 0;
    printf("\n-------------- Search Medicine --------------\n");
    printf("Enter name of medicine to search: ");
    scanf("%s", searchingName);
    for(int i=0;i<size && found==0;i++){
        if(strcmp(inventory[i].name, searchingName) == 0){
            printf("%-30s %-15s %-10s\n", "Medicine Name", "Quantity", "Price");
            printf("%-30s %-15d %-10.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
            found = 1;
        }
    }
    if(found == 0){
        printf("\nMedicine not found!\n\n");
    }
}

void updateMedicine(struct medicine inventory[], int size){
    char updateName[50];
    int found = 0;
    printf("\n-------------- Update Medicine --------------\n");
    printf("Enter name of medicine to be updated: ");
    scanf("%s", updateName);
    for(int i=0;i<size && found==0;i++){
        if(strcmp(inventory[i].name, updateName) == 0){
            printf("Enter updated name of medicine: ");
            scanf("%s", inventory[i].name);
            printf("Enter updated quantity of medicine: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter updated price of medicine: ");
            scanf("%f", &inventory[i].price);
            printf("\nMedicine updated successfully!\n");
            found = 1;
        }
    }
    if(found == 0){
        printf("\nMedicine not found!\n\n");
    }
}

void deleteMedicine(struct medicine inventory[], int size){
    char deleteName[50];
    int found = 0, index;
    printf("\n-------------- Delete Medicine --------------\n");
    printf("Enter name of medicine to be deleted: ");
    scanf("%s", deleteName);
    for(int i=0;i<size && found==0;i++){
        if(strcmp(inventory[i].name, deleteName) == 0){
            index = i;
            found = 1;
        }
    }
    if(found == 0){
        printf("\nMedicine not found!\n\n");
    }
    else{
        for(int i=index;i<size-1;i++){
            strcpy(inventory[i].name, inventory[i+1].name);
            inventory[i].quantity = inventory[i+1].quantity;
            inventory[i].price = inventory[i+1].price;
        }
        printf("\nMedicine deleted successfully!\n");
    }
}