#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    char *buffer = NULL;
    size_t size = 0;

    // Allocate memory for the buffer
    buffer = malloc(size);

    // Read the command from the user
    char command[1024];
    printf("Enter a command: ");
    scanf("%s", command);

    // Execute the command
    if (strcmp(command, "quit") == 0) {
        free(buffer);
        exit(0);
    } else if (strcmp(command, "edit") == 0) {
        // Get the text from the user
        char text[4096];
        printf("Enter text: ");
        scanf("%s", text);

        // Append the text to the buffer
        size_t new_size = size + strlen(text) + 1;
        buffer = realloc(buffer, new_size);
        strcat(buffer, text);

        // Print the updated text
        printf("Updated text: %s", buffer);
    } else {
        printf("Invalid command.\n");
    }

    return 0;
}
