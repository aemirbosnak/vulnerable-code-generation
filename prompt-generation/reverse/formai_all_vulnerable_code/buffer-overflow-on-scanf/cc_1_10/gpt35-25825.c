//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50

struct medicine{
    char name[MAX];
    int quantity;
    float price;
}med[MAX];

void addMedicine(int n){
    for(int i=0; i<n; i++){
        printf("\nEnter medicine name: ");
        scanf("%s", med[i].name);
        printf("Enter quantity: ");
        scanf("%d", &med[i].quantity);
        printf("Enter price: ");
        scanf("%f", &med[i].price);
    }
}

void displayMedicine(int n){
    printf("\nName\tQuantity\tPrice\n");
    for(int i=0; i<n; i++){
        printf("%s\t%d\t%.2f\n", med[i].name, med[i].quantity, med[i].price);
    }
}

void searchMedicine(int n){
    char medName[MAX];
    printf("\nEnter medicine name: ");
    scanf("%s", medName);
    for(int i=0; i<n; i++){
        if(strcmp(medName, med[i].name)==0){
            printf("Name: %s\nQuantity: %d\nPrice: %.2f\n", med[i].name, med[i].quantity, med[i].price);
            return;
        }
    }
    printf("Medicine not found.\n");
}

int main(){
    int choice, num;
    printf("Enter number of medicines in stock: ");
    scanf("%d", &num);
    addMedicine(num);
    while(1){
        printf("\nChoose an option:\n1. Add medicine\n2. Display medicine\n3. Search medicine\n4. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                addMedicine(num);
                break;
            case 2:
                displayMedicine(num);
                break;
            case 3:
                searchMedicine(num);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Choose again.\n");
        }
    }
    return 0;
}