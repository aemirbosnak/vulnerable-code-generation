//Falcon-180B DATASET v1.0 Category: File handling ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char* name;
    int score;
} Student;

int compare_scores(const void* a, const void* b) {
    Student* student_a = (Student*)a;
    Student* student_b = (Student*)b;

    if (student_a->score > student_b->score) {
        return -1;
    } else if (student_a->score < student_b->score) {
        return 1;
    } else {
        return 0;
    }
}

void read_students_from_file(FILE* file, Student** students, int* num_students) {
    char line[MAX_LINE_LENGTH];
    char* name;
    int score;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        name = strtok(line, " ");
        score = atoi(strtok(NULL, " "));

        *num_students += 1;
        *students = realloc(*students, sizeof(Student) * (*num_students));

        Student* new_student = (*students) + (*num_students - 1);
        new_student->name = strdup(name);
        new_student->score = score;
    }
}

void write_students_to_file(FILE* file, Student* students, int num_students) {
    for (int i = 0; i < num_students; i++) {
        fprintf(file, "%s %d\n", students[i].name, students[i].score);
    }
}

void sort_students(Student* students, int num_students) {
    qsort(students, num_students, sizeof(Student), compare_scores);
}

int main() {
    FILE* input_file = fopen("students.txt", "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    FILE* output_file = fopen("sorted_students.txt", "w");
    if (output_file == NULL) {
        printf("Error: could not open output file.\n");
        fclose(input_file);
        return 1;
    }

    Student** students = NULL;
    int num_students = 0;

    read_students_from_file(input_file, &students, &num_students);

    sort_students(students, num_students);

    write_students_to_file(output_file, students, num_students);

    fclose(input_file);
    fclose(output_file);

    free(students);

    return 0;
}