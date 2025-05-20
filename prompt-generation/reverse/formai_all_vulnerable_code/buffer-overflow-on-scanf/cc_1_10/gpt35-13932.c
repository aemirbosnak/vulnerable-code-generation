//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Defining Structure for Medicine
struct medicine{
    char name[25];
    char company[15];
    int quantity;
    float price;
};

//Defining Function to Add Medicine
void addMedicine(struct medicine add[], int n){
    for (int i = 0; i < n; i++){
        printf("Enter the name of Medicine %d: ", i+1);
        scanf("%s", add[i].name);
        printf("Enter the company of Medicine %d: ", i+1);
        scanf("%s", add[i].company);
        printf("Enter the quantity of Medicine %d: ", i+1);
        scanf("%d", &add[i].quantity);
        printf("Enter the price of Medicine %d: ", i+1);
        scanf("%f", &add[i].price);
    }
}

//Defining Function to Search Medicine
void searchMedicine(struct medicine search[], int n, char name[]){
    int flag = 0;
    for (int i = 0; i < n; i++){
        if (strcmp(name, search[i].name) == 0){
            printf("Name of Medicine: %s\n", search[i].name);
            printf("Company of Medicine: %s\n", search[i].company);
            printf("Quantity Available: %d\n", search[i].quantity);
            printf("Price of Medicine: %.2f\n", search[i].price);
            flag = 1;
            break;
        }
    }
    if (flag == 0){
        printf("The Medicine is not available in the store.");
    }
}

//Defining Function to Edit Medicine
void editMedicine(struct medicine edit[], int n, char name[]){
    int flag = 0;
    for (int i = 0; i < n; i++){
        if (strcmp(name, edit[i].name) == 0){
            printf("Enter the new quantity of Medicine %s: ", name);
            scanf("%d", &edit[i].quantity);
            printf("Enter the new price of Medicine %s: ", name);
            scanf("%f", &edit[i].price);
            flag = 1;
            break;
        }
    }
    if (flag == 0){
        printf("The Medicine is not available in the store.");
    }
}

//Defining Main Function
int main(){
    struct medicine med[100];
    int choice, n = 0;
    char name[25];
    printf("\n*****C Medical Store Management System*****\n\n");

    //Defining Infinity Loop Until User Presses '5' to Exit
    while (1){
        printf("\nEnter 1 to Add Medicine\n");
        printf("Enter 2 to Search Medicine\n");
        printf("Enter 3 to Edit Medicine\n");
        printf("Enter 4 to View All Medicines\n");
        printf("Enter 5 to Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        //Switch Statement for User's Choice
        switch (choice){
        case 1:
            printf("How many Medicines do you want to add? ");
            scanf("%d", &n);
            addMedicine(med, n);
            break;

        case 2:
            printf("Enter the name of Medicine you want to search: ");
            scanf("%s", name);
            searchMedicine(med, n, name);
            break;

        case 3:
            printf("Enter the name of Medicine you want to Edit: ");
            scanf("%s", name);
            editMedicine(med, n, name);
            break;

        case 4:
            printf("%-25s%-15s%-10s%-10s\n", "Name", "Company", "Quantity", "Price");
            for (int i = 0; i < n; i++){
                printf("%-25s%-15s%-10d%-10.2f\n", med[i].name, med[i].company, med[i].quantity, med[i].price);
            }
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid Choice! Try Again.\n");
        }
    }
    return 0;
}