//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: Donald Knuth
// Building a simple XML parser
// Inspired by Donald Knuth's literate programming style

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Define a struct to store XML tag information
struct XMLTag {
  char *name;
  char *attribute;
  char *value;
};

// Declare a helper function that trims whitespace from a string
char *trim(char *str) {
  char *end;

  // Trim leading spaces
  while (isspace((unsigned char)*str)) {
    str++;
  }

  if (*str == 0) {  // All spaces?
    return str;
  }

  // Trim trailing spaces
  end = str + strlen(str) - 1;
  while (end > str && isspace((unsigned char)*end)) {
      end--;
  }

  // Write new null terminator character
  end[1] = '\0';

  return str;
}

// Define the main function
int main() {
  // Declare variables
  char filename[100];
  char line[1024];
  char *cursor;
  FILE *file;

  // Prompt user for filename
  printf("Enter the name of the XML file to parse: ");
  scanf("%s", filename);

  // Open the XML file for reading
  file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error: could not open file.\n");
    exit(1);
  }

  // Initialize the XML tag struct
  struct XMLTag tag;
  tag.name = NULL;
  tag.attribute = NULL;
  tag.value = NULL;

  // Read each line of the XML file
  while (fgets(line, sizeof(line), file) != NULL) {
    // Remove leading and trailing whitespace
    cursor = trim(line);

    // Check if this line is a tag
    if (cursor[0] == '<') {
      // Check if this is an opening or closing tag
      if (cursor[1] == '/') {
        // This is a closing tag
        printf("Closing tag: %s\n", tag.name);
        free(tag.name);
        free(tag.attribute);
        free(tag.value);
      } else {
        // This is an opening tag
        printf("Opening tag: ");

        // Parse the tag name
        cursor++;
        while (*cursor != ' ' && *cursor != '>') {
          putchar(*cursor);
          cursor++;
        }
        putchar('\n');
        tag.name = strdup(cursor);

        // Parse the tag attribute and value (if any)
        while (*cursor != '>') {
          if (*cursor == ' ') {
            cursor++;
            char *attr = strdup(cursor);
            cursor = strchr(attr, '=');
            *cursor++ = '\0';
            tag.attribute = attr;
            tag.value = strdup(cursor);
            printf("- attribute: %s, value: %s\n", tag.attribute, tag.value);
          } else {
            cursor++;
          }
        }
      }
    }
  }

  // Close the XML file
  fclose(file);

  return 0;
}