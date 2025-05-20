//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10

typedef struct Question {
    char question[256];
    char answer[256];
    int marks;
} Question;

Question questions[MAX_QUESTIONS];

void readQuestions() {
    FILE *fp = fopen("questions.txt", "r");
    int i = 0;
    if (fp) {
        while (i < MAX_QUESTIONS && fgets(questions[i].question, 256, fp) != NULL) {
            questions[i].marks = 10;
            i++;
        }
        fclose(fp);
    }
}

void takeExam() {
    int i = 0;
    for (i = 0; i < MAX_QUESTIONS; i++) {
        printf("%s", questions[i].question);
        char answer[256];
        scanf("%s", answer);
        if (strcmp(answer, questions[i].answer) == 0) {
            questions[i].marks = 10;
        } else {
            questions[i].marks = 0;
        }
    }
}

void calculateResults() {
    int totalMarks = 0;
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        totalMarks += questions[i].marks;
    }
    printf("Total marks: %d", totalMarks);
    printf("\n");
    printf("Grade: %c", 'A' + totalMarks / 10);
}

int main() {
    readQuestions();
    takeExam();
    calculateResults();
    return 0;
}