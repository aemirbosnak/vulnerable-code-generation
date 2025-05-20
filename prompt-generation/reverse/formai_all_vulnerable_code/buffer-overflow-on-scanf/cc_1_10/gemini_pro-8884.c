//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Question {
    char question[100];
    char options[4][50];
    char answer;
} Question;

typedef struct Student {
    char name[50];
    int score;
} Student;

Question questions[] = {
    {"What is the capital of India?", {"Delhi", "Mumbai", "Kolkata", "Chennai"}, 'A'},
    {"Which is the largest planet in our solar system?", {"Jupiter", "Saturn", "Uranus", "Neptune"}, 'A'},
    {"Who is the current Prime Minister of India?", {"Narendra Modi", "Rahul Gandhi", "Arvind Kejriwal", "Mamata Banerjee"}, 'A'},
    {"Which is the national animal of India?", {"Tiger", "Lion", "Elephant", "Peacock"}, 'A'},
    {"Which is the national bird of India?", {"Peacock", "Parrot", "Myna", "Sparrow"}, 'A'}
};

int num_questions = sizeof(questions) / sizeof(Question);

void take_exam(Student *student) {
    int i;
    int score = 0;

    for (i = 0; i < num_questions; i++) {
        printf("%s\n", questions[i].question);

        for (int j = 0; j < 4; j++) {
            printf("%d. %s\n", j + 1, questions[i].options[j]);
        }

        char answer;
        scanf(" %c", &answer);

        if (answer == questions[i].answer) {
            score++;
        }
    }

    student->score = score;
}

void print_results(Student *student) {
    printf("Name: %s\n", student->name);
    printf("Score: %d\n", student->score);
}

int main() {
    Student student;

    printf("Enter your name: ");
    scanf(" %s", student.name);

    take_exam(&student);

    print_results(&student);

    return 0;
}