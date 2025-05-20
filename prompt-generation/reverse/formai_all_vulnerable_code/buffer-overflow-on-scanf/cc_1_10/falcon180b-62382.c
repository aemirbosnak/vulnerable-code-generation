//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_ANSWER_LENGTH 100

typedef struct {
    char question[MAX_QUESTIONS];
    char answer[MAX_ANSWER_LENGTH];
} question_t;

question_t questions[MAX_QUESTIONS];
int num_questions;

void read_questions(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    int i = 0;
    while (fgets(questions[i].question, MAX_QUESTIONS, file)!= NULL) {
        questions[i].answer[0] = '\0';
        i++;
        if (i >= MAX_QUESTIONS) {
            break;
        }
    }

    num_questions = i;
    fclose(file);
}

void shuffle_questions() {
    for (int i = 0; i < num_questions; i++) {
        int rand_index = rand() % num_questions;
        question_t temp = questions[i];
        questions[i] = questions[rand_index];
        questions[rand_index] = temp;
    }
}

int main() {
    char filename[100];
    printf("Enter the name of the questions file: ");
    scanf("%s", filename);

    read_questions(filename);
    shuffle_questions();

    for (int i = 0; i < num_questions; i++) {
        printf("%s\n", questions[i].question);
    }

    return 0;
}