//FormAI DATASET v1.0 Category: Online Examination System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of questions and the maximum length of each question and answer.
#define MAX_QUESTIONS 20
#define MAX_QUESTION_LENGTH 100
#define MAX_ANSWER_LENGTH 50

// Define the structure for a question.
typedef struct {
    char question[MAX_QUESTION_LENGTH];
    char answer[MAX_ANSWER_LENGTH];
} Question;

// Define the structure for a student.
typedef struct {
    char name[MAX_ANSWER_LENGTH];
    int score;
} Student;

// Define a function to load the questions from a file.
void load_questions(Question *questions, int *num_questions, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s.\n", filename);
        exit(1);
    }

    char buffer[MAX_QUESTION_LENGTH + MAX_ANSWER_LENGTH + 2];
    int i = 0;
    while (fgets(buffer, MAX_QUESTION_LENGTH + MAX_ANSWER_LENGTH + 2, file)) {
        char *slash = strchr(buffer, '/');
        if (slash == NULL) {
            fclose(file);
            printf("Invalid line in file %s.\n", filename);
            exit(1);
        }
        *slash = '\0';
        slash++;
        buffer[strlen(buffer) - 1] = '\0';
        strcpy(questions[i].question, buffer);
        strcpy(questions[i].answer, slash);
        i++;
        if (i >= MAX_QUESTIONS) {
            break;
        }
    }

    fclose(file);
    *num_questions = i;
}

// Define a function to save the scores to a file.
void save_scores(Student *students, int num_students, char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Could not save scores to file %s.\n", filename);
        return;
    }

    for (int i = 0; i < num_students; i++) {
        fprintf(file, "%s,%d\n", students[i].name, students[i].score);
    }

    fclose(file);
}

// Define a function to play the game.
void play_game(Question *questions, int num_questions, int time_limit, int max_attempts) {
    printf("Welcome to the online examination system!\n");
    printf("You have %d seconds to complete the exam.\n", time_limit);
    printf("You can have up to %d attempts per question.\n\n", max_attempts);

    // Allocate memory for the answers and the student.
    char **answers = malloc(sizeof(char *) * num_questions);
    for (int i = 0; i < num_questions; i++) {
        answers[i] = malloc(sizeof(char) * MAX_ANSWER_LENGTH);
    }
    Student student;
    printf("What is your name? ");
    scanf("%s", student.name);
    student.score = 0;

    // Play the game.
    for (int i = 0; i < num_questions; i++) {
        printf("Question %d:\n", i + 1);
        printf("%s\n", questions[i].question);

        for (int attempt = 1; attempt <= max_attempts; attempt++) {
            printf("Attempt %d: ", attempt);
            scanf("%s", answers[i]);
            if (strcmp(answers[i], questions[i].answer) == 0) {
                printf("Correct!\n\n");
                student.score++;
                break;
            } else {
                printf("Incorrect. ");
                if (attempt == max_attempts) {
                    printf("The correct answer was %s.\n\n", questions[i].answer);
                } else {
                    printf("Try again.\n");
                }
            }
        }
    }

    // Print the student's score.
    printf("Your exam is complete.\n");
    printf("Your score is %d out of %d.\n", student.score, num_questions);
    free(answers);
}

int main(int argc, char *argv[]) {
    // Parse the command line arguments.
    if (argc != 5) {
        printf("Usage: %s <filename> <time_limit> <max_attempts> <score_filename>\n", argv[0]);
        exit(1);
    }
    int time_limit = atoi(argv[2]);
    int max_attempts = atoi(argv[3]);

    // Load the questions from the file.
    Question questions[MAX_QUESTIONS];
    int num_questions = 0;
    load_questions(questions, &num_questions, argv[1]);

    // Play the game.
    play_game(questions, num_questions, time_limit, max_attempts);

    // Save the score to a file.
    Student student;
    student.score = 0;
    save_scores(&student, 1, argv[4]);

    return 0;
}