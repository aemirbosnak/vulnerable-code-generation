//FormAI DATASET v1.0 Category: Banking Record System ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char name[50];
    int acc_no;
    float balance;
} bank_record;

void record_to_file(bank_record record){
    FILE *f = fopen("bank_records.txt", "a");
    fprintf(f, "%s %d %.2f\n", record.name, record.acc_no, record.balance);
    fclose(f);
}

void display_records(){
    FILE *f = fopen("bank_records.txt", "r");
    if(f == NULL){
        printf("Error opening file!\n");
        exit(1);
    }
    printf("Name\t\tAccount No.\tBalance\n");
    printf("------------------------------------------\n");
    while(!feof(f)){
        bank_record record;
        fscanf(f, "%s %d %f", record.name, &(record.acc_no), &(record.balance));
        printf("%-15s\t%-10d\t%10.2f\n", record.name, record.acc_no, record.balance);
    }
    fclose(f);
}

void add_record(){
    bank_record record;
    printf("Enter account holder's name: ");
    scanf("%[^\n]", record.name);
    printf("Enter account number: ");
    scanf("%d", &(record.acc_no));
    printf("Enter account balance: ");
    scanf("%f", &(record.balance));
    record_to_file(record);
    printf("Record added successfully!\n");
}

void delete_record(){
    FILE *f1 = fopen("bank_records.txt", "r");
    if(f1 == NULL){
        printf("Error opening file!\n");
        exit(1);
    }
    FILE *f2 = fopen("temp.txt", "w");
    if(f2 == NULL){
        printf("Error opening file!\n");
        exit(1);
    }
    int acc_no;
    printf("Enter account number to delete: ");
    scanf("%d", &acc_no);
    bank_record record;
    int found = 0;
    while(!feof(f1)){
        fscanf(f1, "%s %d %f", record.name, &(record.acc_no), &(record.balance));
        if(record.acc_no == acc_no){
            printf("Record deleted successfully!\n");
            found = 1;
        }
        else{
            fprintf(f2, "%s %d %.2f\n", record.name, record.acc_no, record.balance);
        }
    }
    if(found == 0){
        printf("Record not found!\n");
    }
    fclose(f1);
    fclose(f2);
    remove("bank_records.txt");
    rename("temp.txt", "bank_records.txt");
}

void search_records(){
    FILE *f = fopen("bank_records.txt", "r");
    if(f == NULL){
        printf("Error opening file!\n");
        exit(1);
    }
    int acc_no;
    printf("Enter account number to search: ");
    scanf("%d", &acc_no);
    bank_record record;
    printf("Name\t\tAccount No.\tBalance\n");
    printf("------------------------------------------\n");
    while(!feof(f)){
        fscanf(f, "%s %d %f", record.name, &(record.acc_no), &(record.balance));
        if(record.acc_no == acc_no){
            printf("%-15s\t%-10d\t%10.2f\n", record.name, record.acc_no, record.balance);
            fclose(f);
            return;
        }
    }
    printf("Record not found!\n");
    fclose(f);
}

int main(){
    int choice;
    do{
        printf("Menu:\n");
        printf("1. Display records\n");
        printf("2. Add record\n");
        printf("3. Delete record\n");
        printf("4. Search record\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                display_records();
                break;
            case 2:
                add_record();
                break;
            case 3:
                delete_record();
                break;
            case 4:
                search_records();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
        printf("\n");
    }while(choice != 5);
    return 0;
}