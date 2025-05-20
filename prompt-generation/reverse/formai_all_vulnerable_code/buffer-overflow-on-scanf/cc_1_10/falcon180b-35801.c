//Falcon-180B DATASET v1.0 Category: File handling ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char name[50];
    char address[100];
    int age;
} Person;

void read_file(FILE *fp, Person *person) {
    char line[100];
    int count = 0;
    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (count == 0) {
            strcpy(person->name, line);
        } else if (count == 1) {
            strcpy(person->address, line);
        } else {
            person->age = atoi(line);
            break;
        }
        count++;
    }
}

void write_file(FILE *fp, Person *person) {
    fprintf(fp, "%s\n", person->name);
    fprintf(fp, "%s\n", person->address);
    fprintf(fp, "%d\n", person->age);
}

int main() {
    FILE *fp;
    char filename[50];
    Person person;

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File does not exist.\n");
        exit(0);
    }

    read_file(fp, &person);

    printf("Name: %s\n", person.name);
    printf("Address: %s\n", person.address);
    printf("Age: %d\n", person.age);

    fclose(fp);

    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("File could not be opened for writing.\n");
        exit(0);
    }

    write_file(fp, &person);

    fclose(fp);

    printf("File updated successfully.\n");

    return 0;
}