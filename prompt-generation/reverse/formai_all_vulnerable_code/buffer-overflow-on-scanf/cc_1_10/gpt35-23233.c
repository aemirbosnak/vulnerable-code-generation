//FormAI DATASET v1.0 Category: Online Examination System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 50

// Struct to hold one question
typedef struct {
    char question[100];
    char answers[4][50];
    int correct_answer;
} Question;

// Global variable to hold all the questions
Question questions[MAX_QUESTIONS];

// Function to load the questions from file into the array
int load_questions() {
    FILE *fp;
    char fname[20];
    printf("Enter the file name with questions: ");
    scanf("%s", fname);
    fp = fopen(fname, "r");
    if(fp == NULL) {
        printf("Error opening file!\n");
        return 0;
    }

    int index = 0;
    char line[200], *token;
    while(fgets(line, sizeof(line), fp) != NULL && index < MAX_QUESTIONS) {
        // Remove the newline character at the end of the line
        line[strlen(line) - 1] = '\0';

        // Split the line into question and answers
        token = strtok(line, ",");
        strcpy(questions[index].question, token);

        for(int i = 0; i < 4; i++) {
            token = strtok(NULL, ",");
            strcpy(questions[index].answers[i], token);
        }

        token = strtok(NULL, ",");
        questions[index].correct_answer = atoi(token);

        index++;
    }

    fclose(fp);
    return index;
}

// Function to shuffle the questions
void shuffle_questions(int num_of_questions) {
    srand(time(NULL));
    for(int i = 0; i < num_of_questions; i++) {
        int j = rand() % num_of_questions;
        Question temp = questions[i];
        questions[i] = questions[j];
        questions[j] = temp;
    }
}

// Function to display a question and get user's answer
int ask_question(Question q) {
    printf("%s\n", q.question);
    for(int i = 0; i < 4; i++) {
        printf("%d. %s\n", i+1, q.answers[i]);
    }
    printf("Enter your answer: ");
    int user_answer;
    scanf("%d", &user_answer);
    return user_answer;
}

// Function to grade the user's answers
int grade_answers(int num_of_questions) {
    int score = 0;
    for(int i = 0; i < num_of_questions; i++) {
        if(ask_question(questions[i]) == questions[i].correct_answer) {
            score++;
            printf("Correct!\n");
        } else {
            printf("Incorrect!\n");
        }
    }
    return score;
}

// Main function
int main() {
    int num_of_questions = load_questions();
    if(num_of_questions == 0) {
        return 0;
    }

    shuffle_questions(num_of_questions);

    int score = grade_answers(num_of_questions);

    printf("You got %d out of %d\n", score, num_of_questions);
    return 0;
}