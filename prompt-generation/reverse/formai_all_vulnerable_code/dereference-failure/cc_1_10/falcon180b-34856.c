//Falcon-180B DATASET v1.0 Category: Memory management ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Define a struct for our data
typedef struct {
    int id;
    char name[50];
    float score;
} Student;

// Function to create a new student
Student* createStudent(int id, char* name, float score) {
    Student* newStudent = (Student*) malloc(sizeof(Student));
    if (newStudent == NULL) {
        printf("Error: Could not allocate memory for new student.\n");
        return NULL;
    }
    newStudent->id = id;
    strcpy(newStudent->name, name);
    newStudent->score = score;
    return newStudent;
}

// Function to print a student's information
void printStudent(Student* student) {
    printf("ID: %d\n", student->id);
    printf("Name: %s\n", student->name);
    printf("Score: %f\n", student->score);
}

// Function to free a student's memory
void freeStudent(Student* student) {
    free(student);
}

// Main function
int main() {
    // Create some students
    Student* student1 = createStudent(1, "John Doe", 85.5);
    Student* student2 = createStudent(2, "Jane Smith", 92.0);

    // Print their information
    printStudent(student1);
    printStudent(student2);

    // Free their memory
    freeStudent(student1);
    freeStudent(student2);

    return 0;
}