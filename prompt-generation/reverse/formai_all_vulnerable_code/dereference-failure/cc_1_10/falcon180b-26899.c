//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_FIELD_SIZE 50
#define MAX_TABLE_SIZE 20

typedef struct {
    char name[MAX_FIELD_SIZE];
    int age;
    float salary;
} Record;

typedef struct {
    char table_name[MAX_TABLE_SIZE];
    int num_records;
    Record records[MAX_RECORDS];
} Table;

Table *create_table(char *table_name) {
    Table *table = (Table *) malloc(sizeof(Table));
    strcpy(table->table_name, table_name);
    table->num_records = 0;
    return table;
}

void add_record(Table *table, Record record) {
    if (table->num_records >= MAX_RECORDS) {
        printf("Error: Table is full.\n");
        return;
    }
    strcpy(table->records[table->num_records].name, record.name);
    table->records[table->num_records].age = record.age;
    table->records[table->num_records].salary = record.salary;
    table->num_records++;
}

void display_table(Table *table) {
    printf("Table: %s\n", table->table_name);
    printf("Number of records: %d\n", table->num_records);
    for (int i = 0; i < table->num_records; i++) {
        printf("Record %d:\n", i + 1);
        printf("Name: %s\n", table->records[i].name);
        printf("Age: %d\n", table->records[i].age);
        printf("Salary: $%.2f\n\n", table->records[i].salary);
    }
}

int main() {
    Table *employees = create_table("Employees");
    Record employee1 = {"John Doe", 30, 50000};
    Record employee2 = {"Jane Smith", 25, 45000};
    Record employee3 = {"Bob Johnson", 40, 60000};
    add_record(employees, employee1);
    add_record(employees, employee2);
    add_record(employees, employee3);
    display_table(employees);
    return 0;
}