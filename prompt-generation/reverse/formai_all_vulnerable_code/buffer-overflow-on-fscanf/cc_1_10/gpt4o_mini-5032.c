//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50
#define DB_FILENAME "database.txt"

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float score;
} Student;

typedef struct {
    Student entries[MAX_ENTRIES];
    int count;
} Database;

void loadDatabase(Database *db) {
    FILE *file = fopen(DB_FILENAME, "r");
    if (!file) {
        fprintf(stderr, "Error! Could not open database file.\n");
        exit(EXIT_FAILURE);
    }
    
    while (fscanf(file, "%d %49s %f", &db->entries[db->count].id, db->entries[db->count].name, &db->entries[db->count].score) != EOF) {
        db->count++;
    }
    fclose(file);
    printf("Database loaded! Created %d entries!\n", db->count);
}

void saveDatabase(Database *db) {
    FILE *file = fopen(DB_FILENAME, "w");
    if (!file) {
        fprintf(stderr, "Error! Could not save the database.\n");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < db->count; i++) {
        fprintf(file, "%d %s %.2f\n", db->entries[i].id, db->entries[i].name, db->entries[i].score);
    }
    fclose(file);
    printf("Database saved! Total entries: %d\n", db->count);
}

void addStudent(Database *db) {
    if (db->count >= MAX_ENTRIES) {
        fprintf(stderr, "Error! Database full! Cannot add student.\n");
        return;
    }
    
    Student newStudent;
    printf("Enter student ID: ");
    scanf("%d", &newStudent.id);
    printf("Enter student name: ");
    scanf("%s", newStudent.name);
    printf("Enter student score: ");
    scanf("%f", &newStudent.score);
    
    db->entries[db->count] = newStudent;
    db->count++;
    printf("Student %s added with ID %d!\n", newStudent.name, newStudent.id);
}

void deleteStudent(Database *db) {
    int id, found = 0;
    printf("Enter student ID to delete: ");
    scanf("%d", &id);
    
    for (int i = 0; i < db->count; i++) {
        if (db->entries[i].id == id) {
            found = 1;
            for (int j = i; j < db->count - 1; j++) {
                db->entries[j] = db->entries[j + 1];
            }
            db->count--;
            break;
        }
    }
    
    if (found) {
        printf("Successfully deleted student with ID %d!\n", id);
    } else {
        fprintf(stderr, "Error! Student with ID %d not found.\n", id);
    }
}

void displayStudents(Database *db) {
    if (db->count == 0) {
        fprintf(stderr, "No students to display!\n");
        return;
    }
    
    printf("=== Student Records ===\n");
    for (int i = 0; i < db->count; i++) {
        printf("ID: %d, Name: %s, Score: %.2f\n", db->entries[i].id, db->entries[i].name, db->entries[i].score);
    }
}

int main() {
    Database db = {.count = 0};
    
    loadDatabase(&db);

    int option;
    do {
        printf("\n--- Student Database Management ---\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Display Students\n");
        printf("4. Save and Exit\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                addStudent(&db);
                break;
            case 2:
                deleteStudent(&db);
                break;
            case 3:
                displayStudents(&db);
                break;
            case 4:
                saveDatabase(&db);
                printf("Exiting program...\n");
                break;
            default:
                fprintf(stderr, "Error! Invalid option. Please choose again.\n");
        }
    } while (option != 4);
    
    return 0;
}