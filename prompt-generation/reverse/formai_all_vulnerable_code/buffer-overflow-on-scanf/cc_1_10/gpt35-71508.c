//FormAI DATASET v1.0 Category: Banking Record System ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000

struct bank_record {
    long account_num;
    char f_name[20];
    char l_name[20];
    float balance;
}customer[MAX];

//function to add a new record
int add_customer() {
    int i;
    for(i = 0; i < MAX; i++) {
        if(customer[i].account_num == 0) { //finding an empty spot
            printf("Enter Account Number: ");
            scanf("%ld", &customer[i].account_num);
            printf("Enter First Name: ");
            scanf("%s", customer[i].f_name);
            printf("Enter Last Name: ");
            scanf("%s", customer[i].l_name);
            printf("Enter Balance: $");
            scanf("%f", &customer[i].balance);
            printf("\nNew Record Added Successfully!\n");
            return 0;
        }
    }
    printf("\nSorry..Cannot Add New Record!\n");
    return 1;
}

//function to search for a record
int search_customer() {
    int i;
    long acc_num;
    printf("Enter Account Number to Search: ");
    scanf("%ld", &acc_num);
    //finding the record
    for(i = 0; i < MAX; i++) {
        if(customer[i].account_num == acc_num) {
            printf("\nRecord Found!\n\n");
            printf("Account Number: %ld\n", customer[i].account_num);
            printf("First Name: %s\n", customer[i].f_name);
            printf("Last Name: %s\n", customer[i].l_name);
            printf("Balance: $%.2f\n\n", customer[i].balance);
            return 0;
        }
    }
    printf("\nRecord Not Found!\n");
    return 1;
}

//function to modify a record
int modify_customer() {
    int i;
    long acc_num;
    printf("Enter Account Number to Modify: ");
    scanf("%ld", &acc_num);
    //finding the record
    for(i = 0; i < MAX; i++) {
        if(customer[i].account_num == acc_num) {
            printf("\nRecord Found!\n");
            printf("\nEnter New Balance: $");
            scanf("%f", &customer[i].balance);
            printf("\nRecord Modified Successfully!\n");
            return 0;
        }
    }
    printf("\nRecord Not Found!\n");
    return 1;
}

//function to delete a record
int delete_customer() {
    int i;
    long acc_num;
    printf("Enter Account Number to Delete: ");
    scanf("%ld", &acc_num);
    //finding the record
    for(i = 0; i < MAX; i++) {
        if(customer[i].account_num == acc_num) {
            //deleting the record
            customer[i].account_num = 0;
            strcpy(customer[i].f_name, "");
            strcpy(customer[i].l_name, "");
            customer[i].balance = 0.0;
            printf("\nRecord Deleted Successfully!\n");
            return 0;
        }
    }
    printf("\nRecord Not Found!\n");
    return 1;
}

//function to display all records
void display_all() {
    int i, j;
    struct bank_record temp;
    //sorting the records in ascending order
    for(i = 0; i < MAX - 1; i++) {
        for(j = i + 1; j < MAX; j++) {
            if(customer[i].account_num > customer[j].account_num) {
                temp = customer[i];
                customer[i] = customer[j];
                customer[j] = temp;
            }
        }
    }
    //displaying the records
    printf("\nAll Records: \n\n");
    for(i = 0; i < MAX; i++) {
        if(customer[i].account_num != 0) {
            printf("Account Number: %ld\n", customer[i].account_num);
            printf("First Name: %s\n", customer[i].f_name);
            printf("Last Name: %s\n", customer[i].l_name);
            printf("Balance: $%.2f\n\n", customer[i].balance);
        }
    }
}

int main() {
    int choice;
    while(1) {
        printf("\nBanking Record System\n");
        printf("------------------------\n");
        printf("1. Add Record\n");
        printf("2. Search Record\n");
        printf("3. Modify Record\n");
        printf("4. Delete Record\n");
        printf("5. Display All Records\n");
        printf("6. Exit\n");
        printf("------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: add_customer(); break;
            case 2: search_customer(); break;
            case 3: modify_customer(); break;
            case 4: delete_customer(); break;
            case 5: display_all(); break;
            case 6: exit(0);
            default: printf("\nInvalid Choice!\n");
        }
    }
    return 0;
}