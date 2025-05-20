//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Defining expense categories
enum Category {
    FOOD,
    RENT,
    UTILITIES,
    TRANSPORTATION,
    ENTERTAINMENT,
    OTHER
};

// Defining expense structure
struct Expense {
    double amount;
    enum Category category;
    char* description;
};

// Creating an array of expenses
struct Expense expenses[100];

// Getting user input for expenses
void getExpenses() {
    int i = 0;
    double amount;
    int category;
    char description[100];

    printf("Enter your expenses below:\n");
    while (i < 100) {
        printf("Amount: ");
        scanf("%lf", &amount);
        expenses[i].amount = amount;

        printf("Category: ");
        scanf("%d", &category);
        expenses[i].category = category;

        printf("Description: ");
        scanf("%s", description);
        expenses[i].description = description;

        i++;
    }
}

// Calculating total expenses
double calculateTotal() {
    double total = 0;
    for (int i = 0; i < 100; i++) {
        total += expenses[i].amount;
    }
    return total;
}

// Calculating average expenses
double calculateAverage() {
    double average = 0;
    int count = 0;
    for (int i = 0; i < 100; i++) {
        if (expenses[i].amount > 0) {
            average += expenses[i].amount;
            count++;
        }
    }
    return average / count;
}

// Finding the maximum expense
struct Expense findMax() {
    struct Expense maxExpense = expenses[0];
    for (int i = 1; i < 100; i++) {
        if (expenses[i].amount > maxExpense.amount) {
            maxExpense = expenses[i];
        }
    }
    return maxExpense;
}

// Finding the minimum expense
struct Expense findMin() {
    struct Expense minExpense = expenses[0];
    for (int i = 1; i < 100; i++) {
        if (expenses[i].amount < minExpense.amount) {
            minExpense = expenses[i];
        }
    }
    return minExpense;
}

// Printing the expenses
void printExpenses() {
    for (int i = 0; i < 100; i++) {
        printf("Amount: %.2f\n", expenses[i].amount);
        printf("Category: %d\n", expenses[i].category);
        printf("Description: %s\n\n", expenses[i].description);
    }
}

// Main function
int main() {
    // Getting user input for expenses
    getExpenses();

    // Calculating total expenses
    double total = calculateTotal();

    // Calculating average expenses
    double average = calculateAverage();

    // Finding the maximum expense
    struct Expense maxExpense = findMax();

    // Finding the minimum expense
    struct Expense minExpense = findMin();

    // Printing the expenses
    printExpenses();

    // Printing the total expenses
    printf("Total expenses: %.2f\n", total);

    // Printing the average expenses
    printf("Average expenses: %.2f\n", average);

    // Printing the maximum expense
    printf("Maximum expense: %.2f\n", maxExpense.amount);

    // Printing the minimum expense
    printf("Minimum expense: %.2f\n", minExpense.amount);

    return 0;
}