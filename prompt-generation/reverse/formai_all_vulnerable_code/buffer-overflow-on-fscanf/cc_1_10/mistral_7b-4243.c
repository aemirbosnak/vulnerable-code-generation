//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define FILENAME "data.txt"

typedef struct {
    int id;
    char name[50];
    float grade;
} Student;

void readFile(FILE *file, Student students[], int *count) {
    fseek(file, 0, SEEK_SET); // Reset file position to the beginning
    int i = 0;

    while (fscanf(file, "%d %s %f", &students[i].id, students[i].name, &students[i].grade) != EOF) {
        (*count)++;
        i++;
    }
}

void writeFile(FILE *file, Student students[], int count) {
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d %s %.2f\n", students[i].id, students[i].name, students[i].grade);
    }
}

int main() {
    Student students[MAX_SIZE];
    int count = 0;

    FILE *file = fopen(FILENAME, "r+");

    if (file == NULL) {
        printf("Could not open file.\n");
        return 1;
    }

    readFile(file, students, &count);

    printf("Total number of students: %d\n", count);

    for (int i = 0; i < count; i++) {
        printf("Student %d: ID = %d, Name = %s, Grade = %.2f\n", i + 1, students[i].id, students[i].name, students[i].grade);
    }

    fseek(file, 0, SEEK_SET);

    writeFile(file, students, count);

    fclose(file);

    return 0;
}