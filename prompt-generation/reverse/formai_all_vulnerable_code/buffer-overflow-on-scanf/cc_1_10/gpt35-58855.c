//FormAI DATASET v1.0 Category: Expense Tracker ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ENTRIES 20

// defining the expense structure
struct Expense {
    double amount;
    char category[20];
    char date[11];
    char time[9];
};

// function definitions
void inputExpense(struct Expense* exp);
void printExpenses(struct Expense exp[], int size);
void saveExpenses(struct Expense exp[], int size, char* filename);
void loadExpenses(struct Expense exp[], int* size, char* filename);

// main function
int main() {
    int choice, numOfEntries = 0;
    struct Expense expenses[MAX_ENTRIES];

    while (1) {
        printf("\n Menu: \n");
        printf("1. Add new expense\n");
        printf("2. View all expenses\n");
        printf("3. Save expenses to a file\n");
        printf("4. Load expenses from a file\n");
        printf("5. Exit the program\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (numOfEntries < MAX_ENTRIES) {
                inputExpense(&expenses[numOfEntries]);
                numOfEntries++;
            }
            else {
                printf("Cannot add more expenses (maximum limit reached) \n");
            }
            break;
        case 2:
            if (numOfEntries > 0) {
                printExpenses(expenses, numOfEntries);
            }
            else {
                printf("No expenses to display \n");
            }
            break;
        case 3:
            if (numOfEntries > 0) {
                char* fileName;
                printf("Enter the filename to save the data: ");
                scanf("%s", fileName);
                saveExpenses(expenses, numOfEntries, fileName);
                printf("Expenses saved successfully! \n");
            }
            else {
                printf("No expenses to save \n");
            }
            break;
        case 4:
            {
            int size = 0;
            char* fileName;
            printf("Enter the filename to load the data: ");
            scanf("%s", fileName);
            loadExpenses(expenses, &size, fileName);
            numOfEntries = size;
            printf("Expenses loaded successfully! \n");
            }
            break;
        case 5:
            printf("Exiting the program... Goodbye! \n");
            exit(0);
            break;
        default:
            printf("Invalid choice. Please try again. \n");
            break;
        }
    }
    return 0;
}

// function to input expense details
void inputExpense(struct Expense* exp) {
    printf("Enter expense amount: ");
    scanf("%lf", &(exp->amount));
    printf("Enter expense category: ");
    scanf("%s", exp->category);
    printf("Enter date (yyyy-mm-dd): ");
    scanf("%s", exp->date);
    printf("Enter time (hh:mm:ss): ");
    scanf("%s", exp->time);
}

// function to print all expenses
void printExpenses(struct Expense exp[], int size) {
    printf("\n Expense Records: \n");
    printf(" Amount | Category | Date | Time\n");
    for (int i = 0; i < size; i++) {
        printf(" %.2lf | %s | %s | %s \n", exp[i].amount, exp[i].category, exp[i].date, exp[i].time);
    }
}

// function to save expenses to a file
void saveExpenses(struct Expense exp[], int size, char* filename) {
    FILE* fp;
    fp = fopen(filename, "wb");
    if (fp != NULL) {
        fwrite(exp, sizeof(struct Expense), size, fp);
        fclose(fp);
    }
}

// function to load expenses from a file
void loadExpenses(struct Expense exp[], int* size, char* filename) {
    FILE* fp;
    fp = fopen(filename, "rb");
    if (fp != NULL) {
        fseek(fp, 0, SEEK_END); // point to end of file
        int numOfEntries = ftell(fp) / sizeof(struct Expense); // calculate number of entries
        rewind(fp); // point back to start of file
        fread(exp, sizeof(struct Expense), numOfEntries, fp); // read the entries
        *size = numOfEntries;
        fclose(fp);
    }
}