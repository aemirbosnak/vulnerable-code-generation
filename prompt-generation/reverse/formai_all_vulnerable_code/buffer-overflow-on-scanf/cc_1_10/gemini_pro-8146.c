//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for questions
typedef struct Question {
    char question[256];
    char options[4][64];
    int correctAnswer;
} Question;

// Structure for students
typedef struct Student {
    char name[64];
    int score;
} Student;

// Array of questions
Question questions[] = {
    {"What is the capital of India?", {"Delhi", "Mumbai", "Chennai", "Kolkata"}, 1},
    {"Who is the Prime Minister of India?", {"Narendra Modi", "Rahul Gandhi", "Arvind Kejriwal", "Mamata Banerjee"}, 1},
    {"Which is the largest ocean in the world?", {"Pacific Ocean", "Atlantic Ocean", "Indian Ocean", "Arctic Ocean"}, 1},
    {"What is the chemical symbol for gold?", {"Au", "Ag", "Cu", "Fe"}, 1},
    {"Who is the author of the book 'To Kill a Mockingbird'?", {"Harper Lee", "J.K. Rowling", "Jane Austen", "Charles Dickens"}, 1}
};

// Function to display questions
void displayQuestions(Question *questions, int numQuestions) {
    for (int i = 0; i < numQuestions; i++) {
        printf("%d. %s\n", i + 1, questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("    %c. %s\n", 'A' + j, questions[i].options[j]);
        }
    }
}

// Function to get student input
int getStudentInput(int numQuestions) {
    int score = 0;
    char input[2];

    for (int i = 0; i < numQuestions; i++) {
        printf("Enter the answer for question %d (A/B/C/D): ", i + 1);
        scanf("%s", input);

        if (input[0] - 'A' == questions[i].correctAnswer) {
            score++;
        }
    }

    return score;
}

// Function to display student results
void displayResults(Student *student, int score, int numQuestions) {
    printf("Student Name: %s\n", student->name);
    printf("Score: %d/%d\n", score, numQuestions);
}

int main() {
    // Get student name
    char name[64];
    printf("Enter your name: ");
    scanf("%s", name);

    // Create student struct
    Student student;
    strcpy(student.name, name);

    // Display questions
    displayQuestions(questions, sizeof(questions) / sizeof(Question));

    // Get student input
    student.score = getStudentInput(sizeof(questions) / sizeof(Question));

    // Display results
    displayResults(&student, student.score, sizeof(questions) / sizeof(Question));

    return 0;
}