//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This program is a simple XML parser that takes an XML file as input and outputs
 * the contents of the tags in the file. It does not handle attributes or any
 * complex XML features.
 */

typedef struct tag {
    char name[50];
    char content[500];
} Tag;

int main(int argc, char *argv[]) {
    // check for correct argument count
    if (argc != 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        return 1;
    }

    // open the file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'.\n", argv[1]);
        return 1;
    }

    // parse the file and output the contents of the tags
    Tag current_tag; // temporarily holds the current tag's name and content
    char line[500]; // temporarily holds each line of the file
    int in_tag = 0; // whether or not we are currently inside a tag
    int tag_started = 0; // whether or not we have started a tag
    int tag_ended = 0; // whether or not we have ended a tag
    while (fgets(line, 500, file)) {
        int len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0'; // remove newline character
        }

        // check for start tag
        if (!in_tag && line[0] == '<' && !tag_started) {
            tag_started = 1;
            strcpy(current_tag.name, line + 1);
            in_tag = 1;
        }

        // add content to tag
        if (in_tag) {
            strcat(current_tag.content, line);
        }

        // check for end tag
        if (in_tag && line[len - 2] == '<') {
            tag_ended = 1;
            in_tag = 0;
        }

        // output tag content and reset current_tag
        if (tag_ended) {
            printf("%s: %s\n", current_tag.name, current_tag.content);
            memset(current_tag.content, 0, sizeof(current_tag.content));
            tag_started = 0;
            tag_ended = 0;
        }
    }

    fclose(file);
    return 0;
}