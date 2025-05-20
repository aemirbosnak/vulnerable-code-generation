//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_STUDENTS 5

typedef struct Student {
    char name[MAX_NAME_LENGTH];
    int age;
    float gpa;
} Student;

typedef struct StudentList {
    Student *students;
    size_t count;
} StudentList;

StudentList* create_student_list(size_t count) {
    StudentList *list = (StudentList *)malloc(sizeof(StudentList));
    if (!list) {
        fprintf(stderr, "Memory allocation failed for StudentList\n");
        exit(EXIT_FAILURE);
    }
    
    list->students = (Student *)malloc(count * sizeof(Student));
    if (!list->students) {
        fprintf(stderr, "Memory allocation failed for students\n");
        free(list);
        exit(EXIT_FAILURE);
    }
    list->count = count;
    return list;
}

void free_student_list(StudentList *list) {
    if (list) {
        free(list->students);
        free(list);
    }
}

void initialize_student(Student *student, const char *name, int age, float gpa) {
    strncpy(student->name, name, MAX_NAME_LENGTH - 1);
    student->name[MAX_NAME_LENGTH - 1] = '\0'; // Ensure null termination
    student->age = age;
    student->gpa = gpa;
}

void print_student(const Student *student) {
    printf("Name: %s, Age: %d, GPA: %.2f\n", student->name, student->age, student->gpa);
}

void input_students(StudentList *list) {
    for (size_t i = 0; i < list->count; ++i) {
        char name[MAX_NAME_LENGTH];
        int age;
        float gpa;

        printf("Enter name for Student %zu: ", i + 1);
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = 0; // Remove newline character

        printf("Enter age for Student %zu: ", i + 1);
        scanf("%d", &age);

        printf("Enter GPA for Student %zu: ", i + 1);
        scanf("%f", &gpa);
        
        getchar(); // Clear the newline character from the input buffer
        initialize_student(&list->students[i], name, age, gpa);
    }
}

void display_students(const StudentList *list) {
    printf("\nStudents Information:\n");
    for (size_t i = 0; i < list->count; ++i) {
        print_student(&list->students[i]);
    }
}

float calculate_average_gpa(const StudentList *list) {
    float total_gpa = 0.0;
    for (size_t i = 0; i < list->count; ++i) {
        total_gpa += list->students[i].gpa;
    }
    return total_gpa / list->count;
}

void perform_student_operations() {
    size_t num_students;
    printf("Enter the number of students (max %d): ", MAX_STUDENTS);
    scanf("%zu", &num_students);
    getchar(); // Clear the newline character from the input buffer
    
    if (num_students > MAX_STUDENTS) {
        fprintf(stderr, "Exceeded maximum number of students.\n");
        exit(EXIT_FAILURE);
    }

    StudentList *student_list = create_student_list(num_students);
    input_students(student_list);
    display_students(student_list);
    
    float average_gpa = calculate_average_gpa(student_list);
    printf("Average GPA of students: %.2f\n", average_gpa);

    free_student_list(student_list);
}

int main() {
    perform_student_operations();
    return 0;
}