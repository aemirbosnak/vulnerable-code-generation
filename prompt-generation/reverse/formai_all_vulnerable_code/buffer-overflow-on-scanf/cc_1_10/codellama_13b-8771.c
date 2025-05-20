//Code Llama-13B DATASET v1.0 Category: Database simulation ; Style: creative
/*
 * A unique C Database simulation program
 *
 * Created by [Your Name]
 * Date: [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store information about a student
typedef struct {
    char name[50];
    int age;
    char gender;
    char address[100];
    float marks[5];
} student;

// Function to display a student's information
void displayStudent(student s) {
    printf("Name: %s\n", s.name);
    printf("Age: %d\n", s.age);
    printf("Gender: %c\n", s.gender);
    printf("Address: %s\n", s.address);
    printf("Marks: ");
    for (int i = 0; i < 5; i++) {
        printf("%.2f ", s.marks[i]);
    }
    printf("\n");
}

// Function to update a student's information
void updateStudent(student *s, char *name, int age, char gender, char *address, float *marks) {
    strcpy(s->name, name);
    s->age = age;
    s->gender = gender;
    strcpy(s->address, address);
    for (int i = 0; i < 5; i++) {
        s->marks[i] = marks[i];
    }
}

// Function to add a new student to the database
void addStudent(student *s, int *numStudents) {
    printf("Enter the name of the new student: ");
    scanf("%s", s[*numStudents].name);
    printf("Enter the age of the new student: ");
    scanf("%d", &s[*numStudents].age);
    printf("Enter the gender of the new student: ");
    scanf(" %c", &s[*numStudents].gender);
    printf("Enter the address of the new student: ");
    scanf("%s", s[*numStudents].address);
    printf("Enter the marks of the new student: ");
    for (int i = 0; i < 5; i++) {
        scanf("%f", &s[*numStudents].marks[i]);
    }
    (*numStudents)++;
}

// Function to remove a student from the database
void removeStudent(student *s, int *numStudents) {
    int index;
    printf("Enter the index of the student to be removed: ");
    scanf("%d", &index);
    if (index >= 0 && index < *numStudents) {
        for (int i = index; i < *numStudents - 1; i++) {
            s[i] = s[i + 1];
        }
        (*numStudents)--;
    } else {
        printf("Invalid index\n");
    }
}

// Function to display all students in the database
void displayAllStudents(student *s, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        displayStudent(s[i]);
    }
}

int main() {
    // Create an array of student structures
    student students[100];

    // Initialize the number of students in the database
    int numStudents = 0;

    // Add some students to the database
    addStudent(&students[0], &numStudents);
    addStudent(&students[1], &numStudents);
    addStudent(&students[2], &numStudents);

    // Display all students in the database
    displayAllStudents(students, numStudents);

    // Update a student's information
    updateStudent(&students[0], "John Doe", 25, 'M', "New York", (float[]){78.5, 85.0, 90.0, 80.0, 75.0});

    // Remove a student from the database
    removeStudent(&students[1], &numStudents);

    // Display all students in the database again
    displayAllStudents(students, numStudents);

    return 0;
}