//Falcon-180B DATASET v1.0 Category: File handling ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUM_ENTRIES 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} Person;

int compare_names(const void* a, const void* b) {
    const Person* p1 = a;
    const Person* p2 = b;
    return strcmp(p1->name, p2->name);
}

int compare_ages(const void* a, const void* b) {
    const Person* p1 = a;
    const Person* p2 = b;
    return p1->age - p2->age;
}

void read_data_from_file(FILE* file, Person* people, int* num_entries) {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        Person person;
        sscanf(line, "%s %d", person.name, &person.age);
        strcpy(people[*num_entries].name, person.name);
        people[*num_entries].age = person.age;
        (*num_entries)++;
    }
}

void write_data_to_file(FILE* file, const Person* people, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        fprintf(file, "%s %d\n", people[i].name, people[i].age);
    }
}

void sort_data(Person* people, int num_entries, int (*compare_func)(const void*, const void*)) {
    qsort(people, num_entries, sizeof(Person), compare_func);
}

int main() {
    FILE* input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    Person people[MAX_NUM_ENTRIES];
    int num_entries = 0;

    read_data_from_file(input_file, people, &num_entries);

    if (num_entries == 0) {
        printf("Error: No data found in input file.\n");
        return 1;
    }

    sort_data(people, num_entries, compare_names);

    FILE* output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        return 1;
    }

    write_data_to_file(output_file, people, num_entries);

    fclose(input_file);
    fclose(output_file);

    return 0;
}