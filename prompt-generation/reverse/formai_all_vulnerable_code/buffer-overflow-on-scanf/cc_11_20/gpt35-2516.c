//FormAI DATASET v1.0 Category: Banking Record System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bank_record {
    int account_number;
    char account_holder_name[50];
    float balance;
} record;

int main() {
    int num_records, i, option, account_num;
    char name[50];
    float balance;
    FILE *fp;

    fp = fopen("bank_records.cyb", "rb");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(0);
    }

    printf("Welcome to the Cyberpunk Bank Record System\n");
    printf("Choose an option:\n");
    printf("1. Display records\n");
    printf("2. Add record\n");
    printf("3. Update record\n");
    printf("4. Delete record\n");
    printf("5. Exit\n");
    scanf("%d", &option);

    switch(option) {
        case 1:
            printf("Displaying records...\n");
            while (fread(&record, sizeof(struct bank_record), 1, fp)) {
                printf("%d %s %.2f\n", record.account_number, record.account_holder_name, record.balance);
            }
            break;

        case 2:
            printf("Enter the number of records to add: ");
            scanf("%d", &num_records);

            for (i = 0; i < num_records; i++) {
                printf("Enter account number: ");
                scanf("%d", &record.account_number);

                printf("Enter account holder name: ");
                scanf("%s", record.account_holder_name);

                printf("Enter balance: ");
                scanf("%f", &record.balance);

                fwrite(&record, sizeof(struct bank_record), 1, fp);
            }
            break;

        case 3:
            printf("Enter the account number to update: ");
            scanf("%d", &account_num);

            while (fread(&record, sizeof(struct bank_record), 1, fp)) {
                if (record.account_number == account_num) {
                    printf("Enter account holder name: ");
                    scanf("%s", record.account_holder_name);

                    printf("Enter balance: ");
                    scanf("%f", &record.balance);

                    fseek(fp, -sizeof(struct bank_record), SEEK_CUR);
                    fwrite(&record, sizeof(struct bank_record), 1, fp);
                    break;
                }
            }
            break;

        case 4:
            printf("Enter the account number to delete: ");
            scanf("%d", &account_num);

            fp = fopen("temp.cyb", "wb");

            while (fread(&record, sizeof(struct bank_record), 1, fp)) {
                if (record.account_number != account_num) {
                    fwrite(&record, sizeof(struct bank_record), 1, fp);
                }
            }

            fclose(fp);
            remove("bank_records.cyb");
            rename("temp.cyb", "bank_records.cyb");

            printf("Record deleted successfully\n");
            break;

        case 5:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid option\n");
            break;
    }

    fclose(fp);
    return 0;
}