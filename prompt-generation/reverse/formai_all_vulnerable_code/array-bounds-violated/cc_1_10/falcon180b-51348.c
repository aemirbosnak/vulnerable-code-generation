//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80

typedef struct {
    char *text;
    int width;
} TextLine;

void print_text_line(TextLine *line) {
    int i;
    for (i = 0; i < line->width; i++) {
        printf("-");
    }
    printf("\n");
}

void print_text(TextLine *lines, int num_lines) {
    int i;
    for (i = 0; i < num_lines; i++) {
        print_text_line(&lines[i]);
    }
}

int main() {
    FILE *input_file;
    char input_text[100000];
    char *filename;
    int num_lines = 0;
    TextLine lines[100];

    printf("Enter the name of the input file: ");
    scanf("%s", filename);

    input_file = fopen(filename, "r");

    if (input_file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while (fgets(input_text, sizeof(input_text), input_file)!= NULL) {
        int len = strlen(input_text);
        input_text[len - 1] = '\0';
        lines[num_lines].text = input_text;
        lines[num_lines++].width = strlen(input_text);
    }

    fclose(input_file);

    print_text(lines, num_lines);

    return 0;
}