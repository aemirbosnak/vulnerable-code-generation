//FormAI DATASET v1.0 Category: Online Examination System ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_QUESTIONS 50
#define QUESTION_LIMIT 100
#define MAX_OPTIONS 4
#define OPTION_LIMIT 50
#define MAX_NAME_LENGTH 50

typedef struct{
    char question[QUESTION_LIMIT];
    char options[MAX_OPTIONS][OPTION_LIMIT];
    int answer;
} quiz_question;

quiz_question quiz_questions[MAX_QUESTIONS];

int number_of_questions = 0;

void add_question(){
    if(number_of_questions == MAX_QUESTIONS){
        printf("Quiz question limit reached. Cannot add any more questions.\n");
        return;
    }

    printf("Enter question: ");
    fgets(quiz_questions[number_of_questions].question, QUESTION_LIMIT, stdin);

    for(int i=0; i<MAX_OPTIONS; i++){
        printf("Enter option %d: ", i+1);
        fgets(quiz_questions[number_of_questions].options[i], OPTION_LIMIT, stdin);
    }

    printf("Enter answer (1-4): ");
    scanf("%d", &quiz_questions[number_of_questions].answer);

    getchar(); // Eats up leftover newline
    number_of_questions++;
}

void take_quiz(){
    if(number_of_questions == 0){
        printf("No questions added yet.\n");
        return;
    }

    int score = 0;

    for(int i=0; i<number_of_questions; i++){
        printf("\nQuestion %d: %s", i+1, quiz_questions[i].question);
        for(int j=0; j<MAX_OPTIONS; j++){
            printf("%d. %s", j+1, quiz_questions[i].options[j]);
        }

        int selected_answer = -1;
        while(selected_answer < 1 || selected_answer > 4){
            printf("\nEnter answer (1-4): ");
            scanf("%d", &selected_answer);
        }

        if(selected_answer == quiz_questions[i].answer){
            printf("Correct!\n");
            score++;
        }else{
            printf("Incorrect! The correct answer is %d.\n", quiz_questions[i].answer);
        }

        getchar(); // Eats up leftover newline
    }

    printf("\nYou scored %d out of %d.\n", score, number_of_questions);
}

void print_instructions(){
    printf("\nWelcome to the Online Quiz System!\n\n");
    printf("Enter 1 to add a question.\n");
    printf("Enter 2 to take the quiz.\n");
    printf("Enter 3 to print instructions.\n");
    printf("Enter 4 to exit.\n");
}

int main(){
    int choice = 0;

    while(choice != 4){
        print_instructions();
        scanf("%d", &choice);
        getchar(); // Eats up leftover newline

        switch(choice){
            case 1:
                add_question();
                break;
            case 2:
                take_quiz();
                break;
            case 3:
                print_instructions();
                break;
            case 4:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice.\n");
                break;
        }
    }
    return 0;
}