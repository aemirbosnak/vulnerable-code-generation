//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: creative
#include<stdio.h>
#include<string.h> 

struct medicine{
    char name[100];
    int quantity;
    float price;
    char manufacturer[100];
}med[100];

int count;

void addMedicine(){
    printf("\nEnter Medicine Details: \n");
    printf("Name: ");
    scanf("%s", &med[count].name);
    printf("Quantity: ");
    scanf("%d", &med[count].quantity);
    printf("Price: ");
    scanf("%f", &med[count].price);
    printf("Manufacturer: ");
    scanf("%s", &med[count].manufacturer);
    count++;
}

void searchMedicine(){
    char name[100];
    printf("\nEnter Name of the Medicine to be Searched: ");
    scanf("%s", &name);

    for(int i=0; i<count; i++){
        if(strcmp(name, med[i].name)==0){
            printf("\nMedicine Found!!\n");
            printf("Name: %s\nQuantity: %d\nPrice: %.2f\nManufacturer: %s\n\n", med[i].name, med[i].quantity, med[i].price, med[i].manufacturer);
            return;
        }
    }
    printf("\n Sorry Medicine Not Found\n\n");
}

void buyMedicine(){
    char name[100];
    int quantity;
    printf("\nEnter Name of the Medicine to be Bought: ");
    scanf("%s", &name);
    printf("Enter Quantity: ");
    scanf("%d", &quantity);

    for(int i=0; i<count; i++){
        if(strcmp(name, med[i].name)==0){
            if(quantity<=med[i].quantity){
                printf("\nPurchase Successful!!\n");
                med[i].quantity -= quantity;
                printf("Total Cost: %.2f\n\n", quantity*med[i].price);
                return;
            }
            else{
                printf("\nSorry, Quantity Not Available!!\n\n");
                return;
            }
        }
    }
    printf("\n Sorry Medicine Not Found\n\n");
}

void displayMedicine(){
    if(count==0){
        printf("\nNo Entries Found\n\n");
    }
    else{
        printf("\nMedicine Details: \n");
        for(int i=0; i<count; i++){
            printf("\nMedicine %d", i+1);
            printf("\nName: %s\nQuantity: %d\nPrice: %.2f\nManufacturer: %s\n", med[i].name, med[i].quantity, med[i].price, med[i].manufacturer);
        }
    }
}

void main(){
    int choice;
    count = 0;

    do{
        printf("****Welcome to Medical Store Management System****\n");
        printf("1. Add Medicine \n2. Search Medicine \n3. Buy Medicine \n4. Display Medicine \n5. Exit \nEnter Your Choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: addMedicine();
                    break;
            case 2: searchMedicine();
                    break;
            case 3: buyMedicine();
                    break;
            case 4: displayMedicine();
                    break;
            default: printf("\nInvalid Choice!!\n\n");
        }
    }while(choice!=5);

}