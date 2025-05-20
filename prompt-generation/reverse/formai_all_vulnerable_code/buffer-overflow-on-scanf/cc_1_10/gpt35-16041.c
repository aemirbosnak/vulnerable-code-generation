//FormAI DATASET v1.0 Category: Banking Record System ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct account{
    int acc_no;
    char name[50];
    float balance;
};

int main(){
    int choice, count=0, acc_no, i, found;
    char name[50];
    float balance;
    struct account bank_record[100];

    printf("Welcome to C Banking Record System\n");

    do{
        printf("\n");
        printf("1. Add New Account\n");
        printf("2. View All Accounts\n");
        printf("3. Search an Account\n");
        printf("4. Update an Account\n");
        printf("5. Delete an Account\n");
        printf("6. Exit\n");
        printf("\n");

        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch(choice){
            case 1: //Add New Account
                printf("\nEnter Account No: ");
                scanf("%d", &acc_no);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Balance: ");
                scanf("%f", &balance);

                for(i=0; i<count; i++){
                    if(bank_record[i].acc_no == acc_no){
                        printf("\nAn account with the given account number already exists!\n");
                        break;
                    }
                }
                if(i == count){
                    bank_record[count].acc_no = acc_no;
                    strcpy(bank_record[count].name, name);
                    bank_record[count].balance = balance;
                    count++;
                    printf("\nAccount has been added successfully!\n");
                }
                break;
            
            //Remaining cases will be implemented
            case 6: //Exit
                printf("\nThank you for using C Banking Record System\n");
                exit(0);
                
            default:
                printf("\nInvalid choice! Try Again.\n");
        }

        printf("\n");
    }while(1);
    return 0;
}