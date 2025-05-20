//FormAI DATASET v1.0 Category: Banking Record System ; Style: systematic
#include<stdio.h>
#include<string.h>

struct account{
    int ac_no, balance;
    char name[50], address[100], phone[20];
};

int main(){
    struct account customers[100];
    int n, choice, ac_no, deposit, withdraw;

    printf("Welcome to XYZ Bank Record System!\n");

    while(1){
        printf("\nChoose an option:\n");
        printf("1. Create new account\n");
        printf("2. View account details\n");
        printf("3. Deposit money\n");
        printf("4. Withdraw money\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter account number: ");
                scanf("%d", &customers[n].ac_no);
                printf("Enter customer name: ");
                scanf("%s", customers[n].name);
                printf("Enter customer address: ");
                scanf("%s", customers[n].address);
                printf("Enter customer phone number: ");
                scanf("%s", customers[n].phone);
                printf("Enter initial balance: ");
                scanf("%d", &customers[n].balance);
                printf("Account created successfully.\n");
                n++;
                break;
            case 2:
                printf("Enter account number: ");
                scanf("%d", &ac_no);
                for(int i=0; i<n; i++){
                    if(customers[i].ac_no==ac_no){
                        printf("Account Details:\n Account number: %d\n Customer name: %s\n Customer address: %s\n Customer phone: %s\n Balance: %d\n", customers[i].ac_no, customers[i].name, customers[i].address, customers[i].phone, customers[i].balance);
                        break;
                    }
                    if(i==n-1){
                        printf("Account not found.\n");
                    }
                }
                break;
            case 3:
                printf("Enter account number: ");
                scanf("%d", &ac_no);
                for(int i=0; i<n; i++){
                    if(customers[i].ac_no==ac_no){
                        printf("Enter amount to be deposited: ");
                        scanf("%d", &deposit);
                        customers[i].balance += deposit;
                        printf("Amount deposited successfully.\n");
                        break;
                    }
                    if(i==n-1){
                        printf("Account not found.\n");
                    }
                }
                break;
            case 4:
                printf("Enter account number: ");
                scanf("%d", &ac_no);
                for(int i=0; i<n; i++){
                    if(customers[i].ac_no==ac_no){
                        printf("Enter amount to be withdrawn: ");
                        scanf("%d", &withdraw);
                        if(customers[i].balance<withdraw){
                            printf("Insufficient balance.\n");
                        }
                        else{
                            customers[i].balance -= withdraw;
                            printf("Amount withdrawn successfully.\n");
                        }
                        break;
                    }
                    if(i==n-1){
                        printf("Account not found.\n");
                    }
                }
                break;
            case 5:
                printf("Thank you for using XYZ Bank Record System!\n");
                return 0;
            default:
                printf("Invalid option.\n");
                break;
        }
    }
    return 0;
}