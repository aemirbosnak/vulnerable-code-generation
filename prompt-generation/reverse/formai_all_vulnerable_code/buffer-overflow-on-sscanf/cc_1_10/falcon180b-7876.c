//Falcon-180B DATASET v1.0 Category: File handling ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

struct person {
    char name[MAX_LINE_LENGTH];
    int age;
};

void read_file(const char *filename, struct person *people, int count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    int line_count = 0;
    while (fgets(people[line_count].name, MAX_LINE_LENGTH, file)!= NULL) {
        line_count++;
        if (line_count >= count) {
            printf("Error: Too many lines in file '%s'\n", filename);
            exit(1);
        }
    }

    fclose(file);
}

void write_file(const char *filename, const struct person *people, int count) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error: Could not open file '%s' for writing\n", filename);
        exit(1);
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %d\n", people[i].name, people[i].age);
    }

    fclose(file);
}

int main() {
    struct person people[10];
    int count = 0;

    printf("Enter the name and age of each person (enter 'done' when finished):\n");
    while (count < 10) {
        char input[MAX_LINE_LENGTH];
        if (fgets(input, MAX_LINE_LENGTH, stdin) == NULL) {
            printf("Error: Could not read input\n");
            exit(1);
        }

        if (strcmp(input, "done") == 0) {
            break;
        }

        int age;
        if (sscanf(input, "%s %d", people[count].name, &age)!= 2) {
            printf("Error: Invalid input\n");
            exit(1);
        }

        count++;
    }

    if (count == 0) {
        printf("Error: No people entered\n");
        exit(1);
    }

    read_file("people.txt", people, count);

    write_file("ages.txt", people, count);

    return 0;
}