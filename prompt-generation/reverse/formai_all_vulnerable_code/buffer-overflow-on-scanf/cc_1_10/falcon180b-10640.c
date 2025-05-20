//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct medicine{
    char name[30];
    int price;
    int quantity;
};

void addmedicine(struct medicine *m,int n){
    printf("\nEnter the name of the medicine: ");
    scanf("%s",m[n].name);
    printf("Enter the price of the medicine: ");
    scanf("%d",&m[n].price);
    printf("Enter the current quantity of the medicine: ");
    scanf("%d",&m[n].quantity);
}

void display(struct medicine m[],int n){
    printf("\nName\tPrice\tQuantity\n");
    for(int i=0;i<n;i++){
        printf("%s\t%d\t%d\n",m[i].name,m[i].price,m[i].quantity);
    }
}

void search(struct medicine m[],int n,char name[30]){
    int flag=0;
    printf("\nEnter the name of the medicine to search: ");
    scanf("%s",name);
    for(int i=0;i<n;i++){
        if(strcmp(m[i].name,name)==0){
            printf("\nThe medicine is found!\n");
            flag=1;
            break;
        }
    }
    if(flag==0){
        printf("\nThe medicine is not found!\n");
    }
}

void update(struct medicine m[],int n){
    int choice,flag=0;
    printf("\nEnter 1 to update the price of the medicine.\nEnter 2 to update the quantity of the medicine.\n");
    scanf("%d",&choice);
    printf("\nEnter the name of the medicine to update: ");
    char name[30];
    scanf("%s",name);
    for(int i=0;i<n;i++){
        if(strcmp(m[i].name,name)==0){
            flag=1;
            if(choice==1){
                printf("\nEnter the new price of the medicine: ");
                scanf("%d",&m[i].price);
            }
            else{
                printf("\nEnter the new quantity of the medicine: ");
                scanf("%d",&m[i].quantity);
            }
            break;
        }
    }
    if(flag==0){
        printf("\nThe medicine is not found!\n");
    }
}

void delete(struct medicine m[],int *n){
    char name[30];
    printf("\nEnter the name of the medicine to delete: ");
    scanf("%s",name);
    for(int i=0;i<*n;i++){
        if(strcmp(m[i].name,name)==0){
            for(int j=i;j<*n-1;j++){
                m[j]=m[j+1];
            }
            (*n)--;
            break;
        }
    }
}

int main(){
    struct medicine m[MAX];
    int n=0;

    while(n<MAX){
        printf("\nEnter 1 to add a medicine.\nEnter 2 to display the list of medicines.\nEnter 3 to search for a medicine.\nEnter 4 to update the details of a medicine.\nEnter 5 to delete a medicine.\nEnter 6 to exit.\n");
        int choice;
        scanf("%d",&choice);
        switch(choice){
            case 1: n++;
                    addmedicine(m,n-1);
                    break;
            case 2: display(m,n);
                    break;
            case 3: printf("\nEnter the name of the medicine to search: ");
                    char name[30];
                    scanf("%s",name);
                    search(m,n,name);
                    break;
            case 4: update(m,n);
                    break;
            case 5: delete(m,&n);
                    break;
            case 6: exit(0);
            default: printf("\nInvalid choice!\n");
        }
    }

    return 0;
}