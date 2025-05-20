//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct medicine{
    int med_id;
    char med_name[100];
    float price;
    int quantity;
};

void display(struct medicine med[], int n){
    //function to display the medicine details
    int i;
    printf("\nMedicine Details:\n");
    printf("ID\tMedicine Name\tPrice\tQuantity\n");
    for(i=0;i<n;i++){
        printf("%d\t%s\t%.2f\t%d\n", med[i].med_id, med[i].med_name, med[i].price, med[i].quantity);
    }
}

int findMed(struct medicine med[], int n, int id){
    //function to find medicine by id
    int i;
    for(i=0;i<n;i++){
        if(med[i].med_id==id){
            return i;
        }
    }
    return -1;
}

void add(struct medicine med[], int *n){
    //function to add a new medicine to the system
    printf("\nEnter Medicine Details:\n");
    printf("ID: ");
    scanf("%d", &(med[*n].med_id));
    printf("Medicine Name: ");
    scanf("%s", med[*n].med_name);
    printf("Price: ");
    scanf("%f", &(med[*n].price));
    printf("Quantity: ");
    scanf("%d", &(med[*n].quantity));
    (*n)++;
}

void update(struct medicine med[], int n){
    //function to update medicine details
    int id, index;
    printf("\nEnter Medicine ID to Update: ");
    scanf("%d", &id);
    index=findMed(med, n, id);
    if(index==-1){
        printf("\nMedicine not found.\n");
    }
    else{
        printf("\nEnter Updated Details:\n");
        printf("Medicine Name: ");
        scanf("%s", med[index].med_name);
        printf("Price: ");
        scanf("%f", &(med[index].price));
        printf("Quantity: ");
        scanf("%d", &(med[index].quantity));
    }
}

void sell(struct medicine med[], int n){
    //function to sell medicine
    int id, index, quantity;
    printf("\nEnter Medicine ID to Sell: ");
    scanf("%d", &id);
    index=findMed(med, n, id);
    if(index==-1){
        printf("\nMedicine not found.\n");
    }
    else{
        printf("Enter Quantity to Sell: ");
        scanf("%d", &quantity);
        if(quantity>med[index].quantity){
            printf("\nInsufficient Quantity!\n");
        }
        else{
            med[index].quantity-=quantity;
            printf("\nTotal Amount: %.2f\n", quantity*med[index].price);
        }
    }
}

int main(){
    struct medicine med[100];
    int n=0, choice, id;

    do{
        printf("\nMedical Store Management System\n");
        printf("1. Add Medicine\n");
        printf("2. Update Medicine\n");
        printf("3. Sell Medicine\n");
        printf("4. Display Medicine List\n");
        printf("5. Exit\n");
        printf("Enter your Choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                add(med, &n);
                break;
            case 2:
                update(med, n);
                break;
            case 3:
                sell(med, n);
                break;
            case 4:
                display(med, n);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("\nInvalid Choice!\n");
        }

    }while(choice!=5);

    return 0;
}