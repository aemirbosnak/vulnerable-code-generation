//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_LENGTH 256

typedef struct {
    char name[MAX_LENGTH];
    int age;
    float score;
} Student;

void read_data(const char* filename, Student* students, int* num_students) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    *num_students = 0;
    while (fscanf(file, "%s %d %f", students[*num_students].name, &students[*num_students].age, &students[*num_students].score) != EOF) {
        (*num_students)++;
        if (*num_students >= MAX_RECORDS) {
            break;
        }
    }

    fclose(file);
}

void display_students(Student* students, int num_students) {
    printf("\nStudents Data:\n");
    printf("-----------------------------------------------------------\n");
    printf("| %-10s | %-3s | %-6s |\n", "Name", "Age", "Score");
    printf("-----------------------------------------------------------\n");
    for (int i = 0; i < num_students; i++) {
        printf("| %-10s | %-3d | %-6.2f |\n", students[i].name, students[i].age, students[i].score);
    }
    printf("-----------------------------------------------------------\n");
}

float calculate_average_score(Student* students, int num_students) {
    float total_score = 0.0;
    for (int i = 0; i < num_students; i++) {
        total_score += students[i].score;
    }
    return total_score / num_students;
}

void find_top_student(Student* students, int num_students) {
    if (num_students == 0) return;

    Student top_student = students[0];
    for (int i = 1; i < num_students; i++) {
        if (students[i].score > top_student.score) {
            top_student = students[i];
        }
    }
    
    printf("Top Student: %s with Score: %.2f\n", top_student.name, top_student.score);
}

void sort_students_by_score(Student* students, int num_students) {
    for (int i = 0; i < num_students - 1; i++) {
        for (int j = i + 1; j < num_students; j++) {
            if (students[i].score < students[j].score) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

void write_data(const char* filename, Student* students, int num_students) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        fprintf(stderr, "Error opening file for writing: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < num_students; i++) {
        fprintf(file, "%s %d %.2f\n", students[i].name, students[i].age, students[i].score);
    }

    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input-file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Student students[MAX_RECORDS];
    int num_students;

    read_data(argv[1], students, &num_students);
    display_students(students, num_students);

    float average_score = calculate_average_score(students, num_students);
    printf("Average Score: %.2f\n", average_score);

    find_top_student(students, num_students);

    sort_students_by_score(students, num_students);
    printf("\nSorted Students by Score (Descending):\n");
    display_students(students, num_students);
    
    write_data("sorted_students.txt", students, num_students);
    
    printf("Sorted data has been written to 'sorted_students.txt'.\n");

    return EXIT_SUCCESS;
}