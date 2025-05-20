//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char *question;
    char *options[4];
    char *answer;
} Question;

typedef struct {
    char *name;
    int score;
} Student;

int main() {
    srand(time(NULL));

    // Create a list of questions
    Question questions[] = {
        {"What is the capital of France?", {"Paris", "London", "Rome", "Berlin"}, "Paris"},
        {"What is the largest ocean in the world?", {"Atlantic Ocean", "Pacific Ocean", "Indian Ocean", "Arctic Ocean"}, "Pacific Ocean"},
        {"Who painted the Mona Lisa?", {"Leonardo da Vinci", "Michelangelo", "Raphael", "Donatello"}, "Leonardo da Vinci"},
        {"What is the chemical symbol for gold?", {"Au", "Ag", "Cu", "Fe"}, "Au"},
        {"What is the name of the largest planet in the solar system?", {"Jupiter", "Saturn", "Uranus", "Neptune"}, "Jupiter"}
    };

    // Create a list of students
    Student students[] = {
        {"Alice", 0},
        {"Bob", 0},
        {"Carol", 0},
        {"Dave", 0},
        {"Eve", 0}
    };

    // Give each student a random question
    for (int i = 0; i < sizeof(students) / sizeof(students[0]); i++) {
        students[i].score = rand() % (sizeof(questions) / sizeof(questions[0]));
    }

    // Print the questions and options
    for (int i = 0; i < sizeof(questions) / sizeof(questions[0]); i++) {
        printf("Question %d: %s\n", i + 1, questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("  %c: %s\n", 'A' + j, questions[i].options[j]);
        }
    }

    // Get the answers from the students
    for (int i = 0; i < sizeof(students) / sizeof(students[0]); i++) {
        char answer;
        printf("Student %s, what is your answer to question %d? ", students[i].name, students[i].score + 1);
        scanf(" %c", &answer);
        if (answer == questions[students[i].score].answer[0]) {
            students[i].score++;
        }
    }

    // Print the results
    printf("\nResults:\n");
    for (int i = 0; i < sizeof(students) / sizeof(students[0]); i++) {
        printf("Student %s: %d/%d\n", students[i].name, students[i].score, sizeof(questions) / sizeof(questions[0]));
    }

    return 0;
}