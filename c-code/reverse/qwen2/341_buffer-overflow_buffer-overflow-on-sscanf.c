#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define FIELD_SIZE 20

typedef struct {
    int id;
    char name[FIELD_SIZE];
    int age;
    char profession[FIELD_SIZE];
} Record;

Record records[MAX_RECORDS];
int record_count = 0;

void add_record(int id, const char* name, int age, const char* profession) {
    if (record_count >= MAX_RECORDS) return;
    records[record_count].id = id;
    strncpy(records[record_count].name, name, FIELD_SIZE);
    records[record_count].age = age;
    strncpy(records[record_count].profession, profession, FIELD_SIZE);
    record_count++;
}

void search_records(const char* query) {
    char field[FIELD_SIZE], value[FIELD_SIZE];
    sscanf(query, "%[^=]=%s", field, value);

    for (int i = 0; i < record_count; i++) {
        if ((strcmp(field, "id") == 0 && records[i].id == atoi(value)) ||
            (strcmp(field, "name") == 0 && strcmp(records[i].name, value) == 0) ||
            (strcmp(field, "age") == 0 && records[i].age == atoi(value)) ||
            (strcmp(field, "profession") == 0 && strcmp(records[i].profession, value) == 0)) {
            printf("ID: %d, Name: %s, Age: %d, Profession: %s\n",
                   records[i].id, records[i].name, records[i].age, records[i].profession);
        }
    }
}

int main() {
    add_record(1, "Alice", 30, "Engineer");
    add_record(2, "Bob", 25, "Doctor");
    add_record(3, "Charlie", 35, "Artist");

    search_records("name=Alice");
    search_records("age=35");

    return 0;
}
