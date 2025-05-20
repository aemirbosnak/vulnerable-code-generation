//FormAI DATASET v1.0 Category: Banking Record System ; Style: Donald Knuth
// C Banking Record System Example Program
// Author: Your Name Here
// Date: Today's Date Here

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

//Struct to Store Customer Information 
struct customer{
    char name[MAX];
    char address[MAX];
    int account_no;
    float balance;
};

//Function to add a customer
void add_customer(struct customer *ptr){
    printf("Enter Name: ");
    fgets(ptr->name, MAX, stdin);
    printf("Enter Address: ");
    fgets(ptr->address, MAX, stdin);
    printf("Enter Account Number: ");
    scanf("%d", &ptr->account_no);
    printf("Enter Balance: ");
    scanf("%f", &ptr->balance);
    getchar();
    printf("Customer Added Successfully!\n");
}

//Function to remove a customer
void remove_customer(struct customer *ptr){
    ptr->name[0] = '\0';
    ptr->address[0] = '\0';
    ptr->account_no = 0;
    ptr->balance = 0.0;
    printf("Customer Removed Successfully!\n");
}

//Function to update a customer
void update_customer(struct customer *ptr){
    printf("Enter Name: ");
    fgets(ptr->name, MAX, stdin);
    printf("Enter Address: ");
    fgets(ptr->address, MAX, stdin);
    printf("Enter Account Number: ");
    scanf("%d", &ptr->account_no);
    printf("Enter Balance: ");
    scanf("%f", &ptr->balance);
    getchar();
    printf("Customer Updated Successfully!\n");
}

//Function to display all customers
void display_all(struct customer list[], int n){
    printf("-------------------------------------------------------------------------\n");
    printf("| %-15s | %-15s | %-15s | %-15s |\n", "Name", "Address", "Account No.", "Balance");
    printf("-------------------------------------------------------------------------\n");
    for(int i = 0; i < n; i++){
        if(list[i].name[0] != '\0'){
            printf("| %-15s | %-15s | %-15d | %-15.2f |\n", list[i].name, list[i].address, list[i].account_no, list[i].balance);
        }
    }
    printf("-------------------------------------------------------------------------\n");
}

//Main Function to Run the Program
int main(){
    struct customer list[MAX];
    int choice, count = 0;
    while(1){
        printf("Enter 1 to Add New Customer\n");
        printf("Enter 2 to Remove a Customer\n");
        printf("Enter 3 to Update Customer's Information\n");
        printf("Enter 4 to Display All Customers\n");
        printf("Enter 0 to Exit Program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        switch(choice){
            case 1:
                if(count == MAX){
                    printf("Maximum Customers Reached!\n");
                }
                else{
                    add_customer(&list[count]);
                    count++;
                }
                break;
            case 2:
                if(count == 0){
                    printf("No Customers to Remove!\n");
                }
                else{
                    int acc;
                    printf("Enter Account Number: ");
                    scanf("%d", &acc);
                    getchar();
                    int found = 0;
                    for(int i = 0; i < count; i++){
                        if(list[i].account_no == acc){
                            remove_customer(&list[i]);
                            found = 1;
                            for(int j = i; j < count-1; j++){
                                list[j] = list[j+1];
                            }
                            count--;
                            break;
                        }
                    }
                    if(!found){
                        printf("Customer Not Found!\n");
                    }
                }
                break;
            case 3:
                if(count == 0){
                    printf("No Customers to Update!\n");
                }
                else{
                    int acc;
                    printf("Enter Account Number: ");
                    scanf("%d", &acc);
                    getchar();
                    int found = 0;
                    for(int i = 0; i < count; i++){
                        if(list[i].account_no == acc){
                            update_customer(&list[i]);
                            found = 1;
                            break;
                        }
                    }
                    if(!found){
                        printf("Customer Not Found!\n");
                    }
                }
                break;
            case 4:
                if(count == 0){
                    printf("No Customers to Display!\n");
                }
                else{
                    display_all(list, count);
                }
                break;
            case 0:
                printf("Exiting Program...\n");
                exit(0);
            default:
                printf("Invalid Choice!\n");
        }
    }
    return 0;
}