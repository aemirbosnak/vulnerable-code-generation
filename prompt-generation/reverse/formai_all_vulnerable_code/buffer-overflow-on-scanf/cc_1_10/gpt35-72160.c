//FormAI DATASET v1.0 Category: Banking Record System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct record {
    int account_number;
    char name[50];
    float balance;
};

void write_record(struct record *rec) {
    FILE *file = fopen("records.dat", "ab");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    fwrite(rec, sizeof(struct record), 1, file);
    fclose(file);
}

void display_record(struct record *rec) {
    printf("Account Number: %d\n", rec->account_number);
    printf("Name: %s\n", rec->name);
    printf("Balance: %.2f\n", rec->balance);
}

void search_record(int account_number) {
    FILE *file = fopen("records.dat", "rb");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    struct record rec;
    while (fread(&rec, sizeof(struct record), 1, file) == 1) {
        if (rec.account_number == account_number) {
            display_record(&rec);
            fclose(file);
            return;
        }
    }
    printf("Record not found.\n");
    fclose(file);
}

void delete_record(int account_number) {
    FILE *file = fopen("records.dat", "rb");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    FILE *temp = fopen("temp.dat", "wb");
    if (temp == NULL) {
        perror("Error creating temp file");
        fclose(file);
        return;
    }
    struct record rec;
    while (fread(&rec, sizeof(struct record), 1, file) == 1) {
        if (rec.account_number != account_number) {
            fwrite(&rec, sizeof(struct record), 1, temp);
        }
    }
    fclose(file);
    fclose(temp);
    remove("records.dat");
    rename("temp.dat", "records.dat");
}

int main() {
    struct record rec;
    char choice[10];
    while (1) {
        printf("\n1. Add Record\n");
        printf("2. Search Record\n");
        printf("3. Delete Record\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        fgets(choice, 10, stdin);
        switch (atoi(choice)) {
            case 1:
                printf("Enter account number: ");
                scanf("%d", &rec.account_number);
                printf("Enter name: ");
                getchar();
                fgets(rec.name, 50, stdin);
                strtok(rec.name, "\n"); // remove trailing newline
                printf("Enter balance: ");
                scanf("%f", &rec.balance);
                write_record(&rec);
                break;
            case 2:
                printf("Enter account number: ");
                scanf("%d", &rec.account_number);
                search_record(rec.account_number);
                break;
            case 3:
                printf("Enter account number: ");
                scanf("%d", &rec.account_number);
                delete_record(rec.account_number);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}