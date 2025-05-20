//FormAI DATASET v1.0 Category: Banking Record System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 1000 //Maximum number of records

struct record {
    char name[50];
    int account_number;
    float balance;
};

int main() {
    struct record bank_records[MAX_SIZE];
    int choice, n_records = 0;
    char filename[15];
    printf("Welcome to the C Banking Record System!\n");
    printf("Enter any key to continue: ");
    getchar();

    while (1) {
        printf("\n\nMenu:\n1. Add a new record\n2. Display records\n3. Save records to a file\n4. Load records from a file\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: //Adding a new record
                printf("Enter name: ");
                fgets(bank_records[n_records].name, 50, stdin);
                bank_records[n_records].name[strcspn(bank_records[n_records].name, "\n")] = 0;
                printf("Enter account number: ");
                scanf("%d", &bank_records[n_records].account_number);
                printf("Enter balance: ");
                scanf("%f", &bank_records[n_records].balance);
                n_records++;
                printf("Record added successfully!\n");
                break;

            case 2: //Displaying all records
                if (n_records == 0) {
                    printf("No records found.\n");
                } else {
                    printf("---------------------------------------------------------------------\n");
                    printf("Name\t\tAccount Number\t\tBalance\n");
                    printf("---------------------------------------------------------------------\n");
                    for (int i = 0; i < n_records; i++) {
                        printf("%-20s %-20d %-20.2f\n", bank_records[i].name, bank_records[i].account_number, bank_records[i].balance);
                    }
                    printf("---------------------------------------------------------------------\n");
                }
                break;

            case 3: //Saving records to a file
                if (n_records == 0) {
                    printf("No records found to save.\n");
                } else {
                    printf("Enter filename: ");
                    fgets(filename, 15, stdin);
                    filename[strcspn(filename, "\n")] = 0;
                    FILE *fptr = fopen(filename, "w");
                    if (fptr == NULL) {
                        printf("Error opening file!\n");
                    } else {
                        for (int i = 0; i < n_records; i++) {
                            fprintf(fptr, "%s %d %.2f\n", bank_records[i].name, bank_records[i].account_number, bank_records[i].balance);
                        }
                        printf("Records saved successfully!\n");
                        fclose(fptr);
                    }
                }
                break;

            case 4: //Loading records from a file
                printf("Enter filename: ");
                fgets(filename, 15, stdin);
                filename[strcspn(filename, "\n")] = 0;

                FILE *fptr = fopen(filename, "r");
                if (fptr == NULL) {
                    printf("Error opening file!\n");
                } else {
                    char *line = NULL;
                    size_t len = 0;
                    ssize_t read;
                    while ((read = getline(&line, &len, fptr)) != -1) {
                        sscanf(line, "%s %d %f", bank_records[n_records].name, &bank_records[n_records].account_number, &bank_records[n_records].balance);
                        n_records++;
                    }
                    printf("Records loaded successfully!\n");
                    fclose(fptr);
                }
                break;

            case 5: //Exiting the program
                printf("Thank you for using the C Banking Record System!\n");
                exit(0);

            default: //Invalid choice
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
    return 0;
}