//FormAI DATASET v1.0 Category: Banking Record System ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//structure for holding customer information
struct Customer {
    char name[30];
    char account_no[10];
    float balance;
};

//function prototypes
void add_customer();
void view_customer();
void update_customer();
void delete_customer();

int main() {
    int choice;
    
    do {
        printf("\n\n===BANKING RECORD SYSTEM===\n");
        printf("1. Add Customer\n");
        printf("2. View Customer\n");
        printf("3. Update Customer\n");
        printf("4. Delete Customer\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add_customer();
                break;
            case 2:
                view_customer();
                break;
            case 3:
                update_customer();
                break;
            case 4:
                delete_customer();
                break;
            case 5:
                printf("\nExiting program...");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.");
        }
    } while(choice != 5);
    return 0;
}

void add_customer() {
    FILE *fp;
    struct Customer c;
    
    //open file for writing
    fp = fopen("banking_record.txt", "a");
    
    if(fp == NULL) {
        printf("\nError opening file.");
        return;
    }
    
    printf("\nEnter customer name: ");
    scanf("%s", c.name);
    printf("Enter account number: ");
    scanf("%s", c.account_no);
    printf("Enter balance: ");
    scanf("%f", &c.balance);
    
    //write customer data to file
    fprintf(fp, "%s %s %f\n", c.name, c.account_no, c.balance);
    printf("\nCustomer added successfully.");
    
    //close file
    fclose(fp);
}

void view_customer() {
    FILE *fp;
    struct Customer c;
    int found = 0;
    char account_no[10];
    
    //open file for reading
    fp = fopen("banking_record.txt", "r");
    
    if(fp == NULL) {
        printf("\nError opening file.");
        return;
    }
    
    printf("\nEnter account number to view customer: ");
    scanf("%s", account_no);
    
    //read customer data from file and display on console
    while(fscanf(fp, "%s %s %f", c.name, c.account_no, &c.balance) != EOF) {
        if(strcmp(c.account_no, account_no) == 0) {
            printf("\nName: %s", c.name);
            printf("\nAccount No: %s", c.account_no);
            printf("\nBalance: %f", c.balance);
            found = 1;
            break;
        }
    }
    
    if(!found)
        printf("\nCustomer not found.");
    
    //close file
    fclose(fp);
}

void update_customer() {
    FILE *fp;
    FILE *temp_fp;
    struct Customer c;
    int found = 0;
    char account_no[10];
    
    //open files for reading and writing
    fp = fopen("banking_record.txt", "r");
    temp_fp = fopen("temp.txt", "w");
    
    if(fp == NULL || temp_fp == NULL) {
        printf("\nError opening file.");
        return;
    }
    
    printf("\nEnter account number to update customer: ");
    scanf("%s", account_no);
    
    //read customer data from file, update customer record and write it to temp file
    while(fscanf(fp, "%s %s %f", c.name, c.account_no, &c.balance) != EOF) {
        if(strcmp(c.account_no, account_no) == 0) {
            printf("\nEnter updated balance: ");
            scanf("%f", &c.balance);
            fprintf(temp_fp, "%s %s %f\n", c.name, c.account_no, c.balance);
            found = 1;
        }
        else
            fprintf(temp_fp, "%s %s %f\n", c.name, c.account_no, c.balance);
    }
    
    if(!found)
        printf("\nCustomer not found.");
    else {
        //close both files
        fclose(fp);
        fclose(temp_fp);
        
        //delete original file and rename temp file
        remove("banking_record.txt");
        rename("temp.txt", "banking_record.txt");
        
        printf("\nCustomer updated successfully.");
    }
}

void delete_customer() {
    FILE *fp;
    FILE *temp_fp;
    struct Customer c;
    int found = 0;
    char account_no[10];
    
    //open files for reading and writing
    fp = fopen("banking_record.txt", "r");
    temp_fp = fopen("temp.txt", "w");
    
    if(fp == NULL || temp_fp == NULL) {
        printf("\nError opening file.");
        return;
    }
    
    printf("\nEnter account number to delete customer: ");
    scanf("%s", account_no);
    
    //read customer data from file and write remaining customer data to temp file
    while(fscanf(fp, "%s %s %f", c.name, c.account_no, &c.balance) != EOF) {
        if(strcmp(c.account_no, account_no) == 0) {
            printf("\nCustomer deleted successfully.");
            found = 1;
        }
        else
            fprintf(temp_fp, "%s %s %f\n", c.name, c.account_no, c.balance);
    }
    
    if(!found)
        printf("\nCustomer not found.");
    
    //close both files
    fclose(fp);
    fclose(temp_fp);
    
    //delete original file and rename temp file
    remove("banking_record.txt");
    rename("temp.txt", "banking_record.txt");
}