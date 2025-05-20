//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_STUDENTS 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    float grade;
} Student;

void allocate_students(Student **students, int num_students) {
    *students = (Student *)malloc(num_students * sizeof(Student));
    if (*students == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
}

void deallocate_students(Student *students) {
    free(students);
}

void input_students(Student *students, int num_students) {
    for (int i = 0; i < num_students; i++) {
        printf("Enter name for student %d: ", i + 1);
        fgets(students[i].name, MAX_NAME_LENGTH, stdin);
        students[i].name[strcspn(students[i].name, "\n")] = 0; // Remove newline char

        printf("Enter age for student %d: ", i + 1);
        scanf("%d", &students[i].age);
        printf("Enter grade for student %d: ", i + 1);
        scanf("%f", &students[i].grade);
        getchar(); // Clear buffer
    }
}

void display_students(const Student *students, int num_students) {
    printf("\nList of Students:\n");
    printf("%-20s %-5s %-5s\n", "Name", "Age", "Grade");
    printf("---------------------------------------\n");
    for (int i = 0; i < num_students; i++) {
        printf("%-20s %-5d %-5.2f\n", students[i].name, students[i].age, students[i].grade);
    }
}

int compare_students(const void *a, const void *b) {
    return ((Student *)b)->grade - ((Student *)a)->grade; // Sort in descending order
}

void sort_students(Student *students, int num_students) {
    qsort(students, num_students, sizeof(Student), compare_students);
}

int main() {
    Student *students = NULL;
    int num_students;

    printf("Enter number of students (max %d): ", MAX_STUDENTS);
    scanf("%d", &num_students);
    getchar(); // Clear buffer

    if (num_students <= 0 || num_students > MAX_STUDENTS) {
        fprintf(stderr, "Invalid number of students!\n");
        return EXIT_FAILURE;
    }

    allocate_students(&students, num_students);
    input_students(students, num_students);

    printf("\nBefore Sorting:\n");
    display_students(students, num_students);

    sort_students(students, num_students);

    printf("\nAfter Sorting by grade:\n");
    display_students(students, num_students);

    deallocate_students(students);
    return EXIT_SUCCESS;
}