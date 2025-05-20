//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main() {
    char* username = "john";
    char* password = "password123";

    printf("Welcome, %s!\n", username);

    int user_id = 1;
    int question_id = 1;
    int answer = 1;

    struct question {
        int id;
        char* question;
        char* answer;
    } questions[10];

    questions[0].id = question_id;
    questions[0].question = "What is 1+1?";
    questions[0].answer = "2";

    questions[1].id = question_id;
    questions[1].question = "What is 2+2?";
    questions[1].answer = "4";

    while (answer!= 0) {
        printf("Question %d: %s\n", question_id, questions[question_id-1].question);
        printf("Enter your answer: ");
        scanf("%d", &answer);

        if (answer == questions[question_id-1].answer) {
            printf("Correct!\n");
        } else {
            printf("Incorrect. The correct answer is %d.\n", questions[question_id-1].answer);
        }

        printf("Next question? (0 for no) ");
        scanf("%d", &answer);

        if (answer == 0) {
            break;
        }

        question_id++;
    }

    printf("Examination complete. Thank you for participating.\n");

    return 0;
}