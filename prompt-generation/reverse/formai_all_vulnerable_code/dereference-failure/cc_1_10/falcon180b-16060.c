//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_FIELDS 100
#define MAX_FIELD_LENGTH 100

typedef struct field_t {
    char name[MAX_FIELD_LENGTH];
    char value[MAX_FIELD_LENGTH];
} field_t;

typedef struct metadata_t {
    int num_fields;
    field_t fields[MAX_NUM_FIELDS];
} metadata_t;

metadata_t *parse_metadata(char *metadata) {
    metadata_t *result = malloc(sizeof(metadata_t));
    result->num_fields = 0;

    char *line = strtok(metadata, "\n");
    while (line!= NULL) {
        char *field_name = strtok(line, ":");
        if (field_name == NULL) {
            break;
        }

        char *field_value = strtok(NULL, "\n");
        if (field_value == NULL) {
            break;
        }

        if (result->num_fields >= MAX_NUM_FIELDS) {
            printf("Error: too many fields in metadata.\n");
            exit(1);
        }

        strncpy(result->fields[result->num_fields].name, field_name, MAX_FIELD_LENGTH);
        strncpy(result->fields[result->num_fields].value, field_value, MAX_FIELD_LENGTH);

        result->num_fields++;

        line = strtok(NULL, "\n");
    }

    return result;
}

void print_metadata(metadata_t *metadata) {
    printf("Number of fields: %d\n", metadata->num_fields);
    for (int i = 0; i < metadata->num_fields; i++) {
        printf("Field %d:\n", i + 1);
        printf("  Name: %s\n", metadata->fields[i].name);
        printf("  Value: %s\n", metadata->fields[i].value);
        printf("\n");
    }
}

int main() {
    char metadata[MAX_LINE_LENGTH];
    printf("Enter metadata:\n");
    fgets(metadata, MAX_LINE_LENGTH, stdin);

    metadata_t *result = parse_metadata(metadata);
    if (result == NULL) {
        exit(1);
    }

    print_metadata(result);

    free(result);
    return 0;
}