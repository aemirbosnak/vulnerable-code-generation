//FormAI DATASET v1.0 Category: File handling ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

struct student {
    char name[50];
    int age;
    float gpa;
};

int main() {
    int num;
    printf("Enter the number of students: ");
    scanf("%d", &num);

    // Create and open a file for writing
    FILE *fptr;
    fptr = fopen("students.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    struct student *students = malloc(num * sizeof(struct student));

    // Get student details from user
    for (int i = 0; i < num; i++) {
        printf("\nEnter details of student %d:\n", i + 1);

        printf("Name: ");
        scanf("%s", students[i].name);

        printf("Age: ");
        scanf("%d", &students[i].age);

        printf("GPA: ");
        scanf("%f", &students[i].gpa);

        // Write student details to file
        fprintf(fptr, "%s %d %.2f\n", students[i].name, students[i].age, students[i].gpa);
    }

    // Close the file
    fclose(fptr);

    printf("\nData written to file students.txt successful.");

    // Open the file for reading
    fptr = fopen("students.txt", "r");
    if (fptr == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    printf("\n\nDetails of all students:\n");

    // Read student details from file and display them
    for (int i = 0; i < num; i++) {
        fscanf(fptr, "%s %d %f\n", students[i].name, &students[i].age, &students[i].gpa);

        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("GPA: %.2f\n", students[i].gpa);
        printf("\n");
    }

    // Close the file and free memory
    fclose(fptr);
    free(students);

    return 0;
}