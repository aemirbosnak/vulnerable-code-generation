//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define HTML_HEADER "<html>\n<head>\n<title>%s</title>\n</head>\n<body>\n"
#define HTML_FOOTER "</body>\n</html>\n"

void beautify_html(char *input, char *output) {
  int indent_level = 0;
  int in_tag = 0;
  int in_comment = 0;

  FILE *input_file = fopen(input, "r");
  FILE *output_file = fopen(output, "w");

  if (input_file == NULL || output_file == NULL) {
    fprintf(stderr, "Error opening files.\n");
    exit(1);
  }

  char line[1024];
  while (fgets(line, sizeof(line), input_file)) {
    // Remove leading and trailing whitespace.
    int i = 0;
    int j = strlen(line) - 1;
    while (line[i] == ' ' || line[i] == '\t') {
      i++;
    }
    while (line[j] == ' ' || line[j] == '\t') {
      j--;
    }
    line[j + 1] = '\0';

    // Indent the line.
    int k;
    for (k = 0; k < indent_level; k++) {
      fprintf(output_file, "  ");
    }

    // Write the line to the output file.
    fprintf(output_file, "%s\n", line + i);

    // Handle tags.
    if (line[i] == '<') {
      in_tag = 1;
      if (line[i + 1] == '/') {
        indent_level--;
      } else if (line[i + 1] == '?' || line[i + 1] == '%') {
        in_comment = 1;
      } else {
        indent_level++;
      }
    } else if (line[i] == '>') {
      in_tag = 0;
    }

    // Handle comments.
    if (in_comment && line[i] == '-' && line[i + 1] == '-') {
      in_comment = 0;
    }
  }

  fclose(input_file);
  fclose(output_file);
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s input.html output.html\n", argv[0]);
    exit(1);
  }

  beautify_html(argv[1], argv[2]);

  return 0;
}