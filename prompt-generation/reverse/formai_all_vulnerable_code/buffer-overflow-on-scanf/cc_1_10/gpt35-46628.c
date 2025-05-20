//FormAI DATASET v1.0 Category: Banking Record System ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Record{
    char name[30];
    long int account_no;
    float balance;
    int age;
};

void menu(){
    printf("1. Add record\n");
    printf("2. Search record\n");
    printf("3. Update record\n");
    printf("4. Delete record\n");
    printf("5. View All records\n");
    printf("6. Exit\n");
}

void addRecord(struct Record* r, int* count){
    fflush(stdin);
    printf("Enter name: ");
    fgets(r[*count].name, 30, stdin);
    printf("Enter account number: ");
    scanf("%ld", &r[*count].account_no);
    printf("Enter balance: ");
    scanf("%f", &r[*count].balance);
    printf("Enter age: ");
    scanf("%d", &r[*count].age);
    (*count)++;
}

void searchRecord(struct Record* r, int count){
    long int account_no;
    int found = 0;
    printf("Enter account number to search: ");
    scanf("%ld", &account_no);
    for(int i=0;i<count;i++){
        if(r[i].account_no == account_no){
            printf("Name: %s", r[i].name);
            printf("Account Number: %ld\n", r[i].account_no);
            printf("Balance: %.2f\n", r[i].balance);
            printf("Age: %d\n", r[i].age);
            found = 1;
            break;
        }
    }
    if(!found){
        printf("Record not found!\n");
    }
}

void updateRecord(struct Record* r, int count){
    long int account_no;
    int found = 0;
    printf("Enter account number to update: ");
    scanf("%ld", &account_no);
    for(int i=0;i<count;i++){
        if(r[i].account_no == account_no){
            fflush(stdin);
            printf("Enter name: ");
            fgets(r[i].name, 30, stdin);
            printf("Enter balance: ");
            scanf("%f", &r[i].balance);
            printf("Enter age: ");
            scanf("%d", &r[i].age);
            found = 1;
            break;
        }
    }
    if(!found){
        printf("Record not found!\n");
    }else{
        printf("Record updated successfully!\n");
    }
}

void deleteRecord(struct Record* r, int* count){
    long int account_no;
    int found = 0;
    printf("Enter account number to delete: ");
    scanf("%ld", &account_no);
    for(int i=0;i<*count;i++){
        if(r[i].account_no == account_no){
            for(int j=i;j<*count-1;j++){
                strcpy(r[j].name, r[j+1].name);
                r[j].account_no = r[j+1].account_no;
                r[j].balance = r[j+1].balance;
                r[j].age = r[j+1].age;
            }
            (*count)--;
            found = 1;
            break;
        }
    }
    if(!found){
        printf("Record not found!\n");
    }else{
        printf("Record deleted successfully!\n");
    }
}

void viewAllRecords(struct Record* r, int count){
    for(int i=0;i<count;i++){
        printf("Name: %s", r[i].name);
        printf("Account Number: %ld\n", r[i].account_no);
        printf("Balance: %.2f\n", r[i].balance);
        printf("Age: %d\n", r[i].age);
    }
}

int main(){
    struct Record record[100];
    int count = 0;
    int option;
    while(1){
        system("cls");
        menu();
        printf("Enter your option: ");
        scanf("%d", &option);
        switch(option){
            case 1:
                addRecord(record, &count);
                break;
            case 2:
                searchRecord(record, count);
                break;
            case 3:
                updateRecord(record, count);
                break;
            case 4:
                deleteRecord(record, &count);
                break;
            case 5:
                viewAllRecords(record, count);
                break;
            case 6:
                printf("Thank you for using our service!\n");
                exit(0);
            default:
                printf("Invalid option!");
        }
        fflush(stdin);
        printf("\nPress any key to continue...");
        getchar();
    }
    return 0;
}