//Falcon-180B DATASET v1.0 Category: System administration ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>

#define BUF_SIZE 1024

void print_usage(char *prog_name) {
    printf("Usage: %s <command> [options]\n", prog_name);
    printf("Commands:\n");
    printf("  info\n");
    printf("  create\n");
    printf("  delete\n");
    printf("  rename\n");
    printf("  move\n");
    printf("  copy\n");
    printf("  list\n");
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        print_usage(argv[0]);
        return 1;
    }

    char *command = argv[1];
    int option_flag = 0;
    char *option = NULL;

    if (argc > 3) {
        option = argv[3];
        option_flag = 1;
    }

    switch (command[0]) {
        case 'i':
        case 'I':
            if (strcmp(command, "info") == 0) {
                printf("Info command\n");
            } else {
                printf("Invalid command\n");
            }
            break;
        case 'c':
        case 'C':
            if (strcmp(command, "create") == 0) {
                printf("Create command\n");
            } else if (strcmp(command, "copy") == 0) {
                printf("Copy command\n");
            } else {
                printf("Invalid command\n");
            }
            break;
        case 'd':
        case 'D':
            if (strcmp(command, "delete") == 0) {
                printf("Delete command\n");
            } else if (strcmp(command, "move") == 0) {
                printf("Move command\n");
            } else {
                printf("Invalid command\n");
            }
            break;
        case 'r':
        case 'R':
            if (strcmp(command, "rename") == 0) {
                printf("Rename command\n");
            } else {
                printf("Invalid command\n");
            }
            break;
        case 'l':
        case 'L':
            if (strcmp(command, "list") == 0) {
                printf("List command\n");
            } else {
                printf("Invalid command\n");
            }
            break;
        default:
            printf("Invalid command\n");
            break;
    }

    if (option_flag) {
        if (strcmp(option, "-f") == 0) {
            printf("Force option\n");
        } else {
            printf("Invalid option\n");
        }
    }

    return 0;
}