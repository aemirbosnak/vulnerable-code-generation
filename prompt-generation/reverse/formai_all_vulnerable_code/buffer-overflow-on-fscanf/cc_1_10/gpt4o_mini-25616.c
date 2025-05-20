//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 50
#define FILE_NAME "records.txt"

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    float score;
} Student;

// Function prototypes
void displayStudents(Student students[], int count);
void saveToFile(Student students[], int count);
int loadFromFile(Student students[]);
void addStudent(Student students[], int *count);
void clearBuffer();

int main() {
    Student students[MAX_RECORDS];
    int count = loadFromFile(students);
    int choice;

    do {
        printf("\n--- Student Records Management ---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Save to File\n");
        printf("4. Load from File\n");
        printf("5. Exit\n");
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);
        clearBuffer(); // Clear input buffer

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                saveToFile(students, count);
                break;
            case 4:
                count = loadFromFile(students);
                break;
            case 5:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1-5.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void displayStudents(Student students[], int count) {
    if (count == 0) {
        printf("No records to display.\n");
        return;
    }
    printf("\n--- List of Students ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Score: %.2f\n", students[i].id, students[i].name, students[i].score);
    }
}

void saveToFile(Student students[], int count) {
    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d %s %.2f\n", students[i].id, students[i].name, students[i].score);
    }

    fclose(file);
    printf("Records saved successfully to %s\n", FILE_NAME);
}

int loadFromFile(Student students[]) {
    FILE *file = fopen(FILE_NAME, "r");
    int count = 0;

    if (file == NULL) {
        printf("No records found, starting with an empty list.\n");
        return 0;
    }

    while (fscanf(file, "%d %49s %f", &students[count].id, students[count].name, &students[count].score) == 3) {
        count++;
        if (count >= MAX_RECORDS) {
            break;
        }
    }

    fclose(file);
    printf("%d records loaded successfully from %s\n", count, FILE_NAME);
    return count;
}

void addStudent(Student students[], int *count) {
    if (*count >= MAX_RECORDS) {
        printf("Cannot add more records. Maximum limit reached.\n");
        return;
    }

    Student newStudent;
    newStudent.id = *count + 1; // New ID is count + 1 as IDs start from 1
    printf("Enter student name: ");
    fgets(newStudent.name, MAX_NAME_LENGTH, stdin);
    strtok(newStudent.name, "\n"); // Remove newline character
    printf("Enter student score: ");
    scanf("%f", &newStudent.score);
    clearBuffer(); // Clear input buffer after reading float

    students[*count] = newStudent; // Add new student to the array
    (*count)++; // Increment count
    printf("Student %s added successfully.\n", newStudent.name);
}

void clearBuffer() {
    while (getchar() != '\n'); // Clear input buffer
}