//FormAI DATASET v1.0 Category: File handling ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int id;
    float gpa;
};

int main() {
    FILE* filePointer;
    struct Student student;
    char fileName[50];
    int numStudents;

    printf("Enter file name: ");
    scanf("%s", fileName);

    printf("Enter number of students: ");
    scanf("%d", &numStudents);

    filePointer = fopen(fileName, "w");

    if (filePointer == NULL) {
        printf("Error opening file!");
        exit(1);
    }

    for (int i = 0; i < numStudents; i++) {
        printf("Enter student %d's name: ", i+1);
        scanf("%s", student.name);
        printf("Enter student %d's id: ", i+1);
        scanf("%d", &student.id);
        printf("Enter student %d's GPA: ", i+1);
        scanf("%f", &student.gpa);

        fprintf(filePointer, "%s %d %.2f\n", student.name, student.id, student.gpa);
    }

    fclose(filePointer);

    filePointer = fopen(fileName, "r");

    if (filePointer == NULL) {
        printf("Error opening file!");
        exit(1);
    }

    printf("\n\nStudent Records:\n");
    while (fscanf(filePointer, "%s %d %f", student.name, &student.id, &student.gpa) != EOF) {
        printf("Name: %s, ID: %d, GPA: %.2f\n", student.name, student.id, student.gpa);
    }

    fclose(filePointer);
    return 0;
}