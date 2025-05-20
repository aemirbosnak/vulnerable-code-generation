//MISTRAL-7B DATASET v1.0 Category: Educational ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Student {
    char name[50];
    int roll_number;
    int age;
    float marks;
} Student;

int main() {
    Student *students;
    int i;

    // Allocate memory for 5 students
    students = (Student *)malloc(5 * sizeof(Student));
    if (!students) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("\n--- Student Records ---\n");

    // Read student details and store in allocated memory
    for (i = 0; i < 5; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        scanf("%s", students[i].name);
        students[i].roll_number = i + 1;
        printf("Enter age: ");
        scanf("%d", &students[i].age);
        printf("Enter marks: ");
        scanf("%f", &students[i].marks);
    }

    // Print student details
    printf("\n--- Student Records ---\n");
    for (i = 0; i < 5; i++) {
        printf("\nStudent %d:\n", students[i].roll_number);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Marks: %.2f\n", students[i].marks);
    }

    // Calculate and print average marks
    float sum = 0.0;
    for (i = 0; i < 5; i++) {
        sum += students[i].marks;
    }
    float avg_marks = sum / 5;
    printf("\nAverage marks of all students: %.2f", avg_marks);

    // Free allocated memory
    free(students);

    return 0;
}