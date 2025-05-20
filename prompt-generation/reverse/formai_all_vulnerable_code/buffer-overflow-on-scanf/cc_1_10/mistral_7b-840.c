//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define FILENAME "data.txt"

typedef struct {
    int id;
    char name[50];
    float score;
} Student;

void writeToFile(Student student) {
    FILE *file = fopen(FILENAME, "a");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fprintf(file, "%d %s %.2f\n", student.id, student.name, student.score);
    fclose(file);
}

void readFromFile(int index) {
    FILE *file = fopen(FILENAME, "r");
    Student students[MAX_SIZE];
    int count = 0;

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fscanf(file, "%d %s %f", &students[index].id, students[index].name, &students[index].score) != EOF) {
        count++;
    }

    fclose(file);

    printf("Student %d:\nID: %d\nName: %s\nScore: %.2f\n", index + 1, students[index].id, students[index].name, students[index].score);
}

int main() {
    Student student;
    int choice, index;

    printf("Welcome to Student Management System!\n");
    printf("1. Write student data to file.\n");
    printf("2. Read student data from file.\n");
    printf("3. Exit.\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter student ID: ");
            scanf("%d", &student.id);
            printf("Enter student name: ");
            scanf("%s", student.name);
            printf("Enter student score: ");
            scanf("%f", &student.score);

            writeToFile(student);
            printf("Student data has been written to the file.\n");
            break;

        case 2:
            printf("Enter index of student data to read: ");
            scanf("%d", &index);

            readFromFile(index);
            break;

        case 3:
            exit(0);
            break;

        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}