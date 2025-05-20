//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: visionary
#include<stdio.h>
#include<string.h>

struct medicine{
    char name[100];
    char generic[100];
    int qty, price;
}med[100];

void addMedicine(){
    int n, i;
    printf("\nEnter the number of medicines to be added: ");
    scanf("%d", &n);
    for(i=0;i<n;i++){
        printf("\nEnter the name of the medicine: ");
        scanf("%s", med[i].name);
        printf("\nEnter the generic name of the medicine: ");
        scanf("%s", med[i].generic);
        printf("\nEnter the quantity of the medicine: ");
        scanf("%d", &med[i].qty);
        printf("\nEnter the price of the medicine: ");
        scanf("%d", &med[i].price);
    }
}

void searchMedicine(){
    int i, flag=0;
    char s[100];
    printf("\nEnter the name of the medicine to be searched: ");
    scanf("%s", s);
    for(i=0;i<100;i++){
        if(strcmp(med[i].name, s)==0){
            printf("\nMedicine Found!!!");
            printf("\nName: %s", med[i].name);
            printf("\nGeneric Name: %s", med[i].generic);
            printf("\nQuantity: %d", med[i].qty);
            printf("\nPrice: %d", med[i].price);
            flag++;
            break;
        }
    }
    if(flag==0){
        printf("\nMedicine Not Found!!");
    }
}

void viewInventory(){
    int i;
    printf("\nCurrent Medicine Inventory: \n");
    printf("-------------------------------------------------\n");
    printf("Name\t\tGeneric Name\t\tQuantity\tPrice\n");
    printf("-------------------------------------------------\n");
    for(i=0;i<100;i++){
        if(med[i].qty!=0){
            printf("%s\t\t%s\t\t\t%d\t\t%d\n", med[i].name, med[i].generic, med[i].qty, med[i].price);
        }
    }
}

void deleteMedicine(){
    int i;
    char s[100];
    printf("\nEnter the name of the medicine to be deleted: ");
    scanf("%s", s);
    for(i=0;i<100;i++){
        if(strcmp(med[i].name, s)==0){
            med[i].qty=0;
            med[i].price=0;
            printf("\nMedicine Deleted Successfully!!");
            break;
        }
    }
}

int main(){

    printf("=================================================\n");
    printf("  Welcome to Medical Store Management System\n");
    printf("=================================================\n");


    while(1){

        int choice;

        printf("\n\n1. Add Medicine(s)\n");
        printf("2. Search Medicine\n");
        printf("3. View Inventory\n");
        printf("4. Delete Medicine\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){

            case 1: addMedicine();
                    break;

            case 2: searchMedicine();
                    break;

            case 3: viewInventory();
                    break;

            case 4: deleteMedicine();
                    break;

            case 5: printf("\nExiting....\n");
                    return 0;

            default: printf("\nInvalid choice!!!");
                    break;
        }
    }
    return 0;
}