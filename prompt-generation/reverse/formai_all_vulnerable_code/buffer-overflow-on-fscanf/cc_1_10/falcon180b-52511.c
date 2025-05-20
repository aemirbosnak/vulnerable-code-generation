//Falcon-180B DATASET v1.0 Category: File handling ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int age;
    char address[MAX_SIZE];
} Person;

void read_data(FILE *fp, Person *person) {
    fscanf(fp, "%s %d %s", person->name, &person->age, person->address);
}

void write_data(FILE *fp, Person person) {
    fprintf(fp, "%s %d %s\n", person.name, person.age, person.address);
}

int main() {
    FILE *fp;
    Person person;

    // Open the file for reading
    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("Error opening file for reading\n");
        exit(1);
    }

    // Read data from the file
    while (fscanf(fp, "%s %d %s", person.name, &person.age, person.address)!= EOF) {
        // Do something with the data
        printf("Name: %s\nAge: %d\nAddress: %s\n", person.name, person.age, person.address);
    }

    // Close the file
    fclose(fp);

    // Open the file for writing
    fp = fopen("data.txt", "w");
    if (fp == NULL) {
        printf("Error opening file for writing\n");
        exit(1);
    }

    // Write data to the file
    write_data(fp, person);

    // Close the file
    fclose(fp);

    return 0;
}