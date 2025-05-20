#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100
#define TABLE_MAX 10

typedef struct {
    char name[50];
    int age;
} Person;

void migrate_data(FILE *source, FILE *destination) {
    Person data;
    char line[BUFFER_SIZE];
    while (fgets(line, BUFFER_SIZE, source)) {
        sscanf(line, "%s %d", data.name, &data.age);
        fprintf(destination, "%s %d\n", data.name, data.age);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    FILE *source = fopen(argv[1], "r");
    FILE *destination = fopen(argv[2], "w");

    if (!source || !destination) {
        perror("Failed to open files");
        return 2;
    }

    migrate_data(source, destination);

    fclose(source);
    fclose(destination);

    return 0;
}
