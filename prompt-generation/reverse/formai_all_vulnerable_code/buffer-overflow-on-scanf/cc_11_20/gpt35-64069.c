//FormAI DATASET v1.0 Category: Banking Record System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int acc_num;
    float balance;
} bank_record;

int main() {
    int choice, i, n;
    float amount;
    char acc_name[20];
    FILE *fp;
    bank_record record;

    printf("***** Banking Record System *****\n\n");

    while (1) {
        printf("1. Create a new record\n");
        printf("2. Display records\n");
        printf("3. Update record\n");
        printf("4. Delete record\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                fp = fopen("bank_records.dat", "a");

                printf("\nEnter account name: ");
                scanf("%s", record.name);

                printf("Enter account number: ");
                scanf("%d", &record.acc_num);

                printf("Enter balance: ");
                scanf("%f", &record.balance);

                fwrite(&record, sizeof(bank_record), 1, fp);

                fclose(fp);

                break;

            case 2:
                fp = fopen("bank_records.dat", "r");

                n = fread(&record, sizeof(bank_record), 1, fp);

                printf("\nAccount Name\tAccount Number\tBalance\n");

                while (n == 1) {
                    printf("%s\t\t%d\t\t%.2f\n", record.name, record.acc_num, record.balance);
                    n = fread(&record, sizeof(bank_record), 1, fp);
                }

                fclose(fp);

                break;

            case 3:
                fp = fopen("bank_records.dat", "r+");

                printf("Enter account name to update: ");
                scanf("%s", acc_name);

                n = fread(&record, sizeof(bank_record), 1, fp);

                while (n == 1) {
                    if (strcmp(acc_name, record.name) == 0) {
                        printf("Enter amount to deposit/withdraw: ");
                        scanf("%f", &amount);

                        record.balance += amount;

                        fseek(fp, -sizeof(bank_record), SEEK_CUR);
                        fwrite(&record, sizeof(bank_record), 1, fp);

                        printf("\nRecord updated!\n");
                        break;
                    }

                    n = fread(&record, sizeof(bank_record), 1, fp);
                }

                fclose(fp);

                break;

            case 4:
                fp = fopen("bank_records.dat", "r");

                FILE *temp = fopen("temp.dat", "w");

                printf("Enter account name to delete: ");
                scanf("%s", acc_name);

                n = fread(&record, sizeof(bank_record), 1, fp);

                while (n == 1) {
                    if (strcmp(acc_name, record.name) != 0) {
                        fwrite(&record, sizeof(bank_record), 1, temp);
                    }

                    n = fread(&record, sizeof(bank_record), 1, fp);
                }

                fclose(fp);
                fclose(temp);

                remove("bank_records.dat");
                rename("temp.dat", "bank_records.dat");

                printf("\nRecord deleted!\n");

                break;

            case 5:
                exit(0);

            default:
                printf("\nInvalid choice.\n\n");
                continue;
        }
    }

    return 0;
}