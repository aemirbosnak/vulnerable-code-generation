//FormAI DATASET v1.0 Category: HTML beautifier ; Style: statistical
#include <stdio.h>
#include <string.h>

int main() {
    FILE *file_in, *file_out;
    char filename[50], buffer[1000], c;
    int i, indent = 0, new_line = 1;
    printf("Enter the name of HTML file to beautify: ");
    scanf("%s", filename);

    file_in = fopen(filename, "r");
    if (file_in == NULL) {
        printf("Cannot open file.\n");
        return 0;
    }

    char new_filename[50] = "beauty_";
    strcat(new_filename, filename);
    file_out = fopen(new_filename, "w");

    while ((c = fgetc(file_in)) != EOF) {
        if (new_line) {
            for (i = 0; i < indent; i++) {
                fputc('\t', file_out);
            }
            new_line = 0;
        }

        if (c == '<') {
            if (fgetc(file_in) == '/') {
                indent--;
            }
            else {
                indent++;
            }
            fputc('<', file_out);
            if (fgetc(file_in) == '/') {
                indent--;
            }
            else {
                indent++;
            }
            fputc('\n', file_out);
            new_line = 1;
        }
        else if (c == '>') {
            fputc('>', file_out);
            fputc('\n', file_out);
            new_line = 1;
        }
        else {
            fputc(c, file_out);
        }
    }

    fclose(file_in);
    fclose(file_out);

    printf("Beautification complete.\n");

    return 0;
}