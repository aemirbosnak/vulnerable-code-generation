//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_ANSWER_LENGTH 100

// Structure for a single question
typedef struct {
    char question[MAX_ANSWER_LENGTH];
    int answer;
} Question;

// Function to load questions from a file
Question* loadQuestions(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    Question* questions = malloc(sizeof(Question) * MAX_QUESTIONS);
    int numQuestions = 0;

    char line[MAX_ANSWER_LENGTH];
    while (fgets(line, MAX_ANSWER_LENGTH, file)!= NULL) {
        if (numQuestions >= MAX_QUESTIONS) {
            printf("Error: too many questions in file '%s'\n", filename);
            exit(1);
        }

        char* questionStart = strchr(line, ':');
        if (questionStart == NULL) {
            printf("Error: invalid question format in file '%s'\n", filename);
            exit(1);
        }

        *questionStart = '\0';
        strcpy(questions[numQuestions].question, line);
        questions[numQuestions].answer = atoi(questionStart + 1);

        numQuestions++;
    }

    fclose(file);
    return questions;
}

// Function to save the user's answers to a file
void saveAnswers(char* filename, int numCorrect) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    fprintf(file, "Correct answers: %d\n", numCorrect);
    fclose(file);
}

// Function to display a question and get the user's answer
int displayQuestion(Question* question) {
    printf("%s", question->question);
    int answer;
    scanf("%d", &answer);

    if (answer == question->answer) {
        printf("Correct!\n");
        return 1;
    } else {
        printf("Incorrect.\n");
        return 0;
    }
}

// Main function
int main() {
    Question* questions = loadQuestions("questions.txt");
    int numCorrect = 0;

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        if (displayQuestion(questions + i)) {
            numCorrect++;
        }
    }

    saveAnswers("answers.txt", numCorrect);
    return 0;
}