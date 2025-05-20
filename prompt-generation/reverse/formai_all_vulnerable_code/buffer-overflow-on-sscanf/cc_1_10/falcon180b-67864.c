//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100
#define MAX_FIELD_LENGTH 1024

typedef struct {
    char *name;
    char *value;
} Field;

typedef struct {
    Field *fields;
    int num_fields;
} Metadata;

Metadata *metadata_create() {
    Metadata *metadata = malloc(sizeof(Metadata));
    metadata->fields = NULL;
    metadata->num_fields = 0;
    return metadata;
}

void metadata_destroy(Metadata *metadata) {
    int i;
    for (i = 0; i < metadata->num_fields; i++) {
        free(metadata->fields[i].name);
        free(metadata->fields[i].value);
    }
    free(metadata->fields);
    free(metadata);
}

int metadata_add_field(Metadata *metadata, const char *name, const char *value) {
    Field *field = malloc(sizeof(Field));
    field->name = strdup(name);
    field->value = strdup(value);
    metadata->fields = realloc(metadata->fields, sizeof(Field) * (metadata->num_fields + 1));
    metadata->fields[metadata->num_fields] = *field;
    metadata->num_fields++;
    return 0;
}

int metadata_write(const char *filename, Metadata *metadata) {
    FILE *file;
    int i;
    file = fopen(filename, "w");
    if (file == NULL) {
        return -1;
    }
    for (i = 0; i < metadata->num_fields; i++) {
        fprintf(file, "%s: %s\n", metadata->fields[i].name, metadata->fields[i].value);
    }
    fclose(file);
    return 0;
}

Metadata *metadata_read(const char *filename) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *name, *value;
    Metadata *metadata = metadata_create();
    file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (sscanf(line, "%s: %s", &name, &value) == 2) {
            metadata_add_field(metadata, name, value);
        }
    }
    fclose(file);
    return metadata;
}

int main() {
    Metadata *metadata = metadata_read("metadata.txt");
    if (metadata!= NULL) {
        int i;
        for (i = 0; i < metadata->num_fields; i++) {
            printf("%s: %s\n", metadata->fields[i].name, metadata->fields[i].value);
        }
        metadata_destroy(metadata);
    }
    return 0;
}