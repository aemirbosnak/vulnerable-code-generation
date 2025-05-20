//FormAI DATASET v1.0 Category: Banking Record System ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_CUSTOMERS 100

typedef struct{
    char name[20];
    int account_num;
    float balance;
} Customer;

void addCustomer(Customer[], int*);
void searchCustomer(Customer[], int);
void deleteCustomer(Customer[], int*);
void printAll(Customer[], int);

int main(){
    Customer customers[MAX_CUSTOMERS];
    int num_customers = 0;
    int choice;

    do{
      printf("\n=========================================");
      printf("\nWelcome to the Banking Record System!");
      printf("\n=========================================");
      printf("\n1. Add a customer");
      printf("\n2. Search for a customer");
      printf("\n3. Delete a customer");
      printf("\n4. Display all customers");
      printf("\n5. Quit");
      printf("\nEnter your choice: ");
      scanf("%d", &choice);

      switch(choice){
          case 1:
            addCustomer(customers, &num_customers);
            break;
          case 2:
            searchCustomer(customers, num_customers);
            break;
          case 3:
            deleteCustomer(customers, &num_customers);
            break;
          case 4:
            printAll(customers, num_customers);
            break;
          case 5:
            printf("\nGoodbye!\n");
            break;
          default:
            printf("\nInvalid choice. Try again.\n");
            break;
      }
    }while(choice != 5);

    return 0;
}

void addCustomer(Customer customers[], int* num_customers){
    if(*num_customers == MAX_CUSTOMERS){
        printf("\nCannot add more customers. Maximum limit reached.\n");
        return;
    }

    printf("\nEnter customer name: ");
    scanf("%s", &customers[*num_customers].name);
    printf("Enter account number: ");
    scanf("%d", &customers[*num_customers].account_num);
    printf("Enter opening balance: ");
    scanf("%f", &customers[*num_customers].balance);

    (*num_customers)++;

    printf("\nCustomer added successfully!\n");
}

void searchCustomer(Customer customers[], int num_customers){
    int account_num;
    int i;

    printf("\nEnter account number to search: ");
    scanf("%d", &account_num);

    for(i = 0; i < num_customers; i++){
        if(customers[i].account_num == account_num){
            printf("\nName: %s", customers[i].name);
            printf("\nAccount Number: %d", customers[i].account_num);
            printf("\nBalance: %.2f\n", customers[i].balance);
            return;
        }
    }

    printf("\nCustomer not found.\n");
}

void deleteCustomer(Customer customers[], int* num_customers){
    int account_num;
    int i, j;
    int found = 0;

    printf("\nEnter account number to delete: ");
    scanf("%d", &account_num);

    for(i = 0; i < *num_customers; i++){
        if(customers[i].account_num == account_num){
            found = 1;

            for(j = i; j < *num_customers-1; j++){
                customers[j] = customers[j+1];
            }

            (*num_customers)--;

            printf("\nCustomer deleted successfully!\n");
            break;
        }
    }

    if(!found){
        printf("\nCustomer not found.\n");
    }
}

void printAll(Customer customers[], int num_customers){
    int i;

    printf("\n===============================");
    printf("\nList of all Customers");
    printf("\n===============================");
    for(i = 0; i < num_customers; i++){
        printf("\nName: %s", customers[i].name);
        printf("\nAccount Number: %d", customers[i].account_num);
        printf("\nBalance: %.2f\n", customers[i].balance);
    }
}