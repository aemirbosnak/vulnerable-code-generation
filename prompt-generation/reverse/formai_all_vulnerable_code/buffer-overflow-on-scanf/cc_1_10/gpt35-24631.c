//FormAI DATASET v1.0 Category: Online Examination System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the online examination system!\n");
    printf("Please enter your name: ");
    char name[20];
    scanf("%s", name);
    printf("\n%s, are you ready to enter into the surrealist world of C programming?\n", name);
    printf("Enter 'yes' to proceed or 'no' to exit: ");
    char response[3];
    scanf("%s", response);

    if (strcmp(response, "yes") == 0) {
        printf("\nGreat! The exam will begin now.\n");

        int marks = 0;

        // Question 1
        printf("\nQ1. Write a C program to print the sum of two surreal numbers.\n");
        printf("Enter your answer:");
        float a, b;
        scanf("%f %f", &a, &b);
        float sum = a + b;
        if (sum > 42) {
            printf("Correct!\n");
            marks += 10;
        } else {
            printf("Incorrect!\n");
        }

        // Question 2
        printf("\nQ2. Consider the following code snippet:\nint a = 1;\nwhile (a) {\na *= 2;\n}\nWhat will be the output of this program?\n");
        printf("Enter your answer:");
        long long int x = 1;
        while (x) {
            x *= 2;
            if (x > 999) {
                printf("Correct!\n");
                marks += 10;
                break;
            }
        }

        // Question 3
        printf("\nQ3. Write a C program to find the square root of a negative surreal number.\n");
        printf("Enter your answer:");
        float num;
        scanf("%f", &num);
        if (num < 0) {
            printf("The square root of a negative surreal number is an imaginary number!\n");
            marks += 10;
        } else {
            printf("Incorrect!\n");
        }

        // Results
        printf("\nCongratulations, %s! You have completed the exam.\n", name);
        printf("Your final score is %d out of 30.\n", marks);

    } else {
        printf("\nGoodbye, %s! We hope to see you soon in the surrealist world of C programming!\n", name);
    }

    return 0;
}