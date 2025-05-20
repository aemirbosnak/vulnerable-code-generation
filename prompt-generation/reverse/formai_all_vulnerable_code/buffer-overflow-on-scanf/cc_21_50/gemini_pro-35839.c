//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

int main()
{
    char *args[10];
    int status;
    char cwd[1024];
    int fdi, fdo;
    int i, j, k, l, m, n;
    int pid;

    while(1)
    {
        printf("mysh> ");
        fflush(stdout);

        i = 0;
        while((args[i] = malloc(1024)) != NULL)
        {
            scanf("%s", args[i]);
            if(strcmp(args[i], "|") == 0)
            {
                args[i] = NULL;
                break;
            }
            i++;
        }

        if(strcmp(args[0], "exit") == 0)
        {
            for(j = 0; args[j] != NULL; j++)
            {
                free(args[j]);
            }
            exit(0);
        }

        if(strcmp(args[0], "cd") == 0)
        {
            if(args[1] != NULL)
            {
                if(chdir(args[1]) != 0)
                {
                    printf("Error: %s\n", strerror(errno));
                }
            }
            else
            {
                printf("Error: No directory specified\n");
            }
        }

        if(strcmp(args[0], "pwd") == 0)
        {
            if(getcwd(cwd, sizeof(cwd)) != NULL)
            {
                printf("%s\n", cwd);
            }
            else
            {
                printf("Error: %s\n", strerror(errno));
            }
        }

        if(strcmp(args[0], "echo") == 0)
        {
            for(j = 1; args[j] != NULL; j++)
            {
                if(j > 1)
                {
                    printf(" ");
                }
                printf("%s", args[j]);
            }
            printf("\n");
        }

        if(strcmp(args[0], "ls") == 0)
        {
            pid = fork();

            if(pid == 0)
            {
                if(execvp("ls", args) == -1)
                {
                    printf("Error: %s\n", strerror(errno));
                    exit(1);
                }
            }
            else if(pid > 0)
            {
                wait(&status);
            }
            else
            {
                printf("Error: %s\n", strerror(errno));
            }
        }

        if(strcmp(args[0], "cat") == 0)
        {
            pid = fork();

            if(pid == 0)
            {
                if((fdi = open(args[1], O_RDONLY)) == -1)
                {
                    printf("Error: %s\n", strerror(errno));
                    exit(1);
                }
                if((dup2(fdi, STDIN_FILENO)) == -1)
                {
                    printf("Error: %s\n", strerror(errno));
                    exit(1);
                }
                close(fdi);
                if(execvp("cat", args) == -1)
                {
                    printf("Error: %s\n", strerror(errno));
                    exit(1);
                }
            }
            else if(pid > 0)
            {
                wait(&status);
            }
            else
            {
                printf("Error: %s\n", strerror(errno));
            }
        }

        if(strcmp(args[0], "grep") == 0)
        {
            pid = fork();

            if(pid == 0)
            {
                if((fdo = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
                {
                    printf("Error: %s\n", strerror(errno));
                    exit(1);
                }
                if((dup2(fdo, STDOUT_FILENO)) == -1)
                {
                    printf("Error: %s\n", strerror(errno));
                    exit(1);
                }
                close(fdo);
                if(execvp("grep", args) == -1)
                {
                    printf("Error: %s\n", strerror(errno));
                    exit(1);
                }
            }
            else if(pid > 0)
            {
                wait(&status);
            }
            else
            {
                printf("Error: %s\n", strerror(errno));
            }
        }

        if(strcmp(args[0], "sort") == 0)
        {
            pid = fork();

            if(pid == 0)
            {
                if((fdi = open("output.txt", O_RDONLY)) == -1)
                {
                    printf("Error: %s\n", strerror(errno));
                    exit(1);
                }
                if((dup2(fdi, STDIN_FILENO)) == -1)
                {
                    printf("Error: %s\n", strerror(errno));
                    exit(1);
                }
                close(fdi);
                if(execvp("sort", args) == -1)
                {
                    printf("Error: %s\n", strerror(errno));
                    exit(1);
                }
            }
            else if(pid > 0)
            {
                wait(&status);
            }
            else
            {
                printf("Error: %s\n", strerror(errno));
            }
        }

        if(strcmp(args[0], "wc") == 0)
        {
            pid = fork();

            if(pid == 0)
            {
                if((fdi = open("output.txt", O_RDONLY)) == -1)
                {
                    printf("Error: %s\n", strerror(errno));
                    exit(1);
                }
                if((dup2(fdi, STDIN_FILENO)) == -1)
                {
                    printf("Error: %s\n", strerror(errno));
                    exit(1);
                }
                close(fdi);
                if(execvp("wc", args) == -1)
                {
                    printf("Error: %s\n", strerror(errno));
                    exit(1);
                }
            }
            else if(pid > 0)
            {
                wait(&status);
            }
            else
            {
                printf("Error: %s\n", strerror(errno));
            }
        }

        for(j = 0; args[j] != NULL; j++)
        {
            free(args[j]);
        }
    }

    return 0;
}