//FormAI DATASET v1.0 Category: Educational ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Define a structure to hold student data
struct Student {
    char name[50];
    int age;
    float gpa;
};

// Function to read in student data
void readStudent(struct Student *s) {
    printf("\nEnter student name: ");
    scanf("%s", s->name);
    
    printf("Enter student age: ");
    scanf("%d", &s->age);
    
    printf("Enter student GPA: ");
    scanf("%f", &s->gpa);
}

// Function to print out student data
void printStudent(struct Student s) {
    printf("\nName: %s", s.name);
    printf("\nAge: %d", s.age);
    printf("\nGPA: %.2f", s.gpa);
}

// Main function
int main() {
    int numStudents;
    
    printf("How many students do you want to enter?: ");
    scanf("%d", &numStudents);
    
    // Allocate memory for the student array
    struct Student *students = (struct Student *) malloc(numStudents * sizeof(struct Student));
    
    // Read in student data
    for (int i = 0; i < numStudents; i++) {
        printf("\nEnter data for student %d", i+1);
        readStudent(&students[i]);
    }
    
    // Print out student data
    printf("\n\nStudent Data:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("\nStudent %d:", i+1);
        printStudent(students[i]);
    }
    
    // Free memory
    free(students);
    
    return 0;
}