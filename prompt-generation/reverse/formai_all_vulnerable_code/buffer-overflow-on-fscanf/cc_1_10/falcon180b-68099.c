//Falcon-180B DATASET v1.0 Category: File handling ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a student record
struct student {
    char name[50];
    int roll_no;
    float marks;
};

// Function to read student records from a file
void read_students(FILE *fp, struct student students[]) {
    int i = 0;
    while (fscanf(fp, "%s %d %f", students[i].name, &students[i].roll_no, &students[i].marks)!= EOF) {
        i++;
    }
}

// Function to write student records to a file
void write_students(FILE *fp, struct student students[], int num_students) {
    int i;
    for (i = 0; i < num_students; i++) {
        fprintf(fp, "%s %d %f\n", students[i].name, students[i].roll_no, students[i].marks);
    }
}

// Function to sort student records by roll number
void sort_students(struct student students[], int num_students) {
    int i, j;
    for (i = 0; i < num_students - 1; i++) {
        for (j = i + 1; j < num_students; j++) {
            if (students[i].roll_no > students[j].roll_no) {
                struct student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

int main() {
    FILE *fp;
    char filename[50];
    int choice, num_students;
    struct student students[100];

    // Get filename from user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Read student records from file
    read_students(fp, students);

    // Close the file
    fclose(fp);

    // Get number of students from user
    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    // Sort student records by roll number
    sort_students(students, num_students);

    // Open the file for writing
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Write sorted student records to file
    write_students(fp, students, num_students);

    // Close the file
    fclose(fp);

    // Print success message
    printf("Student records sorted and written to file\n");

    return 0;
}