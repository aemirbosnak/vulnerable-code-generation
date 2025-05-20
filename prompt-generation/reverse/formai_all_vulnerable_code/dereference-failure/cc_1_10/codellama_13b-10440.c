//Code Llama-13B DATASET v1.0 Category: Online Examination System ; Style: beginner-friendly
// beginner-friendly C program for an online examination system

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// structure for a question
struct Question {
    char* question;
    char* answer;
    int points;
};

// structure for a student
struct Student {
    char* name;
    int score;
    struct Question* answers[10];
};

// function to get input from user
char* getInput() {
    char* input = malloc(100 * sizeof(char));
    fgets(input, 100, stdin);
    return input;
}

// function to print a question
void printQuestion(struct Question* question) {
    printf("%s\n", question->question);
}

// function to get a student's answer
void getAnswer(struct Student* student) {
    char* answer = getInput();
    strcpy(student->answers[student->score], answer);
    student->score++;
}

// function to check if a student's answer is correct
void checkAnswer(struct Student* student) {
    int correct = 0;
    for (int i = 0; i < student->score; i++) {
        if (strcmp(student->answers[i], student->answers[i]->answer) == 0) {
            correct++;
        }
    }
    student->score = correct;
}

// function to print a student's score
void printScore(struct Student* student) {
    printf("%s scored %d out of 10\n", student->name, student->score);
}

int main() {
    // create an array of 10 questions
    struct Question questions[10];
    questions[0].question = "What is the capital of France?";
    questions[0].answer = "Paris";
    questions[0].points = 5;
    questions[1].question = "What is the capital of Germany?";
    questions[1].answer = "Berlin";
    questions[1].points = 5;
    questions[2].question = "What is the capital of Italy?";
    questions[2].answer = "Rome";
    questions[2].points = 5;
    questions[3].question = "What is the capital of Spain?";
    questions[3].answer = "Madrid";
    questions[3].points = 5;
    questions[4].question = "What is the capital of Russia?";
    questions[4].answer = "Moscow";
    questions[4].points = 5;
    questions[5].question = "What is the capital of China?";
    questions[5].answer = "Beijing";
    questions[5].points = 5;
    questions[6].question = "What is the capital of Japan?";
    questions[6].answer = "Tokyo";
    questions[6].points = 5;
    questions[7].question = "What is the capital of South Korea?";
    questions[7].answer = "Seoul";
    questions[7].points = 5;
    questions[8].question = "What is the capital of India?";
    questions[8].answer = "New Delhi";
    questions[8].points = 5;
    questions[9].question = "What is the capital of Brazil?";
    questions[9].answer = "Brasilia";
    questions[9].points = 5;

    // create an array of 10 students
    struct Student students[10];
    students[0].name = "John";
    students[0].score = 0;
    students[1].name = "Jane";
    students[1].score = 0;
    students[2].name = "Bob";
    students[2].score = 0;
    students[3].name = "Alice";
    students[3].score = 0;
    students[4].name = "Mike";
    students[4].score = 0;
    students[5].name = "Emily";
    students[5].score = 0;
    students[6].name = "David";
    students[6].score = 0;
    students[7].name = "Sarah";
    students[7].score = 0;
    students[8].name = "Tim";
    students[8].score = 0;
    students[9].name = "Lisa";
    students[9].score = 0;

    // print the questions and get the answers
    for (int i = 0; i < 10; i++) {
        printQuestion(&questions[i]);
        getAnswer(&students[i]);
    }

    // check the answers and print the scores
    for (int i = 0; i < 10; i++) {
        checkAnswer(&students[i]);
        printScore(&students[i]);
    }

    return 0;
}