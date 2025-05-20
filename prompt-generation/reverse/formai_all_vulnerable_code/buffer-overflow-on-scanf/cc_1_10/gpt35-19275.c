//FormAI DATASET v1.0 Category: Data validation ; Style: happy
#include <stdio.h>
#include <stdbool.h>

int main() {
    printf("Welcome to the Happy Data Validator!\n");
    printf("We will be checking to see if your data is input correctly.\n");

    int age;
    printf("\nPlease enter your age: ");
    scanf("%d", &age);

    if (age < 0 || age > 150) {
        printf("Error: Age must be between 0 and 150.\n");
        return 1;
    }

    char gender;
    printf("\nPlease enter your gender (M or F): ");
    scanf(" %c", &gender);

    if (gender != 'M' && gender != 'F') {
        printf("Error: Gender must be 'M' or 'F'.\n");
        return 1;
    }

    float salary;
    printf("\nPlease enter your salary: $");
    scanf("%f", &salary);

    if (salary < 0) {
        printf("Error: Salary cannot be negative.\n");
        return 1;
    }

    int num_children;
    printf("\nPlease enter the number of children you have: ");
    scanf("%d", &num_children);

    if (num_children < 0) {
        printf("Error: Number of children cannot be negative.\n");
        return 1;
    }

    printf("\nCongratulations! Your data has been input correctly.\n");
    printf("Age: %d\n", age);
    printf("Gender: %c\n", gender);
    printf("Salary: $%.2f\n", salary);
    printf("Number of children: %d\n", num_children);

    return 0;
}