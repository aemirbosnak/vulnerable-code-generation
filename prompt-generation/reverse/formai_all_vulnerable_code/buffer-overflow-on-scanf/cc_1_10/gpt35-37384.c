//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int id;
    char name[20];
    float price;
    int quantity;
}drug;

int count=0;
drug *store;

void addDrug(){
    store=(drug*)realloc(store, sizeof(drug)*(count+1));
    printf("\nEnter drug id: ");
    scanf("%d", &store[count].id);
    printf("Enter drug name: ");
    scanf("%s", store[count].name);
    printf("Enter drug price: ");
    scanf("%f", &store[count].price);
    printf("Enter drug quantity: ");
    scanf("%d", &store[count].quantity);
    count++;
    printf("\nDrug added successfully!\n");
}

void deleteDrug(int id){
    int found=-1;
    for(int i=0;i<count;i++){
        if(store[i].id==id){
            found=i;
            break;
        }
    }
    if(found==-1){
        printf("No drug found for ID: %d\n",id);
    }
    else{
        store[found]=store[count-1];
        store=(drug*)realloc(store, sizeof(drug)*(count-1));
        count--;
        printf("Drug deleted successfully!\n");
    }
}

void searchDrug(int id){
    int found=-1;
    for(int i=0;i<count;i++){
        if(store[i].id==id){
            found=i;
            break;
        }
    }
    if(found==-1){
        printf("No drug found for ID: %d\n",id);
    }
    else{
        printf("\nDrug ID: %d\nDrug Name: %s\nDrug Price: %.2f\nDrug Quantity: %d\n", store[found].id, store[found].name, store[found].price, store[found].quantity);
    }
}

void viewAll(){
    if(count==0){
        printf("No drugs available in store.\n");
    }
    else{
        printf("\n----------------------------------------\n");
        printf("ID\t\tNAME\t\tPRICE\t\tQUANTITY\n");
        printf("----------------------------------------\n");
        for(int i=0;i<count;i++){
            printf("%d\t\t%s\t\t%.2f\t\t%d\n", store[i].id, store[i].name, store[i].price, store[i].quantity);
        }
        printf("----------------------------------------\n");
    }
}

int main(){
    int choice,id;
    store=(drug*)malloc(sizeof(drug)*count);
    while(1){
        printf("\nWELCOME TO MEDICAL STORE MANAGEMENT SYSTEM\n");
        printf("1. Add drug\n");
        printf("2. Delete drug\n");
        printf("3. Search drug\n");
        printf("4. View all drugs\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                addDrug();
                break;
            case 2:
                printf("\nEnter drug id to delete: ");
                scanf("%d", &id);
                deleteDrug(id);
                break;
            case 3:
                printf("\nEnter drug id to search: ");
                scanf("%d", &id);
                searchDrug(id);
                break;
            case 4:
                viewAll();
                break;
            case 5:
                printf("\nThank you for using our system!\n");
                return 0;
            default:
                printf("\nInvalid choice!\n");
        }
    }
    return 0;
}