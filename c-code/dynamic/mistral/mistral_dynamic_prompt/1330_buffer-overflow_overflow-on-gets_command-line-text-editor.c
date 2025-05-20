#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 100

void editor() {
    char buffer[BUFFER_SIZE];
    char command[20];

    printf("\nSimple Text Editor\n");
    while (1) {
        printf("\nCurrent buffer:\n%s\n\nCommand (save/quit/edit): ", buffer);
        fgets(command, sizeof(command), stdin);

        if (!strncmp(command, "save", 4)) {
            FILE *file;
            file = fopen("output.txt", "w");
            if (file) {
                fputs(buffer, file);
                fclose(file);
                printf("File saved successfully.\n");
            } else {
                printf("Error saving file.\n");
            }
        } else if (!strncmp(command, "quit", 4)) {
            break;
        } else {
            printf("Invalid command. Try again.\n");
        }
    }
}

int main() {
    char buffer[10000];
    printf("Enter a large amount of text (exploit buffer overflow):\n");
    gets(buffer); // Buffer overflow vulnerability here
    editor();
    return 0;
}
