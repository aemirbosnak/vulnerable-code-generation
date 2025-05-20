//FormAI DATASET v1.0 Category: HTML beautifier ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

void beautifyHTML(const char* filename) {
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: File not found!\n");
        return;
    }

    char line[1000];
    while (fgets(line, sizeof(line), file)) {
        int indentation = 0;
        for (int i = 0; line[i]; i++) {
            if (line[i] == '<') {
                if (line[i + 1] == '/') {
                    indentation -= 2;
                }
                for (int j = 0; j < indentation; j++) {
                    printf(" ");
                }
                printf("%c\n", line[i]);
                indentation += 2;
            }
            else if (line[i] == '>') {
                printf("%c", line[i]);
                if (line[i + 1] != '<' && line[i + 1] != '\n') {
                    printf("\n");
                }
            }
            else {
                printf("%c", line[i]);
            }
        }
    }

    fclose(file);
}

int main() {
    char filename[100];

    printf("Enter HTML file name: ");
    scanf("%s", filename);

    beautifyHTML(filename);

    return 0;
}