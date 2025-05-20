//Falcon-180B DATASET v1.0 Category: Sorting ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Define a structure for storing data
typedef struct {
    int id;
    char name[50];
    float score;
} Student;

// Function for comparing two students based on their scores
int compare(const void *a, const void *b) {
    const Student *studentA = a;
    const Student *studentB = b;

    if (studentA->score > studentB->score) {
        return 1;
    } else if (studentA->score < studentB->score) {
        return -1;
    } else {
        return 0;
    }
}

// Main function
int main() {
    int numStudents;
    scanf("%d", &numStudents);

    // Dynamically allocate memory for an array of students
    Student *students = malloc(numStudents * sizeof(Student));

    // Read data for each student
    for (int i = 0; i < numStudents; i++) {
        scanf("%d %s %f", &students[i].id, students[i].name, &students[i].score);
    }

    // Sort the array of students based on their scores
    qsort(students, numStudents, sizeof(Student), compare);

    // Print the sorted array of students
    for (int i = 0; i < numStudents; i++) {
        printf("%d %s %.2f\n", students[i].id, students[i].name, students[i].score);
    }

    // Free the dynamically allocated memory
    free(students);

    return 0;
}