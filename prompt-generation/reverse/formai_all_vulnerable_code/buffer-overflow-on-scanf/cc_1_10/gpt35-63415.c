//FormAI DATASET v1.0 Category: Database simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_RECORDS 100

// Struct for storing records in the database
struct Record {
    int id;
    char name[50];
    int age;
    float salary;
};

// Global variables for tracking number of records and storing records in memory
int num_records = 0;
struct Record db[MAX_RECORDS];

// Function for adding a record to the database
void add_record() {
    printf("Enter record id: ");
    scanf("%d", &db[num_records].id);
    printf("Enter record name: ");
    scanf("%s", db[num_records].name);
    printf("Enter record age: ");
    scanf("%d", &db[num_records].age);
    printf("Enter record salary: ");
    scanf("%f", &db[num_records].salary);
    num_records++;
    printf("Record added successfully!\n");
}

// Function for searching a record in the database
void find_record() {
    int id;
    printf("Enter record id: ");
    scanf("%d", &id);
    for(int i=0; i<num_records; i++) {
        if(db[i].id == id) {
            printf("Record found!\n");
            printf("id=%d, name=%s, age=%d, salary=%.2f\n", db[i].id, db[i].name, db[i].age, db[i].salary);
            return;
        }
    }
    printf("Record not found!\n");
}

// Function for deleting a record from the database
void delete_record() {
    int id;
    printf("Enter record id: ");
    scanf("%d", &id);
    for(int i=0; i<num_records; i++) {
        if(db[i].id == id) {
            for(int j=i; j<num_records-1; j++) {
                db[j] = db[j+1];
            }
            num_records--;
            printf("Record deleted successfully!\n");
            return;
        }
    }
    printf("Record not found!\n");
}

// Function for displaying all records in the database
void display_all_records() {
    if(num_records == 0) {
        printf("Database is empty!\n");
        return;
    }
    printf("id\tname\tage\tsalary\n");
    for(int i=0; i<num_records; i++) {
        printf("%d\t%s\t%d\t%.2f\n", db[i].id, db[i].name, db[i].age, db[i].salary);
    }
}

// Function for saving records to a file
void save_to_file() {
    FILE *file = fopen("db.txt", "w");
    if(file == NULL) {
        printf("Unable to open file!\n");
        return;
    }
    for(int i=0; i<num_records; i++) {
        fprintf(file, "%d,%s,%d,%f\n", db[i].id, db[i].name, db[i].age, db[i].salary);
    }
    fclose(file);
    printf("Data saved to file successfully!\n");
}

// Function for loading records from a file
void load_from_file() {
    FILE *file = fopen("db.txt", "r");
    if(file == NULL) {
        printf("Unable to open file!\n");
        return;
    }
    char line[100];
    while(fgets(line, 100, file) != NULL) {
        sscanf(line, "%d,%[^,],%d,%f", &db[num_records].id, db[num_records].name, &db[num_records].age, &db[num_records].salary);
        num_records++;
    }
    fclose(file);
    printf("Data loaded from file successfully!\n");
}

int main() {
    int choice;
    while(1) {
        printf("Welcome to the database simulation program!\n");
        printf("1. Add Record\n");
        printf("2. Find Record\n");
        printf("3. Delete Record\n");
        printf("4. Display All Records\n");
        printf("5. Save to File\n");
        printf("6. Load from File\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_record();
                break;
            case 2:
                find_record();
                break;
            case 3:
                delete_record();
                break;
            case 4:
                display_all_records();
                break;
            case 5:
                save_to_file();
                break;
            case 6:
                load_from_file();
                break;
            case 7:
                printf("Exiting program...");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}