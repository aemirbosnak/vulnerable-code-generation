//FormAI DATASET v1.0 Category: File handling ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

struct student {
    char name[50];
    int age;
    float gpa;
};

int main() {
    // define and declare variables
    int num_students;
    struct student *students;

    // prompt user for number of students
    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    // dynamically allocate memory for students
    students = (struct student*) malloc(num_students * sizeof(struct student));

    // prompt user for student details and store them in struct
    for (int i = 0; i < num_students; i++) {
        printf("\nEnter details for student %d:\n", i+1);
        printf("Name: ");
        scanf("%s", (students+i)->name);
        printf("Age: ");
        scanf("%d", &(students+i)->age);
        printf("GPA: ");
        scanf("%f", &(students+i)->gpa);
    }

    // open file in write mode
    FILE *fp = fopen("students.txt", "w");

    // write student details to file
    for (int i = 0; i < num_students; i++) {
        fprintf(fp, "Name: %s | Age: %d | GPA: %.2f\n", (students+i)->name, (students+i)->age, (students+i)->gpa);
    }

    // close file
    fclose(fp);

    // free allocated memory
    free(students);

    printf("\nStudent details written to file successfully!\n");

    return 0;
}