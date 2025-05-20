//LLAMA2-13B DATASET v1.0 Category: Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 25
#define MAX_GRADES 5

// Structure to store student information
typedef struct {
    char name[MAX_NAME_LENGTH];
    float grades[MAX_GRADES];
} student_t;

// Function to read student information from a file
student_t *read_student_info(const char *file_name) {
    student_t *students = NULL;
    int i = 0;
    FILE *file = fopen(file_name, "r");

    if (file == NULL) {
        printf("Error: Unable to open file %s\n", file_name);
        return NULL;
    }

    // Read student names and grades from file
    while (fscanf(file, "%s %f %f %f %f %f", students[i].name, &students[i].grades[0], &students[i].grades[1], &students[i].grades[2], &students[i].grades[3], &students[i].grades[4]) == 6) {
        i++;
    }

    fclose(file);

    return students;
}

// Function to print student information
void print_student_info(student_t *students, int num_students) {
    int i;

    for (i = 0; i < num_students; i++) {
        printf("%d. %s (%f, %f, %f, %f, %f)\n", i + 1, students[i].name, students[i].grades[0], students[i].grades[1], students[i].grades[2], students[i].grades[3], students[i].grades[4]);
    }
}

int main() {
    student_t *students = read_student_info("students.txt");

    if (students == NULL) {
        printf("Error: Unable to read student information from file\n");
        return 1;
    }

    print_student_info(students, 5);

    free(students);

    return 0;
}