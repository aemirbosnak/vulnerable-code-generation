#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 256
#define LINE_BUFFER_SIZE 1024

void editor() {
    char buffer[BUFFER_SIZE];
    char line_buffer[LINE_BUFFER_SIZE];
    char *ptr = buffer;
    int line_num = 1;

    printf("Simple Text Editor\n");
    while (1) {
        printf("\nLine %d\n%s\n", line_num, ptr);
        printf("(I)nsert (L)oad (S)ave (E)dit (Q)uit: ");
        scanf("%s", &buffer);

        switch (buffer[0]) {
            case 'I':
                // Insert logic here
                break;
            case 'L':
                // Load logic here
                break;
            case 'S':
                // Save logic here
                break;
            case 'E':
                // Edit logic here
                break;
            case 'Q':
                return;
            default:
                printf("Invalid command. Please try again.\n");
                break;
        }
        line_num++;
        strcpy(ptr, "\n");
        fgets(ptr, BUFFER_SIZE, stdin);
        strcpy(line_buffer, ptr);
        ptr += strlen(line_buffer) + 1;
    }
}

int main() {
    editor();
    return 0;
}
