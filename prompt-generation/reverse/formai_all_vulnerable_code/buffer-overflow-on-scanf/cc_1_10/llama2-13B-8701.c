//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 20
#define MAX_AGE 100

// Structure to hold student information
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} student_t;

// Array to store student information
student_t students[MAX_RECORDS];

// Function to read student information from database
void read_students(void) {
    int i;
    for (i = 0; i < MAX_RECORDS; i++) {
        printf("Enter name: ");
        scanf("%19s", students[i].name);
        printf("Enter age: ");
        scanf("%d", &students[i].age);
    }
}

// Function to write student information to database
void write_students(void) {
    int i;
    for (i = 0; i < MAX_RECORDS; i++) {
        printf("%s %d\n", students[i].name, students[i].age);
    }
}

// Function to simulate a query to find all students over 18
void find_students_over_18(void) {
    int i;
    for (i = 0; i < MAX_RECORDS; i++) {
        if (students[i].age > 18) {
            printf("%s %d\n", students[i].name, students[i].age);
        }
    }
}

int main(void) {
    srand(time(NULL));

    // Initialize student information
    for (int i = 0; i < MAX_RECORDS; i++) {
        students[i].name[0] = '\0';
        students[i].age = rand() % MAX_AGE + 1;
    }

    // Read student information from database
    read_students();

    // Write student information to database
    write_students();

    // Simulate a query to find all students over 18
    find_students_over_18();

    return 0;
}