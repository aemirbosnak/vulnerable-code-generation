#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void edit_text(char *text) {
    char buffer[10];
    printf("Enter new text: ");
    if (sscanf(text, "%9s", buffer) != 1) {
        fprintf(stderr, "Error reading input.\n");
        return;
    }
    printf("Text edited to: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <initial_text>\n", argv[0]);
        return 1;
    }

    char initial_text[100];
    snprintf(initial_text, sizeof(initial_text), "%s", argv[1]);

    while (1) {
        printf("Current text: %s\n", initial_text);
        printf("Type 'edit' to change text, 'exit' to quit: ");
        char command[10];
        scanf("%9s", command);

        if (strcmp(command, "edit") == 0) {
            char new_text[100];
            printf("Enter new text: ");
            fgets(new_text, sizeof(new_text), stdin);
            new_text[strcspn(new_text, "\n")] = '\0';
            edit_text(new_text);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Unknown command.\n");
        }
    }

    return 0;
}
