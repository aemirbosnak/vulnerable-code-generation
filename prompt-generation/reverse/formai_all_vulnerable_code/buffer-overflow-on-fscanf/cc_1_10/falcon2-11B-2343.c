//Falcon2-11B DATASET v1.0 Category: Database querying ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Student {
    char name[50];
    int age;
    float GPA;
};

int main() {
    // Creating database
    FILE *db = fopen("students.db", "w");
    
    // Creating 10 students
    struct Student students[10];
    
    // Generating random names and ages
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        sprintf(students[i].name, "Student %d", i + 1);
        students[i].age = rand() % 20 + 18;
        students[i].GPA = rand() % 4 + 1;
    }
    
    // Writing data to database
    for (int i = 0; i < 10; i++) {
        fprintf(db, "%s,%d,%f\n", students[i].name, students[i].age, students[i].GPA);
    }
    
    // Closing database
    fclose(db);
    
    // Displaying data
    struct Student students2[10];
    fopen("students.db", "r");
    for (int i = 0; i < 10; i++) {
        fscanf(db, "%s,%d,%f", students2[i].name, &students2[i].age, &students2[i].GPA);
    }
    
    // Searching for a specific student
    for (int i = 0; i < 10; i++) {
        if (strcmp(students[i].name, "Student 1") == 0) {
            printf("Student 1: Name - %s, Age - %d, GPA - %f\n", students[i].name, students[i].age, students[i].GPA);
        }
    }
    
    return 0;
}