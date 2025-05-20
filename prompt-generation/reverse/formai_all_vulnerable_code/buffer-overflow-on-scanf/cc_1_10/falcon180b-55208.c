//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_QUESTIONS 100
#define MAX_ANSWERS 4
#define MAX_STUDENTS 50
#define MAX_NAME_LENGTH 50
#define MAX_QUESTION_LENGTH 200
#define MAX_ANSWER_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Student;

typedef struct {
    char question[MAX_QUESTION_LENGTH];
    char answer[MAX_ANSWERS][MAX_ANSWER_LENGTH];
    int correct_answer;
} Question;

void shuffle(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        int j = rand() % len;
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void generate_question(Question *q) {
    char answer_list[MAX_ANSWERS][MAX_ANSWER_LENGTH];
    int num_answers = 0;
    printf("Enter the question: ");
    scanf("%s", q->question);
    printf("Enter the correct answer: ");
    scanf("%s", answer_list[num_answers]);
    num_answers++;
    while (num_answers < MAX_ANSWERS && scanf("%s", answer_list[num_answers])!= EOF) {
        num_answers++;
    }
    q->correct_answer = rand() % num_answers;
    for (int i = 0; i < num_answers; i++) {
        if (i == q->correct_answer) {
            strcpy(q->answer[i], answer_list[i]);
        } else {
            shuffle(answer_list[i]);
            strcpy(q->answer[i], answer_list[i]);
        }
    }
}

void generate_questions(Question *questions, int num_questions) {
    for (int i = 0; i < num_questions; i++) {
        generate_question(&questions[i]);
    }
}

void read_students(Student *students, int num_students) {
    for (int i = 0; i < num_students; i++) {
        printf("Enter student name: ");
        scanf("%s", students[i].name);
        students[i].score = 0;
    }
}

void take_exam(Question *questions, int num_questions, Student *students, int num_students) {
    for (int i = 0; i < num_questions; i++) {
        int correct_answers = 0;
        for (int j = 0; j < num_students; j++) {
            printf("%s: ", students[j].name);
            char answer[MAX_ANSWER_LENGTH];
            scanf("%s", answer);
            for (int k = 0; k < MAX_ANSWERS; k++) {
                if (strcmp(answer, questions[i].answer[k]) == 0) {
                    correct_answers++;
                    students[j].score++;
                    break;
                }
            }
        }
        if (correct_answers > 0) {
            printf("Correct answers: %d\n", correct_answers);
        } else {
            printf("No correct answers\n");
        }
    }
}

int main() {
    srand(time(NULL));
    Question questions[MAX_QUESTIONS];
    generate_questions(questions, 10);
    Student students[MAX_STUDENTS];
    read_students(students, 5);
    take_exam(questions, 10, students, 5);
    return 0;
}