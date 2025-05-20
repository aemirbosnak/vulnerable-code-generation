//FormAI DATASET v1.0 Category: Data validation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MIN_AGE 18
#define MIN_SALARY 25000.0
#define MAX_SALARY 100000.0

bool validate_age(int age);
bool validate_salary(float salary);

int main()
{
    int age;
    float salary;

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your salary: ");
    scanf("%f", &salary);

    if (validate_age(age) && validate_salary(salary))
    {
        printf("Congratulations! You are eligible.\n");
    }
    else
    {
        printf("Sorry, you are not eligible.\n");
    }

    return 0;
}

bool validate_age(int age)
{
    if (age < MIN_AGE)
    {
        printf("Minimum age requirement: %d\n", MIN_AGE);
        return false;
    }

    return true;
}

bool validate_salary(float salary)
{
    if (salary < MIN_SALARY || salary > MAX_SALARY)
    {
        printf("Salary should be between $%.2f and $%.2f\n", MIN_SALARY, MAX_SALARY);
        return false;
    }

    return true;
}