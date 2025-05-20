//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char med_name[50];
    float price;
    int quantity;
}medicine;

void add_new_medicine(medicine m[],int n);
void search_medicine(medicine m[],int n);
void modify_medicine(medicine m[],int n);
void delete_medicine(medicine m[],int n);

int main(){
    int n=0,choice;
    medicine m[100];

    while(1){
        printf("\n------------------\n");
        printf("Medical Store Management System\n");
        printf("------------------\n");
        printf("1. Add Medicine\n");
        printf("2. Search Medicine\n");
        printf("3. Modify Medicine\n");
        printf("4. Delete Medicine\n");
        printf("5. Exit\n");
        printf("------------------\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                add_new_medicine(m,n);
                n++;
                break;
            case 2:
                search_medicine(m,n);
                break;
            case 3:
                modify_medicine(m,n);
                break;
            case 4:
                delete_medicine(m,n);
                n--;
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

void add_new_medicine(medicine m[],int n){
    printf("Enter the name of medicine: ");
    scanf("%s",m[n].med_name);
    printf("Enter the price of medicine: ");
    scanf("%f",&m[n].price);
    printf("Enter the quantity of medicine: ");
    scanf("%d",&m[n].quantity);
    printf("Medicine added successfully!\n");
}

void search_medicine(medicine m[],int n){
    char name[50];
    printf("Enter the name of medicine to search: ");
    scanf("%s",name);
    int isFound = 0;
    for(int i=0;i<n;i++){
        if(strcmp(m[i].med_name,name)==0){
            printf("Details of medicine\n");
            printf("Name: %s\n",m[i].med_name);
            printf("Price: %f\n",m[i].price);
            printf("Quantity: %d\n",m[i].quantity);
            isFound = 1;
            break;
        }
    }
    if(isFound==0){
        printf("Medicine not found!\n");
    }
}

void modify_medicine(medicine m[],int n){
    char name[50];
    printf("Enter the name of medicine to modify: ");
    scanf("%s",name);
    int isFound = 0;
    for(int i=0;i<n;i++){
        if(strcmp(m[i].med_name,name)==0){
            printf("Details of medicine\n");
            printf("Name: %s\n",m[i].med_name);
            printf("Price: %f\n",m[i].price);
            printf("Quantity: %d\n",m[i].quantity);
            printf("Enter new price: ");
            scanf("%f",&m[i].price);
            printf("Enter new quantity: ");
            scanf("%d",&m[i].quantity);
            printf("Medicine modified successfully!\n");
            isFound = 1;
            break;
        }
    }
    if(isFound==0){
        printf("Medicine not found!\n");
    }
}

void delete_medicine(medicine m[],int n){
    char name[50];
    printf("Enter the name of medicine to delete: ");
    scanf("%s",name);
    int isFound = 0;
    for(int i=0;i<n;i++){
        if(strcmp(m[i].med_name,name)==0){
            for(int j=i;j<n-1;j++){
                m[j] = m[j+1];
            }
            printf("Medicine deleted successfully!\n");
            isFound = 1;
            break;
        }
    }
    if(isFound==0){
        printf("Medicine not found!\n");
    }
}