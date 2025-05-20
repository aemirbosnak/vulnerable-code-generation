//Falcon-180B DATASET v1.0 Category: File handling ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_FILE_NAME_LENGTH 256

typedef struct {
    char *name;
    int age;
} Person;

int main() {
    FILE *file = NULL;
    char file_name[MAX_FILE_NAME_LENGTH] = "data.txt";
    char line[MAX_LINE_LENGTH];
    int num_persons = 0;
    Person persons[100];

    file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", file_name);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *name = strtok(line, ",");
        int age = atoi(strtok(NULL, ","));

        if (num_persons >= 100) {
            printf("Error: Reached maximum number of persons (100)\n");
            exit(1);
        }

        persons[num_persons].name = malloc(strlen(name) + 1);
        strcpy(persons[num_persons].name, name);
        persons[num_persons].age = age;
        num_persons++;
    }

    fclose(file);

    printf("Number of persons: %d\n", num_persons);
    for (int i = 0; i < num_persons; i++) {
        printf("Name: %s, Age: %d\n", persons[i].name, persons[i].age);
    }

    for (int i = 0; i < num_persons; i++) {
        free(persons[i].name);
    }

    return 0;
}