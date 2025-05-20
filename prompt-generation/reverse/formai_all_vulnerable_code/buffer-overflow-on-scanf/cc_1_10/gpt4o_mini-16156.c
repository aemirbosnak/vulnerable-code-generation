//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a student
typedef struct {
    char name[50];
    int id;
    float grades[5];
    float average;
} Student;

// Function to calculate average grade
float calculate_average(float grades[], int num_grades) {
    float sum = 0;
    for (int i = 0; i < num_grades; i++) {
        sum += grades[i];
    }
    return sum / num_grades;
}

// Function to display student details
void display_student(const Student *s) {
    printf("Student ID: %d\n", s->id);
    printf("Name: %s\n", s->name);
    printf("Grades: ");
    for (int i = 0; i < 5; i++) {
        printf("%.2f ", s->grades[i]);
    }
    printf("\nAverage: %.2f\n\n", s->average);
}

// Function to enter student data
void enter_student_data(Student *s) {
    printf("Enter Student ID: ");
    scanf("%d", &s->id);
    printf("Enter Student Name: ");
    getchar(); // clear buffer
    fgets(s->name, sizeof(s->name), stdin);
    s->name[strcspn(s->name, "\n")] = '\0'; // remove newline character

    for (int i = 0; i < 5; i++) {
        printf("Enter grade %d: ", i + 1);
        scanf("%f", &s->grades[i]);
    }
    s->average = calculate_average(s->grades, 5);
}

// Function to sort students based on their average grade
void sort_students(Student *students, int num_students) {
    for (int i = 0; i < num_students - 1; i++) {
        for (int j = i + 1; j < num_students; j++) {
            if (students[j].average > students[i].average) { // Descending order
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

// Main function
int main() {
    int num_students;

    printf("Enter number of students: ");
    scanf("%d", &num_students);
    
    if (num_students <= 0) {
        printf("Invalid number of students.\n");
        return 1;
    }

    // Dynamically allocate memory for students
    Student *students = (Student *)malloc(num_students * sizeof(Student));
    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Enter data for each student
    for (int i = 0; i < num_students; i++) {
        printf("Entering data for student %d:\n", i + 1);
        enter_student_data(&students[i]);
    }

    // Sort students based on average grades
    sort_students(students, num_students);

    // Display sorted student data
    printf("\nStudent data sorted by average grades:\n");
    for (int i = 0; i < num_students; i++) {
        display_student(&students[i]);
    }

    // Clean up
    free(students);
    return 0;
}