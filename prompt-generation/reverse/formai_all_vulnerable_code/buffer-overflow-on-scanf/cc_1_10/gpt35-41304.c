//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct medicine{
    char name[20];
    int id;
    int stock;
    double price;
}medicine;

medicine meds[50];
int num_meds = 0;

void add_medicine(){
    char name[20];
    int id, stock;
    double price;
    printf("Enter medicine name: ");
    scanf("%s", name);
    printf("Enter medicine ID: ");
    scanf("%d", &id);
    printf("Enter medicine stock: ");
    scanf("%d", &stock);
    printf("Enter medicine price: ");
    scanf("%lf", &price);
    strcpy(meds[num_meds].name, name);
    meds[num_meds].id = id;
    meds[num_meds].stock = stock;
    meds[num_meds].price = price;
    num_meds++;
}

void view_medicine(){
    int i;
    printf("Name\tID\tStock\tPrice\n");
    for(i = 0; i < num_meds; i++){
        printf("%s\t%d\t%d\t%.2lf\n", meds[i].name, meds[i].id, meds[i].stock, meds[i].price);
    }
}

void purchase_medicine(){
    int id, qty, i;
    printf("Enter medicine ID: ");
    scanf("%d", &id);
    for(i = 0; i < num_meds; i++){
        if(meds[i].id == id){
            printf("Enter quantity: ");
            scanf("%d", &qty);
            if(meds[i].stock >= qty){
                printf("Total cost: %.2lf gold coins\n", qty * meds[i].price);
                meds[i].stock -= qty;
                return;
            }else{
                printf("Not enough stock!\n");
                return;
            }
        }
    }
    printf("Medicine not found!\n");
}

void menu(){
    printf("Welcome to the Medieval Medical Store Management System\n");
    printf("1. Add medicine\n");
    printf("2. View medicine\n");
    printf("3. Purchase medicine\n");
    printf("4. Exit\n");
}

int main(){
    int choice;
    do{
        menu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: 
                add_medicine();
                break;
            case 2: 
                view_medicine();
                break;
            case 3: 
                purchase_medicine();
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default: 
                printf("Invalid choice!\n");
        }
    }while(choice != 4);
    return 0;
}