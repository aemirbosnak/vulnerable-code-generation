//GEMINI-pro DATASET v1.0 Category: Educational ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Creating a structure to store the details of a student
struct Student {
    char name[50];
    int age;
    float marks;
};

// Function to read the details of the students and store them in an array
void read_students(struct Student *students, int num_students) {
    for (int i = 0; i < num_students; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf("%s", students[i].name);

        printf("Enter the age of student %d: ", i + 1);
        scanf("%d", &students[i].age);

        printf("Enter the marks of student %d: ", i + 1);
        scanf("%f", &students[i].marks);
    }
}

// Function to print the details of the students
void print_students(struct Student *students, int num_students) {
    for (int i = 0; i < num_students; i++) {
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Marks: %.2f\n", students[i].marks);
        printf("-------------------------\n");
    }
}

// Function to find the average marks of the students
float get_average_marks(struct Student *students, int num_students) {
    float total_marks = 0;

    for (int i = 0; i < num_students; i++) {
        total_marks += students[i].marks;
    }

    return total_marks / num_students;
}

int main() {
    // Declare an array of students
    struct Student students[3];

    // Read the details of the students
    read_students(students, 3);

    // Print the details of the students
    print_students(students, 3);

    // Find the average marks of the students
    float average_marks = get_average_marks(students, 3);

    // Print the average marks
    printf("Average marks: %.2f\n", average_marks);

    return 0;
}