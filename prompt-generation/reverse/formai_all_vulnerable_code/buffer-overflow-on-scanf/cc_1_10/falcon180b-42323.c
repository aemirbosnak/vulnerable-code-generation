//Falcon-180B DATASET v1.0 Category: File handling ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000

typedef struct {
    char name[MAX_LINE_SIZE];
    int age;
} Person;

FILE *file = NULL;
Person people[100];
int num_people = 0;

void read_file(char *filename) {
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        Person *person = &people[num_people++];
        strcpy(person->name, line);
        sscanf(line, "%s %d", person->name, &person->age);
    }

    fclose(file);
}

void write_file(char *filename) {
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    for (int i = 0; i < num_people; i++) {
        fprintf(file, "%s %d\n", people[i].name, people[i].age);
    }

    fclose(file);
}

void sort_people(int (*compare)(const void *, const void *)) {
    qsort(people, num_people, sizeof(Person), compare);
}

int compare_age(const void *a, const void *b) {
    const Person *person_a = a;
    const Person *person_b = b;

    return person_a->age - person_b->age;
}

int main() {
    char input_filename[MAX_LINE_SIZE];
    printf("Enter input filename: ");
    scanf("%s", input_filename);

    read_file(input_filename);

    char output_filename[MAX_LINE_SIZE];
    printf("Enter output filename: ");
    scanf("%s", output_filename);

    write_file(output_filename);

    printf("Sorted by age:\n");
    sort_people(compare_age);
    for (int i = 0; i < num_people; i++) {
        printf("%s %d\n", people[i].name, people[i].age);
    }

    return 0;
}