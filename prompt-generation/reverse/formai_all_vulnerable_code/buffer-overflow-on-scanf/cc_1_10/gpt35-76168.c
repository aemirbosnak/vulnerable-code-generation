//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: complete
#include<stdio.h>
#include<stdlib.h>

void displayMenu();
float getUserInput(char*);
float calculateSavings(float,float,float);

int main() {
    int choice;
    float income, expenses, percentage;
    float savings;
    do {
        displayMenu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                income = getUserInput("Enter your monthly income: ");
                break;
            case 2:
                expenses = getUserInput("Enter your monthly expenses: ");
                break;
            case 3:
                percentage = getUserInput("Enter percentage of income to be saved: ");
                break;
            case 4:
                savings = calculateSavings(income, expenses, percentage);
                printf("Your monthly savings: %.2f\n", savings);
                break;
            case 5:
                printf("Thank you for using our Personal Finance Planner!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again!\n");
                break;
        }
    } while(1);

    return 0;
}

void displayMenu() {
    printf("\n\nPersonal Finance Planner\n\n");
    printf("1. Enter monthly income\n");
    printf("2. Enter monthly expenses\n");
    printf("3. Enter percentage of income to be saved\n");
    printf("4. Calculate monthly savings\n");
    printf("5. Quit\n\n");
    printf("Enter your choice: ");
}

float getUserInput(char* message) {
    float value;
    printf("%s", message);
    scanf("%f", &value);
    return value;
}

float calculateSavings(float income, float expenses, float percentage) {
    float savings = income - expenses;
    savings *= (percentage / 100.0);
    return savings;
}