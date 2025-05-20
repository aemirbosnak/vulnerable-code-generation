//Code Llama-13B DATASET v1.0 Category: Database simulation ; Style: statistical
/*
 * C Database Simulation Example
 *
 * This program simulates a database with a single table and a single record.
 * The table has 3 columns: id, name, and age.
 *
 * The program prompts the user to enter the number of records to be generated,
 * and then generates a random number of records between 1 and 100.
 * Each record is then generated with a random id, name, and age between 1 and 100.
 *
 * The program then displays the generated records in a table format.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_RECORDS 100

// Struct to represent a record in the database
typedef struct {
    int id;
    char name[50];
    int age;
} Record;

// Function to generate a random number between a min and max value
int rand_between(int min, int max) {
    return min + (rand() % (max - min + 1));
}

// Function to generate a random name
void generate_name(char *name) {
    int i;
    for (i = 0; i < 50; i++) {
        name[i] = rand_between(97, 122);
    }
    name[50] = '\0';
}

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Prompt user for number of records to generate
    int num_records;
    printf("Enter the number of records to generate: ");
    scanf("%d", &num_records);

    // Generate random records
    Record records[num_records];
    for (int i = 0; i < num_records; i++) {
        records[i].id = rand_between(1, MAX_RECORDS);
        generate_name(records[i].name);
        records[i].age = rand_between(1, 100);
    }

    // Display generated records
    printf("Generated records:\n");
    for (int i = 0; i < num_records; i++) {
        printf("%d\t%s\t%d\n", records[i].id, records[i].name, records[i].age);
    }

    return 0;
}