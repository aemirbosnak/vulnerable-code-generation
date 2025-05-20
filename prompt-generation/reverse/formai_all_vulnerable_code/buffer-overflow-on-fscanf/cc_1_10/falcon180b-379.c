//Falcon-180B DATASET v1.0 Category: File handling ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for student records
struct student {
    int roll_no;
    char name[50];
    float marks;
};

// Function to read student records from file
void read_students(struct student students[], int size) {
    FILE *fp;
    fp = fopen("students.txt", "r");

    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%d %s %f\n", &students[i].roll_no, students[i].name, &students[i].marks)!= EOF) {
        i++;
    }

    fclose(fp);
}

// Function to write student records to file
void write_students(struct student students[], int size) {
    FILE *fp;
    fp = fopen("students.txt", "w");

    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        fprintf(fp, "%d %s %f\n", students[i].roll_no, students[i].name, students[i].marks);
    }

    fclose(fp);
}

// Function to sort student records by marks
void sort_students(struct student students[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (students[j].marks > students[i].marks) {
                struct student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

// Main function
int main() {
    int size;
    printf("Enter number of students: ");
    scanf("%d", &size);

    struct student students[size];

    // Read student records from file
    read_students(students, size);

    // Sort student records by marks
    sort_students(students, size);

    // Write sorted student records to file
    write_students(students, size);

    printf("Students sorted by marks and written to file.\n");

    return 0;
}