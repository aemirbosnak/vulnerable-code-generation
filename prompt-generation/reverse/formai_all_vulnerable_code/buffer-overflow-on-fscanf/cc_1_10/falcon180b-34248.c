//Falcon-180B DATASET v1.0 Category: File handling ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
} Person;

void read_file(char* filename, Person* people, int* num_people) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    Person temp_person;
    int num_read = 0;
    while (fscanf(file, "%s %d", temp_person.name, &temp_person.age)!= EOF) {
        people[num_read] = temp_person;
        num_read++;
    }

    *num_people = num_read;
    fclose(file);
}

void write_file(char* filename, Person* people, int num_people) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    for (int i = 0; i < num_people; i++) {
        fprintf(file, "%s %d\n", people[i].name, people[i].age);
    }

    fclose(file);
}

void sort_people(Person* people, int num_people) {
    for (int i = 0; i < num_people-1; i++) {
        for (int j = i+1; j < num_people; j++) {
            if (people[i].age > people[j].age) {
                Person temp_person = people[i];
                people[i] = people[j];
                people[j] = temp_person;
            }
        }
    }
}

int main() {
    Person people[100];
    int num_people = 0;

    read_file("people.txt", people, &num_people);
    printf("Number of people read: %d\n", num_people);

    sort_people(people, num_people);

    write_file("sorted_people.txt", people, num_people);
    printf("People sorted and written to file sorted_people.txt\n");

    return 0;
}