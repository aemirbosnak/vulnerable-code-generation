//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define FILE_NAME "records.dat"

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float score;
} Student;

// Function prototypes
void addStudent(FILE *file);
void displayStudents(FILE *file);
void searchStudent(FILE *file);
void updateStudent(FILE *file);
void deleteStudent(FILE *file);
void displayMenu();

int main() {
    FILE *file;
    int choice;
    
    file = fopen(FILE_NAME, "ab+");
    if (!file) {
        printf("Error opening file!\n");
        return 1;
    }

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
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
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    fclose(file);
    return 0;
}

void displayMenu() {
    printf("\n*** STUDENT RECORD SYSTEM ***\n");
    printf("1. Add Student\n");
    printf("2. Display All Students\n");
    printf("3. Search Student\n");
    printf("4. Update Student\n");
    printf("5. Delete Student\n");
    printf("6. Exit\n");
}

void addStudent(FILE *file) {
    Student student;
    printf("Enter Student ID: ");
    scanf("%d", &student.id);
    printf("Enter Student Name: ");
    getchar(); // consume newline
    fgets(student.name, NAME_LENGTH, stdin);
    strtok(student.name, "\n"); // remove newline character
    printf("Enter Student Score: ");
    scanf("%f", &student.score);
    
    fseek(file, 0, SEEK_END);
    fwrite(&student, sizeof(Student), 1, file);
    
    printf("Student added successfully!\n");
}

void displayStudents(FILE *file) {
    Student student;
    
    fseek(file, 0, SEEK_SET);
    printf("\n*** STUDENT RECORDS ***\n");
    while (fread(&student, sizeof(Student), 1, file)) {
        printf("ID: %d, Name: %s, Score: %.2f\n", student.id, student.name, student.score);
    }
}

void searchStudent(FILE *file) {
    int id;
    Student student;
    int found = 0;
    
    printf("Enter Student ID to search: ");
    scanf("%d", &id);
    
    fseek(file, 0, SEEK_SET);
    while (fread(&student, sizeof(Student), 1, file)) {
        if (student.id == id) {
            printf("Found - ID: %d, Name: %s, Score: %.2f\n", student.id, student.name, student.score);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Student with ID %d not found!\n", id);
    }
}

void updateStudent(FILE *file) {
    int id;
    Student student;
    int found = 0;
    
    printf("Enter Student ID to update: ");
    scanf("%d", &id);
    
    fseek(file, 0, SEEK_SET);
    while (fread(&student, sizeof(Student), 1, file)) {
        if (student.id == id) {
            printf("Updating Student - ID: %d, Name: %s, Score: %.2f\n", student.id, student.name, student.score);
            printf("Enter new Name: ");
            getchar(); // consume newline
            fgets(student.name, NAME_LENGTH, stdin);
            strtok(student.name, "\n");
            printf("Enter new Score: ");
            scanf("%f", &student.score);
            
            fseek(file, -sizeof(Student), SEEK_CUR); // move back to where the record is
            fwrite(&student, sizeof(Student), 1, file); // update the record
            printf("Student updated successfully!\n");
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Student with ID %d not found!\n", id);
    }
}

void deleteStudent(FILE *file) {
    int id;
    Student student;
    FILE *tempFile;
    int found = 0;
    
    printf("Enter Student ID to delete: ");
    scanf("%d", &id);
    
    tempFile = fopen("temp.dat", "wb");
    if (!tempFile) {
        printf("Error opening temporary file!\n");
        return;
    }

    fseek(file, 0, SEEK_SET);
    while (fread(&student, sizeof(Student), 1, file)) {
        if (student.id == id) {
            found = 1;
            printf("Deleting Student - ID: %d, Name: %s, Score: %.2f\n", student.id, student.name, student.score);
            continue; // skip this student
        }
        fwrite(&student, sizeof(Student), 1, tempFile); // save other students
    }
    
    fclose(tempFile);
    fclose(file);
    remove(FILE_NAME); // delete original file
    rename("temp.dat", FILE_NAME); // rename temp file to original name

    if (found) {
        printf("Student deleted successfully!\n");
    } else {
        printf("Student with ID %d not found!\n", id);
    }

    file = fopen(FILE_NAME, "ab+"); // reopen the file for further operations
}