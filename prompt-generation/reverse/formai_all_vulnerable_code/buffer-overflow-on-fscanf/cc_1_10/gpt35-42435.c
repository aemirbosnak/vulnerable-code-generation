//FormAI DATASET v1.0 Category: File handling ; Style: Ken Thompson
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_STUDENTS 50
#define MAX_NAME 20
#define MAX_GRADE 3

typedef struct {
    char name[MAX_NAME];
    int grade[MAX_GRADE];
} Student;

int main() {
    FILE *in_file, *out_file; // File pointers
    Student students[MAX_STUDENTS]; // Array of structs to hold students

    // Open input file
    in_file = fopen("students.txt", "r");
    if (in_file == NULL) {
        fprintf(stderr, "Error: Could not open input file.\n");
        return 1;
    }

    int num_students = 0; // Counter for number of students

    // Read in students from file
    while (!feof(in_file)) {
        fscanf(in_file, "%s %d %d %d", students[num_students].name, &students[num_students].grade[0], &students[num_students].grade[1], &students[num_students].grade[2]); // Read student data
        num_students++; // Increment counter
    }
    fclose(in_file); // Close input file

    // Open output file
    out_file = fopen("grades.txt", "w");
    if (out_file == NULL) {
        fprintf(stderr, "Error: Could not open output file.\n");
        return 1;
    }

   // Write grades to output file
    for (int i = 0; i < num_students; i++) {
        int sum = 0;
        fprintf(out_file, "Name: %s\n", students[i].name); // Write name to file
        for (int j = 0; j < MAX_GRADE; j++) {
            fprintf(out_file, "Grade %d: %d\n", j+1, students[i].grade[j]); // Write grade to file
            sum += students[i].grade[j]; // Add grade to sum
        }
        fprintf(out_file, "Average grade: %.2f\n\n", (float) sum / (float) MAX_GRADE); // Write average grade to file
    }

    fclose(out_file); // Close output file

    printf("File handling completed successfully. %d student record(s) processed.", num_students);
    return 0;
}