//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    float height;
    char gender;
} Person;

void readFile(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file: %s\n", filename);
        return;
    }

    Person person;
    int count = 0;

    while (fscanf(file, "%[^,],%d,%f,%c\n", person.name, &person.age, &person.height, &person.gender) != EOF) {
        printf("Name: %s, Age: %d, Height: %.2f, Gender: %c\n", person.name, person.age, person.height, person.gender);
        count++;
    }

    fclose(file);
    printf("Total number of people read: %d\n", count);
}

void writeFile(char *filename, Person people[], int size) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Unable to open file: %s\n", filename);
        return;
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%s,%d,%.2f,%c\n", people[i].name, people[i].age, people[i].height, people[i].gender);
    }

    fclose(file);
    printf("Data written to file: %s\n", filename);
}

int main() {
    const int size = 3;
    Person people[size];

    strcpy(people[0].name, "John Doe");
    people[0].age = 25;
    people[0].height = 1.78;
    people[0].gender = 'M';

    strcpy(people[1].name, "Jane Doe");
    people[1].age = 22;
    people[1].height = 1.65;
    people[1].gender = 'F';

    strcpy(people[2].name, "Bob Smith");
    people[2].age = 35;
    people[2].height = 1.85;
    people[2].gender = 'M';

    char filename[] = "people.txt";
    writeFile(filename, people, size);
    readFile(filename);

    return 0;
}