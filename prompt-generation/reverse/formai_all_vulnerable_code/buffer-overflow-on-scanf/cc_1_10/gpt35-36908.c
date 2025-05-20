//FormAI DATASET v1.0 Category: Banking Record System ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#define MAX 20

struct record{
    char name[50];
    int acc_no;
    float balance;
}customer[MAX];

int count = 0;

// Function to add new customer record
void add_record(){
    if(count < MAX){
        printf("\nEnter customer name: ");
        fflush(stdin);
        fgets(customer[count].name,50,stdin);
        printf("\nEnter account number: ");
        scanf("%d",&customer[count].acc_no);
        printf("\nEnter account balance: ");
        scanf("%f",&customer[count].balance);
        count++;
        printf("\nRecord added successfully.\n");
    }
    else{
        printf("\nCannot add more records.\n");
    }
}

// Function to display all records
void display_records(){
    if(count > 0){
        printf("\nAll Records:\n");
        printf("--------------------------------\n");
        for(int i=0;i<count;i++){
            printf("Name: %s",customer[i].name);
            printf("Account Number: %d\n",customer[i].acc_no);
            printf("Balance: %.2f\n",customer[i].balance);
            printf("--------------------------------\n");
        }
    }
    else{
        printf("\nNo records.\n");
    }
}

// Function to search for a record by account number
void search_record(){
    int acc_no;
    printf("\nEnter account number: ");
    scanf("%d",&acc_no);
    for(int i=0;i<count;i++){
        if(customer[i].acc_no == acc_no){
            printf("\nRecord found:\n");
            printf("--------------------------------\n");
            printf("Name: %s",customer[i].name);
            printf("Account Number: %d\n",customer[i].acc_no);
            printf("Balance: %.2f\n",customer[i].balance);
            printf("--------------------------------\n");
            return;
        }
    }
    printf("\nRecord not found.\n");
}

// Function to update a customer record
void update_record(){
    int acc_no;
    printf("\nEnter account number: ");
    scanf("%d",&acc_no);
    for(int i=0;i<count;i++){
        if(customer[i].acc_no == acc_no){
            printf("\nEnter new account balance: ");
            scanf("%f",&customer[i].balance);
            printf("\nRecord updated successfully.\n");
            return;
        }
    }
    printf("\nRecord not found.\n");
}

// Function to delete a customer record
void delete_record(){
    int acc_no;
    printf("\nEnter account number: ");
    scanf("%d",&acc_no);
    for(int i=0;i<count;i++){
        if(customer[i].acc_no == acc_no){
            for(int j=i;j<count-1;j++){
                customer[j] = customer[j+1];
            }
            count--;
            printf("\nRecord deleted successfully.\n");
            return;
        }
    }
    printf("\nRecord not found.\n");
}

int main(){
    int choice;

    while(1){
        printf("\nBanking Record System\n");
        printf("--------------------------------\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Search Record\n");
        printf("4. Update Record\n");
        printf("5. Delete Record\n");
        printf("6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                add_record();
                break;
            case 2:
                display_records();
                break;
            case 3:
                search_record();
                break;
            case 4:
                update_record();
                break;
            case 5:
                delete_record();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}