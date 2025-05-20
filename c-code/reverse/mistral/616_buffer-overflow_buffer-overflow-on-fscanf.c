#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    float gpa;
} Student;

int main(int argc, char *argv[]) {
    FILE *file;
    Student students[MAX_STUDENTS];
    int num_students = 0;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 2;
    }

    while (fscanf(file, "%d%s%f", &students[num_students].id, students[num_students].name, &students[num_students].gpa) == 3) {
        num_students++;
    }

    fclose(file);

    // Print the student records
    for (int i = 0; i < num_students; i++) {
        printf("ID: %d\nName: %s\nGPA: %.2f\n", students[i].id, students[i].name, students[i].gpa);
    }

    return 0;
}
