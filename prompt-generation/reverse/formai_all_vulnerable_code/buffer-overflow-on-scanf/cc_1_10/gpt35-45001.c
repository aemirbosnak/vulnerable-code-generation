//FormAI DATASET v1.0 Category: Online Examination System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Welcome message
    printf("Welcome to the C Online Examination System!\n");

    // Student login
    char name[50];
    printf("Please enter your name: ");
    scanf("%s", name);

    int id;
    printf("Please enter your student ID: ");
    scanf("%d", &id);

    // Exam questions
    printf("\nYou will now begin the exam:\n\n");

    int score = 0;

    printf("Question 1: What does the %c operator do?\n", '%');
    printf("a. Divides two numbers\nb. Multiplies two numbers\nc. Gives the remainder of dividing two numbers\nd. Adds two numbers\n");
    char ans1;
    scanf(" %c", &ans1);
    if (ans1 == 'c') {
        score++;
    }

    printf("Question 2: Which header file should be included for performing file input/output operations?\n");
    printf("a. stdio.h\nb. string.h\nc. math.h\nd. ctype.h\n");
    char ans2;
    scanf(" %c", &ans2);
    if (ans2 == 'a') {
        score++;
    }

    printf("Question 3: What is the output of the following code:\n\nint x = 5;\nprintf(\"%d %d %d\", ++x, ++x, ++x);\n\n");
    printf("a. 6 7 8\nb. 7 7 7\nc. 6 6 6\nd. 5 6 7\n");
    char ans3;
    scanf(" %c", &ans3);
    if (ans3 == 'b') {
        score++;
    }

    printf("\nYou have completed the exam!\n");

    // Calculate percentage score
    float percentage = (float) score / 3 * 100;
    printf("Your score is: %d/3 (%.2f%%)\n", score, percentage);

    // Determine pass or fail
    if (score >= 2) {
        printf("Congratulations, you have passed the exam!\n");
    } else {
        printf("Sorry, you have failed the exam. Please try again.\n");
    }

    return 0;
}