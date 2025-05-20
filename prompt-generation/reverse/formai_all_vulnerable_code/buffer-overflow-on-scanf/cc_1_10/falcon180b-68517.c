//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_CHOICES 4
#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Student;

typedef struct {
    char question[100];
    char choices[MAX_CHOICES][100];
    int answer;
} Question;

void generateRandomQuestion(Question *question) {
    int numChoices = rand() % MAX_CHOICES + 1;
    question->answer = rand() % numChoices;
    for (int i = 0; i < numChoices; i++) {
        strcpy(question->choices[i], "Choice ");
        int len = strlen(question->choices[i]);
        question->choices[i][len] = 'A' + i;
    }
}

int main() {
    int numStudents, numQuestions;
    scanf("%d %d", &numStudents, &numQuestions);

    Student students[MAX_STUDENTS];
    for (int i = 0; i < numStudents; i++) {
        scanf("%s", students[i].name);
    }

    Question questions[MAX_QUESTIONS];
    for (int i = 0; i < numQuestions; i++) {
        generateRandomQuestion(&questions[i]);
    }

    int scores[MAX_STUDENTS];
    memset(scores, 0, sizeof(scores));

    for (int i = 0; i < numStudents; i++) {
        for (int j = 0; j < numQuestions; j++) {
            int choice;
            printf("%s, please answer question %d: %s\n", students[i].name, j + 1, questions[j].question);
            for (int k = 0; k < MAX_CHOICES; k++) {
                printf("%d. %s\n", k + 1, questions[j].choices[k]);
            }
            scanf("%d", &choice);
            if (choice == questions[j].answer) {
                scores[i]++;
            }
        }
    }

    printf("Results:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("%s: %d/%d\n", students[i].name, scores[i], numQuestions);
    }

    return 0;
}