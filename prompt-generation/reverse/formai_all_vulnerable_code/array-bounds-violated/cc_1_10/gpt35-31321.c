//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

int main() {
    char input[10000], output[10000], tags[1000][100];
    int index = 0, tag_index = 0, indent_level = 0, is_comment = 0;

    printf("Enter HTML code:\n");
    fgets(input, 10000, stdin);

    for(int i=0; i<strlen(input); i++) {
        if(input[i] == '<') { // Start of tag
            if(input[i+1] == '!') { // Comment tag
                is_comment = 1;
            } else { // Regular tag
                sprintf(tags[tag_index], "%c", input[i+1]);
                tag_index++;
            }
            if(input[i+1] != '/') { // Don't increase indent level if end tag
                indent_level++;
            }
            index++;
        }
        if(input[i] == '>') { // End of tag
            if(input[i-1] == '/') { // Self-closing tag
                indent_level--;
            } else { // Regular tag
                sprintf(tags[tag_index], "/%c", input[i-tag_index]);
                tag_index--;
                indent_level--;
            }
            is_comment = 0;
            index++;
        }
        if(input[i] == '\n') { // New line
            sprintf(output+index, "\n");
            index++;
            for(int j=0; j<indent_level; j++) { // Add indentation
                sprintf(output+index, "    ");
                index += 4;
            }
        }
        if(!is_comment) { // Regular text, not in a comment
            sprintf(output+index, "%c", input[i]);
            index++;
        }
    }

    printf("Beautified HTML code:\n %s", output);

    return 0;
}