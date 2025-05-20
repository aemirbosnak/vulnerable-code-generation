//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50
#define FILE_NAME "students.dat"

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float gpa;
} Student;

void addStudent(FILE *fp);
void displayStudents(FILE *fp);
void searchStudent(FILE *fp);
void saveToFile(FILE *fp, Student students[], int count);
int loadFromFile(FILE *fp, Student students[]);

int main() {
    FILE *fp;
    Student students[MAX_STUDENTS];
    int count = loadFromFile(fp, students);
    int choice;

    do {
        printf("\nSimple Student Database\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(fp);
                count++;
                break;
            case 2:
                displayStudents(fp);
                break;
            case 3:
                searchStudent(fp);
                break;
            case 4:
                saveToFile(fp, students, count);
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);
    
    return 0;
}

void addStudent(FILE *fp) {
    Student newStudent;
    printf("Enter student ID: ");
    scanf("%d", &newStudent.id);
    printf("Enter student name: ");
    scanf(" %[^\n]s", newStudent.name);
    printf("Enter student GPA: ");
    scanf("%f", &newStudent.gpa);

    fp = fopen(FILE_NAME, "a");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }
    fprintf(fp, "%d %s %.2f\n", newStudent.id, newStudent.name, newStudent.gpa);
    fclose(fp);
    printf("Student added successfully.\n");
}

void displayStudents(FILE *fp) {
    Student student;
    fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    printf("\nStudent List:\n");
    while (fscanf(fp, "%d %s %f", &student.id, student.name, &student.gpa) != EOF) {
        printf("ID: %d, Name: %s, GPA: %.2f\n", student.id, student.name, student.gpa);
    }
    fclose(fp);
}

void searchStudent(FILE *fp) {
    int id;
    Student student;
    int found = 0;

    printf("Enter student ID to search: ");
    scanf("%d", &id);

    fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    while (fscanf(fp, "%d %s %f", &student.id, student.name, &student.gpa) != EOF) {
        if (student.id == id) {
            printf("Found Student - ID: %d, Name: %s, GPA: %.2f\n", student.id, student.name, student.gpa);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No student found with ID %d.\n", id);
    }
    fclose(fp);
}

void saveToFile(FILE *fp, Student students[], int count) {
    fp = fopen(FILE_NAME, "w");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d %s %.2f\n", students[i].id, students[i].name, students[i].gpa);
    }
    fclose(fp);
    printf("Changes saved successfully.\n");
}

int loadFromFile(FILE *fp, Student students[]) {
    fp = fopen(FILE_NAME, "r");
    int count = 0;

    if (fp == NULL) {
        perror("Error opening file");
        return count;
    }

    while (fscanf(fp, "%d %s %f", &students[count].id, students[count].name, &students[count].gpa) != EOF) {
        count++;
    }

    fclose(fp);
    return count;
}