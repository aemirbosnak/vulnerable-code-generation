//FormAI DATASET v1.0 Category: Online Examination System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

int main() {
    int score = 0;
    char answer;

    // Question 1
    printf("1. What is the capital of France?\n");
    printf("a. Paris\nb. London\nc. Tokyo\nd. Beijing\n");
    fflush(stdin);
    scanf("%c", &answer);
    if (answer == 'a') {
        printf("Correct!\n");
        ++score;
    } else {
        printf("Incorrect. The correct answer is a) Paris.\n");
    }

    // Question 2
    printf("2. What is the output of the following code snippet? \n");
    printf("int x = 5;\nint y = 7;\nprintf(\"%d\", x + y);\n");
    fflush(stdin);
    scanf("%c", &answer);
    if (answer == 'c') {
        printf("Correct!\n");
        ++score;
    } else {
        printf("Incorrect. The correct answer is c) 12.\n");
    }

    // Question 3
    printf("3. Which of the following is not a programming language? \n");
    printf("a. Python\nb. JavaScript\nc. HTML\nd. MySQL\n");
    fflush(stdin);
    scanf("%c", &answer);
    if (answer == 'c') {
        printf("Correct!\n");
        ++score;
    } else {
        printf("Incorrect. The correct answer is c) HTML.\n");
    }

    // Question 4
    printf("4. What is the value of the following expression: 7 + 3 * 2? \n");
    fflush(stdin);
    scanf("%c", &answer);
    if (answer == 'a') {
        printf("Correct!\n");
        ++score;
    } else {
        printf("Incorrect. The correct answer is a) 13.\n");
    }

    // Question 5
    printf("5. What is the largest continent in the world? \n");
    printf("a. Asia\nb. Europe\nc. North America\nd. Australia\n");
    fflush(stdin);
    scanf("%c", &answer);
    if (answer == 'a') {
        printf("Correct!\n");
        ++score;
    } else {
        printf("Incorrect. The correct answer is a) Asia.\n");
    }

    // Calculate & Print Score
    int percentage = (score * 100) / 5;
    printf("Your score is: %d/5 (%d%%)\n", score, percentage);

    return 0;
}