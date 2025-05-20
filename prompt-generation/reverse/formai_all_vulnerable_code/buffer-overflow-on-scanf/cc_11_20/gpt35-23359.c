//FormAI DATASET v1.0 Category: Online Examination System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    //User Details
    char firstName[20];
    char lastName[20];
    int age;
    int score = 0;
    int total = 5;

    printf("Enter your first name: ");
    fgets(firstName, 20, stdin);

    printf("Enter your last name: ");
    fgets(lastName, 20, stdin);

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("\nHello %s%s, welcome to our online examination system.\n\n", firstName, lastName);

    //Questions and Answers
    printf("Question 1:\n");
    printf("What is the capital of France?\n");
    printf("A. London\n");
    printf("B. Paris\n");
    printf("C. Berlin\n");
    printf("D. Rome\n");
    char ans1;
    printf("\nEnter your answer: ");
    scanf(" %c", &ans1);

    if (ans1 == 'B' || ans1 == 'b') {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect. The correct answer is B.\n");
    }

    printf("\nQuestion 2:\n");
    printf("What is the smallest planet in our solar system?\n");
    printf("A. Earth\n");
    printf("B. Venus\n");
    printf("C. Mercury\n");
    printf("D. Mars\n");
    char ans2;
    printf("\nEnter your answer: ");
    scanf(" %c", &ans2);

    if (ans2 == 'C' || ans2 == 'c') {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect. The correct answer is C.\n");
    }

    printf("\nQuestion 3:\n");
    printf("What is the powerhouse of the cell?\n");
    printf("A. Mitochondria\n");
    printf("B. Lysosome\n");
    printf("C. Ribosome\n");
    printf("D. Nucleus\n");
    char ans3;
    printf("\nEnter your answer: ");
    scanf(" %c", &ans3);

    if (ans3 == 'A' || ans3 == 'a') {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect. The correct answer is A.\n");
    }

    printf("\nQuestion 4:\n");
    printf("Which planet is known as the Red Planet?\n");
    printf("A. Saturn\n");
    printf("B. Mercury\n");
    printf("C. Mars\n");
    printf("D. Jupiter\n");
    char ans4;
    printf("\nEnter your answer: ");
    scanf(" %c", &ans4);

    if (ans4 == 'C' || ans4 == 'c') {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect. The correct answer is C.\n");
    }

    printf("\nQuestion 5:\n");
    printf("What is the largest organ in the human body?\n");
    printf("A. Lungs\n");
    printf("B. Brain\n");
    printf("C. Liver\n");
    printf("D. Skin\n");
    char ans5;
    printf("\nEnter your answer: ");
    scanf(" %c", &ans5);

    if (ans5 == 'D' || ans5 == 'd') {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect. The correct answer is D.\n");
    }

    //Result
    float percentage = (float)score / (float)total * 100;

    printf("\n\nThank you for taking the exam %s%s.\n", firstName, lastName);
    printf("Your final score is %d/%d, which is %.2f percent.\n\n", score, total, percentage);

    if (percentage >= 60) {
        printf("Congratulations, you have passed the exam!\n");
    } else {
        printf("Sorry, you have failed the exam. Please try again later.\n");
    }

    return 0;
}