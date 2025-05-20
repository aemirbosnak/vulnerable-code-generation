//Falcon-180B DATASET v1.0 Category: File handling ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NAME_LEN 100
#define MAX_DATA_LEN 1000

// Structure for student data
typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    float grade;
} Student;

// Function to read data from file
void read_data_from_file(FILE *fp, Student *students, int *num_students) {
    char line[MAX_DATA_LEN];
    int i = 0;

    while (fgets(line, MAX_DATA_LEN, fp)!= NULL) {
        sscanf(line, "%s %d %f", students[i].name, &students[i].age, &students[i].grade);
        i++;
        *num_students = i;
    }
}

// Function to write data to file
void write_data_to_file(FILE *fp, Student *students, int num_students) {
    for (int i = 0; i < num_students; i++) {
        fprintf(fp, "%s %d %f\n", students[i].name, students[i].age, students[i].grade);
    }
}

// Function to calculate average grade
float calculate_average_grade(Student *students, int num_students) {
    float sum = 0;

    for (int i = 0; i < num_students; i++) {
        sum += students[i].grade;
    }

    return sum / num_students;
}

int main() {
    FILE *input_file, *output_file;
    Student students[MAX_DATA_LEN];
    int num_students = 0;

    // Open input file
    input_file = fopen("input.txt", "r");

    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    // Read data from input file
    read_data_from_file(input_file, students, &num_students);

    // Close input file
    fclose(input_file);

    // Calculate average grade
    float avg_grade = calculate_average_grade(students, num_students);

    // Open output file
    output_file = fopen("output.txt", "w");

    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        return 1;
    }

    // Write data to output file
    write_data_to_file(output_file, students, num_students);

    // Close output file
    fclose(output_file);

    printf("Average grade: %.2f\n", avg_grade);

    return 0;
}