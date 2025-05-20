//FormAI DATASET v1.0 Category: Data validation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {

    char name[20];
    int age;
    char grade;

    printf("Welcome to the happy data validation program!\n");
    printf("Please enter your name: ");

    fgets(name, 20, stdin);

    for (int i = 0; name[i] != '\0'; i++) {
        if (!isalpha(name[i])) {
            printf("Sorry, your name can only contain letters! Please try again.\n");
            return 1;
        }
    }

    printf("Hello, %s! How old are you?\n", name);
    scanf("%d", &age);

    if (age < 0 || age > 120) {
        printf("Oops, it looks like you entered an invalid age!\n");
        printf("Please enter a number between 0 and 120: ");
        scanf("%d", &age);

        if (age < 0 || age > 120) {
            printf("Sorry, you entered an invalid age again! Please restart the program.\n");
            return 1;
        }
    }

    printf("Great! Now, what is your grade (A, B, C, D, or F)?\n");
    scanf(" %c", &grade);

    grade = toupper(grade); // Convert input to uppercase

    if (grade != 'A' && grade != 'B' && grade != 'C' && grade != 'D' && grade != 'F') {
        printf("Whoops, it looks like you entered an invalid grade!\n");
        printf("Please enter A, B, C, D, or F: ");
        scanf(" %c", &grade);

        grade = toupper(grade);

        if (grade != 'A' && grade != 'B' && grade != 'C' && grade != 'D' && grade != 'F') {
            printf("Sorry, you entered an invalid grade again! Please restart the program.\n");
            return 1;
        }
    }

    printf("Thank you for providing your information, %s!\n", name);
    printf("You are %d years old and have a grade of %c.\n", age, grade);

    return 0;
}