//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototype declarations
void displayMenu();
void addStudent(char studentList[][50], int *studentCount);
void removeStudent(char studentList[][50], int *studentCount);
void listStudents(char studentList[][50], int studentCount);
void saveToFile(char studentList[][50], int studentCount, const char *filename);
void loadFromFile(char studentList[][50], int *studentCount, const char *filename);
void clearBuffer();

int main() {
    char studentList[100][50]; // 100 students, each with a max name length of 49
    int studentCount = 0;
    char filename[] = "students.txt";
    int choice;

    loadFromFile(studentList, &studentCount, filename);

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer(); // Clear the buffer for the next input

        switch(choice) {
            case 1:
                addStudent(studentList, &studentCount);
                break;
            case 2:
                removeStudent(studentList, &studentCount);
                break;
            case 3:
                listStudents(studentList, studentCount);
                break;
            case 4:
                saveToFile(studentList, studentCount, filename);
                break;
            case 5:
                loadFromFile(studentList, &studentCount, filename);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while(choice != 6);

    return 0;
}

void displayMenu() {
    printf("\n=== Student Management System ===\n");
    printf("1. Add Student\n");
    printf("2. Remove Student\n");
    printf("3. List Students\n");
    printf("4. Save to File\n");
    printf("5. Load from File\n");
    printf("6. Exit\n");
}

void addStudent(char studentList[][50], int *studentCount) {
    if(*studentCount < 100) {
        printf("Enter student name: ");
        fgets(studentList[*studentCount], 50, stdin);
        studentList[*studentCount][strcspn(studentList[*studentCount], "\n")] = '\0'; // Remove newline character
        (*studentCount)++;
        printf("Student added successfully!\n");
    } else {
        printf("Student list is full!\n");
    }
}

void removeStudent(char studentList[][50], int *studentCount) {
    if(*studentCount == 0) {
        printf("No students to remove.\n");
        return;
    }

    char name[50];
    printf("Enter the name of the student to remove: ");
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove newline character

    int found = 0;
    for(int i = 0; i < *studentCount; i++) {
        if(strcmp(studentList[i], name) == 0) {
            for(int j = i; j < *studentCount - 1; j++) {
                strcpy(studentList[j], studentList[j + 1]);
            }
            (*studentCount)--;
            found = 1;
            printf("Student removed successfully!\n");
            break;
        }
    }

    if(!found) {
        printf("Student not found.\n");
    }
}

void listStudents(char studentList[][50], int studentCount) {
    if(studentCount == 0) {
        printf("No students to display.\n");
    } else {
        printf("\n=== Students List ===\n");
        for(int i = 0; i < studentCount; i++) {
            printf("%d. %s\n", i + 1, studentList[i]);
        }
    }
}

void saveToFile(char studentList[][50], int studentCount, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    
    for(int i = 0; i < studentCount; i++) {
        fprintf(file, "%s\n", studentList[i]);
    }
    
    fclose(file);
    printf("Students saved to file successfully!\n");
}

void loadFromFile(char studentList[][50], int *studentCount, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("No previous records found.\n");
        return;
    }
    
    while (fgets(studentList[*studentCount], 50, file) != NULL && *studentCount < 100) {
        studentList[*studentCount][strcspn(studentList[*studentCount], "\n")] = '\0'; // Remove newline character
        (*studentCount)++;
    }
    
    fclose(file);
    printf("Students loaded from file successfully!\n");
}

void clearBuffer() {
    while (getchar() != '\n'); // Clear input buffer
}