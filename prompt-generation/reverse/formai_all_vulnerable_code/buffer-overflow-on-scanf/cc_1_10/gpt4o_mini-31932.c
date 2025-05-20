//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define ID_LENGTH 10

typedef struct {
    char id[ID_LENGTH];
    char name[NAME_LENGTH];
    int age;
} Student;

typedef struct {
    char id[ID_LENGTH];
    int index; // Index in the student array
} Index;

Student students[MAX_RECORDS];
Index indexTable[MAX_RECORDS];
int studentCount = 0;
int indexCount = 0;

// Function to add a student record
void addStudent() {
    if (studentCount >= MAX_RECORDS) {
        printf("Database is full. Cannot add more students.\n");
        return;
    }
    
    Student newStudent;
    printf("Enter Student ID: ");
    scanf("%s", newStudent.id);
    printf("Enter Student Name: ");
    scanf("%s", newStudent.name);
    printf("Enter Student Age: ");
    scanf("%d", &newStudent.age);

    students[studentCount] = newStudent;
    
    // Update the index
    Index newIndex;
    strcpy(newIndex.id, newStudent.id);
    newIndex.index = studentCount;
    indexTable[indexCount++] = newIndex;

    studentCount++;
    printf("Student added successfully!\n");
}

// Function to search for a student by ID
void searchStudent() {
    char searchID[ID_LENGTH];
    printf("Enter Student ID to search: ");
    scanf("%s", searchID);

    for (int i = 0; i < indexCount; i++) {
        if (strcmp(indexTable[i].id, searchID) == 0) {
            int index = indexTable[i].index;
            printf("Student Found: ID: %s, Name: %s, Age: %d\n", 
                    students[index].id, students[index].name, students[index].age);
            return;
        }
    }
    
    printf("Student with ID %s not found.\n", searchID);
}

// Function to display all students
void displayStudents() {
    if (studentCount == 0) {
        printf("No student records found.\n");
        return;
    }
    
    printf("Student Records:\n");
    for (int i = 0; i < studentCount; i++) {
        printf("ID: %s, Name: %s, Age: %d\n", 
                students[i].id, students[i].name, students[i].age);
    }
}

// Function to save the records to a file
void saveRecordsToFile() {
    FILE *file = fopen("students.dat", "wb");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }
    
    fwrite(&studentCount, sizeof(int), 1, file);
    fwrite(students, sizeof(Student), studentCount, file);
    fclose(file);
    printf("Records saved to file successfully!\n");
}

// Function to load records from a file
void loadRecordsFromFile() {
    FILE *file = fopen("students.dat", "rb");
    if (!file) {
        printf("No saved records found. Starting fresh.\n");
        return;
    }
    
    fread(&studentCount, sizeof(int), 1, file);
    fread(students, sizeof(Student), studentCount, file);
    fclose(file);
    
    // Rebuild the index table
    for (int i = 0; i < studentCount; i++) {
        strcpy(indexTable[i].id, students[i].id);
        indexTable[i].index = i;
    }
    
    indexCount = studentCount;    // Update index count
    printf("Records loaded from file successfully!\n");
}

// Main menu function
void menu() {
    int choice;
    do {
        printf("\n--- Student Database Indexing System ---\n");
        printf("1. Add Student\n");
        printf("2. Search Student\n");
        printf("3. Display All Students\n");
        printf("4. Save Records\n");
        printf("5. Load Records\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: searchStudent(); break;
            case 3: displayStudents(); break;
            case 4: saveRecordsToFile(); break;
            case 5: loadRecordsFromFile(); break;
            case 6: printf("Exiting the program.\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);
}

int main() {
    loadRecordsFromFile(); // Load existing records at startup
    menu(); // Start the menu loop
    return 0;
}