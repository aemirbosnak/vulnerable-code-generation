#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 128

void edit_text(char *text) {
    printf("Enter your text: ");
    gets(text);
}

int main() {
    char *file_name = "example.txt";
    FILE *file;
    char text[MAX_SIZE];

    file = fopen(file_name, "r");
    if (file != NULL) {
        fgets(text, sizeof(text), file);
        fclose(file);
    }

    edit_text(text);

    file = fopen(file_name, "w");
    if (file != NULL) {
        fprintf(file, "%s", text);
        fclose(file);
    } else {
        printf("Error opening file.\n");
    }

    return 0;
}
