//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct medicine{
    char name[50];
    char company[50];
    float price;
    int quantity;
};

typedef struct medicine Medicine;

void add_medicine(Medicine m[], int index){
    printf("Enter name of medicine: ");
    scanf("%s",m[index].name);
    printf("Enter company name: ");
    scanf("%s",m[index].company);
    printf("Enter price: ");
    scanf("%f",&m[index].price);
    printf("Enter quantity: ");
    scanf("%d",&m[index].quantity);
}

void display_medicines(Medicine m[], int n){
    printf("Name\t\tCompany\t\tPrice\tQuantity\n");
    for(int i=0;i<n;i++){
        printf("%s\t\t%s\t\t%f\t%d\n",m[i].name,m[i].company,m[i].price,m[i].quantity);
    }
}

void search_medicine(Medicine m[], int n, char name[]){
    int flag = 0;
    for(int i=0;i<n;i++){
        if(strcmp(m[i].name,name) == 0){
            printf("%s\t\t%s\t\t%f\t%d\n",m[i].name,m[i].company,m[i].price,m[i].quantity);
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        printf("Medicine not found!\n");
    }
}

void update_medicine(Medicine m[], int n, char name[]){
    int flag = 0;
    for(int i=0;i<n;i++){
        if(strcmp(m[i].name,name) == 0){
            printf("Enter new details:\n");
            printf("Enter company name: ");
            scanf("%s",m[i].company);
            printf("Enter price: ");
            scanf("%f",&m[i].price);
            printf("Enter quantity: ");
            scanf("%d",&m[i].quantity);
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        printf("Medicine not found!\n");
    }
}

void sell_medicine(Medicine m[], int n, char name[], int quantity){
    int flag = 0;
    for(int i=0;i<n;i++){
        if(strcmp(m[i].name,name) == 0){
            if(m[i].quantity >= quantity){
                m[i].quantity -= quantity;
                printf("Sold!\n");
            }
            else{
                printf("Insufficient quantity!\n");
            }
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        printf("Medicine not found!\n");
    }
}

int main(){
    Medicine medicines[50];
    int n = 0;
    int choice;
    char name[50];
    int quantity;
    while(1){
        printf("1. Add medicine\n");
        printf("2. Display medicines\n");
        printf("3. Search medicine\n");
        printf("4. Update medicine\n");
        printf("5. Sell medicine\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                add_medicine(medicines,n);
                n++;
                break;
            case 2:
                display_medicines(medicines,n);
                break;
            case 3:
                printf("Enter name of medicine: ");
                scanf("%s",name);
                search_medicine(medicines,n,name);
                break;
            case 4:
                printf("Enter name of medicine: ");
                scanf("%s",name);
                update_medicine(medicines,n,name);
                break;
            case 5:
                printf("Enter name of medicine: ");
                scanf("%s",name);
                printf("Enter quantity: ");
                scanf("%d",&quantity);
                sell_medicine(medicines,n,name,quantity);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}