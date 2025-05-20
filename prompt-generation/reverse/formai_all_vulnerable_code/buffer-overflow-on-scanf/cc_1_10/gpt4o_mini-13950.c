//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 50
#define DATA_FILE "students.dat"

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    float grade;
} Student;

// Function prototypes
void addRecord();
void displayRecords();
void searchRecord();
void deleteRecord();
void saveRecords(Student *students, int count);
int loadRecords(Student *students);

int main() {
    int choice;

    do {
        printf("\nStudent Management System\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Search Record\n");
        printf("4. Delete Record\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addRecord();
                break;
            case 2:
                displayRecords();
                break;
            case 3:
                searchRecord();
                break;
            case 4:
                deleteRecord();
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please enter again.\n");
        }
    } while (choice != 5);

    return 0;
}

void addRecord() {
    FILE *file = fopen(DATA_FILE, "ab");
    if (!file) {
        fprintf(stderr, "Could not open file for writing.\n");
        return;
    }

    Student student;
    printf("Enter ID: ");
    scanf("%d", &student.id);
    printf("Enter Name: ");
    getchar();  // Consume newline character left by previous input
    fgets(student.name, MAX_NAME_LENGTH, stdin);
    student.name[strcspn(student.name, "\n")] = 0;  // Remove newline character
    printf("Enter Grade: ");
    scanf("%f", &student.grade);

    fwrite(&student, sizeof(Student), 1, file);
    fclose(file);
    printf("Record added successfully.\n");
}

void displayRecords() {
    FILE *file = fopen(DATA_FILE, "rb");
    if (!file) {
        fprintf(stderr, "Could not open file for reading.\n");
        return;
    }

    Student student;
    printf("\nStudent Records:\n");
    printf("ID\tName\t\tGrade\n");
    printf("---------------------------\n");

    while (fread(&student, sizeof(Student), 1, file)) {
        printf("%d\t%s\t%.2f\n", student.id, student.name, student.grade);
    }

    fclose(file);
}

void searchRecord() {
    int searchID;
    printf("Enter ID to search: ");
    scanf("%d", &searchID);

    FILE *file = fopen(DATA_FILE, "rb");
    if (!file) {
        fprintf(stderr, "Could not open file for reading.\n");
        return;
    }

    Student student;
    int found = 0;

    while (fread(&student, sizeof(Student), 1, file)) {
        if (student.id == searchID) {
            printf("Record Found: ID: %d, Name: %s, Grade: %.2f\n", student.id, student.name, student.grade);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No record found with ID %d.\n", searchID);
    }

    fclose(file);
}

void deleteRecord() {
    FILE *file = fopen(DATA_FILE, "rb");
    if (!file) {
        fprintf(stderr, "Could not open file for reading.\n");
        return;
    }

    Student students[MAX_RECORDS];
    int count = loadRecords(students);
    fclose(file);

    if (count == 0) {
        printf("No records to delete.\n");
        return;
    }

    int deleteID;
    printf("Enter ID to delete: ");
    scanf("%d", &deleteID);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (students[i].id == deleteID) {
            found = 1;
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            break;
        }
    }

    if (found) {
        saveRecords(students, count);
        printf("Record with ID %d deleted successfully.\n", deleteID);
    } else {
        printf("No record found with ID %d.\n", deleteID);
    }
}

void saveRecords(Student *students, int count) {
    FILE *file = fopen(DATA_FILE, "wb");
    if (!file) {
        fprintf(stderr, "Could not open file for writing.\n");
        return;
    }
    fwrite(students, sizeof(Student), count, file);
    fclose(file);
}

int loadRecords(Student *students) {
    FILE *file = fopen(DATA_FILE, "rb");
    if (!file) {
        return 0;  // Return 0 if file doesn't exist
    }

    int count = fread(students, sizeof(Student), MAX_RECORDS, file);
    fclose(file);
    return count;
}