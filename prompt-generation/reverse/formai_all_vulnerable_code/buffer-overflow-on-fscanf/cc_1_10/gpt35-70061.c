//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118
#define MAX_SYMBOL_LENGTH 3
#define MAX_NAME_LENGTH 25

// struct to hold element properties
typedef struct {
    char symbol[MAX_SYMBOL_LENGTH];
    char name[MAX_NAME_LENGTH];
    int atomic_number;
    float atomic_weight;
} element_t;

// struct to hold quiz options
typedef struct {
    int num_questions;
    int difficulty;
} quiz_options_t;

// function to read elements from file
void read_elements(element_t* elements) {
    FILE* fp = fopen("periodic_table.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Unable to open file\n");
        exit(1);
    }
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        fscanf(fp, "%d %f %s %[^\n]", &elements[i].atomic_number, &elements[i].atomic_weight, elements[i].symbol, elements[i].name);
    }
    fclose(fp);
}

// function to print out quiz options
void print_quiz_options(quiz_options_t* options) {
    printf("****************************************\n");
    printf("*         WELCOME TO QUIZ MODE         *\n");
    printf("****************************************\n");
    printf("* Number of questions:  %d\n", options->num_questions);
    printf("* Difficulty level:     %d\n", options->difficulty);
    printf("****************************************\n");
    printf("\n");
}

// function to get user input for quiz options
void get_quiz_options(quiz_options_t* options) {
    printf("Enter number of questions: ");
    scanf("%d", &options->num_questions);
    printf("Enter difficulty level (1-5): ");
    scanf("%d", &options->difficulty);
}

// function to generate quiz questions
void generate_quiz(element_t* elements, quiz_options_t* options) {
    int num_correct = 0; // keep track of number of correct answers
    char answer[MAX_NAME_LENGTH]; // buffer for user input
    int max_question_number = (options->difficulty * 10); // maximum atomic number for quiz questions
    printf("************* BEGIN QUIZ **************\n");
    for (int i = 0; i < options->num_questions; i++) {
        // generate random atomic number for quiz question
        int question_number = rand() % max_question_number + 1;
        // find corresponding element in element array
        element_t* question_element;
        for (int j = 0; j < MAX_ELEMENTS; j++) {
            if (elements[j].atomic_number == question_number) {
                question_element = &elements[j];
                break;
            }
        }
        // print out quiz question and prompt user for answer
        printf("What element has the atomic number %d? ", question_number);
        scanf("%s", answer);
        // compare answer to actual element name
        if (strcmp(question_element->name, answer) == 0) {
            printf("Correct!\n");
            num_correct++;
        } else {
            printf("Incorrect. The correct answer was %s.\n", question_element->name);
        }
    }
    // print out quiz results
    printf("************* END QUIZ **************\n");
    printf("You answered %d out of %d questions correctly.\n", num_correct, options->num_questions);
}

int main() {
    element_t elements[MAX_ELEMENTS];
    quiz_options_t options;
    read_elements(elements);
    get_quiz_options(&options);
    print_quiz_options(&options);
    generate_quiz(elements, &options);
    return 0;
}