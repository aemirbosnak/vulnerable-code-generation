//MISTRAL-7B DATASET v1.0 Category: Metadata Extractor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 256
#define MAX_NUM_TAGS 10
#define TAG_NAME_LENGTH 32
#define TAG_VALUE_LENGTH 64

typedef struct {
    char name[TAG_NAME_LENGTH];
    char value[TAG_NAME_LENGTH];
} Tag;

int main(int argc, char *argv[]) {
    FILE *file;
    char buffer[MAX_STRING_LENGTH];
    int num_tags = 0;
    Tag tags[MAX_NUM_TAGS];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <metadata file>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", argv[1]);
        return 1;
    }

    while (fgets(buffer, MAX_STRING_LENGTH, file) != NULL) {
        if (num_tags >= MAX_NUM_TAGS) {
            fprintf(stderr, "Error: too many tags\n");
            fclose(file);
            return 1;
        }

        if (strncmp(buffer, "<METADATA>", 7) != 0) {
            continue;
        }

        buffer[strcspn(buffer, "\n")] = '\0'; // remove newline character
        sscanf(buffer + 7, "%s %s", tags[num_tags].name, tags[num_tags].value);
        num_tags++;
    }

    fclose(file);

    printf("<METADATA>\n");
    for (int i = 0; i < num_tags; i++) {
        printf("%s=\"%s\"\n", tags[i].name, tags[i].value);
    }
    printf("</METADATA>");

    return 0;
}