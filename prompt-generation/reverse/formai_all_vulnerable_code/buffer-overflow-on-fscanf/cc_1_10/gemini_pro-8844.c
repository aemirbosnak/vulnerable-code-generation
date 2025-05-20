//GEMINI-pro DATASET v1.0 Category: File handling ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the data of a student
struct student {
    char name[50];
    int roll_no;
    float marks;
};

// Function to read the data from the file
void read_data(char *filename) {
    // Open the file in read mode
    FILE *fp = fopen(filename, "r");

    // Check if the file was opened successfully
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    // Read the data from the file and store it in an array of students
    struct student students[100];
    int i = 0;
    while (fscanf(fp, "%s %d %f", students[i].name, &students[i].roll_no, &students[i].marks) != EOF) {
        i++;
    }

    // Close the file
    fclose(fp);

    // Print the data of the students
    for (int j = 0; j < i; j++) {
        printf("%s %d %.2f\n", students[j].name, students[j].roll_no, students[j].marks);
    }
}

// Function to write the data to the file
void write_data(char *filename) {
    // Open the file in write mode
    FILE *fp = fopen(filename, "w");

    // Check if the file was opened successfully
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    // Write the data of the students to the file
    struct student students[100];
    for (int i = 0; i < 100; i++) {
        fprintf(fp, "%s %d %.2f\n", students[i].name, students[i].roll_no, students[i].marks);
    }

    // Close the file
    fclose(fp);
}

// Main function
int main() {
    // Read the data from the file
    read_data("students.txt");

    // Write the data to the file
    write_data("students.txt");

    return 0;
}