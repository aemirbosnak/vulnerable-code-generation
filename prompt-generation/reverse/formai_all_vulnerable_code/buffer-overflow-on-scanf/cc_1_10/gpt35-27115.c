//FormAI DATASET v1.0 Category: Database simulation ; Style: futuristic
#include <stdio.h>
#include <string.h>

// Define a struct to hold our data
struct Record {
    char name[100];
    int age;
    float salary;
};

// Define an array of Records and an array size
struct Record db[100];
int size = 0;

// Function to add a Record to the database
void add_record() {
    printf("Enter name: ");
    scanf("%s", db[size].name);
    printf("Enter age: ");
    scanf("%d", &db[size].age);
    printf("Enter salary: ");
    scanf("%f", &db[size].salary);
    size++;
    printf("Record added.\n");
}

// Function to print the database
void print_database() {
    printf("Name\tAge\tSalary\n");
    for (int i=0; i<size; i++) {
        printf("%s\t%d\t%.2f\n", db[i].name, db[i].age, db[i].salary);
    }
}

// Function to search for a Record by name
void search_record() {
    char name[100];
    printf("Enter name to search: ");
    scanf("%s", name);
    for (int i=0; i<size; i++) {
        if (strcmp(name, db[i].name) == 0) {
            printf("Name\tAge\tSalary\n");
            printf("%s\t%d\t%.2f\n", db[i].name, db[i].age, db[i].salary);
            return;
        }
    }
    printf("Record not found.\n");
}

// Main function
int main() {
    int choice;
    while (1) {
        printf("1. Add record\n");
        printf("2. Print database\n");
        printf("3. Search record\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_record();
                break;
            case 2:
                print_database();
                break;
            case 3:
                search_record();
                break;
            case 4:
                return 0;
        }
    }
}