//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_TAGS 10
#define MAX_TAG_LENGTH 32

struct tag {
    char name[MAX_TAG_LENGTH];
    int count;
};

struct line {
    char text[MAX_LINE_LENGTH];
    struct tag tags[MAX_NUM_TAGS];
    int num_tags;
};

void print_tags(struct tag tags[], int num_tags) {
    for (int i = 0; i < num_tags; i++) {
        printf("%s: %d\n", tags[i].name, tags[i].count);
    }
}

void print_line(struct line line) {
    printf("%s\n", line.text);
    printf("Tags:\n");
    print_tags(line.tags, line.num_tags);
}

int main() {
    FILE *file;
    char filename[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    struct line current_line;
    int current_line_num = 0;
    int in_tag = 0;
    int tag_index = 0;
    char *tag_name;
    struct tag *current_tag;

    // Prompt user for filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read file line by line
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        // Increment line number
        current_line_num++;

        // Reset tag index and tag name
        tag_index = 0;
        tag_name = NULL;

        // Parse line for tags
        in_tag = 0;
        current_tag = &current_line.tags[0];
        for (int i = 0; i < strlen(line); i++) {
            if (line[i] == '<') {
                in_tag = 1;
                tag_name = &line[i + 1];
            } else if (line[i] == '>') {
                in_tag = 0;
                *tag_name = '\0';
                strcpy(current_tag->name, tag_name);
                current_tag->count++;
                current_tag++;
                tag_index++;
                if (tag_index >= MAX_NUM_TAGS) {
                    break;
                }
            }
        }

        // Store line text
        strcpy(current_line.text, line);
        current_line.num_tags = tag_index;

        // Print current line
        print_line(current_line);
    }

    // Close file
    fclose(file);

    return 0;
}