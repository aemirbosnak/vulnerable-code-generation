//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define MAX_NAME 50

typedef struct {
    char name[MAX_NAME];
    int age;
} Person;

void read_data(Person* data, int size) {
    FILE* file = fopen("data.txt", "r");

    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        fscanf(file, "%s %d", data[i].name, &data[i].age);
    }

    fclose(file);
}

void write_data(Person* data, int size) {
    FILE* file = fopen("data.txt", "w");

    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%s %d\n", data[i].name, data[i].age);
    }

    fclose(file);
}

void search_data(Person* data, int size, char* name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(data[i].name, name) == 0) {
            printf("Name: %s\nAge: %d\n", data[i].name, data[i].age);
            return;
        }
    }

    printf("No results found.\n");
}

int main() {
    Person data[MAX_SIZE];
    int size = 0;

    read_data(data, MAX_SIZE);
    size = sizeof(data) / sizeof(data[0]);

    char name[MAX_NAME];

    while (1) {
        printf("Enter name to search for: ");
        scanf("%s", name);

        search_data(data, size, name);
    }

    return 0;
}