//FormAI DATASET v1.0 Category: Database simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct to hold the data records
typedef struct {
    int id;
    char name[50];
    int age;
    float salary;
} Record;

//Function to insert record in the database
void insertRecord(FILE *db, Record r) {
    fwrite(&r, sizeof(Record), 1, db);
    printf("Record added successfully!\n");
}

//Function to search record from the database
void searchRecord(FILE *db, int id) {
    Record r;
    int found = 0;
    rewind(db);
    while(fread(&r, sizeof(Record), 1, db)) {
        if(r.id == id) {
            found = 1;
            printf("ID: %d\nName: %s\nAge: %d\nSalary: %.2f\n", r.id, r.name, r.age, r.salary);
            break;
        }
    }
    if(!found) {
        printf("Record not found!\n");
    }
}

//Function to delete record from the database
void deleteRecord(FILE *db, int id) {
    Record r;
    FILE *tmp;
    tmp = fopen("temp", "wb+");
    rewind(db);
    while(fread(&r, sizeof(Record), 1, db)) {
        if(r.id != id) {
            fwrite(&r, sizeof(Record), 1, tmp);
        }
    }
    fclose(db);
    fclose(tmp);
    remove("data");
    rename("temp", "data");
    printf("Record deleted successfully!\n");
}

//Function to display all records from the database
void displayRecords(FILE *db) {
    Record r;
    rewind(db);
    printf("ID\tName\t\tAge\tSalary\n");
    while(fread(&r, sizeof(Record), 1, db)) {
        printf("%d\t%s\t\t%d\t%.2f\n", r.id, r.name, r.age, r.salary);
    }
}

int main() {
    FILE *db;
    Record r;
    int choice, id;
    db = fopen("data", "ab+");
    if(db == NULL) {
        printf("Couldn't load database!\n");
        return 1;
    }
    do {
        printf("\n--Menu--\n");
        printf("1. Add Record\n");
        printf("2. Search Record\n");
        printf("3. Delete Record\n");
        printf("4. Display Records\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &r.id);
                printf("Enter Name: ");
                scanf("%s", r.name);
                printf("Enter Age: ");
                scanf("%d", &r.age);
                printf("Enter Salary: ");
                scanf("%f", &r.salary);
                insertRecord(db, r);
                break;
            case 2:
                printf("Enter ID: ");
                scanf("%d", &id);
                searchRecord(db, id);
                break;
            case 3:
                printf("Enter ID: ");
                scanf("%d", &id);
                deleteRecord(db, id);
                break;
            case 4:
                displayRecords(db);
                break;
            case 5:
                printf("Exiting!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while(choice != 5);
    fclose(db);
    return 0;
}