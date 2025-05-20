//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int score;
} Student;

void readData(const char *filename, Student students[], int *count);
void calculateStatistics(Student students[], int count);
void printStatistics(float average, int highest, int lowest, int passCount, int failCount);

int main() {
    Student students[MAX_STUDENTS];
    int studentCount = 0;

    readData("students.csv", students, &studentCount);
    calculateStatistics(students, studentCount);

    return 0;
}

void readData(const char *filename, Student students[], int *count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char line[100];
    fgets(line, 100, file); // Skip header line

    while (fgets(line, 100, file)) {
        sscanf(line, "%[^,],%d", students[*count].name, &students[*count].score);
        (*count)++;
    }

    fclose(file);
}

void calculateStatistics(Student students[], int count) {
    if (count == 0) {
        printf("No student data available.\n");
        return;
    }

    int totalScore = 0;
    int highestScore = 0;
    int lowestScore = 100;
    int passCount = 0;
    int failCount = 0;

    for (int i = 0; i < count; i++) {
        totalScore += students[i].score;

        if (students[i].score > highestScore) {
            highestScore = students[i].score;
        }

        if (students[i].score < lowestScore) {
            lowestScore = students[i].score;
        }

        if (students[i].score >= 50) {
            passCount++;
        } else {
            failCount++;
        }
    }

    float averageScore = (float)totalScore / count;
    printStatistics(averageScore, highestScore, lowestScore, passCount, failCount);
}

void printStatistics(float average, int highest, int lowest, int passCount, int failCount) {
    printf("Statistics of student scores:\n");
    printf("Average Score: %.2f\n", average);
    printf("Highest Score: %d\n", highest);
    printf("Lowest Score: %d\n", lowest);
    printf("Number of Students Passed: %d\n", passCount);
    printf("Number of Students Failed: %d\n", failCount);
}