//FormAI DATASET v1.0 Category: Expense Tracker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

struct expense {
    char date[10];
    char category[20];
    float amount;
} record;

int main() {
    FILE *fp;
    char filename[20];
    int choice;

    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "ab+");

    if (fp == NULL) {
        printf("Error! Cannot open file.\n");
        exit(1);
    }

    while (1) {
        printf("1. Add Expense\n");
        printf("2. View Expense\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the date (dd/mm/yyyy): ");
                scanf("%s", record.date);
                printf("Enter the category: ");
                scanf("%s", record.category);
                printf("Enter the amount: ");
                scanf("%f", &record.amount);
                fwrite(&record, sizeof(record), 1, fp);
                printf("Expense added successfully!\n");
                break;
            case 2:
                printf("Date\t\tCategory\tAmount\n");
                while (fread(&record, sizeof(record), 1, fp) == 1)
                    printf("%s\t%s\t\t%.2f\n", record.date, record.category, record.amount);
                break;
            case 3:
                fclose(fp);
                printf("Exiting program...");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}