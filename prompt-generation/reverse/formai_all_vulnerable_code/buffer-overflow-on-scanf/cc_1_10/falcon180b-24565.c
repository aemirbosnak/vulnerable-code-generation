//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWERS 4
#define MAX_STUDENTS 50

typedef struct {
    char name[50];
    int score;
} Student;

typedef struct {
    char question[100];
    char answer[MAX_ANSWERS][100];
    int correct_answer;
} Question;

void generate_question(Question* question) {
    srand(time(NULL));
    int num_answers = rand() % (MAX_ANSWERS - 1) + 1;
    for (int i = 0; i < num_answers; i++) {
        strcpy(question->answer[i], "Answer " + i);
    }
    question->correct_answer = rand() % num_answers;
    strcpy(question->question, "What is the capital of France? ");
    strcpy(question->answer[question->correct_answer], "Paris");
}

int main() {
    Student students[MAX_STUDENTS];
    Question questions[MAX_QUESTIONS];

    int num_students, num_questions;
    printf("Enter the number of students: ");
    scanf("%d", &num_students);
    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);

    for (int i = 0; i < num_students; i++) {
        printf("Enter the name of student %d: ", i+1);
        scanf("%s", students[i].name);
    }

    for (int i = 0; i < num_questions; i++) {
        generate_question(&questions[i]);
    }

    int num_correct_answers = 0;
    for (int i = 0; i < num_questions; i++) {
        for (int j = 0; j < num_students; j++) {
            printf("%s, please answer question %d: ", students[j].name, i+1);
            int answer_index;
            scanf("%d", &answer_index);
            if (answer_index == questions[i].correct_answer) {
                num_correct_answers++;
            }
        }
    }

    printf("The exam is over. ");
    for (int i = 0; i < num_students; i++) {
        printf("%s got %d out of %d correct. ", students[i].name, num_correct_answers, num_questions);
    }

    return 0;
}