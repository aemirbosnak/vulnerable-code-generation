//Falcon-180B DATASET v1.0 Category: Memory management ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
    int id;
} Student;

Student *createStudent(char *name, int age, int id) {
    Student *student = (Student *)malloc(sizeof(Student));
    student->name = strdup(name);
    student->age = age;
    student->id = id;
    return student;
}

void printStudent(Student *student) {
    printf("Name: %s\n", student->name);
    printf("Age: %d\n", student->age);
    printf("ID: %d\n", student->id);
}

int main() {
    char input[MAX_SIZE];
    char *name = NULL;
    int age = 0;
    int id = 0;

    while (1) {
        printf("Enter name (or type 'done' to finish): ");
        fgets(input, MAX_SIZE, stdin);
        if (strcmp(input, "done") == 0) {
            break;
        }
        name = strtok(input, " ");
        age = atoi(strtok(NULL, " "));
        id = atoi(strtok(NULL, " "));

        Student *student = createStudent(name, age, id);
        printStudent(student);
        free(student->name);
        free(student);
    }

    return 0;
}