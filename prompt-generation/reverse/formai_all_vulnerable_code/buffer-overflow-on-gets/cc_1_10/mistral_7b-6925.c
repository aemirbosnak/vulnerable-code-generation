//MISTRAL-7B DATASET v1.0 Category: Online Examination System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define MAX_OPTIONS 5
#define MAX_CHAR 100

typedef struct {
    char question[MAX_CHAR];
    char options[MAX_OPTIONS][MAX_CHAR];
    int answer;
} Question;

void printQuestion(Question q) {
    int i;
    printf("\n%s\n", q.question);
    for (i = 0; i < MAX_OPTIONS; i++) {
        printf("%d. %s\n", i+1, q.options[i]);
    }
}

int main() {
    srand(time(NULL));
    Question questions[MAX_QUESTIONS];
    int i, j, k, l, m, n, o, p;
    int totalMarks = 0;
    int marksObtained = 0;

    for (i = 0; i < MAX_QUESTIONS; i++) {
        printf("\nQuestion %d:\n", i+1);

        // Generate a question
        gets(questions[i].question);
        if (strlen(questions[i].question) > MAX_CHAR - 1) {
            printf("Question too long. Try again.\n");
            i--;
            continue;
        }

        // Generate options
        for (j = 0; j < MAX_OPTIONS; j++) {
            gets(questions[i].options[j]);
            if (strlen(questions[i].options[j]) > MAX_CHAR - 1) {
                printf("Option too long. Try again.\n");
                j--;
                continue;
            }
        }

        // Shuffle options
        for (k = 0; k < MAX_OPTIONS; k++) {
            l = rand() % (MAX_OPTIONS+1);
            if (l > MAX_OPTIONS) l--;
            if (l == k) {
                k--;
                continue;
            }
            o = questions[i].answer;
            questions[i].answer = questions[i].options[k][0];
            questions[i].options[k][0] = o;
            o = questions[i].options[l][0];
            questions[i].options[l][0] = questions[i].answer;
            questions[i].answer = o;
        }

        // Generate answer
        for (m = 0; m < MAX_OPTIONS; m++) {
            if (strcmp(questions[i].options[m], questions[i].question+strlen(questions[i].question)-5) == 0) {
                questions[i].answer = m+1;
                break;
            }
        }

        // Print question and options
        printQuestion(questions[i]);

        // Get user answer
        scanf("%d", &n);

        // Check answer
        if (n == questions[i].answer) {
            marksObtained++;
            printf("Correct!\n");
        } else {
            printf("Incorrect. The answer was %d.\n", questions[i].answer);
        }

        // Calculate total marks
        totalMarks += MAX_OPTIONS;

        // Print total marks and marks obtained
        printf("Total marks for this question: %d\n", totalMarks);
        printf("Marks obtained: %d\n\n", marksObtained);
    }

    // Calculate percentage
    float percentage = (float)marksObtained/totalMarks * 100;

    // Print percentage
    printf("Percentage: %.2f%%\n", percentage);

    return 0;
}