//MISTRAL-7B DATASET v1.0 Category: Metadata Extractor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILE_SIZE (1024 * 1024)
#define MAX_METADATA_SIZE (1024)

typedef struct {
    char name[100];
    int age;
    char gender;
    char metadata[MAX_METADATA_SIZE];
} Person;

bool extract_metadata(const char *filename, Person *person) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: Unable to open file %s\n", filename);
        return false;
    }

    fseek(file, -sizeof(Person), SEEK_END);
    if (ftell(file) != sizeof(Person)) {
        fprintf(stderr, "Error: File size is not valid\n");
        fclose(file);
        return false;
    }

    fread(person, sizeof(Person), 1, file);
    fclose(file);

    if (strstr(person->metadata, "AGE")) {
        sscanf(person->metadata, "AGE:%d", &person->age);
    }

    if (strstr(person->metadata, "GENDER")) {
        sscanf(person->metadata, "GENDER:%c", &person->gender);
    }

    return true;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    Person person;

    if (!extract_metadata(argv[1], &person)) {
        fprintf(stderr, "Error: Unable to extract metadata from file %s\n", argv[1]);
        return 1;
    }

    printf("Name: %s\n", person.name);
    printf("Age: %d\n", person.age);
    printf("Gender: %c\n", person.gender);
    printf("Metadata: %s\n", person.metadata);

    return 0;
}