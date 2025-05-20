//FormAI DATASET v1.0 Category: Online Examination System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure to store questions
struct question {
    char question[100];
    char option1[50], option2[50], option3[50], option4[50];
    int answer;
};

int main()
{
    // variables to store user input
    int num_questions, num_attempts;
    char name[50];

    // ask for user input
    printf("Welcome to the C Online Examination System!\n\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Enter the number of questions in the exam: ");
    scanf("%d", &num_questions);
    printf("Enter the number of attempts allowed: ");
    scanf("%d", &num_attempts);

    // create array of questions
    struct question questions[num_questions];

    // loop to get question data from user
    for(int i=0; i<num_questions; i++) {
        printf("\nEnter details for question %d:\n", i+1);
        printf("Enter question: ");
        scanf("%s", questions[i].question);
        printf("Enter option 1: ");
        scanf("%s", questions[i].option1);
        printf("Enter option 2: ");
        scanf("%s", questions[i].option2);
        printf("Enter option 3: ");
        scanf("%s", questions[i].option3);
        printf("Enter option 4: ");
        scanf("%s", questions[i].option4);
        printf("Enter correct answer: ");
        scanf("%d", &questions[i].answer);
    }

    // loop to administer exam
    for(int i=0; i<num_attempts; i++) {
        printf("\nAttempt %d\n", i+1);
        int score = 0;
        for(int j=0; j<num_questions; j++) {
            printf("\nQuestion %d\n", j+1);
            printf("%s\n", questions[j].question);
            printf("1. %s\n", questions[j].option1);
            printf("2. %s\n", questions[j].option2);
            printf("3. %s\n", questions[j].option3);
            printf("4. %s\n", questions[j].option4);
            int user_answer;
            printf("Enter answer: ");
            scanf("%d", &user_answer);
            if(user_answer == questions[j].answer) {
                printf("Correct!\n");
                score++;
            }
            else {
                printf("Incorrect :(\n");
            }
        }
        printf("\n%s, your score for attempt %d is %d/%d\n", name, i+1, score, num_questions);
    }

    printf("\nThank you for using the C Online Examination System!\n");

    return 0;
}