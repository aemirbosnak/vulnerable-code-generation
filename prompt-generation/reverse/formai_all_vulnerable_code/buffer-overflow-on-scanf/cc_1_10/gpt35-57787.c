//FormAI DATASET v1.0 Category: Database simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct Record {
    int id;
    char name[50];
    int age;
} Record;

Record* database[MAX_RECORDS]; // an array of pointers to records
int num_records = 0; // current number of records in the database

// function prototypes
void print_records();
void add_record();
void delete_record();
void search_record();
void save_records();

int main() {
    int choice;
    while(1) {
        printf("\n1. Add record\n2. Delete record\n3. Search record\n4. Print records\n5. Save records\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_record();
                break;
            case 2:
                delete_record();
                break;
            case 3:
                search_record();
                break;
            case 4:
                print_records();
                break;
            case 5:
                save_records();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

// function to print all the records in the database
void print_records() {
    printf("ID\tName\t\tAge\n");
    printf("---------------------------------------\n");
    for(int i = 0; i < num_records; i++) {
        printf("%d\t%s\t\t%d\n", database[i]->id, database[i]->name, database[i]->age);
    }
}

// function to add a new record to the database
void add_record() {
    Record *new_record = malloc(sizeof(Record));
    printf("Enter ID: ");
    scanf("%d", &new_record->id);
    printf("Enter name: ");
    scanf("%s", new_record->name);
    printf("Enter age: ");
    scanf("%d", &new_record->age);
    database[num_records++] = new_record;
    printf("Record added successfully!\n");
}

// function to delete a record from the database
void delete_record() {
    int id;
    printf("Enter ID of record to delete: ");
    scanf("%d", &id);
    int index = -1;
    for(int i = 0; i < num_records; i++) {
        if(database[i]->id == id) {
            index = i;
            break;
        }
    }
    if(index == -1) {
        printf("Record not found!\n");
        return;
    }
    free(database[index]);
    for(int i = index+1; i < num_records; i++) {
        database[i-1] = database[i];
    }
    num_records--;
    printf("Record deleted successfully!\n");
}

// function to search for a record in the database
void search_record() {
    int id;
    printf("Enter ID of record to search: ");
    scanf("%d", &id);
    for(int i = 0; i < num_records; i++) {
        if(database[i]->id == id) {
            printf("ID\tName\t\tAge\n");
            printf("---------------------------------------\n");
            printf("%d\t%s\t\t%d\n", database[i]->id, database[i]->name, database[i]->age);
            return;
        }
    }
    printf("Record not found!\n");
}

// function to save all the records to a file
void save_records() {
    char filename[50];
    printf("Enter filename to save records to: ");
    scanf("%s", filename);
    FILE *file = fopen(filename, "w");
    for(int i = 0; i < num_records; i++) {
        fprintf(file, "%d %s %d\n", database[i]->id, database[i]->name, database[i]->age);
    }
    fclose(file);
    printf("Records saved successfully!\n");
}