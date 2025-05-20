//FormAI DATASET v1.0 Category: Educational ; Style: intelligent
#include <stdio.h>

// Define a struct for storing student information
struct Student {
    char name[50];
    int rollNumber;
    int marks[5]; // Marks of the student in 5 subjects
};

int main() {
    int numStudents, i, j;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    // Create an array of struct Student
    struct Student students[numStudents];

    // Get input from the user for each student's information
    for(i=0; i<numStudents; i++) {
        printf("\nEnter the name of student %d: ", i+1);
        scanf("%s", students[i].name);

        printf("Enter the roll number of student %d: ", i+1);
        scanf("%d", &students[i].rollNumber);

        printf("Enter the marks of student %d in 5 subjects: ", i+1);
        for(j=0; j<5; j++) {
            scanf("%d", &students[i].marks[j]);
        }
    }

    // Calculate the total marks and percentage of each student
    for(i=0; i<numStudents; i++) {
        int totalMarks = 0;
        for(j=0; j<5; j++) {
            totalMarks += students[i].marks[j];
        }
        float percentage = ((float)totalMarks / 500) * 100;

        printf("\nDetails of student %d:", i+1);
        printf("\nName: %s", students[i].name);
        printf("\nRoll number: %d", students[i].rollNumber);
        printf("\nMarks in 5 subjects: ");
        for(j=0; j<5; j++) {
            printf("%d ", students[i].marks[j]);
        }
        printf("\nTotal marks: %d", totalMarks);
        printf("\nPercentage: %.2f%%", percentage);
    }

    return 0;
}