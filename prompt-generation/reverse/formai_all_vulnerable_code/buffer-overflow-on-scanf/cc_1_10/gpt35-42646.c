//FormAI DATASET v1.0 Category: Online Examination System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct Question {
    char text[100];
    char answer[20];
    int points;
} Question;

int main() {
    printf("Welcome to the Online Examination System!\n");
    printf("Please enter your name: ");

    char name[50];
    scanf("%s", name);

    printf("\nHello %s!\n", name);

    int num_questions;
    printf("How many questions would you like to answer? (max 10) ");
    scanf("%d", &num_questions);

    if(num_questions > 10) {
        printf("Sorry, you can only answer up to 10 questions.\n");
        return 0;
    }

    Question questions[10];

    strcpy(questions[0].text, "What is 2+2?");
    strcpy(questions[0].answer, "4");
    questions[0].points = 10;

    strcpy(questions[1].text, "What is the capital of France?");
    strcpy(questions[1].answer, "Paris");
    questions[1].points = 20;

    strcpy(questions[2].text, "What is the largest mammal in the world?");
    strcpy(questions[2].answer, "Blue Whale");
    questions[2].points = 30;

    strcpy(questions[3].text, "What is the primary language spoken in Japan?");
    strcpy(questions[3].answer, "Japanese");
    questions[3].points = 25;

    strcpy(questions[4].text, "Who invented the telephone?");
    strcpy(questions[4].answer, "Alexander Graham Bell");
    questions[4].points = 40;

    strcpy(questions[5].text, "What is the formula for water?");
    strcpy(questions[5].answer, "H2O");
    questions[5].points = 15;

    strcpy(questions[6].text, "What is the largest planet in our solar system?");
    strcpy(questions[6].answer, "Jupiter");
    questions[6].points = 35;

    strcpy(questions[7].text, "What is the name of the world's largest desert?");
    strcpy(questions[7].answer, "Sahara");
    questions[7].points = 30;

    strcpy(questions[8].text, "What is the chemical symbol for gold?");
    strcpy(questions[8].answer, "Au");
    questions[8].points = 20;

    strcpy(questions[9].text, "What is the highest mountain in the world?");
    strcpy(questions[9].answer, "Mount Everest");
    questions[9].points = 50;

    int total_points = 0;
    int points_earned = 0;
    srand(time(NULL));
    int answered_questions = 0;

    while(answered_questions < num_questions) {
        int index = rand() % 10;

        if(questions[index].points > 0) {
            printf("\n%s (worth %d points)\n", questions[index].text, 
                   questions[index].points);

            char user_answer[20];
            scanf("%s", user_answer);

            if(strcmp(user_answer, questions[index].answer) == 0) {
                printf("Correct!\n");
                points_earned += questions[index].points;
            }
            else {
                printf("Incorrect! The correct answer was: %s\n", 
                       questions[index].answer);
            }

            total_points += questions[index].points;
            questions[index].points = 0;
            answered_questions++;
        }
    }

    printf("\nCongratulations %s, you earned %d out of %d points! (%.2f%%)\n", 
           name, points_earned, total_points, 
           ((float)points_earned / total_points) * 100);

    return 0;
}