#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 256

void read_line(char *buf, int size) {
    if (fgets(buf, size, stdin) == NULL)
        exit(0);
}

void print_buffer(char *buffer) {
    printf("\nBuffer contents:\n");
    for (int i = 0; i < strlen(buffer); ++i) {
        printf("%c", buffer[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    char buffer[MAX_LINE];
    char *edited_buffer = (char *) malloc(MAX_LINE);

    printf("Simple Text Editor\n");
    printf("------------------\n");

    while (1) {
        printf("\nLoad/Edit buffer: ");
        read_line(buffer, MAX_LINE);

        if (!strcmp(buffer, "save\n")) {
            printf("Saving...\n");
            printf("Buffer contents:\n");
            print_buffer(edited_buffer);

            FILE *file = fopen("output.txt", "w");
            fputs(edited_buffer, file);
            fclose(file);
            break;
        } else if (!strcmp(buffer, "quit\n")) {
            printf("Exiting...\n");
            break;
        } else if (!strcmp(buffer, "print\n")) {
            printf("Buffer contents:\n");
            print_buffer(edited_buffer);
        } else {
            strcpy(edited_buffer, buffer);
        }
    }

    free(edited_buffer);
    return 0;
}
