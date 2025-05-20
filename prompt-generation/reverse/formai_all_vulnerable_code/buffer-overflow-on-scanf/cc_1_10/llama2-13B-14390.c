//LLAMA2-13B DATASET v1.0 Category: Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_NAME_LEN 20
#define MAX_GRADE_LEN 5
#define MAX_STUDENT_COUNT 20

typedef struct student {
    char name[MAX_NAME_LEN];
    char grade[MAX_GRADE_LEN];
} Student;

int main() {
    int i, j, k, num_students;
    Student students[MAX_STUDENT_COUNT];
    char input_name[MAX_NAME_LEN];
    char input_grade[MAX_GRADE_LEN];

    srand(time(NULL));

    printf("Welcome to the grade book!\n");

    // Ask the user for the number of students
    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    // Create the students
    for (i = 0; i < num_students; i++) {
        printf("Enter student %d's name: ", i + 1);
        scanf("%s", input_name);
        strcpy(students[i].name, input_name);

        printf("Enter student %d's grade: ", i + 1);
        scanf("%s", input_grade);
        strcpy(students[i].grade, input_grade);
    }

    // Print the grade book
    for (i = 0; i < num_students; i++) {
        printf("%d. %s (%s)\n", i + 1, students[i].name, students[i].grade);
    }

    // Add some randomness to the grades
    for (i = 0; i < num_students; i++) {
        students[i].grade[0] = 'A' + (rand() % 26);
    }

    // Print the grade book again
    for (i = 0; i < num_students; i++) {
        printf("%d. %s (%s)\n", i + 1, students[i].name, students[i].grade);
    }

    return 0;
}