#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

#define MAX_STUDENTS 100

typedef struct {
    char name[50];
    int age;
} Student;

int main() {
    FILE *file = fopen("students.txt", "r");
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }

    Student students[MAX_STUDENTS];
    int count = 0;

    while (count < MAX_STUDENTS && fscanf(file, "%s %d", students[count].name, &students[count].age) != EOF) {
        count++;
    }

    fclose(file);

    for (int i = 0; i < count; i++) {
        printf("Name: %s, Age: %d\n", students[i].name, students[i].age);
    }

    return 0;
}
