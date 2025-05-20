//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: brave
#include <stdio.h>
#include <math.h>

#define MAX_STUDENTS 100

// Structure to hold student data
typedef struct {
    char name[50];
    int examScores[5];
    float average;
} Student;

// Function declarations
void inputStudentData(Student* student);
void calculateAverageScore(Student* student);
void displayStudentInfo(const Student* student);
void displayStatistics(const Student students[], int count);
void sortStudentsByAverage(Student students[], int count);
void swap(Student* a, Student* b);

int main() {
    Student students[MAX_STUDENTS];
    int numStudents, i;

    printf("Welcome to the Brave Student Grader!\n");
    printf("How many students do you want to record data for (max %d)? ", MAX_STUDENTS);
    scanf("%d", &numStudents);

    if (numStudents < 1 || numStudents > MAX_STUDENTS) {
        printf("Invalid number of students. Exiting...\n");
        return 1;
    }

    // Input data for each student
    for (i = 0; i < numStudents; i++) {
        printf("\nEntering data for student %d:\n", i + 1);
        inputStudentData(&students[i]);
        calculateAverageScore(&students[i]);
    }

    // Display the statistics
    displayStatistics(students, numStudents);

    return 0;
}

// Function to input student data
void inputStudentData(Student* student) {
    printf("Enter the name of the student: ");
    scanf("%s", student->name); // Read student name
    for (int i = 0; i < 5; i++) {
        printf("Enter score for exam %d: ", i + 1);
        scanf("%d", &student->examScores[i]); // Read exam scores
    }
}

// Function to calculate the average score for a student
void calculateAverageScore(Student* student) {
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += student->examScores[i];
    }
    student->average = sum / 5.0; // Calculate the average
}

// Function to display individual student information
void displayStudentInfo(const Student* student) {
    printf("\n=== Student Info ===\n");
    printf("Name: %s\n", student->name);
    
    printf("Exam Scores: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", student->examScores[i]);
    }
    printf("\nAverage Score: %.2f\n", student->average);
}

// Function to display overall statistics
void displayStatistics(const Student students[], int count) {
    int totalPassed = 0, totalFailed = 0;
    float overallAverage = 0.0;
    
    for (int i = 0; i < count; i++) {
        overallAverage += students[i].average;
        if (students[i].average >= 50) {
            totalPassed++;
        } else {
            totalFailed++;
        }
    }
    
    overallAverage /= count; // Calculate overall average
    printf("\n=== Overall Statistics ===\n");
    printf("Total Students: %d\n", count);
    printf("Total Passed: %d\n", totalPassed);
    printf("Total Failed: %d\n", totalFailed);
    printf("Overall Average Score: %.2f\n", overallAverage);

    // Sort and display students by average score
    sortStudentsByAverage(students, count);
    printf("\n=== Students Sorted by Average Score ===\n");
    for (int i = 0; i < count; i++) {
        displayStudentInfo(&students[i]);
    }
}

// Function to sort students by average score in descending order
void sortStudentsByAverage(Student students[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].average < students[j + 1].average) {
                swap(&students[j], &students[j + 1]);
            }
        }
    }
}

// Function to swap two student records
void swap(Student* a, Student* b) {
    Student temp = *a;
    *a = *b;
    *b = temp;
}