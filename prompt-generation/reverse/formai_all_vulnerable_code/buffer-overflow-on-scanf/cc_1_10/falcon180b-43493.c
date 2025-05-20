//Falcon-180B DATASET v1.0 Category: Educational ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a student
struct Student {
    char name[50];
    int age;
    float GPA;
};

// Define a function to read a CSV file and store student data in an array of structures
void readCSV(struct Student students[], FILE *file) {
    char line[100];
    int i = 0;

    // Read the header line
    fgets(line, sizeof(line), file);

    // Loop through each line of the file
    while (fgets(line, sizeof(line), file)!= NULL) {
        // Split the line into fields
        char *token = strtok(line, ",");

        // Read the name field
        strcpy(students[i].name, token);

        // Read the age field
        students[i].age = atoi(token = strtok(NULL, ","));

        // Read the GPA field
        students[i].GPA = atof(token = strtok(NULL, ","));

        // Increment the index for the next student
        i++;
    }

    // Close the file
    fclose(file);
}

// Define a function to calculate the average GPA of all students
float calculateAverageGPA(struct Student students[], int numStudents) {
    float sum = 0;

    // Loop through each student
    for (int i = 0; i < numStudents; i++) {
        // Add the student's GPA to the sum
        sum += students[i].GPA;
    }

    // Return the average GPA
    return sum / numStudents;
}

int main() {
    // Declare an array of student structures
    struct Student students[100];

    // Declare variables for reading the CSV file
    FILE *file;
    char filename[50];
    int numStudents = 0;

    // Prompt the user for the filename
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file for reading
    file = fopen(filename, "r");

    // Check if the file was opened successfully
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read the student data from the CSV file
    readCSV(students, file);

    // Close the file
    fclose(file);

    // Calculate the average GPA of all students
    float avgGPA = calculateAverageGPA(students, numStudents);

    // Print the results
    printf("Number of students: %d\n", numStudents);
    printf("Average GPA: %.2f\n", avgGPA);

    return 0;
}