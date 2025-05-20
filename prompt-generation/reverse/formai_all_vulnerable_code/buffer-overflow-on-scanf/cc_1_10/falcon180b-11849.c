//Falcon-180B DATASET v1.0 Category: Database querying ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

typedef struct {
    char *name;
    int age;
} Person;

typedef struct {
    char *name;
    int age;
    float salary;
} Employee;

void create_table(char *table_name) {
    printf("CREATE TABLE %s (\n", table_name);
    printf("    id INT NOT NULL AUTO_INCREMENT,\n");
    printf("    name VARCHAR(255) NOT NULL,\n");
    printf("    age INT NOT NULL,\n");
    printf("    salary FLOAT NOT NULL,\n");
    printf("    PRIMARY KEY (id)\n");
    printf(");\n");
}

void insert_data(char *table_name, Person *data, int num_rows) {
    for (int i = 0; i < num_rows; i++) {
        printf("INSERT INTO %s (name, age, salary) VALUES ('%s', %d, %.2f);\n", table_name, data[i].name, data[i].age, 0);
    }
}

void query_data(char *table_name, int min_age, int max_age) {
    printf("SELECT * FROM %s WHERE age BETWEEN %d AND %d;\n", table_name, min_age, max_age);
}

int main() {
    Person people[MAX_ROWS];
    int num_people = 0;

    while (num_people < MAX_ROWS && scanf("%s %d", people[num_people].name, &people[num_people].age) == 2) {
        num_people++;
    }

    create_table("people");
    insert_data("people", people, num_people);

    query_data("people", 18, 25);

    return 0;
}