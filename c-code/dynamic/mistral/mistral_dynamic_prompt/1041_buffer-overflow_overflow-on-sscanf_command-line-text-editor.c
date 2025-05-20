#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_LINE 1024

void editor() {
    char line[MAX_LINE];
    char command[10];

    while (1) {
        printf("\nText Editor\n");
        printf("> ");
        fgets(line, MAX_LINE, stdin);
        sscanf(line, "%s", command);

        if (!strcmp(command, "save")) {
            FILE *fp = fopen("text.txt", "w");
            fputs(line, fp);
            fclose(fp);
            printf("File saved.\n");
        } else if (!strcmp(command, "load")) {
            char buffer[MAX_LINE];
            FILE *fp = fopen("text.txt", "r");
            fgets(buffer, MAX_LINE, fp);
            fclose(fp);
            printf(buffer);
        } else if (!strcmp(command, "quit")) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }
}

int main() {
    editor();
    return 0;
}
