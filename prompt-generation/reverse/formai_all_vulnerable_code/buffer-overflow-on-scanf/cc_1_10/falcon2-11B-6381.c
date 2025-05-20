//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Exam {
    int numQuestions;
    int numCorrect;
    int totalTime;
    int startTime;
};

void printExam(struct Exam exam) {
    printf("Exam:\n");
    printf("Number of questions: %d\n", exam.numQuestions);
    printf("Number of correct answers: %d\n", exam.numCorrect);
    printf("Total time: %d seconds\n", exam.totalTime);
    printf("Start time: %d seconds\n", exam.startTime);
    printf("End time: %d seconds\n", exam.startTime + exam.totalTime);
}

int main() {
    struct Exam exam;
    exam.numQuestions = 10;
    exam.numCorrect = 0;
    exam.totalTime = 600;
    exam.startTime = time(NULL);
    srand(exam.startTime);

    int numCorrect = 0;
    int questionIndex = 0;
    int questionAnswer = rand() % 2;

    while (numCorrect < exam.numQuestions) {
        printf("Question %d: %d + %d = ", questionIndex + 1, rand() % 100, rand() % 100);
        scanf("%d", &questionAnswer);
        if (questionAnswer == questionIndex + 1 + rand() % 100) {
            numCorrect++;
            printf("Correct!\n");
        } else {
            printf("Incorrect.\n");
        }
        if (numCorrect >= exam.numQuestions) {
            break;
        }
        questionIndex++;
    }

    if (numCorrect >= exam.numQuestions) {
        printf("You passed the exam!\n");
    } else {
        printf("You failed the exam.\n");
    }

    return 0;
}