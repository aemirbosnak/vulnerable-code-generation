//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure of Medicines
typedef struct medicines{
    char name[100];
    float price;
    int quantity;
}medicines;

//Function Definitions
void addMedicine(medicines* , int* );
void deleteMedicine(medicines* , int* );
void displayMedicines(medicines* , int );

//Main Function
int main(){
    int choice, n=0;
    medicines* store = (medicines*)malloc(n*sizeof(medicines));

    do{
        printf("\n\n*** Medical Store Management System ***\n");
        printf("\n1. Add Medicine\n2. Delete Medicine\n3. Display Medicines\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addMedicine(store, &n);
                break;
            case 2:
                deleteMedicine(store, &n);
                break;
            case 3:
                displayMedicines(store, n);
                break;
            case 4:
                printf("\nExiting. Thank you for using the system.");
                break;
            default:
                printf("\nInvalid choice. Please try again.");
        }

    }while(choice!=4);

    return 0;
}

//Add Medicine Function
void addMedicine(medicines* store, int* n){
    char name[100];
    float price;
    int quantity;

    printf("\nEnter Medicine Details\n");
    printf("Name: ");
    scanf("%s", name);
    printf("Price: ");
    scanf("%f", &price);
    printf("Quantity: ");
    scanf("%d", &quantity);

    //Allocate memory to store new Medicine
    *n = *n + 1;
    store = (medicines*)realloc(store, *n*sizeof(medicines));
    strcpy(store[*n-1].name, name);
    store[*n-1].price = price;
    store[*n-1].quantity = quantity;

    printf("\nMedicine added successfully!");
}

//Delete Medicine Function
void deleteMedicine(medicines* store, int* n){
    char name[100];
    int flag=0, i;

    printf("\nEnter name of Medicine to be deleted: ");
    scanf("%s", name);

    //Search for Medicine to be deleted
    for(i=0; i<*n; i++){
        if(strcmp(store[i].name, name)==0){
            flag = 1;
            break;
        }
    }

    //If Medicine found, delete it
    if(flag==1){
        for(; i<*n-1; i++){
            store[i] = store[i+1];
        }
        *n = *n - 1;
        store = (medicines*)realloc(store, *n*sizeof(medicines));
        printf("\nMedicine deleted successfully!");
    }
    else{
        printf("\nMedicine not found in store.");
    }
}

//Display Medicines Function
void displayMedicines(medicines* store, int n){
    if(n==0){
        printf("\nNo medicines found in store.");
    }
    else{
        printf("\n Medicine Name \t Price \t Quantity ");
        printf("\n----------------------------------------------------------");
        for(int i=0; i<n; i++){
            printf("\n %s \t\t %.2f \t %d", store[i].name, store[i].price, store[i].quantity);
        }
    }
}