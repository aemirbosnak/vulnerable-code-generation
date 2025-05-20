//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBERS 100
#define MAX_NAME_LEN 50

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    float score;
} Student;

void init_student(Student* s, int id, const char* name, float score) {
    s->id = id;
    strncpy(s->name, name, MAX_NAME_LEN - 1);
    s->name[MAX_NAME_LEN - 1] = '\0'; // Ensuring null-termination
    s->score = score;
}

void print_student(const Student* s) {
    printf("ID: %d, Name: %s, Score: %.2f\n", s->id, s->name, s->score);
}

Student* allocate_students(int count) {
    Student* students = (Student*)malloc(count * sizeof(Student));
    if (students == NULL) {
        perror("Failed to allocate memory for students");
        exit(EXIT_FAILURE);
    }
    return students;
}

void free_students(Student* students) {
    free(students);
}

void allocate_and_init_students(Student* students, int count) {
    for (int i = 0; i < count; i++) {
        char name[MAX_NAME_LEN];
        snprintf(name, sizeof(name), "Student%d", i + 1);
        float score = (rand() % 10000) / 100.0; // Random score between 0.00 and 99.99
        init_student(&students[i], i + 1, name, score);
    }
}

void sort_students_by_score(Student* students, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].score < students[j + 1].score) {
                // Swap students
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void display_top_students(const Student* students, int count, int top_n) {
    printf("\nTop %d Students:\n", top_n);
    for (int i = 0; i < top_n && i < count; i++) {
        print_student(&students[i]);
    }
}

int main() {
    srand((unsigned)time(NULL)); // Seed for random number generation

    int student_count;
    printf("Enter number of students (max %d): ", MAX_NUMBERS);
    scanf("%d", &student_count);
    if (student_count > MAX_NUMBERS || student_count <= 0) {
        printf("Invalid number of students. Please enter a value between 1 and %d.\n", MAX_NUMBERS);
        return EXIT_FAILURE;
    }

    // Allocate memory for students
    Student* students = allocate_students(student_count);
    
    // Initialize students
    allocate_and_init_students(students, student_count);

    // Sort students by score descending
    sort_students_by_score(students, student_count);

    // Display top 5 students
    display_top_students(students, student_count, 5);

    // Free allocated memory
    free_students(students);

    return EXIT_SUCCESS;
}