#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 256
#define MAX_LINES 1000

char lines[MAX_LINES][BUF_SIZE];
int num_lines = 0;

void edit_line(int line_num) {
    char input[BUF_SIZE];
    printf("Line %d: %s\n", line_num, lines[line_num - 1]);
    printf("> ");
    fgets(input, BUF_SIZE, stdin);
    strcpy(lines[line_num - 1], input);
}

void print_lines() {
    for (int i = 0; i < num_lines; ++i) {
        printf("%d: %s\n", i + 1, lines[i]);
    }
}

int main() {
    char command[BUF_SIZE];

    while (1) {
        printf("> ");
        fgets(command, BUF_SIZE, stdin);

        if (strchr(command, 'n')) {
            char* token = strtok(command, "n");
            num_lines++;
            lines[num_lines - 1][strcspn(lines[num_lines - 1], "\n")] = 0;
            continue;
        }

        if (strchr(command, 'p')) {
            print_lines();
            continue;
        }

        if (strchr(command, 'e')) {
            char* token = strtok(command, " ");
            int line_num = atoi(token);
            edit_line(line_num);
            continue;
        }
    }

    return 0;
}
