//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define FILE_NAME "records.dat"

// Structure to hold student data
typedef struct {
    int id;
    char name[NAME_LENGTH];
    float grade;
} Student;

// Function prototypes
void addStudent(FILE *file);
void displayStudents(FILE *file);
void searchStudent(FILE *file);
void updateStudent(FILE *file);
void deleteStudent(FILE *file);
void listMenu();

int main() {
    FILE *file;
    int choice;

    // Open the file in read and write binary mode
    if ((file = fopen(FILE_NAME, "ab+")) == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    do {
        listMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(file);
                break;
            case 2:
                displayStudents(file);
                break;
            case 3:
                searchStudent(file);
                break;
            case 4:
                updateStudent(file);
                break;
            case 5:
                deleteStudent(file);
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
    } while (choice != 6);

    fclose(file);
    return EXIT_SUCCESS;
}

void listMenu() {
    printf("==== Student Records Management ====\n");
    printf("1. Add Student\n");
    printf("2. Display Students\n");
    printf("3. Search Student by ID\n");
    printf("4. Update Student Record\n");
    printf("5. Delete Student Record\n");
    printf("6. Exit\n");
}

void addStudent(FILE *file) {
    Student student;
    printf("Enter Student ID: ");
    scanf("%d", &student.id);
    printf("Enter Student Name: ");
    getchar(); // to consume the leftover newline
    fgets(student.name, NAME_LENGTH, stdin);
    student.name[strcspn(student.name, "\n")] = '\0'; // Remove newline
    printf("Enter Student Grade: ");
    scanf("%f", &student.grade);

    fseek(file, 0, SEEK_END);
    fwrite(&student, sizeof(Student), 1, file);
    printf("Student added successfully!\n");
}

void displayStudents(FILE *file) {
    Student student;
    rewind(file);
    printf("=== List of Students ===\n");
    while (fread(&student, sizeof(Student), 1, file) == 1) {
        printf("ID: %d, Name: %s, Grade: %.2f\n", student.id, student.name, student.grade);
    }
}

void searchStudent(FILE *file) {
    int id, found = 0;
    Student student;
    printf("Enter Student ID to search: ");
    scanf("%d", &id);
    rewind(file);
    
    while (fread(&student, sizeof(Student), 1, file) == 1) {
        if (student.id == id) {
            printf("Student found! ID: %d, Name: %s, Grade: %.2f\n", student.id, student.name, student.grade);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}

void updateStudent(FILE *file) {
    int id, found = 0;
    Student student;
    
    printf("Enter Student ID to update: ");
    scanf("%d", &id);
    rewind(file);
    
    while (fread(&student, sizeof(Student), 1, file) == 1) {
        if (student.id == id) {
            found = 1;
            printf("Current Name: %s, Current Grade: %.2f\n", student.name, student.grade);
            printf("Enter new Name: ");
            getchar(); // consume newline
            fgets(student.name, NAME_LENGTH, stdin);
            student.name[strcspn(student.name, "\n")] = '\0'; // Remove newline
            printf("Enter new Grade: ");
            scanf("%f", &student.grade);

            // Move the file position to the beginning of this record
            fseek(file, -sizeof(Student), SEEK_CUR);
            fwrite(&student, sizeof(Student), 1, file);
            printf("Student record updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}

void deleteStudent(FILE *file) {
    int id, found = 0;
    Student student;
    FILE *tempFile;
   
    if ((tempFile = fopen("temp.dat", "wb")) == NULL) {
        perror("Error opening temp file");
        return;
    }

    printf("Enter Student ID to delete: ");
    scanf("%d", &id);
    rewind(file);
    
    while (fread(&student, sizeof(Student), 1, file) == 1) {
        if (student.id != id) {
            fwrite(&student, sizeof(Student), 1, tempFile);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(tempFile);
    
    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);
    
    if (found) {
        printf("Student with ID %d deleted successfully.\n", id);
    } else {
        printf("Student with ID %d not found.\n", id);
    }
}