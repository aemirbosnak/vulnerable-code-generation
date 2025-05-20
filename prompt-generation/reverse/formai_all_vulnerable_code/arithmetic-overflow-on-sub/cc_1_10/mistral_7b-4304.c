//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: minimalist
/*
 * Minimalistic C Expense Tracker
 * This program allows the user to add, delete and list expenses.
 */

#define MAX_EXPENSES 10
#define MAX_NAME_LENGTH 20
#define MAX_DESCRIPTION_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int current_index = 0;

void add_expense(const char *name, const char *description, float amount) {
    if (current_index >= MAX_EXPENSES) {
        printf("Error: Maximum number of expenses reached.\n");
        return;
    }

    strncpy(expenses[current_index].name, name, MAX_NAME_LENGTH);
    strncpy(expenses[current_index].description, description, MAX_DESCRIPTION_LENGTH);
    expenses[current_index].amount = amount;
    current_index++;
}

void delete_expense(int index) {
    if (index < 0 || index >= current_index) {
        printf("Error: Invalid expense index.\n");
        return;
    }

    current_index--;
    memmove(&expenses[index], &expenses[index + 1], sizeof(Expense) * (current_index - index));
}

void list_expenses() {
    printf("\nExpenses:\n");
    for (int i = 0; i < current_index; i++) {
        printf("%d. %s: %s - $%.2f\n", i + 1, expenses[i].name, expenses[i].description, expenses[i].amount);
    }
}

int main() {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    float amount;
    int choice, index;

    while (1) {
        printf("\n1. Add expense\n2. Delete expense\n3. List expenses\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Name: ");
                scanf("%s", name);
                printf("Description: ");
                scanf("%s", description);
                printf("Amount: $");
                scanf("%f", &amount);
                add_expense(name, description, amount);
                break;
            case 2:
                printf("Enter expense index: ");
                scanf("%d", &index);
                delete_expense(index - 1);
                break;
            case 3:
                list_expenses();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}