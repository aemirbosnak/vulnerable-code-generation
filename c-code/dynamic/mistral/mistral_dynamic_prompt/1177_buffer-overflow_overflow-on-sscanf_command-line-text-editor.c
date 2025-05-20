#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 256
#define BUFFER_SIZE 8192

char line[MAX_LINE];
char buffer[BUFFER_SIZE];

void read_input() {
    printf("> ");
    fgets(line, MAX_LINE, stdin);
}

void list() {
    printf("\n1. Open\n2. Save\n3. Quit\n");
}

int open() {
    // Assuming filename is entered in the buffer
    FILE *file;
    int result = sscanf(buffer, "%s", line);
    file = fopen(line, "r");

    if (!file) {
        printf("Error: Unable to open file\n");
        return -1;
    }

    // Unbounded read into buffer
    char c;
    while ((c = fgetc(file)) != EOF) {
        buffer[BUFFER_SIZE - 1] = c;
        buffer[BUFFER_SIZE] = '\0';
    }

    printf("%s", buffer);
    return 0;
}

int save() {
    // Unbounded write to file
    FILE *file;
    file = fopen(buffer, "w");

    if (!file) {
        printf("Error: Unable to open file\n");
        return -1;
    }

    fputs(buffer, file);
    fclose(file);
    printf("File saved\n");
    return 0;
}

int main() {
    char choice;

    while (1) {
        list();
        read_input();
        choice = atoi(buffer);

        switch (choice) {
            case 1:
                open();
                break;
            case 2:
                save();
                break;
            case 3:
                return 0;
            default:
                printf("Invalid option\n");
        }
    }

    return 0;
}
