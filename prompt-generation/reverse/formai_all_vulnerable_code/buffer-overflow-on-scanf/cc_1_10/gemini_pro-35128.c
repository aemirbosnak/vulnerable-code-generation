//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Question {
    char question[256];
    char options[4][64];
    int correct_answer;
} Question;

typedef struct Student {
    char name[64];
    int score;
} Student;

Question questions[] = {
    {"What is the capital of India?", {"New Delhi", "Mumbai", "Bangalore", "Kolkata"}, 0},
    {"Who is the current Prime Minister of India?", {"Narendra Modi", "Rahul Gandhi", "Arvind Kejriwal", "Mamata Banerjee"}, 0},
    {"What is the national animal of India?", {"Tiger", "Lion", "Elephant", "Leopard"}, 0},
    {"What is the national bird of India?", {"Peacock", "Parrot", "Eagle", "Sparrow"}, 0},
    {"What is the national flower of India?", {"Lotus", "Rose", "Lily", "Jasmine"}, 0}
};

Student students[] = {
    {"John Doe", 0},
    {"Jane Doe", 0},
    {"Peter Parker", 0},
    {"Mary Jane", 0},
    {"Tony Stark", 0}
};

int main() {
    int num_questions = sizeof(questions) / sizeof(Question);
    int num_students = sizeof(students) / sizeof(Student);

    printf("Online Examination System\n\n");

    // Display questions
    for (int i = 0; i < num_questions; i++) {
        printf("Question %d: %s\n", i + 1, questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("\t%d. %s\n", j + 1, questions[i].options[j]);
        }
    }

    // Get answers from students
    for (int i = 0; i < num_students; i++) {
        printf("\nStudent %d: %s\n", i + 1, students[i].name);
        for (int j = 0; j < num_questions; j++) {
            int answer;
            do {
                printf("Enter your answer for Question %d (1-4): ", j + 1);
                scanf("%d", &answer);
            } while (answer < 1 || answer > 4);

            if (answer == questions[j].correct_answer) {
                students[i].score++;
            }
        }
    }

    // Display results
    printf("\nResults:\n\n");
    for (int i = 0; i < num_students; i++) {
        printf("Student %d: %s\n", i + 1, students[i].name);
        printf("Score: %d\n\n", students[i].score);
    }

    return 0;
}