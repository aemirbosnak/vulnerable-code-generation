//FormAI DATASET v1.0 Category: Online Examination System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int numQuestions, numStudents, i, j, k;
    printf("Welcome to the Online Examination System.\n");

    // Get number of questions and students
    printf("Enter the number of questions in the exam: ");
    scanf("%d", &numQuestions);
    printf("Enter the number of students taking the exam: ");
    scanf("%d", &numStudents);

    // Create array to store correct answers
    char *answers = (char*) malloc (numQuestions * sizeof(char));
    printf("Enter the correct answers, separated by spaces: ");
    for (i = 0; i < numQuestions; i++) {
        scanf(" %c", &answers[i]);
    }

    // Create array to store student answers
    char **studentAnswers = (char**) malloc (numStudents * sizeof(char*));
    for (i = 0; i < numStudents; i++) {
        studentAnswers[i] = (char*) malloc (numQuestions * sizeof(char));
    }

    // Get student answers
    for (i = 0; i < numStudents; i++) {
        printf("Enter student %d's answers, separated by spaces: ", i+1);
        for (j = 0; j < numQuestions; j++) {
            scanf(" %c", &studentAnswers[i][j]);
        }
    }

    // Grade each student
    int *grades = (int*) malloc (numStudents * sizeof(int));
    for (i = 0; i < numStudents; i++) {
        grades[i] = 0;
        for (j = 0; j < numQuestions; j++) {
            if (studentAnswers[i][j] == answers[j]) {
                grades[i]++;
            }
        }
    }

    // Output results
    printf("Results:\n");
    for (i = 0; i < numStudents; i++) {
        printf("Student %d scored %d out of %d\n", i+1, grades[i], numQuestions);
    }

    // Find highest and lowest scores
    int highest = grades[0], lowest = grades[0];
    for (i = 1; i < numStudents; i++) {
        if (grades[i] > highest) {
            highest = grades[i];
        }
        if (grades[i] < lowest) {
            lowest = grades[i];
        }
    }

    // Find average score
    float sum = 0;
    for (i = 0; i < numStudents; i++) {
        sum += grades[i];
    }
    float average = sum / numStudents;

    // Output additional results
    printf("Highest score: %d\n", highest);
    printf("Lowest score: %d\n", lowest);
    printf("Average score: %0.2f\n", average);

    // Free memory and exit
    free(answers);
    for (i = 0; i < numStudents; i++) {
        free(studentAnswers[i]);
    }
    free(studentAnswers);
    free(grades);
    return 0;
}