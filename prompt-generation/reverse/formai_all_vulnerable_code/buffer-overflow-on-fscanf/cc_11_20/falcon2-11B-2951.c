//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char name[50];
    int id;
};

struct student students[10]; // Array of 10 student records

int main() {
    int n, i;
    
    // Create database
    FILE* db = fopen("students.db", "w");
    
    // Insert student records
    for(i=0; i<10; i++) {
        if (fscanf(db, "%s %d\n", students[i].name, &students[i].id) == 2) {
            printf("Record %d: %s, id: %d\n", i+1, students[i].name, students[i].id);
        } else {
            printf("Error reading record %d\n", i+1);
        }
    }
    
    // Retrieve student records
    for(i=0; i<10; i++) {
        if (fscanf(db, "%s %d\n", students[i].name, &students[i].id) == 2) {
            printf("Record %d: %s, id: %d\n", i+1, students[i].name, students[i].id);
        } else {
            printf("Error reading record %d\n", i+1);
        }
    }
    
    // Update student record
    students[2].id = 123;
    
    // Retrieve updated student record
    for(i=0; i<10; i++) {
        if (strcmp(students[i].name, "John") == 0 && students[i].id == 123) {
            printf("Record %d: %s, id: %d\n", i+1, students[i].name, students[i].id);
        } else {
            printf("Error reading record %d\n", i+1);
        }
    }
    
    // Delete student record
    students[2].id = -1;
    
    // Retrieve deleted student record
    for(i=0; i<10; i++) {
        if (strcmp(students[i].name, "John") == 0 && students[i].id == 123) {
            printf("Record %d: %s, id: %d\n", i+1, students[i].name, students[i].id);
        } else {
            printf("Error reading record %d\n", i+1);
        }
    }
    
    // Close database
    fclose(db);
    
    return 0;
}