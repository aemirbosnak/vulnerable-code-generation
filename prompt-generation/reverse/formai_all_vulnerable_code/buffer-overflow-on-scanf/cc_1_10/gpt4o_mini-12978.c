//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 10
#define NAME_LENGTH 30

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float score;
} Student;

void displayMenu();
void addRecord(Student students[], int *count);
void displayRecords(const Student students[], int count);
void findRecord(const Student students[], int count);
void deleteRecord(Student students[], int *count);
void saveRecords(const Student students[], int count);
void loadRecords(Student students[], int *count);

int main() {
    Student students[MAX_RECORDS];
    int count = 0;  
    loadRecords(students, &count);
    
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Clear newline from input buffer

        switch (choice) {
            case 1: addRecord(students, &count); break;
            case 2: displayRecords(students, count); break;
            case 3: findRecord(students, count); break;
            case 4: deleteRecord(students, &count); break;
            case 5: saveRecords(students, count); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }

    } while (choice != 6);

    return 0;
}

void displayMenu() {
    printf("\n=== Student Database Menu ===\n");
    printf("1. Add Student Record\n");
    printf("2. Display All Records\n");
    printf("3. Find a Record by ID\n");
    printf("4. Delete a Record by ID\n");
    printf("5. Save Records to File\n");
    printf("6. Exit\n");
}

void addRecord(Student students[], int *count) {
    if (*count >= MAX_RECORDS) {
        printf("Database is full, cannot add more records.\n");
        return;
    }

    Student newStudent;
    newStudent.id = (*count) + 1;
    printf("Enter student name: ");
    fgets(newStudent.name, NAME_LENGTH, stdin);
    strtok(newStudent.name, "\n"); // Remove newline character
    printf("Enter student score: ");
    scanf("%f", &newStudent.score);
    getchar(); // Clear newline from input buffer

    students[*count] = newStudent;
    (*count)++;
    printf("Record added successfully!\n");
}

void displayRecords(const Student students[], int count) {
    if (count == 0) {
        printf("No records found.\n");
        return;
    }

    printf("\n=== Student Records ===\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Score: %.2f\n", students[i].id, students[i].name, students[i].score);
    }
}

void findRecord(const Student students[], int count) {
    int id;
    printf("Enter Student ID to find: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("Record found - ID: %d, Name: %s, Score: %.2f\n", students[i].id, students[i].name, students[i].score);
            return;
        }
    }
    printf("Record with ID %d not found.\n", id);
}

void deleteRecord(Student students[], int *count) {
    int id;
    printf("Enter Student ID to delete: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < *count; i++) {
        if (students[i].id == id) {
            for (int j = i; j < *count - 1; j++) {
                students[j] = students[j + 1]; // Shift records left
            }
            (*count)--;
            printf("Record with ID %d deleted successfully.\n", id);
            return;
        }
    }
    printf("Record with ID %d not found.\n", id);
}

void saveRecords(const Student students[], int count) {
    FILE *file = fopen("students.dat", "wb");
    if (!file) {
        printf("Error opening file for writing!\n");
        return;
    }
    
    fwrite(students, sizeof(Student), count, file);
    fclose(file);
    printf("Records saved successfully to students.dat.\n");
}

void loadRecords(Student students[], int *count) {
    FILE *file = fopen("students.dat", "rb");
    if (!file) {
        printf("No previous records found. Starting fresh.\n");
        return;
    }
    
    *count = fread(students, sizeof(Student), MAX_RECORDS, file);
    fclose(file);
    printf("%d records loaded successfully.\n", *count);
}