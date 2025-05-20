//FormAI DATASET v1.0 Category: Banking Record System ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct record {
    int acc_no;
    char name[50];
    float balance;
}customer[100];

int num_records=0;

void add_record() {
    printf("\n******** Adding a new record ********\n");
    printf("\nEnter account number: ");
    scanf("%d",&customer[num_records].acc_no);
    printf("Enter name: ");
    scanf("%s",customer[num_records].name);
    printf("Enter balance: ");
    scanf("%f",&customer[num_records].balance);
    num_records++;
    printf("Record added successfully!\n");
}

void display_records() {
    printf("\n******** Displaying all records ********\n");
    if(num_records==0) {
        printf("No records found.\n");
        return;
    }
    for(int i=0;i<num_records;i++) {
        printf("Account number: %d\n",customer[i].acc_no);
        printf("Name: %s\n",customer[i].name);
        printf("Balance: %f\n\n",customer[i].balance);
    }
}

void search_record(char name[50]) {
    printf("\n******** Searching for record ********\n");
    int flag=0;
    for(int i=0;i<num_records;i++) {
        if(strcmp(customer[i].name,name)==0) {
            printf("Account number: %d\n",customer[i].acc_no);
            printf("Name: %s\n",customer[i].name);
            printf("Balance: %f\n\n",customer[i].balance);
            flag=1;
        }
    }
    if(flag==0) {
        printf("No records found for %s.\n",name);
    }
}

void delete_record(int acc_no) {
    printf("\n******** Deleting record ********\n");
    int flag=0;
    for(int i=0;i<num_records;i++) {
        if(customer[i].acc_no==acc_no) {
            for(int j=i;j<num_records-1;j++) {
                customer[j].acc_no=customer[j+1].acc_no;
                strcpy(customer[j].name,customer[j+1].name);
                customer[j].balance=customer[j+1].balance;
            }
            num_records--;
            flag=1;
            break;
        }
    }
    if(flag==1) {
        printf("Record deleted successfully!\n");
    }
    else {
        printf("Record not found for account number %d.\n",acc_no);
    }
}

int main() {
    int choice,acc_no;
    char name[50];
    while(1) {
        printf("\n");
        printf("1. Add a new record\n");
        printf("2. Display all records\n");
        printf("3. Search for a record\n");
        printf("4. Delete a record\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                add_record();
                break;
            case 2:
                display_records();
                break;
            case 3:
                printf("\nEnter name to search: ");
                scanf("%s",name);
                search_record(name);
                break;
            case 4:
                printf("\nEnter account number to delete: ");
                scanf("%d",&acc_no);
                delete_record(acc_no);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}