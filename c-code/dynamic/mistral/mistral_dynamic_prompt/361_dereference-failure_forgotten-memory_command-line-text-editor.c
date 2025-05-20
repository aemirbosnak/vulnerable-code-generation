#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1024

void edit_line(int line, char* buffer) {
    printf("Editing line %d\n", line);
    char input[MAX_SIZE];
    printf("Current text: %s\n", buffer);
    printf("Enter new text: ");
    fgets(input, MAX_SIZE, stdin);
    strcpy(buffer, input);
}

int main() {
    char* buffer[100];
    int num_lines = 0;
    char line[MAX_SIZE];

    while (1) {
        printf("> ");
        fgets(line, MAX_SIZE, stdin);

        if (strcmp(line, "new\n") == 0) {
            if (num_lines == 100) {
                printf("Max number of lines reached.\n");
                break;
            }
            buffer[num_lines] = (char*)malloc(MAX_SIZE * sizeof(char));
            printf("Line %d:\n", num_lines + 1);
            edit_line(num_lines + 1, buffer[num_lines]);
            num_lines++;
        } else if (strcmp(line, "list\n") == 0) {
            for (int i = 0; i < num_lines; i++) {
                printf("%d: %s\n", i + 1, buffer[i]);
            }
        } else if (strcmp(line, "exit\n") == 0) {
            break;
        } else {
            edit_line(atoi(line), buffer[atoi(line) - 1]);
        }
    }

    return 0;
}
