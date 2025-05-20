//Falcon-180B DATASET v1.0 Category: File handling ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for student data
typedef struct {
    char name[50];
    int roll_no;
    float marks;
} Student;

// Function to read data from file
void read_file(char* filename, Student students[], int size) {
    FILE* fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(fp, "%s %d %f\n", students[count].name, &students[count].roll_no, &students[count].marks)!= EOF) {
        count++;
    }

    fclose(fp);
}

// Function to write data to file
void write_file(char* filename, Student students[], int size) {
    FILE* fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        fprintf(fp, "%s %d %f\n", students[i].name, students[i].roll_no, students[i].marks);
    }

    fclose(fp);
}

// Function to sort students based on roll number
void sort_students(Student students[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (students[i].roll_no > students[j].roll_no) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

int main() {
    char filename[50] = "students.txt";
    Student students[100];
    int size = 0;

    // Read data from file
    read_file(filename, students, 100);
    size = sizeof(students) / sizeof(students[0]);

    // Sort students based on roll number
    sort_students(students, size);

    // Write sorted data to file
    write_file("sorted_students.txt", students, size);

    return 0;
}