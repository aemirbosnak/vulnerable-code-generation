//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int id;
} Student;

void paranoid_search(Student *students, int num_students, char *name) {
    int i;
    for (i = 0; i < num_students; i++) {
        if (strcmp(students[i].name, name) == 0) {
            // Student found, do something with the ID
            printf("Student ID: %d\n", students[i].id);
            // Exit the program to prevent further execution
            exit(0);
        }
    }
}

int main() {
    Student students[MAX_SIZE];
    int num_students = 0;

    // Initialize the students array with some data
    students[num_students].name = "Alice";
    students[num_students].id = 1;
    num_students++;

    students[num_students].name = "Bob";
    students[num_students].id = 2;
    num_students++;

    students[num_students].name = "Charlie";
    students[num_students].id = 3;
    num_students++;

    // Prompt the user to enter a name to search for
    char name[100];
    printf("Enter a name to search for: ");
    scanf("%s", name);

    // Call the paranoid_search function to find the student
    paranoid_search(students, num_students, name);

    return 0;
}