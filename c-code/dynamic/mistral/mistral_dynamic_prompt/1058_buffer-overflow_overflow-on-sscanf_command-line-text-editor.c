#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE 256
#define BUFFER_SIZE 1024

char buffer[BUFFER_SIZE];
char line[MAX_LINE];

void edit() {
    printf("\n[Text Editor]\n");
    printf("===========================\n\n");

    memset(buffer, 0, BUFFER_SIZE);
    size_t read_bytes;

    while (1) {
        printf("%s", buffer);
        printf("> ");

        read_bytes = fgets(line, MAX_LINE, stdin);

        if (read_bytes <= 0) break;

        sscanf(line, "%*s %[^\n]s", buffer);
    }
}

int main() {
    edit();
    return 0;
}
