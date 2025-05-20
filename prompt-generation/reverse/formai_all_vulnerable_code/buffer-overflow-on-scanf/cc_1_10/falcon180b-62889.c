//Falcon-180B DATASET v1.0 Category: File handling ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char name[MAX_LINE_SIZE];
    int age;
    char address[MAX_LINE_SIZE];
} Person;

int main() {
    FILE *file;
    char filename[MAX_LINE_SIZE];
    char line[MAX_LINE_SIZE];
    char delimiter = ',';
    Person person;
    int count = 0;

    printf("Enter the name of the input file: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        count++;
        if (count == 1) {
            // Skip header row
            continue;
        }

        person.name[0] = '\0';
        person.age = 0;
        person.address[0] = '\0';

        char *token = strtok(line, &delimiter);
        while (token!= NULL) {
            if (count == 1) {
                // Skip header row
                continue;
            }

            if (strcmp(token, "name") == 0) {
                strcpy(person.name, strtok(NULL, &delimiter));
            } else if (strcmp(token, "age") == 0) {
                person.age = atoi(strtok(NULL, &delimiter));
            } else if (strcmp(token, "address") == 0) {
                strcpy(person.address, strtok(NULL, &delimiter));
            }

            token = strtok(NULL, &delimiter);
        }

        printf("Name: %s\n", person.name);
        printf("Age: %d\n", person.age);
        printf("Address: %s\n", person.address);
        printf("\n");
    }

    fclose(file);

    return 0;
}