//Falcon-180B DATASET v1.0 Category: File handling ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char name[50];
    int age;
    float grade;
} Student;

int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[100], outputFileName[100];
    Student students[100];
    int numStudents = 0;

    // Get input file name from user
    printf("Enter input file name: ");
    scanf("%s", inputFileName);

    // Open input file for reading
    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Read students from input file
    while (fscanf(inputFile, "%s %d %f", students[numStudents].name, &students[numStudents].age, &students[numStudents].grade)!= EOF) {
        numStudents++;
    }

    // Close input file
    fclose(inputFile);

    // Get output file name from user
    printf("Enter output file name: ");
    scanf("%s", outputFileName);

    // Open output file for writing
    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Write students to output file
    for (int i = 0; i < numStudents; i++) {
        fprintf(outputFile, "%s %d %f\n", students[i].name, students[i].age, students[i].grade);
    }

    // Close output file
    fclose(outputFile);

    printf("Done!\n");

    return 0;
}