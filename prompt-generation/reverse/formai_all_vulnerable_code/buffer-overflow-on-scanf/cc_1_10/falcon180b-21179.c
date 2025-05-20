//Falcon-180B DATASET v1.0 Category: Educational ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_NUM_STUDENTS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Student;

void read_students(Student* students, int num_students) {
    for (int i = 0; i < num_students; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter score of %s: ", students[i].name);
        scanf("%d", &students[i].score);
    }
}

void sort_students(Student* students, int num_students) {
    for (int i = 0; i < num_students - 1; i++) {
        for (int j = i + 1; j < num_students; j++) {
            if (students[j].score > students[i].score) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

void print_students(Student* students, int num_students) {
    printf("Name\tScore\n");
    for (int i = 0; i < num_students; i++) {
        printf("%s\t%d\n", students[i].name, students[i].score);
    }
}

int main() {
    int num_students;

    printf("Enter number of students: ");
    scanf("%d", &num_students);

    if (num_students > MAX_NUM_STUDENTS) {
        printf("Error: Too many students\n");
        return 1;
    }

    Student students[num_students];

    read_students(students, num_students);
    sort_students(students, num_students);
    print_students(students, num_students);

    return 0;
}