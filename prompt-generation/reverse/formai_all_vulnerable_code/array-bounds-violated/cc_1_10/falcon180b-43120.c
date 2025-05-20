//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_CHOICES 5
#define MAX_ANSWERS 50
#define MAX_STUDENTS 100

typedef struct {
    char name[50];
    int student_id;
    int score;
} Student;

typedef struct {
    char question[100];
    char correct_answer;
    char choices[MAX_CHOICES][50];
    int num_choices;
} Question;

Question questions[MAX_QUESTIONS];
int num_questions = 0;

void add_question(char* question, char correct_answer, char choices[MAX_CHOICES][50], int num_choices) {
    strcpy(questions[num_questions].question, question);
    questions[num_questions].correct_answer = correct_answer;
    strcpy(questions[num_questions].choices[0], choices[0]);
    for (int i = 1; i < num_choices; i++) {
        strcpy(questions[num_questions].choices[i], choices[i]);
    }
    questions[num_questions].num_choices = num_choices;
    num_questions++;
}

int main() {
    int num_students, num_answers;
    scanf("%d", &num_students);
    Student students[MAX_STUDENTS];
    for (int i = 0; i < num_students; i++) {
        scanf("%s %d", students[i].name, &students[i].student_id);
    }
    scanf("%d", &num_answers);
    for (int i = 0; i < num_answers; i++) {
        int question_id, choice_id;
        scanf("%d %d", &question_id, &choice_id);
        students[i].score += questions[question_id - 1].num_choices == choice_id + 1? 1 : 0;
    }
    for (int i = 0; i < num_students; i++) {
        printf("%s %d %d\n", students[i].name, students[i].student_id, students[i].score);
    }
    return 0;
}