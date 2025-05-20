//FormAI DATASET v1.0 Category: Hotel Management System ; Style: grateful
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct customer{
    char name[30];
    char room[10];
    char contact[11];
    int days;
};

int main(){
    struct customer c[10];
    int n,i,choice,flag=0;
    
    printf("Welcome to C Hotel Management System\n");
    printf("Enter the number of customers: ");
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        printf("Enter Customer %d Details:\n",i+1);
        printf("Name: ");
        scanf("%s",c[i].name);
        printf("Room Number: ");
        scanf("%s",c[i].room);
        printf("Contact Number: ");
        scanf("%s",c[i].contact);
        printf("Number of Days of Stay: ");
        scanf("%d",&c[i].days);
    }
    
    while(1){
        printf("\nMenu:\n");
        printf("1. Display all Customer Records\n");
        printf("2. Search for Customer Details\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        
        switch(choice){
            case 1: printf("All Customer Records:\n");
                    for(i=0;i<n;i++){
                        printf("\nName: %s\n",c[i].name);
                        printf("Room Number: %s\n",c[i].room);
                        printf("Contact Number: %s\n",c[i].contact);
                        printf("Number of Days of Stay: %d\n",c[i].days);
                    }
                    break;
            
            case 2: flag=0;
                    char search[30];
                    printf("Enter Customer Name to Search: ");
                    scanf("%s",search);
                    for(i=0;i<n;i++){
                        if(strcmp(search,c[i].name)==0){
                            printf("\nName: %s\n",c[i].name);
                            printf("Room Number: %s\n",c[i].room);
                            printf("Contact Number: %s\n",c[i].contact);
                            printf("Number of Days of Stay: %d\n",c[i].days);
                            flag=1;
                        }
                    }
                    if(flag==0)
                        printf("No Record Found!\n");
                    break;
            
            case 3: printf("Thank you for using C Hotel Management System!\n");
                    exit(0);
            
            default: printf("Invalid Choice! Please try again.\n");
                     break;
        }
    }
    return 0;
}