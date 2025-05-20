//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_TAGS 100

typedef struct {
    char* name;
    char* value;
} Tag;

int num_tags = 0;
Tag tags[MAX_NUM_TAGS];

void add_tag(char* name, char* value) {
    if (num_tags >= MAX_NUM_TAGS) {
        printf("Error: Maximum number of tags reached.\n");
        return;
    }

    tags[num_tags].name = strdup(name);
    tags[num_tags].value = strdup(value);
    num_tags++;
}

void print_tags() {
    for (int i = 0; i < num_tags; i++) {
        printf("%s: %s\n", tags[i].name, tags[i].value);
    }
}

int main() {
    FILE* file = fopen("metadata.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open metadata file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char* name = strtok(line, ":");
        char* value = strtok(NULL, ":");

        if (name == NULL || value == NULL) {
            printf("Error: Invalid metadata format.\n");
            fclose(file);
            return 1;
        }

        add_tag(name, value);
    }

    fclose(file);
    print_tags();

    return 0;
}