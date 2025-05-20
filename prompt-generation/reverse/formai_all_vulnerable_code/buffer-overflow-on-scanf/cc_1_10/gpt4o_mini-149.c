//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int score;
} Student;

// Function to compare students for sorting by name
int compareByName(const void *a, const void *b) {
    Student *studentA = (Student *)a;
    Student *studentB = (Student *)b;
    
    return strcmp(studentA->name, studentB->name);
}

// Function to compare students for sorting by score
int compareByScore(const void *a, const void *b) {
    Student *studentA = (Student *)a;
    Student *studentB = (Student *)b;

    return studentB->score - studentA->score;  // Descending order
}

// Function to display the list of students
void displayStudents(Student students[], int count) {
    printf("\nList of Students:\n");
    printf("%-30s %-10s\n", "Name", "Score");
    printf("---------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-30s %-10d\n", students[i].name, students[i].score);
    }
}

int main() {
    Student students[MAX_STUDENTS];
    int studentCount = 0;
    char choice;

    // Input loop for student data
    do {
        if (studentCount >= MAX_STUDENTS) {
            printf("Maximum student limit reached!\n");
            break;
        }
        printf("Enter student name: ");
        fgets(students[studentCount].name, sizeof(students[studentCount].name), stdin);
        strtok(students[studentCount].name, "\n"); // Remove newline character

        printf("Enter score for %s: ", students[studentCount].name);
        scanf("%d", &students[studentCount].score);
        getchar(); // Consume newline left by scanf

        studentCount++;

        printf("Do you want to add another student? (y/n): ");
        scanf(" %c", &choice);
        getchar(); // Consume newline left by scanf
    } while (choice == 'y' || choice == 'Y');

    // Sort students by name
    qsort(students, studentCount, sizeof(Student), compareByName);
    displayStudents(students, studentCount);

    // Sort students by score (descending order)
    qsort(students, studentCount, sizeof(Student), compareByScore);
    displayStudents(students, studentCount);

    return 0;
}