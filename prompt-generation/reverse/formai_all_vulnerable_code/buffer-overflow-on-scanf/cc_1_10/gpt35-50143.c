//FormAI DATASET v1.0 Category: Online Examination System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 20
#define MAX_ANS_CHARS 50

typedef struct {
    char question[MAX_ANS_CHARS];
    char answer[MAX_ANS_CHARS];
} Question;

void clear_screen() {
    system("cls||clear");
}

void display_question(Question q) {
    printf("%s\n", q.question);
}

void display_menu() {
    printf("Welcome to the C Online Examination System!\n\n");
    printf("1. Take exam\n");
    printf("2. Exit\n\n");
    printf("Your choice: ");
}

void take_exam(Question *questions, int num_questions) {
    printf("You will be presented with %d questions.\n", num_questions);
    printf("Please answer the questions with the letter of the correct answer.\n");
    printf("You will receive your score at the end of the exam.\n\n");

    int score = 0;

    for (int i = 0; i < num_questions; i++) {
        display_question(questions[i]);

        char answer[MAX_ANS_CHARS];
        scanf("%s", answer);

        if (strcmp(answer, questions[i].answer) == 0) {
            score++;
        }

        clear_screen();
    }

    printf("Your score: %d/%d\n\n", score, num_questions);

    if (score >= num_questions/2) {
        printf("Congratulations! You passed the exam!\n");
    } else {
        printf("Sorry, you did not pass the exam. Please try again.\n");
    }

    printf("\nPress enter to return to the main menu.\n");
    getchar();
    getchar(); // wait for user to press enter
}

int main() {
    Question questions[MAX_QUESTIONS] = {
        {"What does the acronym \"C\" stand for?", "a"},
        {"Which of the following is not a valid data type in C?", "d"},
        {"What is the result of the expression 5 + 2 * 3?", "c"},
        {"What is the correct syntax for declaring a function?", "b"},
        {"Which of the following is an example of a looping structure?", "c"},
        {"Which of the following is not a logical operator in C?", "d"},
        {"What is the difference between a while loop and a do-while loop?", "c"},
        {"What is the value of the expression 1 == 2?", "d"},
        {"What is the purpose of the \"continue\" keyword?", "b"},
        {"What is the correct syntax for a switch statement?", "d"},
        {"What is the maximum value that can be stored in an unsigned int data type?", "a"},
        {"What is the correct syntax for accessing an element in an array?", "c"},
        {"What does the \"break\" keyword do?", "b"},
        {"What is the difference between a global variable and a local variable?", "d"},
        {"What are the three logical operators in C?", "a"},
        {"What is the difference between a float and a double data type?", "d"},
        {"What is the correct syntax for a for loop?", "b"},
        {"What is the purpose of the \"return\" keyword?", "a"},
        {"What is the difference between = and == in C?", "c"},
        {"What does the \"#define\" keyword do?", "a"}
    };

    int num_questions = 20;

    clear_screen();

    while (1) {
        display_menu();
        
        char choice[MAX_ANS_CHARS];
        scanf("%s", choice);

        if (strcmp(choice, "1") == 0) {
            take_exam(questions, num_questions);
            clear_screen();
        } else if (strcmp(choice, "2") == 0) {
            printf("Thank you for using the C Online Examination System!\n\n");
            break;
        } else {
           printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}