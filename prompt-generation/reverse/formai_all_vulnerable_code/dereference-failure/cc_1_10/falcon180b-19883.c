//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define MAX_COMMANDS 100
#define DELIM " "

char *programs[MAX_COMMANDS];

int main(int argc, char *argv[]) {
    int i, j, k, num_progs, status;
    char input[1024];
    char *token;

    printf("Enter the number of programs to run: ");
    scanf("%d", &num_progs);

    for (i = 0; i < num_progs; i++) {
        printf("Enter program %d: ", i + 1);
        fgets(input, sizeof(input), stdin);
        programs[i] = strdup(input);
        programs[i][strcspn(programs[i], "\n")] = '\0';
    }

    for (i = 0; i < num_progs; i++) {
        token = strtok(programs[i], DELIM);
        while (token!= NULL) {
            if (strcmp(token, ">") == 0) {
                token = strtok(NULL, DELIM);
                if (token!= NULL) {
                    programs[i] = realloc(programs[i], strlen(programs[i]) + strlen(token) + 2);
                    strcat(programs[i], " > ");
                    strcat(programs[i], token);
                }
            }
            token = strtok(NULL, DELIM);
        }
    }

    for (i = 0; i < num_progs; i++) {
        printf("Running program %d: %s\n", i + 1, programs[i]);
        if (fork() == 0) {
            if (execvp(programs[i], NULL) == -1) {
                perror("execvp");
            }
            exit(EXIT_FAILURE);
        }
    }

    for (i = 0; i < num_progs; i++) {
        waitpid(0, &status, WNOHANG);
    }

    return 0;
}