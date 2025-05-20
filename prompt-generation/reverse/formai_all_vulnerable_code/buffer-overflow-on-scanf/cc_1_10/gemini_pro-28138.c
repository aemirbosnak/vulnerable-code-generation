//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: inquisitive
// Embark on a whimsical journey through the realm of command-line adventures!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Define an array of commands to explore
char *commands[] = {
    "echo", "ls", "pwd", "cd", "cat", "grep", "wc", "ps", "kill", "exit"
};

// Introduce your intrepid shell
int main() {
    printf("\nWelcome to the realm of the Inquisitive Shell!\n");

    // Prompt the user for their next escapade
    char input[100];
    printf("\nEnter thy command, intrepid adventurer: ");
    scanf("%s", input);

    // Embark on a search for the user's desired command
    int found = 0;
    for (int i = 0; i < sizeof(commands) / sizeof(char *); i++) {
        if (strcmp(input, commands[i]) == 0) {
            found = 1;
            break;
        }
    }

    // Guide the user's command into existence
    if (found) {
        pid_t pid = fork();
        if (pid == 0) {  // Child process
            execlp(input, input, NULL);
            perror("Failed to execute command");
            exit(1);
        } else {  // Parent process
            int status;
            wait(&status);
            printf("Thy command hath been executed, o mighty one.\n");
        }
    } else {
        printf("Alas, such a command does not reside within my repertoire.\n");
    }

    // Embark on further adventures or bid farewell
    printf("\nWouldst thou embark on another quest? (Y/N) ");
    char choice;
    scanf(" %c", &choice);
    if (choice == 'Y') {
        main();
    } else {
        printf("\nFarewell, intrepid adventurer. May thy future quests be fruitful!\n\n");
    }

    return 0;
}