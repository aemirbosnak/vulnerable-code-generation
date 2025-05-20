//FormAI DATASET v1.0 Category: Database Indexing System ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_TABLE_SIZE 1000
#define MAX_NAME_LENGTH 20

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int age;
} Person;

typedef struct {
    int key;
    int index;
} Index;

Index* table[MAX_TABLE_SIZE];
Person* data[MAX_TABLE_SIZE];
int num_records = 0;

void insert(Person* person);
void search(int key);
void print();

int main() {
    int choice, key;
    Person* person;

    while (1) {
        printf("\nMenu\n1. Insert record\n2. Search record\n3. Print table\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:     // Insert
                person = (Person*) malloc(sizeof(Person));
                person->id = ++num_records;

                printf("Enter name: ");
                scanf("%s", person->name);

                printf("Enter age: ");
                scanf("%d", &(person->age));

                insert(person);
                printf("\nRecord with id %d inserted successfully!\n", person->id);
                break;

            case 2:     // Search
                printf("Enter id to search: ");
                scanf("%d", &key);

                search(key);
                break;

            case 3:     // Print
                print();
                break;

            case 4:     // Exit
                printf("\nExiting...\n");
                exit(0);
                break;

            default:    // Invalid choice
                printf("\nInvalid choice!");
        }
    }

    return 0;
}

void insert(Person* person) {
    // Create index
    Index* index = (Index*) malloc(sizeof(Index));
    index->key = person->id;
    index->index = num_records - 1;

    // Insert index into table
    table[num_records - 1] = index;
    data[num_records - 1] = person;
}

void search(int key) {
    // Linear search through the table for index with matching key
    Index* index = NULL;
    int i;
    for (i = 0; i < num_records; i++) {
        if (table[i]->key == key) {
            index = table[i];
            break;
        }
    }

    if (index == NULL) {
        printf("\nRecord with id %d not found\n", key);
        return;
    }

    // Print matching record
    Person* person = data[index->index];
    printf("\n%d. %s, %d years old\n", person->id, person->name, person->age);
}

void print() {
    if (num_records == 0) {
        printf("\nNo records to display\n");
        return;
    }

    printf("\nID\tName\t\tAge\n");

    int i;
    for (i = 0; i < num_records; i++) {
        Person* person = data[table[i]->index];
        printf("%d\t%-10s\t%d\n", person->id, person->name, person->age);
    }
}