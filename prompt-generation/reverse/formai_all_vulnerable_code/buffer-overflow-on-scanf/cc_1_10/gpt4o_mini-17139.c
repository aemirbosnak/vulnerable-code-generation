//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_COURSES 50
#define MAX_ENROLLMENTS 200
#define NAME_LEN 50
#define CODE_LEN 10

typedef struct {
    int id;
    char name[NAME_LEN];
} Student;

typedef struct {
    char code[CODE_LEN];
    char title[NAME_LEN];
} Course;

typedef struct {
    int studentId;
    char courseCode[CODE_LEN];
} Enrollment;

Student students[MAX_STUDENTS];
Course courses[MAX_COURSES];
Enrollment enrollments[MAX_ENROLLMENTS];

int studentCount = 0;
int courseCount = 0;
int enrollmentCount = 0;

void addStudent() {
    if (studentCount < MAX_STUDENTS) {
        printf("Enter student ID: ");
        scanf("%d", &students[studentCount].id);
        printf("Enter student name: ");
        getchar();  // Consume leftover newline character
        fgets(students[studentCount].name, NAME_LEN, stdin);
        students[studentCount].name[strcspn(students[studentCount].name, "\n")] = '\0';  // Remove the newline
        studentCount++;
        printf("Student added successfully.\n");
    } else {
        printf("Maximum student limit reached!\n");
    }
}

void addCourse() {
    if (courseCount < MAX_COURSES) {
        printf("Enter course code: ");
        getchar();  // Consume leftover newline character
        fgets(courses[courseCount].code, CODE_LEN, stdin);
        courses[courseCount].code[strcspn(courses[courseCount].code, "\n")] = '\0';  // Remove the newline
        printf("Enter course title: ");
        fgets(courses[courseCount].title, NAME_LEN, stdin);
        courses[courseCount].title[strcspn(courses[courseCount].title, "\n")] = '\0';  // Remove the newline
        courseCount++;
        printf("Course added successfully.\n");
    } else {
        printf("Maximum course limit reached!\n");
    }
}

void enrollStudent() {
    if (enrollmentCount < MAX_ENROLLMENTS) {
        int studentId;
        char courseCode[CODE_LEN];
        printf("Enter student ID to enroll: ");
        scanf("%d", &studentId);
        printf("Enter course code to enroll in: ");
        getchar();  // Consume leftover newline character
        fgets(courseCode, CODE_LEN, stdin);
        courseCode[strcspn(courseCode, "\n")] = '\0';  // Remove the newline
        
        // Check if student and course exist
        int studentExists = 0, courseExists = 0;
        for (int i = 0; i < studentCount; i++) {
            if (students[i].id == studentId) {
                studentExists = 1;
                break;
            }
        }
        
        for (int j = 0; j < courseCount; j++) {
            if (strcmp(courses[j].code, courseCode) == 0) {
                courseExists = 1;
                break;
            }
        }
        
        if (studentExists && courseExists) {
            enrollments[enrollmentCount].studentId = studentId;
            strcpy(enrollments[enrollmentCount].courseCode, courseCode);
            enrollmentCount++;
            printf("Student enrolled successfully.\n");
        } else {
            printf("Invalid student ID or course code.\n");
        }
    } else {
        printf("Maximum enrollment limit reached!\n");
    }
}

void displayEnrollments() {
    printf("\nEnrollments:\n");
    for (int i = 0; i < enrollmentCount; i++) {
        printf("Student ID: %d, Course Code: %s\n", enrollments[i].studentId, enrollments[i].courseCode);
    }
}

void displayStudents() {
    printf("\nStudents:\n");
    for (int i = 0; i < studentCount; i++) {
        printf("ID: %d, Name: %s\n", students[i].id, students[i].name);
    }
}

void displayCourses() {
    printf("\nCourses:\n");
    for (int i = 0; i < courseCount; i++) {
        printf("Code: %s, Title: %s\n", courses[i].code, courses[i].title);
    }
}

int main() {
    int choice;

    do {
        printf("\n--- Simple Database Simulation ---\n");
        printf("1. Add Student\n");
        printf("2. Add Course\n");
        printf("3. Enroll Student in Course\n");
        printf("4. Display Students\n");
        printf("5. Display Courses\n");
        printf("6. Display Enrollments\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                addCourse();
                break;
            case 3:
                enrollStudent();
                break;
            case 4:
                displayStudents();
                break;
            case 5:
                displayCourses();
                break;
            case 6:
                displayEnrollments();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}