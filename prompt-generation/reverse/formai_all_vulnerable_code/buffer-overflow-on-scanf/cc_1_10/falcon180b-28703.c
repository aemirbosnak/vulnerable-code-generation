//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 20
#define MAX_OPTIONS 4
#define MAX_STUDENTS 100

struct question {
    char question[100];
    char options[MAX_OPTIONS][50];
    int answer;
};

struct student {
    char name[50];
    int roll_no;
    int score;
};

int main() {
    int num_questions, num_students;
    struct question questions[MAX_QUESTIONS];
    struct student students[MAX_STUDENTS];

    printf("Enter number of questions: ");
    scanf("%d", &num_questions);

    for (int i = 0; i < num_questions; i++) {
        printf("Enter question %d: ", i + 1);
        scanf("%s", questions[i].question);

        printf("Enter number of options: ");
        scanf("%d", &questions[i].answer);

        for (int j = 0; j < questions[i].answer; j++) {
            printf("Enter option %d: ", j + 1);
            scanf("%s", questions[i].options[j]);
        }
    }

    printf("Enter number of students: ");
    scanf("%d", &num_students);

    for (int i = 0; i < num_students; i++) {
        printf("Enter student name %d: ", i + 1);
        scanf("%s", students[i].name);

        printf("Enter student roll number %d: ", i + 1);
        scanf("%d", &students[i].roll_no);

        students[i].score = 0;
    }

    srand(time(NULL));

    for (int i = 0; i < num_questions; i++) {
        int correct_option = rand() % questions[i].answer;

        for (int j = 0; j < num_students; j++) {
            int option = rand() % questions[i].answer;

            if (option == correct_option) {
                students[j].score++;
            }
        }
    }

    printf("Examination Results:\n");
    for (int i = 0; i < num_students; i++) {
        printf("Student %s (%d) scored %d out of %d\n", students[i].name, students[i].roll_no, students[i].score, num_questions);
    }

    return 0;
}