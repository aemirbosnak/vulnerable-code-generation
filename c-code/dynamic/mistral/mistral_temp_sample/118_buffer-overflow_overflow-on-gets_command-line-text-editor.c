#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024

char buffer[MAX_LINE];

void editor() {
    system("clear");
    printf("\nSimple Text Editor\n");
    while (1) {
        printf("\nBuffer: %s\n", buffer);
        printf("\n1. Edit\n2. Save\n3. Quit\n> ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter your edit: ");
                fgets(buffer, MAX_LINE, stdin);
                break;
            case 2:
                printf("\nSaving...\n");
                break;
            case 3:
                printf("\nExiting...\n");
                exit(0);
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    }
}

int main() {
    char *args[] = {"/bin/sh", NULL};
    char *env[] = {getenv("HOME"), NULL};

    while (1) {
        editor();
        args[0] = buffer;
        execvp(args[0], args);
        printf("\nError executing command. Try again.\n");
    }

    return 0;
}
