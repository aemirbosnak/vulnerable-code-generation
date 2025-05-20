//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Question structure
struct Question {
    char question[100];
    int num_options;
    char options[4][100];
    int correct_option;
};

// Student structure
struct Student {
    char name[100];
    int score;
};

// Function to generate a random number
int generate_random(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to load questions from a file
void load_questions(struct Question *questions, int num_questions) {
    FILE *file = fopen("questions.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    for (int i = 0; i < num_questions; i++) {
        fgets(questions[i].question, 100, file);
        fscanf(file, "%d\n", &questions[i].num_options);
        for (int j = 0; j < questions[i].num_options; j++) {
            fgets(questions[i].options[j], 100, file);
        }
        fscanf(file, "%d\n", &questions[i].correct_option);
    }

    fclose(file);
}

// Function to take a quiz
void take_quiz(struct Question *questions, int num_questions, struct Student *student) {
    int score = 0;

    for (int i = 0; i < num_questions; i++) {
        printf("%s\n", questions[i].question);
        for (int j = 0; j < questions[i].num_options; j++) {
            printf("%d. %s\n", j + 1, questions[i].options[j]);
        }

        int answer;
        printf("Enter your answer: ");
        scanf("%d", &answer);

        if (answer == questions[i].correct_option) {
            score++;
        }
    }

    student->score = score;
}

// Function to generate a report
void generate_report(struct Student *students, int num_students) {
    printf("Examination Report\n");
    printf("--------------------\n");

    for (int i = 0; i < num_students; i++) {
        printf("%s: %d\n", students[i].name, students[i].score);
    }
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Load questions from file
    const int NUM_QUESTIONS = 10;
    struct Question questions[NUM_QUESTIONS];
    load_questions(questions, NUM_QUESTIONS);

    // Get student details
    const int NUM_STUDENTS = 5;
    struct Student students[NUM_STUDENTS];
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Enter student %d's name: ", i + 1);
        scanf("%s", students[i].name);
    }

    // Take the quiz
    for (int i = 0; i < NUM_STUDENTS; i++) {
        take_quiz(questions, NUM_QUESTIONS, &students[i]);
    }

    // Generate report
    generate_report(students, NUM_STUDENTS);

    return 0;
}