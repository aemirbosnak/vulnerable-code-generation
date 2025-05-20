#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 10

void edit(char* buffer) {
    int pos = 0;
    char command[3];
    while (1) {
        printf("\nText Editor (type 'q' to quit)\n");
        printf("> ");
        scanf("%s", command);

        switch (command[0]) {
            case 'a': // Append text
                if (BUFFER_SIZE - pos > 1) {
                    char newText[10];
                    printf("Enter new text: ");
                    scanf("%s", newText);
                    strcat(buffer + pos, newText);
                    pos += strlen(newText);
                } else {
                    printf("Out of bounds write error\n");
                }
                break;

            case 'r': // Replace text
                // Implement this feature later
                break;

            case 'c': // Cut text
                // Implement this feature later
                break;

            case 'p': // Paste text
                // Implement this feature later
                break;

            case 'd': // Delete text
                // Implement this feature later
                break;

            case 'q':
                return;

            default:
                printf("Invalid command\n");
                break;
        }
    }
}

int main() {
    char buffer[BUFFER_SIZE] = "Hello, World!";
    edit(buffer);
    return 0;
}
