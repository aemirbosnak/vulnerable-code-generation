//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

typedef struct{
    char name[20];
    int quantity;
    float price;
}Product;

typedef struct{
    char name[20];
    int id;
    float salary;
}Employee;

void addProduct(Product *p, int n){
    printf("Enter product name: ");
    scanf("%s",p[n].name);
    printf("Enter product quantity: ");
    scanf("%d",&p[n].quantity);
    printf("Enter product price: ");
    scanf("%f",&p[n].price);
}

void displayProduct(Product p[], int n){
    printf("\nProduct ID\tProduct Name\tQuantity\tPrice\n");
    for(int i=0;i<n;i++){
        printf("%d\t%s\t%d\t%.2f\n",i+1,p[i].name,p[i].quantity,p[i].price);
    }
}

void addEmployee(Employee *e, int n){
    printf("Enter employee name: ");
    scanf("%s",e[n].name);
    printf("Enter employee ID: ");
    scanf("%d",&e[n].id);
    printf("Enter employee salary: ");
    scanf("%f",&e[n].salary);
}

void displayEmployee(Employee e[], int n){
    printf("\nEmployee ID\tEmployee Name\tSalary\n");
    for(int i=0;i<n;i++){
        printf("%d\t%s\t%.2f\n",e[i].id,e[i].name,e[i].salary);
    }
}

void main(){
    Product p[MAX];
    Employee e[MAX];
    int ch,n=0,m=0;

    while(1){
        printf("\n1.Add Product\n2.Display Product\n3.Add Employee\n4.Display Employee\n5.Exit\n");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                printf("Enter number of products: ");
                scanf("%d",&n);

                for(int i=0;i<n;i++){
                    addProduct(p,i);
                }
                break;

            case 2:
                displayProduct(p,n);
                break;

            case 3:
                printf("Enter number of employees: ");
                scanf("%d",&m);

                for(int i=0;i<m;i++){
                    addEmployee(e,i);
                }
                break;

            case 4:
                displayEmployee(e,m);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}