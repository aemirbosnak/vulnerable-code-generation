//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 100
#define MAX_ANSWERS 4
#define MAX_CHOICES 4

typedef struct {
    char question[100];
    char answer[100];
    char choices[MAX_CHOICES][100];
    int correct_answer;
} Question;

void shuffle(char* arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    FILE* fp;
    char filename[100];
    int num_questions, i, j, score = 0;
    Question questions[MAX_QUESTIONS];
    char answer[100];
    time_t start_time, end_time;

    printf("Enter the name of the question file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read number of questions
    fscanf(fp, "%d", &num_questions);

    // Read questions
    for (i = 0; i < num_questions; i++) {
        fscanf(fp, "%s", questions[i].question);
        fscanf(fp, "%s", questions[i].answer);
        fscanf(fp, "%d", &questions[i].correct_answer);
        for (j = 0; j < MAX_CHOICES; j++) {
            fscanf(fp, "%s", questions[i].choices[j]);
        }
    }

    fclose(fp);

    // Shuffle questions
    shuffle(questions, num_questions);

    // Start timer
    time(&start_time);

    for (i = 0; i < num_questions; i++) {
        printf("\nQuestion %d:\n%s", i + 1, questions[i].question);
        for (j = 0; j < MAX_CHOICES; j++) {
            printf("%d. %s\n", j + 1, questions[i].choices[j]);
        }
        printf("Enter your answer: ");
        scanf("%s", answer);
        if (strcmp(answer, questions[i].answer) == 0) {
            score++;
        }
    }

    // End timer
    time(&end_time);
    printf("\nYour score is %d out of %d.\n", score, num_questions);
    printf("Time taken: %ld seconds.\n", end_time - start_time);

    return 0;
}