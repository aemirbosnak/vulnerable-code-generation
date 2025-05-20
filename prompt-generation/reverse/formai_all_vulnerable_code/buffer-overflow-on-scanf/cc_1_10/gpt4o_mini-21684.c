//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COURSES 5
#define MAX_STUDENTS 10
#define COURSE_NAME_LEN 50
#define STUDENT_NAME_LEN 50

typedef struct {
    char name[COURSE_NAME_LEN];
    int enrolledStudents;
} Course;

typedef struct {
    char name[STUDENT_NAME_LEN];
    int courseIndex;  // Index in the course array
} Student;

Course courses[MAX_COURSES];
Student students[MAX_STUDENTS];
int totalCourses = 0;
int totalStudents = 0;

void createCourse() {
    if (totalCourses >= MAX_COURSES) {
        fprintf(stderr, "🎓 Error: Maximum course limit reached! Can't add more courses.\n");
        return;
    }

    printf("✨ Enter the course name: ");
    fgets(courses[totalCourses].name, COURSE_NAME_LEN, stdin);
    courses[totalCourses].name[strcspn(courses[totalCourses].name, "\n")] = 0; // Remove newline
    courses[totalCourses].enrolledStudents = 0;
    totalCourses++;
    printf("🎉 Course '%s' created successfully!\n", courses[totalCourses - 1].name);
}

void enrollStudent() {
    if (totalStudents >= MAX_STUDENTS) {
        fprintf(stderr, "🚨 Error: Student capacity reached! No more enrollments allowed.\n");
        return;
    }

    char studentName[STUDENT_NAME_LEN];
    printf("📅 Enter the student's name: ");
    fgets(studentName, STUDENT_NAME_LEN, stdin);
    studentName[strcspn(studentName, "\n")] = 0; // Remove newline

    printf("Choose the course to enroll in (0 to %d):\n", totalCourses - 1);
    for (int i = 0; i < totalCourses; i++) {
        printf("%d: %s\n", i, courses[i].name);
    }

    int courseIndex;
    printf("Enter your choice (number): ");
    scanf("%d", &courseIndex);
    getchar(); // Clear newline from buffer

    if (courseIndex < 0 || courseIndex >= totalCourses) {
        fprintf(stderr, "❌ Error: Invalid course choice! Please enter a valid number.\n");
        return;
    }

    if (courses[courseIndex].enrolledStudents >= MAX_STUDENTS) {
        fprintf(stderr, "🚀 Error: Course '%s' is already full! Can't enroll more students.\n", 
                courses[courseIndex].name);
        return;
    }

    strcpy(students[totalStudents].name, studentName);
    students[totalStudents].courseIndex = courseIndex;
    courses[courseIndex].enrolledStudents++;
    totalStudents++;
    printf("🎊 Student '%s' enrolled in '%s' successfully!\n", studentName, courses[courseIndex].name);
}

void listCourses() {
    printf("📋 List of Courses:\n");
    for (int i = 0; i < totalCourses; i++) {
        printf("%d: %s - Enrolled Students: %d\n", 
               i, courses[i].name, courses[i].enrolledStudents);
    }
}

void listStudents() {
    printf("👩‍🎓 List of Students:\n");
    for (int i = 0; i < totalStudents; i++) {
        printf("%d: %s - Enrolled in: %s\n",
               i, students[i].name, courses[students[i].courseIndex].name);
    }
}

int main() {
    printf("🚀 Welcome to the Course Enrollment System!\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create Course\n");
        printf("2. Enroll Student\n");
        printf("3. List Courses\n");
        printf("4. List Students\n");
        printf("5. Exit\n");
        printf("Choose an option (1-5): ");

        int choice;
        scanf("%d", &choice);
        getchar(); // Clear newline from buffer

        switch (choice) {
            case 1:
                createCourse();
                break;
            case 2:
                enrollStudent();
                break;
            case 3:
                listCourses();
                break;
            case 4:
                listStudents();
                break;
            case 5:
                printf("👋 Exiting the system. Have a great day!\n");
                exit(0);
            default:
                fprintf(stderr, "❗️ Error: Invalid option! Please choose a number between 1 and 5.\n");
        }
    }

    return 0;
}