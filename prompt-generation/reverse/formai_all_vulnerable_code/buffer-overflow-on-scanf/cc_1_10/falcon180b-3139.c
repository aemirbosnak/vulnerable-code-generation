//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct medicine{
    char name[20];
    char company[20];
    int price;
    int quantity;
};

void addMedicine(struct medicine *m, int n){
    printf("\nEnter Medicine Name: ");
    scanf("%s", m[n].name);

    printf("\nEnter Company Name: ");
    scanf("%s", m[n].company);

    printf("\nEnter Price: ");
    scanf("%d", &m[n].price);

    printf("\nEnter Quantity: ");
    scanf("%d", &m[n].quantity);
}

void displayMedicine(struct medicine *m, int n){
    printf("\nMedicine Name: %s", m[n].name);
    printf("\nCompany Name: %s", m[n].company);
    printf("\nPrice: %d", m[n].price);
    printf("\nQuantity: %d", m[n].quantity);
}

void searchMedicine(struct medicine *m, int n, char name[20]){
    int flag = 0;
    for(int i=0; i<n; i++){
        if(strcmp(m[i].name, name) == 0){
            printf("\nMedicine Found!");
            displayMedicine(m, i);
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        printf("\nMedicine Not Found!");
    }
}

void main(){
    struct medicine m[MAX];
    int n;

    printf("\nEnter number of medicines: ");
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        addMedicine(m, i);
    }

    char name[20];
    while(1){
        printf("\nEnter 1 to add medicine\nEnter 2 to display all medicines\nEnter 3 to search medicine by name\nEnter 4 to exit");
        scanf("%d", &n);

        switch(n){
            case 1:
                addMedicine(m, n);
                break;

            case 2:
                for(int i=0; i<n; i++){
                    displayMedicine(m, i);
                }
                break;

            case 3:
                printf("\nEnter medicine name to search: ");
                scanf("%s", name);
                searchMedicine(m, n, name);
                break;

            case 4:
                exit(0);

            default:
                printf("\nInvalid choice!");
        }
    }
}