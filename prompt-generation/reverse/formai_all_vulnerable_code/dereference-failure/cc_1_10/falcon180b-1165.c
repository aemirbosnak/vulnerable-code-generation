//Falcon-180B DATASET v1.0 Category: Database querying ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a record
typedef struct {
    char name[50];
    int age;
    float salary;
} Record;

// Define the structure of a table
typedef struct {
    Record *data;
    int num_records;
    int num_fields;
} Table;

// Function to create a new table
Table *create_table(int num_fields, int num_records) {
    Table *table = malloc(sizeof(Table));
    table->data = malloc(num_records * sizeof(Record));
    table->num_records = num_records;
    table->num_fields = num_fields;
    for (int i = 0; i < num_records; i++) {
        for (int j = 0; j < num_fields; j++) {
            table->data[i].name[j] = '\0';
            table->data[i].age = 0;
            table->data[i].salary = 0;
        }
    }
    return table;
}

// Function to insert a record into a table
void insert_record(Table *table, char *name, int age, float salary) {
    Record *record = table->data;
    for (int i = 0; i < table->num_records; i++) {
        if (record[i].name[0] == '\0') {
            strcpy(record[i].name, name);
            record[i].age = age;
            record[i].salary = salary;
            break;
        }
    }
}

// Function to print a table
void print_table(Table *table) {
    Record *record = table->data;
    printf("Name\tAge\tSalary\n");
    for (int i = 0; i < table->num_records; i++) {
        if (record[i].name[0]!= '\0') {
            printf("%s\t%d\t%.2f\n", record[i].name, record[i].age, record[i].salary);
        }
    }
}

// Function to retrieve records based on a condition
void select_records(Table *table, char *condition) {
    Record *record = table->data;
    printf("Selected records:\n");
    for (int i = 0; i < table->num_records; i++) {
        if (record[i].name[0]!= '\0' && strcmp(condition, record[i].name) == 0) {
            printf("%s\t%d\t%.2f\n", record[i].name, record[i].age, record[i].salary);
        }
    }
}

int main() {
    Table *table = create_table(3, 5);
    insert_record(table, "John", 25, 50000);
    insert_record(table, "Jane", 30, 60000);
    insert_record(table, "Bob", 20, 40000);
    insert_record(table, "Alice", 28, 55000);
    insert_record(table, "Charlie", 22, 45000);
    print_table(table);
    select_records(table, "John");
    return 0;
}