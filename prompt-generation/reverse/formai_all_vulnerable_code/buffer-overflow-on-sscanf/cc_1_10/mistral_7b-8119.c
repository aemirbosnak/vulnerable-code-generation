//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define DATA_FILE "input.txt"
#define BINARY_FILE "output.bin"

typedef struct {
    char name[50];
    int age;
    float weight;
} Person;

void read_text_file(FILE *fp) {
    char line[MAX_LINE_LENGTH];
    Person person;
    int line_number = 1;

    fp = fopen(DATA_FILE, "r");

    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        sscanf(line, "%s %d %f", person.name, &person.age, &person.weight);

        // Data validation
        if (strlen(person.name) > 49 || person.age < 0 || person.weight < 0) {
            printf("Invalid data on line %d: %s\n", line_number, line);
            continue;
        }

        // Write data to binary file
        FILE *binary_fp = fopen(BINARY_FILE, "ab");
        fwrite(&person, sizeof(Person), 1, binary_fp);
        fclose(binary_fp);

        line_number++;
    }

    fclose(fp);
}

int main() {
    read_text_file(stdin); // For testing purposes only, use a file instead in production

    printf("Data processed successfully and written to %s.\n", BINARY_FILE);

    return EXIT_SUCCESS;
}