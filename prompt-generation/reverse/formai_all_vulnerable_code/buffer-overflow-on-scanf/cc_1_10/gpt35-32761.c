//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// defining a structure to hold the information about medical drugs
struct drug{
    char name[50];
    char company[50];
    float price;
    int quantity;
};

// global instances to store the drugs database details
struct drug drugs[100];
int num_of_drugs = 0;

// function to add a new drug to the database
void add_drug(){
    printf("Enter the name of drug : ");
    scanf("%s", drugs[num_of_drugs].name);
    printf("Enter the company of drug : ");
    scanf("%s", drugs[num_of_drugs].company);
    printf("Enter the price of drug : ");
    scanf("%f", &drugs[num_of_drugs].price);
    printf("Enter the quantity of drug : ");
    scanf("%d", &drugs[num_of_drugs].quantity);
    num_of_drugs++;
}

// function to display all the drugs in the database
void display_drugs(){
    if(num_of_drugs == 0){
        printf("No drugs in the store!\n");
        return;
    }
    printf("Name\tCompany\tPrice\tQuantity\n");
    for(int i=0;i<num_of_drugs;i++){
        printf("%s\t%s\t%.2f\t%d\n", drugs[i].name, drugs[i].company, drugs[i].price, drugs[i].quantity);
    }
}

// function to search for a drug by name
void search_drug(){
    if(num_of_drugs == 0){
        printf("No drugs in the store!\n");
        return;
    }
    char name[50];
    printf("Enter the name of drug to search : ");
    scanf("%s", name);
    for(int i=0;i<num_of_drugs;i++){
        if(strcmp(drugs[i].name, name) == 0){
            printf("Name\tCompany\tPrice\tQuantity\n");
            printf("%s\t%s\t%.2f\t%d\n", drugs[i].name, drugs[i].company, drugs[i].price, drugs[i].quantity);
            return;
        }
    }
    printf("Drug not found!\n");
}

// function to sell a drug from the store
void sell_drug(){
    if(num_of_drugs == 0){
        printf("No drugs in the store!\n");
        return;
    }
    char name[50];
    int quantity;
    printf("Enter the name of drug to sell : ");
    scanf("%s", name);
    for(int i=0;i<num_of_drugs;i++){
        if(strcmp(drugs[i].name, name) == 0){
            printf("Enter the quantity of drug to sell : ");
            scanf("%d", &quantity);
            if(quantity <= drugs[i].quantity){
                drugs[i].quantity -= quantity;
                printf("Total cost : %.2f\n", drugs[i].price*quantity);
                return;
            }else{
                printf("Not enough quantity available!\n");
                return;
            }
        }
    }
    printf("Drug not found!\n");
}

int main(){
    printf("Welcome to the Medical Store Management System\n");
    int choice;
    while(1){
        printf("\nMenu:\n");
        printf("1. Add new drug\n");
        printf("2. Display all drugs\n");
        printf("3. Search for a drug\n");
        printf("4. Sell a drug\n");
        printf("5. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                add_drug();
                break;
            case 2:
                display_drugs();
                break;
            case 3:
                search_drug();
                break;
            case 4:
                sell_drug();
                break;
            case 5:
                printf("Thank you for using our system!\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}