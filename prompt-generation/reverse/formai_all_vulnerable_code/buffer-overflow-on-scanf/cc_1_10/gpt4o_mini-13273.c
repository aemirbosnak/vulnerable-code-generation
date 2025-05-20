//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_DESC_SIZE 100

typedef struct {
    char description[MAX_DESC_SIZE];
    float amount;
} Expense;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    int count;
} Tracker;

void initialize_tracker(Tracker *tracker) {
    tracker->count = 0;
}

void add_expense(Tracker *tracker) {
    if (tracker->count < MAX_EXPENSES) {
        printf("Enter the description of your expense, dear lover: ");
        scanf(" %[^\n]", tracker->expenses[tracker->count].description);
        printf("Whence didst thou incur the cost, fair heart? Enter amount: ");
        scanf("%f", &tracker->expenses[tracker->count].amount);
        tracker->count++;
        printf("A new expense hath been added to the scroll of time!\n");
    } else {
        printf("Alas! No more space to inscribe thy expenses.\n");
    }
}

void view_expenses(const Tracker *tracker) {
    if (tracker->count == 0) {
        printf("Oh, the silence of empty coffers! No expenses recorded.\n");
        return;
    }

    printf("\nList of thy expenses has been gathered:\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%d. %s - $%.2f\n", i + 1, tracker->expenses[i].description, tracker->expenses[i].amount);
    }
    printf("\n");
}

float calculate_total(const Tracker *tracker) {
    float total = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->expenses[i].amount;
    }
    return total;
}

void remove_expense(Tracker *tracker) {
    if (tracker->count == 0) {
        printf("Alas! No expenses to banish from our records.\n");
        return;
    }

    int index;
    printf("Which expense doth thou wish to erase? Enter the number: ");
    scanf("%d", &index);
    if (index < 1 || index > tracker->count) {
        printf("Alas! Thy selection is out of range. Choose wisely!\n");
        return;
    }

    for (int i = index - 1; i < tracker->count - 1; i++) {
        tracker->expenses[i] = tracker->expenses[i + 1];
    }
    tracker->count--;
    printf("The shadow of that expense hath been lifted!\n");
}

void display_menu() {
    printf("Welcome, dear friend, to the ledger of expense!\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Calculate Total Expenses\n");
    printf("4. Remove Expense\n");
    printf("5. Exit\n");
    printf("Choose thy fate: ");
}

int main() {
    Tracker tracker;
    initialize_tracker(&tracker);
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_expense(&tracker);
                break;
            case 2:
                view_expenses(&tracker);
                break;
            case 3:
                printf("The total expense hath emerged from the shadows: $%.2f\n", calculate_total(&tracker));
                break;
            case 4:
                remove_expense(&tracker);
                break;
            case 5:
                printf("Farewell, kind friend! May thy coffers be filled with joy.\n");
                exit(0);
            default:
                printf("Lo! An unknown choice. Please select again.\n");
                break;
        }
    }
    
    return 0;
}