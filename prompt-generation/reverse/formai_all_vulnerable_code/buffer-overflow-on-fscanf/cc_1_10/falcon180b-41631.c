//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[20];
    int age;
} person;

void read_file(person *people, FILE *file) {
    int count = 0;
    while (fscanf(file, "%d %s %d\n", &people[count].id, people[count].name, &people[count].age)!= EOF) {
        count++;
    }
}

void write_file(person *people, FILE *file) {
    int count = 0;
    while (count < 10) {
        fprintf(file, "%d %s %d\n", people[count].id, people[count].name, people[count].age);
        count++;
    }
}

int main() {
    person people[10];
    FILE *file;

    // Read data from file
    file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }
    read_file(people, file);
    fclose(file);

    // Modify data
    people[0].id = 100;
    strcpy(people[0].name, "John");
    people[0].age = 25;

    // Write data to file
    file = fopen("data.txt", "w");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }
    write_file(people, file);
    fclose(file);

    return 0;
}