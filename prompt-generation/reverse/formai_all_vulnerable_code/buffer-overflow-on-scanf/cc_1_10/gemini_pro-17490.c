//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store student data
typedef struct student {
    int rollno;
    char name[50];
    int marks[5];
    float total;
    float percentage;
} student;

// Function to calculate total marks
float calculateTotal(student *s) {
    int i;
    float total = 0;
    for (i = 0; i < 5; i++) {
        total += s->marks[i];
    }
    return total;
}

// Function to calculate percentage
float calculatePercentage(student *s) {
    float percentage = (s->total / 500) * 100;
    return percentage;
}

// Function to print student data
void printStudentData(student *s) {
    printf("Roll No: %d\n", s->rollno);
    printf("Name: %s\n", s->name);
    int i;
    for (i = 0; i < 5; i++) {
        printf("Marks in Subject %d: %d\n", i + 1, s->marks[i]);
    }
    printf("Total Marks: %.2f\n", s->total);
    printf("Percentage: %.2f%%\n\n", s->percentage);
}

// Function to compare students based on their total marks
int compareStudents(const void *a, const void *b) {
    const student *s1 = (const student *)a;
    const student *s2 = (const student *)b;
    return (int)(s2->total - s1->total);
}

// Main function
int main() {
    // Array of students
    student students[10];

    // Get student data
    int i;
    for (i = 0; i < 10; i++) {
        printf("Enter student %d data:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &students[i].rollno);
        printf("Name: ");
        scanf("%s", students[i].name);
        int j;
        for (j = 0; j < 5; j++) {
            printf("Marks in Subject %d: ", j + 1);
            scanf("%d", &students[i].marks[j]);
        }
    }

    // Calculate total and percentage for each student
    for (i = 0; i < 10; i++) {
        students[i].total = calculateTotal(&students[i]);
        students[i].percentage = calculatePercentage(&students[i]);
    }

    // Sort students based on their total marks
    qsort(students, 10, sizeof(student), compareStudents);

    // Print student data
    printf("Student Data:\n\n");
    for (i = 0; i < 10; i++) {
        printStudentData(&students[i]);
    }

    return 0;
}