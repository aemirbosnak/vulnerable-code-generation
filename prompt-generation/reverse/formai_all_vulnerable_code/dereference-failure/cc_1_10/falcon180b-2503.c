//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_TAGS 100

typedef struct {
    char *name;
    char *value;
} Tag;

int num_tags = 0;
Tag tags[MAX_NUM_TAGS];

void add_tag(char *name, char *value) {
    if (num_tags >= MAX_NUM_TAGS) {
        printf("Error: Maximum number of tags reached.\n");
        return;
    }
    tags[num_tags].name = strdup(name);
    tags[num_tags].value = strdup(value);
    num_tags++;
}

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *tag_name, *tag_value;
    int in_tag = 0;

    if (argc!= 2) {
        printf("Usage: %s <metadata_file>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (strncmp(line, "TAG=", 4) == 0) {
            in_tag = 1;
            tag_name = line + 4;
            tag_value = strchr(tag_name, ':');
            if (tag_value == NULL) {
                printf("Error: Invalid tag format.\n");
                fclose(file);
                return 1;
            }
            *tag_value = '\0';
            tag_value++;
            add_tag(tag_name, tag_value);
        } else if (in_tag) {
            if (strncmp(line, ":ENDTAG", 7) == 0) {
                in_tag = 0;
            }
        }
    }

    if (in_tag) {
        printf("Error: Missing :ENDTAG.\n");
        fclose(file);
        return 1;
    }

    fclose(file);

    printf("Metadata:\n");
    for (int i = 0; i < num_tags; i++) {
        printf("%s: %s\n", tags[i].name, tags[i].value);
    }

    for (int i = 0; i < num_tags; i++) {
        free(tags[i].name);
        free(tags[i].value);
    }

    return 0;
}