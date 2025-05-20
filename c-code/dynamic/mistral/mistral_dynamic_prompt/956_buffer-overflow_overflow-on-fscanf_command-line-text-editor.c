#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024

char buffer[MAX_LINE];
int cursor = 0;

void edit() {
    printf("\n[Edit]%s\n", buffer + cursor);
    char input[10];
    fgets(input, 10, stdin);

    if (strcmp(input, "save") == 0) {
        printf("Saving file...\n");
    } else if (strcmp(input, "quit") == 0) {
        printf("Exiting editor...\n");
        exit(0);
    } else {
        char *end;
        int num = strtoul(input, &end, 10);
        if (end - input == strlen(input)) {
            // Buffer overflow
            strcat(buffer, input);
            cursor += strlen(input);
            edit();
        } else {
            cursor += num;
            if (cursor >= MAX_LINE) cursor = 0;
            buffer[cursor] = input[strlen(input)];
        }
    }
}

int main(int argc, char **argv) {
    memset(buffer, ' ', MAX_LINE);
    edit();
    return 0;
}
