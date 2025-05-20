//FormAI DATASET v1.0 Category: HTML beautifier ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

void printIndentation(int depth) {
  for (int i = 0; i < depth; i++) {
    printf(" ");
  }
}

int main(int argc, char *argv[]) {
  char ch;
  int depth = 0;
  int in_angle_bracket = 0;
  int in_attribute = 0;
  int in_comment = 0;
  FILE *input, *output;

  if (argc < 3) {
    printf("Usage: htmlbeautifier input_file output_file\n");
    return 1;
  }

  input = fopen(argv[1], "r");
  if (input == NULL) {
    printf("Could not open input file\n");
    return 1;
  }

  output = fopen(argv[2], "w");
  if (output == NULL) {
    printf("Could not open output file\n");
    return 1;
  }

  while ((ch = fgetc(input)) != EOF) {
    switch (ch) {
      case '<':
        in_angle_bracket = 1;
        fprintf(output, "%c", ch);
        break;
      case '>':
        in_angle_bracket = 0;
        fprintf(output, "%c\n", ch);
        break;
      case '/':
        if (in_angle_bracket && !in_attribute) {
          printIndentation(depth * 2);
          fprintf(output, "/");
        } else {
          fprintf(output, "%c", ch);
        }
        break;
      case '\"':
        if (in_angle_bracket) {
          in_attribute = !in_attribute;
        }
        fprintf(output, "%c", ch);
        break;
      case '-':
        if (in_angle_bracket && fgetc(input) == '-' && fgetc(input) == ' ') {
          in_comment = 1;
        }
        fprintf(output, "-");
        break;
      case '\n':
        if (in_comment) {
          in_comment = 0;
        }
        fprintf(output, "\n");
        break;
      default:
        if (in_angle_bracket) {
          fprintf(output, "%c", ch);
        } else {
          if (!in_comment) {
            printIndentation(depth * 2);
            fprintf(output, "%c", ch);
          }
        }
        break;
    }

    if (!in_angle_bracket && !in_attribute && ch == '<' && fgetc(input) == '/') {
      depth--;
      fseek(input, -1, SEEK_CUR);
    }

    if (!in_angle_bracket && ch == '<') {
      depth++;
    }
  }

  fclose(input);
  fclose(output);

  return 0;
}