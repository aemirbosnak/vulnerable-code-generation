//FormAI DATASET v1.0 Category: Online Examination System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_QUESTIONS 20
#define MAX_ANSWERS 4
#define MAX_NAME_LEN 50

struct test_question {
    char question[100];
    char answers[MAX_ANSWERS][50];
    int correct_answer;
};

struct test {
    char name[MAX_NAME_LEN];
    int num_questions;
    struct test_question questions[MAX_QUESTIONS];
};

bool run_test(struct test test);
void display_results(int num_correct, int num_questions);

int main() {
    struct test test1 = {
        .name = "C Programming Basics",
        .num_questions = 3,
        .questions[0] = {
            .question = "What is the syntax for declaring a variable?",
            .answers = {"a. variable name = value", "b. value = variable name", "c. int variable_name", "d. None of the above"},
            .correct_answer = 2
        },
        .questions[1] = {
            .question = "What is the output of the following code: printf(\"%%d\", 5+2);",
            .answers = {"a. 7", "b. 52", "c. Some error will occur", "d. None of the above"},
            .correct_answer = 0
        },
        .questions[2] = {
            .question = "What is the correct way to declare a function that takes no arguments and returns an int?",
            .answers = {"a. void my_function() { return 1; }",
                        "b. int my_function() { return; }",
                        "c. int my_function(void) { return 1; }",
                        "d. None of the above"
                       },
            .correct_answer = 2
        }
    };
    
    run_test(test1);
    
    return 0;
}

bool run_test(struct test test) {
    int num_correct = 0;
    
    printf("Welcome to the %s test!\n", test.name);
    printf("You will be given %d questions, each with %d possible answers.\n", test.num_questions, MAX_ANSWERS);
    printf("Please select the correct answer by typing the corresponding letter.\n");
    printf("Press enter to begin.\n");
    getchar();
    
    for (int i = 0; i < test.num_questions; i++) {
        printf("\nQuestion %d: %s\n", i+1, test.questions[i].question);
        
        for (int j = 0; j < MAX_ANSWERS; j++) {
            printf("%s\n", test.questions[i].answers[j]);
        }
        
        char choice;
        scanf(" %c", &choice);
        
        if ((int)(choice - 'a') == test.questions[i].correct_answer) {
            printf("Correct!\n");
            num_correct++;
        } else {
            printf("Incorrect. The correct answer was %c.\n", (char)(test.questions[i].correct_answer + 'a'));
        }
    }
    
    display_results(num_correct, test.num_questions);
    
    return true;
}

void display_results(int num_correct, int num_questions) {
    printf("\nYou answered %d out of %d questions correctly.\n", num_correct, num_questions);
    if (num_correct == num_questions) {
        printf("Great job!\n");
    } else if (num_correct >= num_questions/2) {
        printf("Not bad!\n");
    } else {
        printf("You'll need more practice.\n");
    }
}