//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold question and answer
struct question {
    char question[100];
    char answer[100];
};

// Function to read questions from file
void readQuestions(struct question* questions, int numQuestions, char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(file, "%s %s", questions[i].question, questions[i].answer)!= EOF) {
        i++;
    }

    fclose(file);
}

// Function to display questions and get user's answer
int takeExam(struct question questions[], int numQuestions) {
    int score = 0;
    for (int i = 0; i < numQuestions; i++) {
        printf("%d. %s\n", i+1, questions[i].question);
        char answer[100];
        scanf("%s", answer);

        if (strcmp(answer, questions[i].answer) == 0) {
            score++;
        }
    }

    return score;
}

int main() {
    struct question questions[10];
    int numQuestions = 10;

    // Read questions from file
    char filename[100] = "questions.txt";
    readQuestions(questions, numQuestions, filename);

    // Take exam
    int score = takeExam(questions, numQuestions);

    // Print score
    printf("Your score is %d out of %d.\n", score, numQuestions);

    return 0;
}