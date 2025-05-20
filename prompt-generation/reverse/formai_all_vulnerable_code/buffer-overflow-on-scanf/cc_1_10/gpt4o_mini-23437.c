//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_BUDGET_ITEMS 100
#define MAX_STRING_LENGTH 100
#define NUM_THREADS 3

// Structure to store budget item details
typedef struct {
    char name[MAX_STRING_LENGTH];
    float amount;
} BudgetItem;

// Global variables
BudgetItem budgetItems[MAX_BUDGET_ITEMS];
int itemCount = 0;
float totalBudget = 0.0;
pthread_mutex_t mutex;

// Function declarations
void* addItem(void* arg);
void* viewBudget(void* arg);
void* totalExpenditure(void* arg);
void clearInputBuffer();

// Main program
int main() {
    pthread_t threads[NUM_THREADS];
    int choice;

    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    do {
        printf("\n=== Personal Finance Planner ===\n");
        printf("1. Add Budget Item\n");
        printf("2. View Budget\n");
        printf("3. Total Expenditure\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        clearInputBuffer(); // Clear the input buffer

        switch (choice) {
            case 1:
                pthread_create(&threads[0], NULL, addItem, NULL);
                pthread_join(threads[0], NULL);
                break;
            case 2:
                pthread_create(&threads[1], NULL, viewBudget, NULL);
                pthread_join(threads[1], NULL);
                break;
            case 3:
                pthread_create(&threads[2], NULL, totalExpenditure, NULL);
                pthread_join(threads[2], NULL);
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (choice != 0);

    // Clean up
    pthread_mutex_destroy(&mutex);
    return 0;
}

// Function to add a budget item
void* addItem(void* arg) {
    pthread_mutex_lock(&mutex);

    if (itemCount >= MAX_BUDGET_ITEMS) {
        printf("Budget list is full. Cannot add more items.\n");
    } else {
        printf("Enter the name of the budget item: ");
        fgets(budgetItems[itemCount].name, MAX_STRING_LENGTH, stdin);
        budgetItems[itemCount].name[strcspn(budgetItems[itemCount].name, "\n")] = 0; // Remove newline

        printf("Enter the amount for the budget item: ");
        scanf("%f", &budgetItems[itemCount].amount);
        clearInputBuffer(); // Clear the input buffer

        totalBudget += budgetItems[itemCount].amount;
        itemCount++;
        printf("Budget item added successfully!\n");
    }

    pthread_mutex_unlock(&mutex);
    return NULL;
}

// Function to view all budget items
void* viewBudget(void* arg) {
    pthread_mutex_lock(&mutex);

    printf("\n--- Budget Items ---\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Item %d: %s - Amount: $%.2f\n", i + 1, budgetItems[i].name, budgetItems[i].amount);
    }
    if (itemCount == 0) {
        printf("No budget items to display.\n");
    }
    
    pthread_mutex_unlock(&mutex);
    return NULL;
}

// Function to calculate total expenditure
void* totalExpenditure(void* arg) {
    pthread_mutex_lock(&mutex);
    printf("Total Expenditure: $%.2f\n", totalBudget);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

// Function to clear the input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}