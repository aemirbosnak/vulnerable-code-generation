//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct medicine{
    char name[50];
    int price;
    int quantity;
};

void addMedicine(struct medicine *m, int n){
    printf("\nEnter the name of the medicine: ");
    scanf("%s", m[n].name);
    printf("Enter the price of the medicine: ");
    scanf("%d", &m[n].price);
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &m[n].quantity);
}

void displayMedicine(struct medicine m[], int n){
    printf("\nName\tPrice\tQuantity");
    for(int i=0; i<n; i++){
        printf("\n%s\t%d\t%d", m[i].name, m[i].price, m[i].quantity);
    }
}

void searchMedicine(struct medicine m[], int n, char name[50]){
    printf("\nEnter the name of the medicine to search: ");
    scanf("%s", name);
    for(int i=0; i<n; i++){
        if(strcmp(m[i].name, name) == 0){
            printf("\nName: %s", m[i].name);
            printf("\nPrice: %d", m[i].price);
            printf("\nQuantity: %d", m[i].quantity);
        }
    }
}

void updateQuantity(struct medicine m[], int n){
    printf("\nEnter the name of the medicine to update quantity: ");
    char name[50];
    scanf("%s", name);
    for(int i=0; i<n; i++){
        if(strcmp(m[i].name, name) == 0){
            printf("\nEnter the new quantity: ");
            scanf("%d", &m[i].quantity);
        }
    }
}

void main(){
    struct medicine m[MAX];
    int n;

    printf("\nEnter the number of medicines: ");
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        addMedicine(m, i);
    }

    displayMedicine(m, n);

    char name[50];
    while(1){
        printf("\nPress 1 to search medicine\nPress 2 to update quantity\nPress 0 to exit");
        scanf("%d", &n);
        switch(n){
            case 1:
                printf("\nEnter the name of the medicine to search: ");
                scanf("%s", name);
                searchMedicine(m, n, name);
                break;
            case 2:
                updateQuantity(m, n);
                displayMedicine(m, n);
                break;
            case 0:
                exit(0);
            default:
                printf("\nInvalid choice");
        }
    }
}