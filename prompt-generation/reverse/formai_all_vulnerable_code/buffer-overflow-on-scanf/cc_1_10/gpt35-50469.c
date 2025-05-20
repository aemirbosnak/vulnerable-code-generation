//FormAI DATASET v1.0 Category: Banking Record System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int account_number;
    char first_name[20];
    char last_name[20];
    float balance;
} Bank_Record;

int main() {
    FILE *fileptr;

    Bank_Record record;

    fileptr = fopen("bank_records.txt", "a");

    if (fileptr == NULL) {
        printf("Error opening file!");
        exit(1);
    }

    printf("Enter account number: ");
    scanf("%d", &record.account_number);
    getchar(); // To consume newline character from input buffer

    printf("Enter first name: ");
    fgets(record.first_name, 20, stdin);
    record.first_name[strcspn(record.first_name, "\n")] = 0; // To remove newline character from the end

    printf("Enter last name: ");
    fgets(record.last_name, 20, stdin);
    record.last_name[strcspn(record.last_name, "\n")] = 0; // To remove newline character from the end

    printf("Enter balance: ");
    scanf("%f", &record.balance);
    getchar(); // To consume newline character from input buffer

    fprintf(fileptr, "%d %s %s %.2f\n", record.account_number, record.first_name, record.last_name, record.balance);

    fclose(fileptr);

    fileptr = fopen("bank_records.txt", "r");

    if (fileptr == NULL) {
        printf("Error opening file!");
        exit(1);
    }

    printf("\n========= Bank Records =========\n");
    printf("Account Number  First Name  Last Name  Balance\n");

    while (fscanf(fileptr, "%d %s %s %f", &record.account_number, record.first_name, record.last_name, &record.balance) != EOF) {
        printf("%d\t   %s\t      %s\t   %.2f\n", record.account_number, record.first_name, record.last_name, record.balance);
    }

    fclose(fileptr);

    return 0;
}