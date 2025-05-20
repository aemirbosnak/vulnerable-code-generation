//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: careful
#include<stdio.h>
#include<stdlib.h>

float income, rent, utilities, groceries, transport, medical, entertainment, other_expenses;

void calculateExpenses()
{
    float totalExpenses = rent + utilities + groceries + transport + medical + entertainment + other_expenses;
    printf("\nTotal expenses: $%.2f\n", totalExpenses);
}

void calculateSavings()
{
    float totalExpenses = rent + utilities + groceries + transport + medical + entertainment + other_expenses;
    float totalIncome = income;
    float totalSavings = totalIncome - totalExpenses;
    printf("\nTotal savings: $%.2f\n", totalSavings);
    if (totalSavings < 0)
    {
        printf("Warning: You are overspending!\n");
    }
}

void addIncome()
{
    printf("Enter monthly income: $");
    scanf("%f", &income);
}

void addRent()
{
    printf("Enter monthly rent: $");
    scanf("%f", &rent);
}

void addUtilities()
{
    printf("Enter monthly utilities: $");
    scanf("%f", &utilities);
}

void addGroceries()
{
    printf("Enter monthly groceries: $");
    scanf("%f", &groceries);
}

void addTransport()
{
    printf("Enter monthly transport: $");
    scanf("%f", &transport);
}

void addMedical()
{
    printf("Enter monthly medical expenses: $");
    scanf("%f", &medical);
}

void addEntertainment()
{
    printf("Enter monthly entertainment expenses: $");
    scanf("%f", &entertainment);
}

void addOtherExpenses()
{
    printf("Enter other monthly expenses: $");
    scanf("%f", &other_expenses);
}

int main()
{
    int choice;
    printf("Welcome to your Personal Finance Planner\n\n");
    printf("Please enter your monthly income and expenses\n\n");

    addIncome();
    addRent();
    addUtilities();
    addGroceries();
    addTransport();
    addMedical();
    addEntertainment();
    addOtherExpenses();

    printf("\nIncome: $%.2f", income);
    printf("\nRent: $%.2f", rent);
    printf("\nUtilities: $%.2f", utilities);
    printf("\nGroceries: $%.2f", groceries);
    printf("\nTransport: $%.2f", transport);
    printf("\nMedical Expenses: $%.2f", medical);
    printf("\nEntertainment: $%.2f", entertainment);
    printf("\nOther expenses: $%.2f\n", other_expenses);

    while(1)
    {
        printf("\n\n1. Calculate total expenses\n");
        printf("2. Calculate monthly savings\n");
        printf("3. Change income or expenses\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: calculateExpenses();
                    break;
            case 2: calculateSavings();
                    break;
            case 3: printf("\nWhich field do you want to change?\n");
                    printf("1. Income\n");
                    printf("2. Rent\n");
                    printf("3. Utilities\n");
                    printf("4. Groceries\n");
                    printf("5. Transport\n");
                    printf("6. Medical Expenses\n");
                    printf("7. Entertainment\n");
                    printf("8. Other expenses\n");
                    printf("9. Exit\n");
                    printf("\nEnter your choice: ");
                    scanf("%d", &choice);
                    switch(choice)
                    {
                        case 1: addIncome();
                                break;
                        case 2: addRent();
                                break;
                        case 3: addUtilities();
                                break;
                        case 4: addGroceries();
                                break;
                        case 5: addTransport();
                                break;
                        case 6: addMedical();
                                break;
                        case 7: addEntertainment();
                                break;
                        case 8: addOtherExpenses();
                                break;
                        case 9: break;
                        default: printf("Invalid choice\n");
                    }
                    break;
            case 4: exit(0);
                    break;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}