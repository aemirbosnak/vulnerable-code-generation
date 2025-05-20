//FormAI DATASET v1.0 Category: Database simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define NUM_SUBJECTS 5
#define NUM_STUDENTS 10

struct Student {
    char name[MAX_NAME_LENGTH];
    int grades[NUM_SUBJECTS];
};

void print_menu() {
    printf("\n\nStudent Database Menu:\n");
    printf("1. Add a new student\n");
    printf("2. Update student's grades\n");
    printf("3. Delete a student\n");
    printf("4. View a student's grades\n");
    printf("5. View all students' grades\n");
    printf("6. Exit\n\n");
}

void print_grades(int grades[], int num_grades) {
    for (int i = 0; i < num_grades; i++) {
        printf("%d ", grades[i]);
    }
}

void print_student(struct Student student) {
    printf("Name: %s\n", student.name);
    printf("Grades: ");
    print_grades(student.grades, NUM_SUBJECTS);
    printf("\n");
}

void print_all_students(struct Student students[], int num_students) {
    for (int i = 0; i < num_students; i++) {
        printf("Student %d:\n", i+1);
        print_student(students[i]);
    }
}

int get_student_index(struct Student students[], int num_students, char name[]) {
    for (int i = 0; i < num_students; i++) {
        if (strcmp(students[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int add_student(struct Student students[], int num_students) {
    struct Student new_student;
    printf("Enter student name (max %d characters): ", MAX_NAME_LENGTH);
    scanf("%s", new_student.name);
    printf("Enter student grades for %d subjects: ", NUM_SUBJECTS);
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        scanf("%d", &new_student.grades[i]);
    }
    students[num_students] = new_student;
    printf("New student added!\n");
    return num_students + 1;
}

void update_grades(struct Student students[], int num_students, char name[]) {
    int student_index = get_student_index(students, num_students, name);
    if (student_index == -1) {
        printf("Student not found.\n");
        return;
    }
    printf("Enter updated grades for %s: ", name);
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        scanf("%d", &students[student_index].grades[i]);
    }
    printf("Grades updated successfully!\n");
}

int delete_student(struct Student students[], int num_students, char name[]) {
    int student_index = get_student_index(students, num_students, name);
    if (student_index == -1) {
        printf("Student not found.\n");
        return num_students;
    }
    for (int i = student_index; i < num_students - 1; i++) {
        students[i] = students[i+1];
    }
    printf("%s deleted!\n", name);
    return num_students - 1;
}

void view_student(struct Student students[], int num_students, char name[]) {
    int student_index = get_student_index(students, num_students, name);
    if (student_index == -1) {
        printf("Student not found.\n");
        return;
    }
    printf("Student %s:\n", name);
    print_student(students[student_index]);
}

int main() {
    struct Student students[NUM_STUDENTS];
    int num_students = 0;
    int choice;
    char name[MAX_NAME_LENGTH];

    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                num_students = add_student(students, num_students);
                break;
            case 2:
                printf("Enter name of student to update grades: ");
                scanf("%s", name);
                update_grades(students, num_students, name);
                break;
            case 3:
                printf("Enter name of student to delete: ");
                scanf("%s", name);
                num_students = delete_student(students, num_students, name);
                break;
            case 4:
                printf("Enter name of student to view grades: ");
                scanf("%s", name);
                view_student(students, num_students, name);
                break;
            case 5:
                printf("All students:\n");
                print_all_students(students, num_students);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}