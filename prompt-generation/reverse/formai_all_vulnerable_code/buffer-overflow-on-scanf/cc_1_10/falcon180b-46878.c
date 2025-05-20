//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_ANSWERS 4
#define MAX_STUDENTS 100

typedef struct {
    char question[100];
    char answer[MAX_ANSWERS][100];
    int correct_answer;
} Question;

typedef struct {
    char name[50];
    int score;
} Student;

int main() {
    int num_questions, num_students;
    Question questions[MAX_QUESTIONS];
    Student students[MAX_STUDENTS];

    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);

    printf("Enter the questions and answers (in the format: question answer1 answer2 answer3 correct_answer):\n");
    for (int i = 0; i < num_questions; i++) {
        scanf("%s", questions[i].question);
        int num_answers = 0;
        while (num_answers < MAX_ANSWERS && scanf("%s", questions[i].answer[num_answers])!= EOF) {
            num_answers++;
        }
        scanf("%d", &questions[i].correct_answer);
    }

    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    printf("Enter the student names:\n");
    for (int i = 0; i < num_students; i++) {
        scanf("%s", students[i].name);
    }

    int num_correct_answers = 0;
    for (int i = 0; i < num_questions; i++) {
        for (int j = 0; j < num_students; j++) {
            printf("%s: ", students[j].name);
            int answer_index = 0;
            while (answer_index < MAX_ANSWERS) {
                printf("%s ", questions[i].answer[answer_index]);
                answer_index++;
            }
            printf("\n");
        }
    }

    return 0;
}