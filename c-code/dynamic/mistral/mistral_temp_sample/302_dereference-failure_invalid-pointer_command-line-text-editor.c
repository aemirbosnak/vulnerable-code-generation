#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256
#define LINE_BUFFER_SIZE 4096

char buffer[BUFFER_SIZE];
char lines[100][LINE_BUFFER_SIZE];
int num_lines = 0;
int current_line = 0;

void display_lines() {
    for (int i = 0; i < num_lines; ++i) {
        printf("%s", lines[i]);
        if (i != num_lines - 1)
            printf("\n");
    }
}

void read_input() {
    fgets(buffer, BUFFER_SIZE, stdin);
    char* token = strtok(buffer, "\n");
    if (strcmp(token, "save") == 0) {
        FILE *fp = fopen("output.txt", "w");
        for (int i = 0; i < num_lines; ++i) {
            fprintf(fp, "%s", lines[i]);
            if (i != num_lines - 1)
                fprintf(fp, "\n");
        }
        fclose(fp);
    } else if (strcmp(token, "quit") == 0) {
        exit(0);
    } else {
        char* line = strtok(NULL, "\n");
        if (line != NULL) {
            strcpy(lines[num_lines], line);
            ++num_lines;
        }
        if (num_lines > 1)
            current_line = (current_line + 1) % num_lines;
    }
}

int main() {
    char c;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            read_input();
            continue;
        }
        buffer[BUFFER_SIZE - 1] = c;
        buffer[BUFFER_SIZE] = '\0';
    }

    display_lines();
    return 0;
}
