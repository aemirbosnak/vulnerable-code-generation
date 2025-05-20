//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ARGS        10
#define MAX_LINE_LENGTH  100

int main()
{
    char line[MAX_LINE_LENGTH];
    char *args[MAX_ARGS];
    int argc = 0;

    while (1) {
        printf("# ");
        fgets(line, MAX_LINE_LENGTH, stdin);

        if (strlen(line) == 0) {
            continue;
        }

        args[0] = strtok(line, " ");
        for (argc = 1; argc < MAX_ARGS; argc++) {
            args[argc] = strtok(NULL, " ");
            if (args[argc] == NULL) {
                break;
            }
        }

        if (strcmp(args[0], "exit") == 0) {
            break;
        } else if (strcmp(args[0], "cd") == 0) {
            if (argc < 2) {
                fprintf(stderr, "Usage: cd <directory>\n");
            } else {
                if (chdir(args[1]) != 0) {
                    fprintf(stderr, "Error: Unable to change directory to %s\n", args[1]);
                }
            }
        } else if (strcmp(args[0], "ls") == 0) {
            if (argc < 2) {
                system("ls");
            } else {
                system("ls");
                system(args[1]);
            }
        } else {
            fprintf(stderr, "Error: Unknown command %s\n", args[0]);
        }
    }

    return 0;
}