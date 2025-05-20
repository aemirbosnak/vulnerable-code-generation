//FormAI DATASET v1.0 Category: Banking Record System ; Style: Alan Touring
/* C Banking Record System */
#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char name[30];
    int acc_no;
    float balance;
} bank;

int main(){
    int option;
    int count = 0;
    int i;
    bank *records;
    int acc_no;
    float amount;
    
    printf("\n***** Welcome to C Banking Record System *****\n\n");
    printf("How many records would you like to store? ");
    scanf("%d", &count);
    
    records = (bank*)malloc(sizeof(bank)*count);
    
    do{
        printf("\nAvailable options:\n");
        printf("1. Create a new record\n");
        printf("2. Update a record\n");
        printf("3. Delete a record\n");
        printf("4. View all records\n");
        printf("5. Exit\n");
        printf("Enter option number: ");
        scanf("%d", &option);
        
        switch(option){
            case 1:
                for(i=0; i<count; i++){
                    if(records[i].acc_no == 0){
                        printf("\nEnter name: ");
                        scanf("%s", records[i].name);
                        printf("Enter account number: ");
                        scanf("%d", &records[i].acc_no);
                        printf("Enter balance: ");
                        scanf("%f", &records[i].balance);
                        break;
                    }
                }
                if(i == count){
                    printf("\nSorry, maximum records reached.\n");
                }
            break;
            
            case 2:
                printf("\nEnter account number to update: ");
                scanf("%d", &acc_no);
                for(i=0; i<count; i++){
                    if(records[i].acc_no == acc_no){
                        printf("\nEnter amount to deposit/withdraw (positive/negative): ");
                        scanf("%f", &amount);
                        records[i].balance += amount;
                        printf("New balance of account %d: %.2f\n", records[i].acc_no, records[i].balance);
                        break;
                    }
                }
                if(i == count){
                    printf("\nAccount number not found.\n");
                }
            break;
            
            case 3:
                printf("\nEnter account number to delete: ");
                scanf("%d", &acc_no);
                for(i=0; i<count; i++){
                    if(records[i].acc_no == acc_no){
                        records[i].acc_no = 0;
                        records[i].balance = 0;
                        printf("\nRecord of account %d deleted.\n", acc_no);
                        break;
                    }
                }
                if(i == count){
                    printf("\nAccount number not found.\n");
                }
            break;
            
            case 4:
                printf("\nList of all records:\n");
                for(i=0; i<count; i++){
                    if(records[i].acc_no != 0){
                        printf("Name: %s\n", records[i].name);
                        printf("Account number: %d\n", records[i].acc_no);
                        printf("Balance: %.2f\n\n", records[i].balance);
                    }
                }
                if(i == count && records[i-1].acc_no == 0){
                    printf("No records found.\n");
                }
            break;
            
            case 5:
                printf("\nGoodbye!\n");
            break;
            
            default:
                printf("\nInvalid option.\n");
        }
        
    }while(option != 5);
    
    free(records);
    
    return 0;
}