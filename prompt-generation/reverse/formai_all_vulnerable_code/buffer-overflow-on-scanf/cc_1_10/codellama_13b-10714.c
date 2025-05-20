//Code Llama-13B DATASET v1.0 Category: Online Examination System ; Style: introspective
/*
 * Online Examination System
 *
 * Created by [Your Name]
 * Date: [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store examination details
struct Exam {
    char name[20];
    int marks;
};

// Function to add a new examination
void addExam(struct Exam *exams, int *numExams) {
    // Ask for examination name
    printf("Enter examination name: ");
    scanf("%s", exams[*numExams].name);

    // Ask for examination marks
    printf("Enter examination marks: ");
    scanf("%d", &exams[*numExams].marks);

    // Increment number of examinations
    (*numExams)++;
}

// Function to display examination details
void displayExams(struct Exam *exams, int numExams) {
    int i;

    // Display examination details
    for (i = 0; i < numExams; i++) {
        printf("Examination: %s\n", exams[i].name);
        printf("Marks: %d\n", exams[i].marks);
    }
}

int main() {
    struct Exam exams[10];
    int numExams = 0;

    // Add examinations
    addExam(exams, &numExams);
    addExam(exams, &numExams);
    addExam(exams, &numExams);

    // Display examination details
    displayExams(exams, numExams);

    return 0;
}