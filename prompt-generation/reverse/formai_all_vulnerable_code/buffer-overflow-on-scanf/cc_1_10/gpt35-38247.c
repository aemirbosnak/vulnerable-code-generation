//FormAI DATASET v1.0 Category: Database simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100 // Maximum number of records that can be stored in the database

typedef struct {
    char name[20];
    int age;
    float height;
    float weight;
} Record;

int num_records = 0; // Keeps track of the number of records currently stored in the database

Record db[MAX_RECORDS]; // The database array

int add_record(char name[], int age, float height, float weight) {
    // Adds a new record to the database
    if (num_records == MAX_RECORDS) {
        printf("Database is full!\n");
        return 0;
    }
    
    Record new_record;
    
    strcpy(new_record.name, name);
    new_record.age = age;
    new_record.height = height;
    new_record.weight = weight;
    
    db[num_records] = new_record;
    num_records++;
    
    return 1;
}

void print_database() {
    // Prints the entire contents of the database
    
    printf("\n-----------------------\n");
    printf("|     DATABASE        |\n");
    printf("-----------------------\n");
    printf("| Name      | Age | Height | Weight |\n");
    printf("|-----------|-----|--------|--------|\n");
    
    for (int i = 0; i < num_records; i++) {
        printf("| %-10s| %-3d |  %-3.1f  |  %-3.1f  |\n", db[i].name, db[i].age, db[i].height, db[i].weight);
    }
    
    printf("-----------------------\n\n");
}

int main() {
    printf("Welcome to the C Database Simulation Example Program!\n");
    printf("------------------------------------------------------\n\n");
    
    // Add some initial records to the database
    add_record("John", 25, 5.9, 170);
    add_record("Mary", 28, 5.4, 130);
    add_record("Peter", 31, 6.1, 200);
    add_record("Jane", 23, 5.7, 150);
    add_record("Bob", 35, 5.11, 180);
    
    printf("Initial Records Added:\n");
    print_database();
    
    // Prompt the user to add a new record
    printf("Would you like to add a new record? (y/n): ");
    char input[10];
    scanf("%s", input);
    
    if (input[0] == 'y') {
        char name[20];
        int age;
        float height, weight;
        
        printf("Enter the new record details:\n");
        printf("Name: ");
        scanf("%s", name);
        printf("Age: ");
        scanf("%d", &age);
        printf("Height: ");
        scanf("%f", &height);
        printf("Weight: ");
        scanf("%f", &weight);
        
        if (add_record(name, age, height, weight)) {
            printf("Record added successfully!\n");
            print_database();
        } else {
            printf("Record could not be added. Sorry!\n");
        }
    } else {
        printf("Okay. Goodbye!\n");
    }
    
    return 0;
}