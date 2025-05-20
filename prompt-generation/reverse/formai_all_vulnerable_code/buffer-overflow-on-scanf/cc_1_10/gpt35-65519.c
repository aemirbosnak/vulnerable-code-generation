//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: modular
#include <stdio.h>
#include <stdlib.h>

float calculate_total(float[], int);
float calculate_average(float[], int);
float determine_min(float[], int);
float determine_max(float[], int);
void print_array(float[], int);

int main()
{
    int num_months = 12;
    float expenses[num_months];
    float total_expenses, average_expenses, min_expense, max_expense;

    printf("Enter your monthly expenses for the last 12 months: \n");

    // prompt user to input expenses for each month
    for (int i = 0; i < num_months; i++)
    {
        printf("Month %d: ", i + 1);
        scanf("%f", &expenses[i]);
    }

    // calculate total, average, min, and max expenses
    total_expenses = calculate_total(expenses, num_months);
    average_expenses = calculate_average(expenses, num_months);
    min_expense = determine_min(expenses, num_months);
    max_expense = determine_max(expenses, num_months);

    // print out the results
    printf("Here are your monthly expenses:\n");
    print_array(expenses, num_months);
    printf("Total expenses for the year: $%.2f\n", total_expenses);
    printf("Average monthly expenses: $%.2f\n", average_expenses);
    printf("The lowest monthly expense was $%.2f\n", min_expense);
    printf("The highest monthly expense was $%.2f\n", max_expense);
    return 0;
}

float calculate_total(float arr[], int size)
{
    float sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

float calculate_average(float arr[], int size)
{
    float sum = calculate_total(arr, size);
    return sum / size;
}

float determine_min(float arr[], int size)
{
    float min = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

float determine_max(float arr[], int size)
{
    float max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void print_array(float arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}