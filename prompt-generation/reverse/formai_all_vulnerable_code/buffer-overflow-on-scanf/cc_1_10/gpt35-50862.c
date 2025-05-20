//FormAI DATASET v1.0 Category: HTML beautifier ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

void beautify(char *filename);

int main() {
    char filename[100];

    printf("Welcome to the HTML Beautifier Program!\n");
    printf("Please enter the filename of the HTML file you want to beautify: ");
    scanf("%s", filename);

    beautify(filename);

    printf("\n%s has been beautifully formatted! Thank you for using our program!\n", filename);

    return 0;
}

void beautify(char *filename) {
    FILE *file;
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char temp_char;
    int indentation = 0;
    int open_tag = 0;

    while ((temp_char = fgetc(file)) != EOF) {
        if (temp_char == '<') {
            if (open_tag == 0) {
                for (int i = 0; i < indentation; i++) {
                    printf("    ");
                }
                open_tag = 1;
            }
            printf("%c", temp_char);
            if (fgetc(file) == '/') indentation--;
            else indentation++;
            continue;
        }
        if (temp_char == '>') {
            printf("%c\n", temp_char);
            open_tag = 0;
            continue;
        }
        printf("%c", temp_char);
    }
    fclose(file);
}