//FormAI DATASET v1.0 Category: Data mining ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_FILENAME_SIZE 50

struct Student {
    char name[MAX_BUFFER_SIZE];
    float gpax;
    int year;
};

void writeToFile(char* filename, struct Student* students, int size);
void readFromFile(char* filename);
float averageGPAX(struct Student* students, int size);

int main() {
    struct Student students[3];

    // Prompt user for student data input
    for (int i = 0; i < 3; i++) {
        printf("Enter student name: ");
        fgets(students[i].name, MAX_BUFFER_SIZE, stdin);
        strtok(students[i].name, "\n"); // remove newline character

        printf("Enter student GPAX: ");
        scanf("%f", &students[i].gpax);
        getchar(); // flush newline character from input buffer

        printf("Enter student year: ");
        scanf("%d", &students[i].year);
        getchar(); // flush newline character from input buffer
    }

    // Calculate and print average GPAX
    printf("Average GPAX: %.2f\n\n", averageGPAX(students, 3));

    // Write student data to file
    char filename[MAX_FILENAME_SIZE];
    printf("Enter filename to save student data: ");
    fgets(filename, MAX_FILENAME_SIZE, stdin);
    strtok(filename, "\n");
    writeToFile(filename, students, 3);

    // Read and print student data from file
    printf("Student data from file:\n");
    readFromFile(filename);

    return 0;
}

void writeToFile(char* filename, struct Student* students, int size) {
    FILE* fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("Error: Could not open file\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        fprintf(fp, "%s,%.2f,%d\n", students[i].name, students[i].gpax, students[i].year);
    }

    fclose(fp);
}

void readFromFile(char* filename) {
    FILE* fp = fopen(filename, "r");
    char buffer[MAX_BUFFER_SIZE];
    char* token;

    if (fp == NULL) {
        printf("Error: Could not open file\n");
        return;
    }

    while (fgets(buffer, MAX_BUFFER_SIZE, fp)) {
        token = strtok(buffer, ",");
        printf("Name: %s\n", token);

        token = strtok(NULL, ",");
        printf("GPAX: %.2f\n", atof(token));

        token = strtok(NULL, ",");
        printf("Year: %d\n\n", atoi(token));
    }

    fclose(fp);
}

float averageGPAX(struct Student* students, int size) {
    float sum = 0;

    for (int i = 0; i < size; i++) {
        sum += students[i].gpax;
    }

    return sum / size;
}