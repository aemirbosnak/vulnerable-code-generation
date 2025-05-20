//FormAI DATASET v1.0 Category: Online Examination System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

//Function to calculate total marks obtained
int calculateMarks(int n, int correctAnswers[], int studentAnswers[]) {
    int marks = 0, i;
    for(i=0;i<n;i++) {
        if(correctAnswers[i] == studentAnswers[i]) {
            marks++;
        }
    }
    return marks;
}

int main() {
    int n, i, marksObtained;
    printf("Enter the number of questions: ");
    scanf("%d", &n);

    int correctAnswers[n];
    printf("Enter the correct answers for each question:\n");
    for(i=0;i<n;i++) {
        scanf("%d", &correctAnswers[i]);
    }

    printf("The correct answers are: ");
    for(i=0;i<n;i++) {
        printf("%d ", correctAnswers[i]);
    }
    printf("\n");

    int studentAnswers[n];
    printf("Enter your answers for each question:\n");
    for(i=0;i<n;i++) {
        scanf("%d", &studentAnswers[i]);
    }

    printf("Your answers are: ");
    for(i=0;i<n;i++) {
        printf("%d ", studentAnswers[i]);
    }
    printf("\n");

    marksObtained = calculateMarks(n, correctAnswers, studentAnswers);
    printf("You have obtained %d out of %d marks.\n", marksObtained, n);

    if(marksObtained >= (n/2)) {
        printf("Congratulations! You have passed the exam.\n");
    }
    else {
        printf("Sorry! You have failed the exam.\n");
    }
    return 0;
}