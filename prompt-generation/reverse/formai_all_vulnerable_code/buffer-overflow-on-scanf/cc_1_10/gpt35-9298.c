//FormAI DATASET v1.0 Category: Banking Record System ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct bank_record {
    char name[30];
    char account_no[15];
    float balance;
};

void display_menu(){
    printf("\n1. Add a new record\n");
    printf("2. Display all records\n");
    printf("3. Search record by account number\n");
    printf("4. Update record\n");
    printf("5. Delete record\n");
    printf("6. Exit\n");
}

void add_record(struct bank_record* records, int* num_records){
    printf("\nEnter name: ");
    scanf(" %[^\n]s", records[*num_records].name);
    printf("Enter account number: ");
    scanf(" %[^\n]s", records[*num_records].account_no);
    printf("Enter balance: ");
    scanf("%f", &records[*num_records].balance);
    (*num_records)++;
}

void display_records(struct bank_record* records, int num_records){
    printf("\nName\tAccount No.\tBalance\n");
    for(int i=0; i<num_records; i++){
        printf("%s\t%s\t%.2f\n", records[i].name, records[i].account_no, records[i].balance);
    }
}

void search_record(struct bank_record* records, int num_records){
    char account_no[15];
    printf("\nEnter account number: ");
    scanf(" %[^\n]s", account_no);
    for(int i=0; i<num_records; i++){
        if(strcmp(records[i].account_no, account_no) == 0){
            printf("\nName: %s\nAccount No.: %s\nBalance: %.2f\n", records[i].name, records[i].account_no, records[i].balance);
            return;
        }
    }
    printf("\nRecord not found!\n");
}

void update_record(struct bank_record* records, int num_records){
    char account_no[15];
    printf("\nEnter account number of record to be updated: ");
    scanf(" %[^\n]s", account_no);
    for(int i=0; i<num_records; i++){
        if(strcmp(records[i].account_no, account_no) == 0){
            printf("\nEnter new balance: ");
            scanf("%f", &records[i].balance);
            printf("\nRecord updated successfully!\n");
            return;
        }
    }
    printf("\nRecord not found!\n");
}

void delete_record(struct bank_record* records, int* num_records){
    char account_no[15];
    printf("\nEnter account number of record to be deleted: ");
    scanf(" %[^\n]s", account_no);
    for(int i=0; i<*num_records; i++){
        if(strcmp(records[i].account_no, account_no) == 0){
            for(int j=i; j<(*num_records)-1; j++){
                records[j] = records[j+1];
            }
            (*num_records)--;
            printf("\nRecord deleted successfully!\n");
            return;
        }
    }
    printf("\nRecord not found!\n");
}

int main(){
    struct bank_record records[100];
    int num_records = 0;
    int choice;
    do {
        display_menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                add_record(records, &num_records);
                break;
            case 2:
                display_records(records, num_records);
                break;
            case 3:
                search_record(records, num_records);
                break;
            case 4:
                update_record(records, num_records);
                break;
            case 5:
                delete_record(records, &num_records);
                break;
            case 6:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    } while (choice != 6);
    return 0;
}