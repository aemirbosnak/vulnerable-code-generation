//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Structure to represent an XML tag
typedef struct {
    char *tag_name;
    char **attributes;
    int num_attributes;
    int has_content;
    char *content;
} xml_tag;

// Function to parse an XML file and return an array of xml_tag structures
xml_tag *parse_xml_file(char *filename, int *num_tags) {
    FILE *file;
    char buffer[BUFFER_SIZE];
    int buffer_ptr = 0;
    int in_tag = 0;
    int in_attribute = 0;
    int num_chars_read = 0;
    int num_tags_read = 0;
    xml_tag *tags = NULL;
    xml_tag *current_tag = NULL;
    
    // Open XML file
    if ((file = fopen(filename, "r")) == NULL) {
        printf("Error: could not open file %s\n", filename);
        return NULL;
    }
    
    // Read file character by character
    while ((num_chars_read = fread(buffer+buffer_ptr, sizeof(char), BUFFER_SIZE-buffer_ptr, file))) {
        // Iterate through buffer character by character
        for (int i = 0; i < num_chars_read; i++) {
            // Check if we are currently in a tag
            if (in_tag) {
                if (buffer[buffer_ptr+i] == '>') {
                    // End of the tag, add it to the array
                    in_tag = 0;
                    num_tags_read++;
                    tags = realloc(tags, sizeof(xml_tag)*num_tags_read);
                    current_tag = &tags[num_tags_read-1];
                } else if (buffer[buffer_ptr+i] == ' ') {
                    // Space indicates a new attribute, add it to the current tag
                    in_attribute = 1;
                    current_tag->num_attributes++;
                    current_tag->attributes = realloc(current_tag->attributes, sizeof(char*)*current_tag->num_attributes);
                } else if (in_attribute) {
                    // Read attribute name and value
                    char *name = &buffer[buffer_ptr+i];
                    char *value = NULL;
                    while (buffer[buffer_ptr+i] != '=') i++;
                    buffer[buffer_ptr+i] = '\0';
                    i++;
                    if (buffer[buffer_ptr+i] == '"') {
                        value = &buffer[buffer_ptr+i+1];
                        i++;
                    }
                    while (buffer[buffer_ptr+i] != '"') i++;
                    buffer[buffer_ptr+i] = '\0';
                    current_tag->attributes[current_tag->num_attributes-1] = name;
                    current_tag->num_attributes++;
                    current_tag->attributes = realloc(current_tag->attributes, sizeof(char*)*current_tag->num_attributes);
                    current_tag->attributes[current_tag->num_attributes-1] = value;
                    in_attribute = 0;
                } else {
                    // Read tag name
                    int tag_name_start = i;
                    while (buffer[buffer_ptr+i] != ' ' && buffer[buffer_ptr+i] != '>') i++;
                    buffer[buffer_ptr+i] = '\0';
                    current_tag->tag_name = &buffer[buffer_ptr+tag_name_start];
                    current_tag->has_content = (buffer[buffer_ptr+i-1] != '/');
                    if (current_tag->has_content) {
                        current_tag->content = NULL;
                    }
                    i--;
                }
            } else if (buffer[buffer_ptr+i] == '<') {
                // Start of a new tag
                in_tag = 1;
                current_tag = NULL;
                tags = realloc(tags, sizeof(xml_tag)*num_tags_read+1);
                current_tag = &tags[num_tags_read];
                current_tag->attributes = NULL;
                current_tag->num_attributes = 0;
                current_tag->has_content = 0;
                current_tag->content = NULL;
            } else if (current_tag != NULL && current_tag->has_content) {
                // Read tag content
                if (current_tag->content == NULL) {
                    current_tag->content = &buffer[buffer_ptr+i];
                }
            }
        }
        buffer_ptr = BUFFER_SIZE - (num_chars_read + buffer_ptr);
        // Shift remaining characters to beginning of buffer
        memmove(buffer, buffer+num_chars_read, buffer_ptr);
    }
    *num_tags = num_tags_read;
    return tags;
}

int main(void) {
    int num_tags;
    xml_tag *tags = parse_xml_file("example.xml", &num_tags);
    if (tags == NULL) {
        return 1;
    }
    for (int i = 0; i < num_tags; i++) {
        printf("Tag %d: %s\n", i+1, tags[i].tag_name);
        if (tags[i].num_attributes > 0) {
            printf("  Attributes:\n");
            for (int j = 0; j < tags[i].num_attributes; j+=2) {
                printf("    %s = %s\n", tags[i].attributes[j], tags[i].attributes[j+1]);
            }
        }
        if (tags[i].has_content) {
            printf("  Content: %s\n", tags[i].content);
        }
    }
    return 0;
}