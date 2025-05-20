//MISTRAL-7B DATASET v1.0 Category: Online Examination System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Struct to hold student information
typedef struct Student {
    char name[50];
    int roll_number;
    int total_marks;
    int obtained_marks;
} Student;

// Function to read student data from a file
void read_students(const char *filename, Student students[], int num_students) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < num_students; i++) {
        fscanf(file, "%[^,],%d,%d", students[i].name, &students[i].roll_number, &students[i].total_marks);
        students[i].obtained_marks = students[i].total_marks; // Assuming all students have obtained all marks initially
    }

    fclose(file);
}

// Function to process exam data from a file
void process_exam_data(const char *filename, Student students[], int num_students) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char question[100];
    int marks;

    while (fscanf(file, "%[^:]:%d", question, &marks) != EOF) {
        for (int i = 0; i < num_students; i++) {
            int answer;
            fscanf(file, "%d", &answer);

            if (strcmp(question, students[i].name) == 0) {
                students[i].obtained_marks += marks;
                break;
            }
        }
    }

    fclose(file);
}

// Function to calculate and display student results
void display_results(const char *output_filename, Student students[], int num_students) {
    FILE *file = fopen(output_filename, "w");

    if (file == NULL) {
        printf("Error: Unable to open file %s for writing\n", output_filename);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < num_students; i++) {
        fprintf(file, "%s: Roll Number %d, Total Marks %d, Obtained Marks %d\n", students[i].name, students[i].roll_number, students[i].total_marks, students[i].obtained_marks);
    }

    fclose(file);
}

// Main function to run the JJPOES
int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <students.csv> <exam.csv> <output.csv>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *students_filename = argv[1];
    const char *exam_filename = argv[2];
    const char *output_filename = argv[3];

    int num_students = 0;
    Student students[1000]; // Assuming a maximum of 1000 students

    read_students(students_filename, students, sizeof(students) / sizeof(Student));

    process_exam_data(exam_filename, students, sizeof(students) / sizeof(Student));

    display_results(output_filename, students, sizeof(students) / sizeof(Student));

    printf("Joyful Juicy Pineapple Online Examination System:\nResults have been successfully generated in %s\n", output_filename);

    return EXIT_SUCCESS;
}