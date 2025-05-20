//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_FILE_NAME_LEN 100

typedef struct {
    int roll_no;
    char name[MAX_NAME_LEN];
} Student;

void write_student_to_file(FILE *file, Student student) {
    fwrite(&student, sizeof(Student), 1, file);
}

void read_students_from_file(FILE *file) {
    Student student;
    printf("\n--- Student Records ---\n");
    while (fread(&student, sizeof(Student), 1, file) == 1) {
        printf("Roll No: %d, Name: %s\n", student.roll_no, student.name);
    }
}

void add_student(const char *filename) {
    FILE *file = fopen(filename, "ab");
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    Student student;
    printf("Enter Roll Number: ");
    scanf("%d", &student.roll_no);
    printf("Enter Name: ");
    getchar(); // consume newline left by scanf
    fgets(student.name, MAX_NAME_LEN, stdin);
    student.name[strcspn(student.name, "\n")] = '\0'; // remove newline char

    write_student_to_file(file, student);
    fclose(file);
    printf("Student added successfully.\n");
}

void view_students(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    read_students_from_file(file);
    fclose(file);
}

void delete_student(const char *filename, int roll_no) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    FILE *temp_file = fopen("temp.dat", "wb");
    if (temp_file == NULL) {
        perror("Unable to create temporary file");
        fclose(file);
        return;
    }

    Student student;
    int found = 0;
    
    while (fread(&student, sizeof(Student), 1, file) > 0) {
        if (student.roll_no != roll_no) {
            fwrite(&student, sizeof(Student), 1, temp_file);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(temp_file);

    if (found) {
        remove(filename);
        rename("temp.dat", filename);
        printf("Student with Roll No %d deleted successfully.\n", roll_no);
    } else {
        printf("No student found with Roll No %d.\n", roll_no);
        remove("temp.dat");
    }
}

int main() {
    const char *filename = "students.dat";
    int choice, roll_no;

    do {
        printf("\n--- Student Record Management ---\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Delete Student\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_student(filename);
                break;
            case 2:
                view_students(filename);
                break;
            case 3:
                printf("Enter Roll No of the student to delete: ");
                scanf("%d", &roll_no);
                delete_student(filename, roll_no);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}