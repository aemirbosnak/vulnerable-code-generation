//Falcon-180B DATASET v1.0 Category: File handling ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of the record
typedef struct {
    char name[50];
    int age;
    float GPA;
} Student;

// Define the function to read the data from the file
void read_data(FILE* fp, Student* students, int count) {
    fseek(fp, 0, SEEK_SET); // Move the file pointer to the beginning of the file
    int i;
    for (i = 0; i < count; i++) {
        fscanf(fp, "%s %d %f", students[i].name, &students[i].age, &students[i].GPA);
    }
}

// Define the function to write the data to the file
void write_data(FILE* fp, Student* students, int count) {
    int i;
    for (i = 0; i < count; i++) {
        fprintf(fp, "%s %d %f\n", students[i].name, students[i].age, students[i].GPA);
    }
}

// Define the function to sort the data in ascending order of age
void sort_data(Student* students, int count) {
    int i, j;
    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            if (students[i].age > students[j].age) {
                // Swap the records
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

// Define the main function
int main() {
    int count;
    FILE* fp;
    Student* students;

    // Open the file for reading
    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file for reading.\n");
        exit(1);
    }

    // Read the number of records from the file
    fscanf(fp, "%d", &count);

    // Allocate memory for the records
    students = (Student*) malloc(count * sizeof(Student));
    if (students == NULL) {
        printf("Error: Could not allocate memory for records.\n");
        fclose(fp);
        exit(1);
    }

    // Read the data from the file
    read_data(fp, students, count);

    // Sort the data in ascending order of age
    sort_data(students, count);

    // Open the file for writing
    fp = fopen("students.txt", "w");
    if (fp == NULL) {
        printf("Error: Could not open file for writing.\n");
        free(students);
        exit(1);
    }

    // Write the data to the file
    write_data(fp, students, count);

    // Close the file
    fclose(fp);

    // Free the memory allocated for the records
    free(students);

    return 0;
}