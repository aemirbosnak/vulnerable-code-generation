//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LEN 1024
#define MAX_TAG_LEN 64

typedef struct {
  char *name;
  char *value;
} Attribute;

typedef struct {
  char *name;
  Attribute *attributes;
  int num_attributes;
  char *content;
} Tag;

int main() {
  char line[MAX_LINE_LEN];
  int in_tag = 0;
  Tag *tag = NULL;

  while (fgets(line, MAX_LINE_LEN, stdin) != NULL) {
    char *start = line;
    char *end = NULL;

    // Trim leading whitespace
    while (*start == ' ' || *start == '\t') {
      start++;
    }

    // Find the end of the tag
    end = strchr(start, '>');

    // If we're not in a tag, look for the start of one
    if (!in_tag) {
      if (*start == '<') {
        in_tag = 1;
        tag = malloc(sizeof(Tag));
        tag->name = NULL;
        tag->attributes = NULL;
        tag->num_attributes = 0;
        tag->content = NULL;
        start++;
      }
    }

    // If we're in a tag, parse it
    if (in_tag) {
      // Parse the tag name
      char *name = start;
      end = strchr(start, ' ');
      if (end == NULL) {
        end = strchr(start, '>');
      }
      tag->name = strndup(name, end - name);

      // Parse the attributes
      while (end != NULL) {
        start = end + 1;
        end = strchr(start, '=');
        if (end == NULL) {
          break;
        }
        char *name = strndup(start, end - start);
        start = end + 1;
        end = strchr(start, '"');
        if (end == NULL) {
          break;
        }
        char *value = strndup(start, end - start);
        Attribute attribute = {name, value};
        tag->attributes = realloc(tag->attributes, (tag->num_attributes + 1) * sizeof(Attribute));
        tag->attributes[tag->num_attributes] = attribute;
        tag->num_attributes++;
        start = end + 1;
      }

      // Parse the content
      start = end + 1;
      end = strchr(start, '<');
      if (end == NULL) {
        end = strchr(start, '\0');
      }
      tag->content = strndup(start, end - start);

      // Print the formatted tag
      printf("<%s", tag->name);
      for (int i = 0; i < tag->num_attributes; i++) {
        printf(" %s=\"%s\"", tag->attributes[i].name, tag->attributes[i].value);
      }
      printf(">%s</%s>\n", tag->content, tag->name);

      // Clean up
      free(tag->name);
      free(tag->attributes);
      free(tag->content);
      free(tag);
      in_tag = 0;
    }
  }

  return 0;
}