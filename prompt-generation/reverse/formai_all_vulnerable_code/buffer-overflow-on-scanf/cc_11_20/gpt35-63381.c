//FormAI DATASET v1.0 Category: Banking Record System ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure to store bank records.
struct bankRecord{
    int accountNumber;
    char name[50];
    float balance;
};

int main(){
    int numRecords,i,accNum,choice;
    float addAmount,withdrawAmount;
    char searchName[50];
    
    //Prompting user to enter number of records.
    printf("Enter number of records: ");
    scanf("%d",&numRecords);
    
    //Dynamically allocating memory for bank records.
    struct bankRecord* records = (struct bankRecord*)malloc(numRecords * sizeof(struct bankRecord));
    
    //Prompting user to enter details for each record.
    for(i=0;i<numRecords;i++){
        printf("\nRecord %d:\n",i+1);
        printf("Enter Account Number: ");
        scanf("%d",&records[i].accountNumber);
        printf("Enter Name: ");
        scanf("%s",records[i].name);
        printf("Enter Balance: ");
        scanf("%f",&records[i].balance);
    }
    
    //Menu driven program.
    do{
        printf("\n\n1. Deposit Amount.\n2. Withdraw Amount.\n3. Search Record.\n4. Display All Records.\n5. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        
        switch(choice){
            //Deposit amount.
            case 1:
                printf("Enter Account Number: ");
                scanf("%d",&accNum);
                for(i=0;i<numRecords;i++){
                    if(records[i].accountNumber == accNum){
                        printf("Enter amount to deposit: ");
                        scanf("%f",&addAmount);
                        records[i].balance += addAmount;
                        printf("Amount deposited successfully!\n");
                        break;
                    }
                }
                if(i == numRecords){
                    printf("Record not found!\n");
                }
                break;
            
            //Withdraw amount.
            case 2:
                printf("Enter Account Number: ");
                scanf("%d",&accNum);
                for(i=0;i<numRecords;i++){
                    if(records[i].accountNumber == accNum){
                        printf("Enter amount to withdraw: ");
                        scanf("%f",&withdrawAmount);
                        if(records[i].balance >= withdrawAmount){
                            records[i].balance -= withdrawAmount;
                            printf("Amount withdrawn successfully!\n");
                        }
                        else{
                            printf("Insufficient Balance!\n");
                        }
                        break;
                    }
                }
                if(i == numRecords){
                    printf("Record not found!\n");
                }
                break;
            
            //Search record.
            case 3:
                printf("Enter Name: ");
                scanf("%s",searchName);
                for(i=0;i<numRecords;i++){
                    if(strcmp(records[i].name,searchName) == 0){
                        printf("\nRecord Found:\n");
                        printf("Account Number: %d\n",records[i].accountNumber);
                        printf("Name: %s\n",records[i].name);
                        printf("Balance: %f\n",records[i].balance);
                        break;
                    }
                }
                if(i == numRecords){
                    printf("Record not found!\n");
                }
                break;
            
            //Display all records.
            case 4:
                printf("\nAll Records:\n");
                for(i=0;i<numRecords;i++){
                    printf("Account Number: %d\n",records[i].accountNumber);
                    printf("Name: %s\n",records[i].name);
                    printf("Balance: %f\n\n",records[i].balance);
                }
                break;
            
            //Exit program.
            case 5:
                printf("\nExiting Program!\n");
                break;
            
            //Invalid choice.
            default:
                printf("\nInvalid Choice!\n");
        }
    }while(choice != 5);
    
    //Freeing dynamically allocated memory.
    free(records);
    
    return 0;
}