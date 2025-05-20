//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
    int id;
} Student;

Student *createStudent(char *name, int age, int id) {
    Student *student = (Student *)malloc(sizeof(Student));
    student->name = (char *)malloc((strlen(name) + 1) * sizeof(char));
    strcpy(student->name, name);
    student->age = age;
    student->id = id;
    return student;
}

int compareStudents(const void *a, const void *b) {
    Student *studentA = (Student *)a;
    Student *studentB = (Student *)b;
    int result;

    if (studentA->age > studentB->age) {
        result = 1;
    } else if (studentA->age < studentB->age) {
        result = -1;
    } else {
        result = 0;
    }
    return result;
}

void printStudent(Student *student) {
    printf("Name: %s\n", student->name);
    printf("Age: %d\n", student->age);
    printf("ID: %d\n", student->id);
}

int main() {
    int numStudents;
    scanf("%d", &numStudents);

    Student **students = (Student **)malloc(numStudents * sizeof(Student *));

    for (int i = 0; i < numStudents; i++) {
        char name[MAX_SIZE];
        int age, id;
        scanf("%s %d %d", name, &age, &id);
        students[i] = createStudent(name, age, id);
    }

    qsort(students, numStudents, sizeof(Student *), compareStudents);

    for (int i = 0; i < numStudents; i++) {
        printStudent(students[i]);
    }

    for (int i = 0; i < numStudents; i++) {
        free(students[i]->name);
        free(students[i]);
    }
    free(students);

    return 0;
}