//FormAI DATASET v1.0 Category: Database simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int id;
    float gpa;
} Student;

int main() {
    Student students[10];
    int num_students = 0;
    FILE *file;

    // create or open file in write mode
    file = fopen("students.txt", "w");

    // ask user for input and write to file
    for(int i=0; i<10; i++) {
        printf("Enter student name (or 'done' to finish): ");
        scanf("%s", students[i].name);

        // if user enters 'done' break the loop
        if(strcmp(students[i].name, "done") == 0) {
            break;
        }

        printf("Enter student ID: ");
        scanf("%d", &students[i].id);

        printf("Enter student GPA: ");
        scanf("%f", &students[i].gpa);

        // write the student data to file
        fprintf(file, "%s %d %.2f", students[i].name, students[i].id, students[i].gpa);

        num_students++;
    }

    fclose(file);

    // open the file in read mode and print student data to console
    file = fopen("students.txt", "r");

    for(int i=0; i<num_students; i++) {
        fscanf(file, "%s %d %f", students[i].name, &students[i].id, &students[i].gpa);
        printf("Name: %s  ID: %d  GPA: %.2f\n", students[i].name, students[i].id, students[i].gpa);
    }

    fclose(file);

    return 0;
}