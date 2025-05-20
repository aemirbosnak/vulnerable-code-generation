//FormAI DATASET v1.0 Category: Data validation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char name[50];
    int age;
    float salary;
    char gender;

    printf("Please enter your name: ");
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = '\0'; // remove trailing newline

    // validate name
    int i;
    for (i = 0; i < strlen(name); i++) {
        if (!isalpha(name[i]) && !isspace(name[i])) {
            printf("Error: Name can only contain alphabets and spaces.\n");
            exit(1);
        }
    }

    printf("Please enter your age: ");
    scanf("%d", &age);

    // validate age
    if (age < 18 || age > 120) {
        printf("Error: Age must be between 18 and 120.\n");
        exit(1);
    }

    printf("Please enter your gender (M/F): ");
    scanf(" %c", &gender);

    // validate gender
    if (toupper(gender) != 'M' && toupper(gender) != 'F') {
        printf("Error: Gender must be either 'M' or 'F'.\n");
        exit(1);
    }

    printf("Please enter your salary: ");
    scanf("%f", &salary);

    // validate salary
    if (salary < 0) {
        printf("Error: Salary cannot be negative.\n");
        exit(1);
    }

    printf("Thank you for providing your information!\n");

    return 0;
}