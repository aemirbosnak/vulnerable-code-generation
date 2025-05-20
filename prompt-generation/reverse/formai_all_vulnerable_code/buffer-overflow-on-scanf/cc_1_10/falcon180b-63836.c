//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char name[MAX_SIZE];
    int id;
} Student;

void create_students(Student* students, int num_students) {
    for (int i = 0; i < num_students; i++) {
        sprintf(students[i].name, "Student %d", i+1);
        students[i].id = i+1;
    }
}

int compare_students(const void* a, const void* b) {
    const Student* student_a = (const Student*)a;
    const Student* student_b = (const Student*)b;

    return strcmp(student_a->name, student_b->name);
}

void print_students(Student* students, int num_students) {
    for (int i = 0; i < num_students; i++) {
        printf("%s\n", students[i].name);
    }
}

int main() {
    Student students[MAX_SIZE];
    int num_students = 10;

    create_students(students, num_students);
    qsort(students, num_students, sizeof(Student), compare_students);
    print_students(students, num_students);

    char search_name[MAX_SIZE];
    printf("Enter a name to search for: ");
    scanf("%s", search_name);

    Student* found_student = bsearch(&search_name, students, num_students, sizeof(Student), compare_students);

    if (found_student!= NULL) {
        printf("Found student: %s\n", found_student->name);
    } else {
        printf("Student not found.\n");
    }

    return 0;
}