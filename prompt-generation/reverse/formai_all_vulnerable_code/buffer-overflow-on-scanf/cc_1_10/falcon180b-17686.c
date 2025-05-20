//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_STUDENTS 100

struct question {
    char question[100];
    char options[MAX_OPTIONS][100];
    int correct_option;
};

struct student {
    char name[50];
    int score;
};

int main() {
    int num_questions, num_students;
    scanf("%d %d", &num_questions, &num_students);

    struct question questions[MAX_QUESTIONS];
    struct student students[MAX_STUDENTS];

    for(int i=0; i<num_questions; i++) {
        scanf("%s", questions[i].question);
        int num_options = 0;
        while(scanf("%s", questions[i].options[num_options])!= EOF) {
            num_options++;
        }
        questions[i].correct_option = num_options - 1;
    }

    for(int i=0; i<num_students; i++) {
        scanf("%s", students[i].name);
        students[i].score = 0;
    }

    for(int i=0; i<num_questions; i++) {
        printf("%s\n", questions[i].question);
        for(int j=0; j<MAX_OPTIONS; j++) {
            printf("%d) %s\n", j+1, questions[i].options[j]);
        }
        scanf("%d", &students[0].score);
        for(int j=1; j<num_students; j++) {
            scanf("%d", &students[j].score);
        }
    }

    printf("\nResults:\n");
    for(int i=0; i<num_students; i++) {
        printf("%s: %d/%d\n", students[i].name, students[i].score, num_questions);
    }

    return 0;
}