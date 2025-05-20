//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: Cryptic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX 100

struct account{
    int accno;
    char name[20];
    char address[50];
    float balance;
};

struct account a[MAX];

int i,n=0,ch;
char str[50];

void deposit(){
    printf("\nEnter account number: ");
    scanf("%d",&ch);
    for(i=0;i<n;i++){
        if(a[i].accno==ch){
            printf("\nEnter amount to be deposited: ");
            scanf("%f",&a[i].balance);
            printf("\nAmount deposited successfully!");
            break;
        }
        else{
            printf("\nAccount not found!");
        }
    }
}

void withdraw(){
    printf("\nEnter account number: ");
    scanf("%d",&ch);
    for(i=0;i<n;i++){
        if(a[i].accno==ch){
            printf("\nEnter amount to be withdrawn: ");
            scanf("%f",&a[i].balance);
            printf("\nAmount withdrawn successfully!");
            break;
        }
        else{
            printf("\nAccount not found!");
        }
    }
}

void display(){
    printf("\n\nAccount Number\tName\tAddress\tBalance");
    for(i=0;i<n;i++){
        printf("\n%d\t\t%s\t\t%s\t\t%.2f",a[i].accno,a[i].name,a[i].address,a[i].balance);
    }
}

void search(){
    printf("\nEnter account number: ");
    scanf("%d",&ch);
    for(i=0;i<n;i++){
        if(a[i].accno==ch){
            printf("\nAccount found!");
            printf("\nName: %s",a[i].name);
            printf("\nAddress: %s",a[i].address);
            printf("\nBalance: %.2f",a[i].balance);
            break;
        }
        else{
            printf("\nAccount not found!");
        }
    }
}

int main(){
    int ch,i;
    char str[50];

    printf("\n\nWELCOME TO BANKING RECORD SYSTEM\n");
    printf("\nEnter 1 to deposit\nEnter 2 to withdraw\nEnter 3 to display all records\nEnter 4 to search for a particular account\nEnter 5 to exit");
    scanf("%d",&ch);

    switch(ch){
        case 1:
            deposit();
            break;
        case 2:
            withdraw();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\nEnter account number: ");
            scanf("%d",&ch);
            search();
            break;
        case 5:
            exit(0);
        default:
            printf("\nInvalid choice!");
    }

    return 0;
}