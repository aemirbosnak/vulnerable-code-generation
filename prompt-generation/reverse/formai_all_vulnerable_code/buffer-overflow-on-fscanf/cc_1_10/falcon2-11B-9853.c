//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Structure for a student record
typedef struct {
    char name[50];
    int age;
    float gpa;
} Student;

// Function to generate a hash code for a given string
unsigned int hash_string(const char *str) {
    unsigned int hash = 0;
    int c;
    while ((c = *str++)) {
        hash = (hash << 5) + hash + c; /* hash * 33 + c */
    }
    return hash;
}

// Function to add a student record to the database
void add_student(const char *name, int age, float gpa) {
    Student record;
    strcpy(record.name, name);
    record.age = age;
    record.gpa = gpa;
    
    // Open the database file for writing
    FILE *db = fopen("students.db", "a+");
    
    // If the file does not exist, create it
    if (!db) {
        fprintf(stderr, "Error: Unable to open database file.\n");
        exit(1);
    }
    
    // Write the new student record to the file
    fprintf(db, "%s %d %f\n", record.name, record.age, record.gpa);
    
    // Close the file
    fclose(db);
}

// Function to search for a student by name
bool search_student(const char *name) {
    Student record;
    FILE *db = fopen("students.db", "r");
    
    // If the file does not exist, return false
    if (!db) {
        fprintf(stderr, "Error: Unable to open database file.\n");
        exit(1);
    }
    
    // Read the first line of the file to get the record count
    int record_count = 0;
    if (fscanf(db, "%d\n", &record_count) == 1) {
        fseek(db, 0, SEEK_SET);
    }
    
    // Search for the student record by name
    for (int i = 0; i < record_count; i++) {
        if (fscanf(db, "%s %d %f\n", record.name, &record.age, &record.gpa) == 3) {
            // If the record matches, return true
            if (strcmp(record.name, name) == 0) {
                fclose(db);
                return true;
            }
        }
    }
    
    // If the record is not found, return false
    fclose(db);
    return false;
}

int main() {
    // Add some student records to the database
    add_student("Alice", 20, 3.5);
    add_student("Bob", 22, 3.9);
    add_student("Charlie", 19, 2.8);
    
    // Search for a student by name
    bool found = search_student("Bob");
    if (found) {
        printf("Student found.\n");
    } else {
        printf("Student not found.\n");
    }
    
    return 0;
}