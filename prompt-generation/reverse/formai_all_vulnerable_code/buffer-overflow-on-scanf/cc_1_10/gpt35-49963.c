//FormAI DATASET v1.0 Category: Banking Record System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct banking_record{
    char name[50];
    int account_number;
    float balance;
};

int main(){
    struct banking_record record;
    FILE *record_file;
    char file_name[50];
    int num_records, choice, index;
    float deposit_amount, withdraw_amount;

    printf("Welcome to the Curious Banking Record System!\n\n");

    printf("Enter the name of the record file (without .txt): ");
    scanf("%s", file_name);

    strcat(file_name, ".txt");
    record_file = fopen(file_name, "a+");

    if(record_file == NULL){
        printf("Error opening record file.\n");
        exit(1);
    }

    fseek(record_file, 0, SEEK_END);
    num_records = ftell(record_file) / sizeof(struct banking_record);

    while(1){
        printf("\n\n1. Add a record\n2. View a record\n3. Edit a record\n4. Exit\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter name: ");
                scanf("%s", record.name);
                printf("Enter account number: ");
                scanf("%d", &record.account_number);
                printf("Enter balance: ");
                scanf("%f", &record.balance);

                fwrite(&record, sizeof(struct banking_record), 1, record_file);
                printf("Record added successfully!\n\n");
                break;

            case 2:
                printf("Enter the index of the record to view: ");
                scanf("%d", &index);

                if(index >= num_records){
                    printf("Invalid index.\n");
                    break;
                }

                fseek(record_file, index * sizeof(struct banking_record), SEEK_SET);
                fread(&record, sizeof(struct banking_record), 1, record_file);

                printf("\nName: %s\nAccount Number: %d\nBalance: %.2f\n\n", record.name, record.account_number, record.balance);
                break;

            case 3:
                printf("Enter the index of the record to edit: ");
                scanf("%d", &index);

                if(index >= num_records){
                    printf("Invalid index.\n");
                    break;
                }

                fseek(record_file, index * sizeof(struct banking_record), SEEK_SET);
                fread(&record, sizeof(struct banking_record), 1, record_file);

                printf("\nName: %s\nAccount Number: %d\nBalance: %.2f\n\n", record.name, record.account_number, record.balance);

                printf("Enter deposit amount: ");
                scanf("%f", &deposit_amount);

                printf("Enter withdraw amount: ");
                scanf("%f", &withdraw_amount);

                record.balance += deposit_amount - withdraw_amount;

                fseek(record_file, index * sizeof(struct banking_record), SEEK_SET);
                fwrite(&record, sizeof(struct banking_record), 1, record_file);

                printf("Record edited successfully!\n\n");
                break;

            case 4:
                fclose(record_file);
                printf("Thank you for using the Curious Banking Record System!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }

        fflush(stdin);
    }

    return 0;
}