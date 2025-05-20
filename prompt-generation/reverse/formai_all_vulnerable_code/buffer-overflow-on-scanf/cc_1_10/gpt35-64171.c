//FormAI DATASET v1.0 Category: HTML beautifier ; Style: sophisticated
//HTML Beautifier - C program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautify(char *input, char *output)
{
    int indent = 0;
    int len = strlen(input);
    int i = 0;
    int j = 0;
    while (i < len) {
        if (input[i] == '<') {
            if (input[i + 1] == '/') {
                indent -= 4;
                i += 3;
            } else {
                for (int k = 0; k < indent; k++)
                    output[j++] = ' ';
                indent += 4;
                i++;
            }
        }
        output[j++] = input[i++];
        if (input[i - 1] == '>' && input[i] == '\n') {
            output[j++] = '\n';
        }
    }
}

int main()
{
    char input_file[100];
    char output_file[100];
    printf("Enter input HTML file name:\n");
    scanf("%s", input_file);
    printf("Enter output file name:\n");
    scanf("%s", output_file);
    FILE *fin = fopen(input_file, "r");
    FILE *fout = fopen(output_file, "w");
    if (fin == NULL || fout == NULL) {
        printf("Error opening files.\n");
        exit(1);
    }
    char input[1000];
    char output[1000];
    while (fgets(input, 1000, fin)) {
        beautify(input, output);
        fputs(output, fout);
    }
    fclose(fin);
    fclose(fout);
    printf("Beautifier complete.\n");
    return 0;
}