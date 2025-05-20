//FormAI DATASET v1.0 Category: Data recovery tool ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum input string size
#define MAX_INPUT_SIZE 1000

// Define a custom data type to hold data read from the file
typedef struct {
    int id;
    char name[50];
    float marks;
} Student;

// Define a function to read data from the file into an array of Student objects
void read_data(const char *filename, Student *students, int *num_students) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    char line[MAX_INPUT_SIZE];
    int i = 0;
    while (fgets(line, MAX_INPUT_SIZE, fp) != NULL) {
        sscanf(line, "%d,%[^,],%f", &students[i].id, students[i].name, &students[i].marks);
        i++;
    }
    fclose(fp);
    *num_students = i;
}

// Define a function to write data from an array of Student objects to a file
void write_data(const char *filename, Student *students, int num_students) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    for (int i = 0; i < num_students; i++) {
        fprintf(fp, "%d,%s,%.2f\n", students[i].id, students[i].name, students[i].marks);
    }
    fclose(fp);
}

// Define a function to recover data from a backup file
void recover_data(const char *filename, Student *students, int *num_students) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    char line[MAX_INPUT_SIZE];
    int i = 0;
    while (fgets(line, MAX_INPUT_SIZE, fp) != NULL) {
        sscanf(line, "%d,%[^,],%f", &students[i].id, students[i].name, &students[i].marks);
        i++;
    }
    fclose(fp);
    *num_students = i;
}

// Define the main function
int main() {
    // Prompt the user to enter the file name and read data from file to array of student objects
    char filename[MAX_INPUT_SIZE];
    printf("Enter the file name to read the student data from: ");
    scanf("%s", filename);
    Student students[100];
    int num_students = 0;
    read_data(filename, students, &num_students);

    // Prompt the user to enter the ID of the student to be updated
    int id;
    printf("Enter the ID of the student to be updated: ");
    scanf("%d", &id);

    // Search for the student with the specified ID and update their data
    int found = 0;
    for (int i = 0; i < num_students; i++) {
        if (students[i].id == id) {
            printf("Enter the new data for the student (name and marks): ");
            scanf("%s%f", students[i].name, &students[i].marks);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No student with ID %d found\n", id);
    }

    // Write the updated student data to the file
    write_data(filename, students, num_students);

    // Simulate a data corruption by deleting the original file and renaming the backup file
    remove(filename);
    rename("backup.txt", filename);

    // Try to read the data from the original file and recover it from the backup file if there is an error
    Student recovered_students[100];
    int num_recovered_students = 0;
    while (1) {
        read_data(filename, recovered_students, &num_recovered_students);
        if (num_recovered_students == num_students) {
            break;
        } else {
            printf("Error reading data from file %s, trying to recover from backup...\n", filename);
        }
        recover_data("backup.txt", recovered_students, &num_recovered_students);
        printf("Successfully recovered data from backup file\n");
        break;
    }

    // Print the recovered data to verify that it matches the original data
    printf("Recovered student data:\n");
    for (int i = 0; i < num_recovered_students; i++) {
        printf("%d,%s,%.2f\n", recovered_students[i].id, recovered_students[i].name, recovered_students[i].marks);
    }

    return 0;
}