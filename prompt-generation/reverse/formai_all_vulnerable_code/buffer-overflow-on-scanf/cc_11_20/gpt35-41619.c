//FormAI DATASET v1.0 Category: Banking Record System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct record {
    char name[50];
    int account_number;
    float balance;
};

int main() {
    int choice;
    struct record rec;
    FILE *fp;

    fp = fopen("customer_records.txt", "ab+"); // Open or create records file

    do {
        printf("\nBanking Record System\n");
        printf("---------------------\n");
        printf("1. Add a new record\n");
        printf("2. Search a record\n");
        printf("3. Update a record\n");
        printf("4. Delete a record\n");
        printf("5. Display all records\n");
        printf("6. Exit\n\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch(choice) {
            case 1: // Add a new record
                printf("\nEnter Name: ");
                scanf("%s", rec.name);
                printf("Enter account number: ");
                scanf("%d", &rec.account_number);
                printf("Enter balance: ");
                scanf("%f", &rec.balance);

                fwrite(&rec, sizeof(struct record), 1, fp);

                printf("\nRecord inserted successfully.\n");
                break;
            case 2: // Search a record
                printf("\nEnter account number to search: ");
                scanf("%d", &rec.account_number);

                while(fread(&rec, sizeof(struct record), 1, fp) == 1) {
                    if(rec.account_number == choice) {
                        printf("\nRecord Found.\n");
                        printf("Name: %s\n", rec.name);
                        printf("Account number: %d\n", rec.account_number);
                        printf("Balance: %.2f\n", rec.balance);
                        break;
                    }
                }

                if(feof(fp)) {
                    printf("\nRecord not found.\n");
                }

                break;
            case 3: // Update a record
                printf("\nEnter account number to update: ");
                scanf("%d", &rec.account_number);

                while(fread(&rec, sizeof(struct record), 1, fp) == 1) {
                    if(rec.account_number == choice) {
                        printf("\nEnter new name: ");
                        scanf("%s", rec.name);
                        printf("Enter new balance: ");
                        scanf("%f", &rec.balance);

                        fseek(fp, -sizeof(struct record), SEEK_CUR);
                        fwrite(&rec, sizeof(struct record), 1, fp);
                        printf("\nRecord updated successfully.\n");

                        break;
                    }
                }

                if(feof(fp)) {
                    printf("\nRecord not found.\n");
                }

                break;
            case 4: // Delete a record
                printf("\nEnter account number to delete: ");
                scanf("%d", &rec.account_number);

                FILE *ft;
                ft = fopen("temp_file.txt", "wb");

                rewind(fp);

                while(fread(&rec, sizeof(struct record), 1, fp) == 1) {
                    if(rec.account_number != choice) {
                        fwrite(&rec, sizeof(struct record), 1, ft);
                    }
                }

                fclose(fp);
                fclose(ft);

                remove("customer_records.txt");
                rename("temp_file.txt", "customer_records.txt");

                printf("\nRecord deleted successfully.\n");

                break;
            case 5: // Display all records
                printf("\nBanking Database\n");
                printf("-----------------\n");

                rewind(fp);

                while(fread(&rec, sizeof(struct record), 1, fp) == 1) {
                    printf("Name: %s\n", rec.name);
                    printf("Account number: %d\n", rec.account_number);
                    printf("Balance: %.2f\n", rec.balance);
                    printf("-----------------\n");
                }

                break;
        }
    } while(choice != 6);

    fclose(fp);

    return 0;
}