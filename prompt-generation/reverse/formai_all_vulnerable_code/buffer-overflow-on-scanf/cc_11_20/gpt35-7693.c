//FormAI DATASET v1.0 Category: Data mining ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Structure definition to hold student information
struct StudentInfo {
    int rollNo;
    char name[30];
    int marks[5];
};

int main() {
    int n, i, j, k;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Dynamic allocation of memory to hold array of student structures
    struct StudentInfo* students = (struct StudentInfo*)malloc(n * sizeof(struct StudentInfo));

    // Taking input from user for each student's roll number, name and marks
    for (i = 0; i < n; i++) {
        printf("\nEnter the roll number of student %d: ", i+1);
        scanf("%d", &students[i].rollNo);

        printf("Enter the name of student %d: ", i+1);
        scanf(" %[^\n]s", students[i].name);

        printf("Enter the marks (out of 100) of student %d in 5 subjects: ", i+1);
        for (j = 0; j < 5; j++) {
            scanf("%d", &students[i].marks[j]);
        }
    }

    // Finding the student with highest marks in each subject
    int highestMarks[5] = {0};
    int highestMarksStudent[5] = {0};

    for (j = 0; j < 5; j++) {
        for (i = 0; i < n; i++) {
            if (students[i].marks[j] > highestMarks[j]) {
                highestMarks[j] = students[i].marks[j];
                highestMarksStudent[j] = students[i].rollNo;
            }
        }
    }

    // Printing the roll number and name of each student along with their marks in each subject
    printf("\nRoll No.\tName\t\tSubject 1\tSubject 2\tSubject 3\tSubject 4\tSubject 5\n");

    for (i = 0; i < n; i++) {
        printf("%d\t\t%s\t\t", students[i].rollNo, students[i].name);

        for (j = 0; j < 5; j++) {
            printf("%d\t\t", students[i].marks[j]);
        }

        printf("\n");
    }

    // Printing the roll number and name of student with highest marks in each subject
    printf("\n\nSubject\t\tRoll No.\tName\n");

    for (j = 0; j < 5; j++) {
        printf("Subject %d\t%d\t\t", j+1, highestMarksStudent[j]);

        for (i = 0; i < n; i++) {
            if (students[i].rollNo == highestMarksStudent[j]) {
                printf("%s", students[i].name);
            }
        }

        printf("\n");
    }

    // Freeing the dynamically allocated memory
    free(students);

    return 0;
}