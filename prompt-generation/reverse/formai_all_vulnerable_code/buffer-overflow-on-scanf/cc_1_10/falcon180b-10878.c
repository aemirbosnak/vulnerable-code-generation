//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_CHOICES 5
#define MAX_STUDENTS 50
#define MAX_NAME_LENGTH 50
#define MAX_ANSWER_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Student;

typedef struct {
    char question[MAX_ANSWER_LENGTH];
    char choices[MAX_CHOICES][MAX_ANSWER_LENGTH];
    int answer;
} Question;

void create_question(Question* q) {
    printf("Enter question: ");
    scanf("%s", q->question);
    printf("Enter number of choices: ");
    scanf("%d", &q->answer);
    for (int i = 0; i < q->answer; i++) {
        printf("Enter choice %d: ", i+1);
        scanf("%s", q->choices[i]);
    }
}

int main() {
    Question questions[MAX_QUESTIONS];
    Student students[MAX_STUDENTS];
    int num_questions, num_students;

    printf("Enter number of questions: ");
    scanf("%d", &num_questions);
    for (int i = 0; i < num_questions; i++) {
        create_question(&questions[i]);
    }

    printf("Enter number of students: ");
    scanf("%d", &num_students);
    for (int i = 0; i < num_students; i++) {
        printf("Enter student name: ");
        scanf("%s", students[i].name);
    }

    int total_score = 0;
    for (int i = 0; i < num_students; i++) {
        for (int j = 0; j < num_questions; j++) {
            printf("Student %s, question %d: ", students[i].name, j+1);
            int choice;
            scanf("%d", &choice);
            if (choice == questions[j].answer) {
                students[i].score++;
            }
        }
        total_score += students[i].score;
    }

    printf("Total score: %d\n", total_score);

    return 0;
}