//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: optimized
#define MAX_EXPENSES 100
#define FALSE 0
#define TRUE 1

typedef struct {
    char category[20];
    float amount;
    int date;
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense(char *cat, float amt, int d) {
    if (num_expenses < MAX_EXPENSES) {
        strcpy(expenses[num_expenses].category, cat);
        expenses[num_expenses].amount = amt;
        expenses[num_expenses].date = d;
        num_expenses++;
    }
}

void display_expenses() {
    int i;
    printf("\nExpenses:\n");
    for (i = 0; i < num_expenses; i++) {
        printf("%s: %.2f on %d\n", expenses[i].category, expenses[i].amount, expenses[i].date);
    }
}

void search_expenses(char *cat) {
    int i;
    float total = 0;
    int found = FALSE;

    for (i = 0; i < num_expenses; i++) {
        if (strcmp(expenses[i].category, cat) == 0) {
            total += expenses[i].amount;
            found = TRUE;
        }
    }

    if (found) {
        printf("%s: Total %.2f\n", cat, total);
    } else {
        printf("%s: Not found\n", cat);
    }
}

int main() {
    int choice;
    char category[20];
    float amount;
    int date;

    while (1) {
        printf("\nExpense Tracker\n");
        printf("1. Add Expense\n");
        printf("2. Display Expenses\n");
        printf("3. Search Expenses\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter category: ");
                scanf("%s", category);
                printf("Enter amount: ");
                scanf("%f", &amount);
                printf("Enter date (yyyy mm dd): ");
                scanf("%d %d %d", &date, &date, &date); // fix this
                add_expense(category, amount, date);
                break;
            case 2:
                display_expenses();
                break;
            case 3:
                printf("Enter category to search: ");
                scanf("%s", category);
                search_expenses(category);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}