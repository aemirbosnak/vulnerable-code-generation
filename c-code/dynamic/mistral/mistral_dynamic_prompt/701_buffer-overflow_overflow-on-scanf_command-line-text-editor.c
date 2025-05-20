#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char buffer[10];
char text[500];

void editor() {
    int i;
    printf("\033[2J\033[H");
    printf("Your text editor\n\n");
    printf("%s\n", text);

    while (1) {
        printf("> ");
        scanf("%s", buffer);
        if (!strcmp(buffer, "save")) {
            break;
        } else if (!strcmp(buffer, "exit")) {
            return;
        } else {
            strcat(text, buffer);
            strcat(text, "\n");
        }
    }

    FILE *file = fopen("file.txt", "w");
    fprintf(file, "%s", text);
    fclose(file);
}

int main() {
    while (1) {
        editor();
    }
    return 0;
}
