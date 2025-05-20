//Falcon-180B DATASET v1.0 Category: File handling ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 50
#define MAX_FILE_SIZE 1000
#define MAX_LINE_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    int score;
} Student;

void read_file(FILE *file, Student *students, int *count) {
    char line[MAX_LINE_LENGTH];
    char name[MAX_NAME_LENGTH];
    int score;
    int age;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (*count >= MAX_FILE_SIZE) {
            printf("Error: File is too large.\n");
            exit(1);
        }

        if (sscanf(line, "%s %d %d", name, &age, &score)!= 3) {
            printf("Error: Invalid line format.\n");
            exit(1);
        }

        strcpy(students[*count].name, name);
        students[*count].age = age;
        students[*count].score = score;
        (*count)++;
    }
}

void write_file(FILE *file, Student *students, int count) {
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %d %d\n", students[i].name, students[i].age, students[i].score);
    }
}

int main() {
    FILE *input_file, *output_file;
    int count;
    Student students[MAX_FILE_SIZE];

    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    count = 0;
    read_file(input_file, students, &count);
    fclose(input_file);

    if (count == 0) {
        printf("Error: Input file is empty.\n");
        exit(1);
    }

    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    write_file(output_file, students, count);
    fclose(output_file);

    printf("Successfully processed %d records.\n", count);

    return 0;
}