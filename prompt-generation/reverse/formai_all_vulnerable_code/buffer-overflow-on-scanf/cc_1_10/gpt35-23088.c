//FormAI DATASET v1.0 Category: Expense Tracker ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct expense {
    char date[15];
    float amount;
    char category[25];
};

void saveData(struct expense records[], int size) {
    FILE *fptr;
    fptr = fopen("expense_records.txt", "w");
    if(fptr == NULL) {
        printf("Error: Unable to create file\n");
        exit(1);
    }
    for(int i = 0; i < size; i++) {
        fprintf(fptr, "%s\t%.2f\t%s\n", records[i].date, records[i].amount, records[i].category);
    }
    printf("Data saved successfully!\n");
    fclose(fptr);
}

void displayData(struct expense records[], int size) {
    printf("Date\tAmount\tCategory\n");
    for(int i = 0; i < size; i++) {
        printf("%s\t%.2f\t%s\n", records[i].date, records[i].amount, records[i].category);
    }
}

int main() {
    int choice, count = 0;
    char ch;
    struct expense records[100];
    do {
        printf("\n\nExpense Tracker\n");
        printf("1. Add Expense\n");
        printf("2. Save Expenses\n");
        printf("3. Display Expenses\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter date (dd/mm/yyyy): ");
                scanf("%s", records[count].date);
                printf("Enter amount: ");
                scanf("%f", &records[count].amount);
                printf("Enter category: ");
                scanf("%s", records[count].category);
                count++;
                break;
            case 2:
                saveData(records, count);
                break;
            case 3:
                displayData(records, count);
                break;
            case 4:
                printf("Exiting program\n");
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
        printf("Press any key to continue..");
        scanf(" %c", &ch);
    } while(choice != 4);
    return 0;
}