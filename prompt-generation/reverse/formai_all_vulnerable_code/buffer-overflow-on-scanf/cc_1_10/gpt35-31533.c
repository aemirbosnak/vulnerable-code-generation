//FormAI DATASET v1.0 Category: Expense Tracker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
    int amount;
    char category[50];
    char date[20];
};

void add_expense(struct expense *arr, int *size) {
    struct expense e;
    printf("\nEnter the amount spent: ");
    scanf("%d", &(e.amount));
    printf("Enter the category: ");
    scanf("%s", e.category);
    printf("Enter the date in format 'dd/mm/yyyy': ");
    scanf("%s", e.date);
    arr[*size] = e;
    *size += 1;
    printf("\nExpense added successfully!\n");
}

void display_expenses(struct expense *arr, int size) {
    if(size == 0) {
        printf("\nThere are no expenses to display!\n");
        return;
    }
    printf("\n\n------------- EXPENSES -------------\n");
    printf("%-15s %-20s %s\n", "Amount", "Category", "Date");
    for(int i=0; i<size; i++) {
        printf("%-15d %-20s %s\n", arr[i].amount, arr[i].category, arr[i].date);
    }
    printf("\n");
}

void delete_expense(struct expense *arr, int *size) {
    if(*size == 0) {
        printf("\nThere are no expenses to delete!\n");
        return;
    }
    int index_to_delete;
    printf("\nEnter the index of the expense to be deleted: ");
    scanf("%d", &index_to_delete);

    if(index_to_delete < 0 || index_to_delete >= *size) {
        printf("\nInvalid index entered!\n");
        return;
    }
    for(int i=index_to_delete; i<*size-1 ; i++) {
        arr[i] = arr[i+1];
    }
    *size -= 1;
    printf("\nExpense deleted successfully!\n");
}

int main() {
    struct expense arr[100];
    int size = 0, choice = 0;
    while(1) {
        printf("\n\n+++++++ EXPENSE TRACKER +++++++\n");
        printf("1. Add expense\n2. Display expenses\n3. Delete expense\n4. Exit\n\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_expense(arr, &size);
                break;
            case 2:
                display_expenses(arr, size);
                break;
            case 3:
                delete_expense(arr, &size);
                break;
            case 4:
                printf("\nThank you for using our expense tracker!\n");
                exit(0);
            default:
                printf("\nInvalid choice entered, please enter again!\n");
        }
    }
    return 0;
}