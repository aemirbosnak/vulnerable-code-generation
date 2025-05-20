//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Futuristic Expense Tracker Interface
    // Version 1.0 - Galactic Credits Edition

    // Declare variables
    char name[20];
    int year, month, day, hour, minute;
    float amount;
    char category[50];
    int i = 0;

    // Create an array of expenses
    float expenses[100];

    // Get the user's name
    printf("Enter your name: ");
    scanf("%s", name);

    // Get the current date and time
    printf("Enter the year: ");
    scanf("%d", &year);

    printf("Enter the month: ");
    scanf("%d", &month);

    printf("Enter the day: ");
    scanf("%d", &day);

    printf("Enter the hour: ");
    scanf("%d", &hour);

    printf("Enter the minute: ");
    scanf("%d", &minute);

    // Get the expense amount
    printf("Enter the expense amount: ");
    scanf("%f", &amount);

    // Get the expense category
    printf("Enter the expense category: ");
    scanf("%s", category);

    // Store the expense in the array
    expenses[i] = amount;

    // Increment the index
    i++;

    // Print the expenses
    printf("Your expenses for %d/%d/%d: ", year, month, day);
    for (int j = 0; j < i; j++)
    {
        printf("%f - %s\n", expenses[j], category[j]);
    }

    return 0;
}