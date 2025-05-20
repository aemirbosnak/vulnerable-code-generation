//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define MAX_OPTIONS 4
#define MAX_ANSWERS 100

typedef struct {
    char question[256];
    char options[MAX_OPTIONS][256];
    int correctAnswerIndex;
} Question;

typedef struct {
    char studentName[50];
    int score;
    int totalQuestions;
} Student;

void displayWelcomeMessage() {
    printf("=========================================\n");
    printf("Welcome to the Futuristic Online Examination System!\n");
    printf("=========================================\n");
}

void initializeQuestions(Question *questions) {
    // Sample Questions Initialization for a futuristic subject 
    strcpy(questions[0].question, "What is the capital of the Moon Colony?");
    strcpy(questions[0].options[0], "Luna City");
    strcpy(questions[0].options[1], "New Earth");
    strcpy(questions[0].options[2], "Mars Base");
    strcpy(questions[0].options[3], "Titan Station");
    questions[0].correctAnswerIndex = 0;

    strcpy(questions[1].question, "Which material is used for space construction?");
    strcpy(questions[1].options[0], "Plutonium");
    strcpy(questions[1].options[1], "Titanium");
    strcpy(questions[1].options[2], "Graphene");
    strcpy(questions[1].options[3], "Carbon Fiber");
    questions[1].correctAnswerIndex = 2;

    // Additional questions can be added similarly...
    strcpy(questions[2].question, "What is the main energy source for Earth ships?");
    strcpy(questions[2].options[0], "Solar Power");
    strcpy(questions[2].options[1], "Nuclear Fusion");
    strcpy(questions[2].options[2], "Dark Energy");
    strcpy(questions[2].options[3], "Hydrogen Fuel");
    questions[2].correctAnswerIndex = 1;

    // Filling remaining questions with dummy data for the sake of example
    for (int i = 3; i < MAX_QUESTIONS; i++) {
        sprintf(questions[i].question, "Sample question %d?", i + 1);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            sprintf(questions[i].options[j], "Option %d", j + 1);
        }
        questions[i].correctAnswerIndex = 0;
    }
}

void conductExamination(Question *questions, Student *student) {
    int selectedAnswer;
    
    student->score = 0;
    student->totalQuestions = MAX_QUESTIONS;

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("Question %d: %s\n", i + 1, questions[i].question);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("  %d. %s\n", j + 1, questions[i].options[j]);
        }
        printf("Enter your answer (1-%d): ", MAX_OPTIONS);
        scanf("%d", &selectedAnswer);
        
        if (selectedAnswer - 1 == questions[i].correctAnswerIndex) {
            printf("Correct!\n\n");
            student->score++;
        } else {
            printf("Incorrect! The correct answer was: %s\n\n", questions[i].options[questions[i].correctAnswerIndex]);
        }
    }
}

void displayResults(Student *student) {
    printf("=========================================\n");
    printf("Exam completed. Here are your results!\n");
    printf("Name: %s\n", student->studentName);
    printf("Score: %d/%d\n", student->score, student->totalQuestions);
    printf("=========================================\n");
}

int main() {
    // Seed for random if needed in future extensions
    srand(time(NULL));

    Question questions[MAX_QUESTIONS];
    Student student;

    displayWelcomeMessage();
    
    printf("Please enter your name: ");
    scanf("%s", student.studentName);
    
    initializeQuestions(questions);
    conductExamination(questions, &student);
    displayResults(&student);
    
    return 0;
}