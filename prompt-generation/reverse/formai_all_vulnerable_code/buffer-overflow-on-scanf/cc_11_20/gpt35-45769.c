//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct customer{
    int table_no;
    char name[50];
    int total_bill;
};

int main(){
    struct customer c[50];
    int i=0, choice, bill, flag=0, table, flag2=0;
    char temp[50];
    
    while(1){
        printf("\n\n");
        printf("1. Add customer\n");
        printf("2. Remove customer\n");
        printf("3. View total bill of a table\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
            
        switch(choice){
            case 1: 
                printf("\nEnter table number: ");
                scanf("%d", &table);
                printf("\nEnter name: ");
                scanf("%s", temp);
                printf("\nEnter total bill: ");
                scanf("%d", &bill);
                for(int j=0; j<i+1; j++){
                    if(c[j].table_no == table){
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0){
                    c[i].table_no = table;
                    strcpy(c[i].name, temp);
                    c[i].total_bill = bill;
                    i++;
                    printf("\nCustomer added successfully!\n");
                }
                else{
                    printf("\nTable number already exists!\n");
                }
                flag=0;
                break;
            
            case 2:
                printf("\nEnter table number: ");
                scanf("%d", &table);
                for(int j=0; j<i; j++){
                    if(c[j].table_no == table){
                        for(int k=j; k<i-1; k++){
                            c[k] = c[k+1];
                        }
                        i--;
                        printf("\nCustomer removed successfully!\n");
                        flag2=1;
                        break;
                    }
                }
                if(flag2 == 0){
                    printf("\nTable number not found!\n");
                }
                flag2=0;
                break;
            
            case 3:
                printf("\nEnter table number: ");
                scanf("%d", &table);
                for(int j=0; j<i; j++){
                    if(c[j].table_no == table){
                        printf("\n\nTable number: %d\n", c[j].table_no);
                        printf("Name: %s\n", c[j].name);
                        printf("Total bill: %d\n", c[j].total_bill);
                        flag2=1;
                        break;
                    }
                }
                if(flag2 == 0){
                    printf("\nTable number not found!\n");
                }
                flag2=0;
                break;
            
            case 4:
                exit(0);
                break;
                
            default: 
                printf("\nInvalid choice!\n");
                break;
        }
    }
    return 0;
}