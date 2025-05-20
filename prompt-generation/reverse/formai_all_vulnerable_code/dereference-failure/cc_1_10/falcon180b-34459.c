//Falcon-180B DATASET v1.0 Category: Educational ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000
#define MAX_LINE_LENGTH 100

typedef struct {
    char *name;
    int age;
    float grade;
} Student;

typedef struct {
    Student students[MAX_SIZE];
    int num_students;
} Class;

void add_student(Class *class, char *name, int age, float grade) {
    if (class->num_students >= MAX_SIZE) {
        printf("Class is full. Cannot add more students.\n");
        return;
    }

    Student *student = &class->students[class->num_students];
    student->name = malloc(strlen(name) + 1);
    strcpy(student->name, name);
    student->age = age;
    student->grade = grade;

    class->num_students++;
}

void print_class(Class *class) {
    printf("Class: %s\n", class->students[0].name);
    printf("Number of students: %d\n", class->num_students);

    for (int i = 0; i < class->num_students; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", class->students[i].name);
        printf("Age: %d\n", class->students[i].age);
        printf("Grade: %.2f\n", class->students[i].grade);
        printf("\n");
    }
}

void sort_class(Class *class, int (*compare)(const void *, const void *)) {
    qsort(class->students, class->num_students, sizeof(Student), compare);
}

int compare_age(const void *a, const void *b) {
    Student *s1 = (Student *)a;
    Student *s2 = (Student *)b;

    if (s1->age < s2->age)
        return -1;
    else if (s1->age > s2->age)
        return 1;
    else
        return 0;
}

int main() {
    Class class;
    class.num_students = 0;

    add_student(&class, "John Doe", 18, 85.5);
    add_student(&class, "Jane Smith", 19, 90.0);
    add_student(&class, "Bob Johnson", 20, 78.5);

    print_class(&class);

    sort_class(&class, compare_age);

    printf("Sorted by age:\n");
    print_class(&class);

    return 0;
}