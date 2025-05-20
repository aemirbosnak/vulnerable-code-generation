//FormAI DATASET v1.0 Category: Database simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DATABASE_SIZE 1000
#define MAX_NAME_LENGTH 50
#define MAX_ID_LENGTH 10

// Struct representing a record in the database
typedef struct Record {
    char name[MAX_NAME_LENGTH];
    char id[MAX_ID_LENGTH];
    int age;
    int salary;
} Record;

// Function to generate a new record with random data
Record generate_record() {
    Record r;
    int name_length = rand() % MAX_NAME_LENGTH + 1;
    for (int i = 0; i < name_length; i++) {
        r.name[i] = 'A' + rand() % 26;
    }
    r.name[name_length] = '\0';
    int id_length = rand() % MAX_ID_LENGTH + 1;
    for (int i = 0; i < id_length; i++) {
        r.id[i] = '0' + rand() % 10;
    }
    r.id[id_length] = '\0';
    r.age = rand() % 101;
    r.salary = rand() % 100001;
    return r;
}

int main() {
    srand(time(NULL));
    Record database[DATABASE_SIZE];
    for (int i = 0; i < DATABASE_SIZE; i++) {
        database[i] = generate_record();
    }
    // Calculate some statistics
    int total_salary = 0;
    int max_salary = 0;
    int min_salary = 100000;
    int oldest_age = 0;
    int youngest_age = 100;
    for (int i = 0; i < DATABASE_SIZE; i++) {
        total_salary += database[i].salary;
        if (database[i].salary > max_salary) {
            max_salary = database[i].salary;
        }
        if (database[i].salary < min_salary) {
            min_salary = database[i].salary;
        }
        if (database[i].age > oldest_age) {
            oldest_age = database[i].age;
        }
        if (database[i].age < youngest_age) {
            youngest_age = database[i].age;
        }
    }
    double average_salary = (double) total_salary / DATABASE_SIZE;
    printf("Database statistics:\n");
    printf("Total salary: %d\n", total_salary);
    printf("Average salary: %.2lf\n", average_salary);
    printf("Maximum salary: %d\n", max_salary);
    printf("Minimum salary: %d\n", min_salary);
    printf("Oldest age: %d\n", oldest_age);
    printf("Youngest age: %d\n", youngest_age);
    return 0;
}