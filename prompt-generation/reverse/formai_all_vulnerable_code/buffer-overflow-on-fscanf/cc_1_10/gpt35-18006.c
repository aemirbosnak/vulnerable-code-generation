//FormAI DATASET v1.0 Category: Data mining ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of students and courses
#define MAX_STUDENTS 50
#define MAX_COURSES 5

// Define the struct for a student
typedef struct {
    int id;
    float grades[MAX_COURSES];
} student;

// Define the struct for a course
typedef struct {
    char name[20];
    int credits;
} course;

// Function to calculate the average grade of a student
float calculateAverage(student s, int numCourses) {
    float sum = 0.0;
    for(int i=0; i<numCourses; i++){
        sum += s.grades[i];
    }
    return sum/numCourses;
}

int main() {
    // Declare an array of students and courses
    student students[MAX_STUDENTS];
    course courses[MAX_COURSES] = {
        {"Maths", 3},
        {"Physics", 4},
        {"Chemistry", 3},
        {"Biology", 2},
        {"English", 3}
    };

    // Read the number of students and their grades from a file
    FILE *fp;
    fp = fopen("data.txt", "r");
    if(fp == NULL){
        printf("Error opening file\n");
        return 1;   
    }
    int numStudents, numCourses, studentId;
    fscanf(fp, "%d%d", &numStudents, &numCourses);
    for(int i=0; i<numStudents; i++){
        fscanf(fp, "%d", &studentId);
        students[i].id = studentId;
        for(int j=0; j<numCourses; j++){
            float grade;
            fscanf(fp, "%f", &grade);
            students[i].grades[j] = grade;
        }
    }
    fclose(fp);

    // Find the student with the highest average grade
    float highestAverage = 0.0;
    int highestAverageStudentIndex = 0;
    for(int i=0; i<numStudents; i++){
        float average = calculateAverage(students[i], numCourses);
        if(average > highestAverage){
            highestAverage = average;
            highestAverageStudentIndex = i;
        }
    }

    // Print the details of the student with the highest average grade
    printf("Student with the highest average grade:\n");
    printf("ID: %d\n", students[highestAverageStudentIndex].id);
    printf("Average grade: %0.2f\n", highestAverage);
    printf("Course Grades:\n");
    for(int i=0; i<numCourses; i++){
        printf("%s: %0.2f\n", courses[i].name, students[highestAverageStudentIndex].grades[i]);
    }

    return 0;
}