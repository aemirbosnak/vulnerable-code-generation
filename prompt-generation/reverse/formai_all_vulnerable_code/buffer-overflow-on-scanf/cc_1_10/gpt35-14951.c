//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    char name[30];
    int price;
    int quantity;
} Medicine;

void populateMeds(Medicine *meds, int size){
    for(int i=0; i<size; i++){
        printf("\nEnter the details of Medicine %d:\n", i+1);
        printf("Name: ");
        scanf("%s", (meds+i)->name);

        printf("Price: ");
        scanf("%d", &(meds+i)->price);

        printf("Quantity: ");
        scanf("%d", &(meds+i)->quantity);
    }
}

void displayMeds(Medicine *meds, int size){
    printf("\nMedicine Details:\n");
    printf("_____________________\n");
    printf("Name\tPrice\tQuantity\n");
    for(int i=0; i<size; i++){
        printf("%s\t%d\t%d\n", (meds+i)->name, (meds+i)->price, (meds+i)->quantity);
    }
}

void orderMeds(Medicine *meds, int size){
    int order_quantity, flag=0;
    char order_name[30];
    printf("\nEnter the name of the medicine to order: ");
    scanf("%s", order_name);
    
    for(int i=0; i<size; i++){
        if(strcmp((meds+i)->name,order_name)==0){
            printf("\nEnter the quantity to be ordered: ");
            scanf("%d", &order_quantity);
            if(order_quantity > (meds+i)->quantity){
                printf("\nNot enough stock available.");
                flag=1;
                break;
            }
            else{
                (meds+i)->quantity -= order_quantity;
                printf("\nOrder successfully placed!");
                flag = 1;
                break;
            }
        }
    }
    if(flag==0){
        printf("\nMedicine not found in the inventory.");
    }
}

void addMeds(Medicine *meds, int size){
    int add_quantity, flag=0;
    char add_name[30];
    printf("\nEnter the name of the medicine to add: ");
    scanf("%s", add_name);
    
    for(int i=0; i<size; i++){
        if(strcmp((meds+i)->name,add_name)==0){
            printf("\nEnter the quantity to be added: ");
            scanf("%d", &add_quantity);
            (meds+i)->quantity += add_quantity;
            printf("\nStock successfully added!");
            flag = 1;
            break;
        }
    }
    if(flag==0){
        printf("\nMedicine not found in the inventory.");
    }
}

int main(){
    int choice, num_meds;
    printf("Enter the number of medicines to be added: ");
    scanf("%d", &num_meds);

    Medicine *meds = (Medicine*) malloc(num_meds*sizeof(Medicine));

    if(meds == NULL){
        printf("\nMemory allocation failed!");
        return 0;
    }

    populateMeds(meds, num_meds);

    do{
        printf("\n\nMedical Store Management System.\n");
        printf("1. Display all medicines\n");
        printf("2. Order medicine\n");
        printf("3. Add medicine to inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                displayMeds(meds, num_meds);
                break;
            case 2:
                orderMeds(meds, num_meds);
                break;
            case 3:
                addMeds(meds, num_meds);
                break;
            case 4:
                printf("\nExiting program...");
                break;
            default:
                printf("\nInvalid choice. Try again!");
        }
    }while(choice!=4);

    free(meds);

    return 0;
}