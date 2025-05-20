//FormAI DATASET v1.0 Category: HTML beautifier ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

void beautify(char * filename) {
    FILE * file_ptr = NULL;

    // Open the file in read mode
    file_ptr = fopen(filename, "r");
    if (file_ptr == NULL) {
        printf("Error: Failed to open %s file", filename);
        return;
    }

    // Open a new file in write mode to write the beautified code
    FILE * output_ptr = fopen("beautified.html", "w");

    int indent = 0;
    int space_flag = 0;
    char ch, next_ch;

    while ((ch = fgetc(file_ptr)) != EOF) {
        if (ch == '<') {
            putc(ch, output_ptr);
            next_ch = fgetc(file_ptr);

            if (next_ch == '/') {
                indent -= 4;
            } else {
                indent += 4;
            }

            putc(next_ch, output_ptr);
            putc('\n', output_ptr);

            for (int i = 0; i < indent; i++) {
                putc(' ', output_ptr);
            }

            space_flag = 1;
        } else if (ch == '>') {
            putc(ch, output_ptr);
            putc('\n', output_ptr);
            space_flag = 1;
        } else {
            if (space_flag && ch != ' ') {
                putc(' ', output_ptr);
                space_flag = 0;
            }
            putc(ch, output_ptr);
        }
    }

    fclose(file_ptr);
    fclose(output_ptr);

    printf("Beautified HTML code is saved in beautified.html file.\n");
}

int main() {
    char filename[50];

    printf("Enter the filename: ");
    scanf("%s", filename);

    beautify(filename);

    return 0;
}