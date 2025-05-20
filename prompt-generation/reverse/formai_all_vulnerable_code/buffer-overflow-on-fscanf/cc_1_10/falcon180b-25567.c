//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_CHOICES 5
#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Student;

typedef struct {
    char question[MAX_NAME_LENGTH];
    char choices[MAX_CHOICES][MAX_NAME_LENGTH];
    char answer;
} Question;

void readQuestions(Question questions[], int numQuestions) {
    FILE *file = fopen("questions.txt", "r");
    if (file == NULL) {
        printf("Error opening questions file.\n");
        exit(1);
    }

    for (int i = 0; i < numQuestions; i++) {
        fscanf(file, "%s %c", questions[i].question, &questions[i].answer);
        for (int j = 0; j < MAX_CHOICES; j++) {
            fscanf(file, "%s", questions[i].choices[j]);
        }
    }

    fclose(file);
}

int main() {
    Student students[MAX_STUDENTS];
    Question questions[MAX_QUESTIONS];

    readQuestions(questions, MAX_QUESTIONS);

    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    for (int i = 0; i < numStudents; i++) {
        printf("Enter student name: ");
        scanf("%s", students[i].name);
        students[i].score = 0;
    }

    int numCorrectAnswers = 0;

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        int numCorrect = 0;

        for (int j = 0; j < numStudents; j++) {
            printf("Student %s's answer for question %s: ", students[j].name, questions[i].question);
            char answer;
            scanf("%c", &answer);

            if (answer == questions[i].answer) {
                students[j].score++;
                numCorrect++;
            }
        }

        if (numCorrect > 0) {
            printf("%d students answered question %s correctly.\n", numCorrect, questions[i].question);
            numCorrectAnswers++;
        }
    }

    printf("Number of correct answers: %d\n", numCorrectAnswers);

    return 0;
}