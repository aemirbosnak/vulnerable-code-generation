//FormAI DATASET v1.0 Category: Online Examination System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Question {
    char question[256];
    char optionA[64];
    char optionB[64];
    char optionC[64];
    char optionD[64];
    char answer;
} Question;

typedef struct Student {
    char name[64];
    char email[64];
    int score;
} Student;

void displayWelcomeMessage(void);
void displayInstructions(void);
void displayQuestion(Question);
int validateAnswer(char, Question);
void collectStudentDetails(Student *);
int generateQuestionnaire(int, Question[]);
int calculateScore(Student *, Question[], int);

int main(void) {
    int numQuestions = 3;
    int score = 0;
    Question questionnaire[numQuestions];
    Student student;
    displayWelcomeMessage();
    displayInstructions();
    collectStudentDetails(&student);
    generateQuestionnaire(numQuestions, questionnaire);
    score = calculateScore(&student, questionnaire, numQuestions);
    printf("Thank you for taking the exam %s. Your score is: %d.\n", student.name, score);
    return 0;
}

void displayWelcomeMessage() {
    printf("Welcome to the C Online Examination System.\n");
}

void displayInstructions() {
    printf("Please ensure you have read and understood the following instructions before taking the exam.\n");
    printf("1. The exam consists of multiple-choice questions.\n");
    printf("2. There are a total of 3 questions in the exam.\n");
    printf("3. Each correct answer is worth 1 mark.\n");
    printf("4. There is no negative marking for incorrect answers.\n");
    printf("5. The duration of the exam is 10 minutes.\n");
}

void displayQuestion(Question question) {
    printf("%s\n", question.question);
    printf("A. %s\n", question.optionA);
    printf("B. %s\n", question.optionB);
    printf("C. %s\n", question.optionC);
    printf("D. %s\n", question.optionD);
}

int validateAnswer(char answer, Question question) {
    if (toupper(answer) == toupper(question.answer)) {
        printf("Correct answer!\n");
        return 1;
    }
    else {
        printf("Incorrect answer.\n");
        return 0;
    }
}

void collectStudentDetails(Student *student) {
    printf("Please enter your name: ");
    scanf("%s", student->name);
    printf("Please enter your email address: ");
    scanf("%s", student->email);
}

int generateQuestionnaire(int numQuestions, Question questionnaire[]) {
    if (numQuestions < 1) {
        printf("Error: Invalid number of questions.\n");
        return -1;
    }
    Question question1 = {"What is the value of the constant pi?", "3.14", "4.13", "5.15", "6.16", 'A'};
    Question question2 = {"Which of the following is not a valid data type in C?", "float", "integer", "char", "double", 'B'};
    Question question3 = {"What does the keyword 'break' do in a switch statement?", "exits the switch statement", "continues to the next case", "does nothing", "breaks the code", 'A'};
    questionnaire[0] = question1;
    questionnaire[1] = question2;
    questionnaire[2] = question3;
    return 0;
}

int calculateScore(Student *student, Question questionnaire[], int numQuestions) {
    char answer;
    int score = 0;
    for (int i = 0; i < numQuestions; i++) {
        displayQuestion(questionnaire[i]);
        printf("Enter your answer (A/B/C/D): ");
        scanf(" %c", &answer);
        score += validateAnswer(answer, questionnaire[i]);
    }
    student->score = score;
    return score;
}