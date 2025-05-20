//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_SUBJECTS 10
#define MAX_STUDENTS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    float scores[MAX_SUBJECTS];
    int subject_count;
} Student;

typedef struct {
    Student students[MAX_STUDENTS];
    int student_count;
} StudentDatabase;

void add_student(StudentDatabase *db);
void display_students(const StudentDatabase *db);
void calculate_average_scores(const StudentDatabase *db);
void save_to_file(const StudentDatabase *db, const char *filename);
void load_from_file(StudentDatabase *db, const char *filename);

int main() {
    StudentDatabase db;
    db.student_count = 0;

    int choice;
    char filename[50];
    
    printf("Welcome to the Student Management System\n");

    while (1) {
        printf("\n1. Add Student\n2. Display Students\n3. Calculate Average Scores\n4. Save to File\n5. Load from File\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_student(&db);
                break;
            case 2:
                display_students(&db);
                break;
            case 3:
                calculate_average_scores(&db);
                break;
            case 4:
                printf("Enter the filename to save: ");
                scanf("%s", filename);
                save_to_file(&db, filename);
                break;
            case 5:
                printf("Enter the filename to load: ");
                scanf("%s", filename);
                load_from_file(&db, filename);
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void add_student(StudentDatabase *db) {
    if (db->student_count >= MAX_STUDENTS) {
        printf("Cannot add more students. Maximum limit reached.\n");
        return;
    }

    Student new_student;
    printf("Enter student name: ");
    scanf("%s", new_student.name);
    
    printf("Enter number of subjects: ");
    scanf("%d", &new_student.subject_count);
    if (new_student.subject_count > MAX_SUBJECTS) {
        printf("Exceeds maximum subjects. Setting to %d.\n", MAX_SUBJECTS);
        new_student.subject_count = MAX_SUBJECTS;
    }

    for (int i = 0; i < new_student.subject_count; i++) {
        printf("Enter score for subject %d: ", i + 1);
        scanf("%f", &new_student.scores[i]);
    }

    db->students[db->student_count] = new_student;
    db->student_count++;
    printf("Student added successfully!\n");
}

void display_students(const StudentDatabase *db) {
    if (db->student_count == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\nList of Students:\n");
    for (int i = 0; i < db->student_count; i++) {
        printf("Name: %s\n", db->students[i].name);
        for (int j = 0; j < db->students[i].subject_count; j++) {
            printf("  Subject %d Score: %.2f\n", j + 1, db->students[i].scores[j]);
        }
    }
}

void calculate_average_scores(const StudentDatabase *db) {
    if (db->student_count == 0) {
        printf("No students to calculate average scores.\n");
        return;
    }

    printf("\nAverage Scores:\n");
    for (int i = 0; i < db->student_count; i++) {
        Student student = db->students[i];
        float total = 0;
        for (int j = 0; j < student.subject_count; j++) {
            total += student.scores[j];
        }
        float average = total / student.subject_count;
        printf("Name: %s, Average Score: %.2f\n", student.name, average);
    }
}

void save_to_file(const StudentDatabase *db, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }

    fwrite(db, sizeof(StudentDatabase), 1, file);
    fclose(file);
    printf("Data saved to %s successfully!\n", filename);
}

void load_from_file(StudentDatabase *db, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error opening file for reading.\n");
        return;
    }

    fread(db, sizeof(StudentDatabase), 1, file);
    fclose(file);
    printf("Data loaded from %s successfully!\n", filename);
}