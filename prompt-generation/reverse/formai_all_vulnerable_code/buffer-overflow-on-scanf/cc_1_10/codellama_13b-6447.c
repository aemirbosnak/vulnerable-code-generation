//Code Llama-13B DATASET v1.0 Category: File system simulation ; Style: interoperable
/*
 * File system simulation program
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store file information
struct file {
    char name[32];
    char contents[1024];
};

// Array to store file system
struct file fs[1024];

// Function to create a new file
void create_file(char *name) {
    int i;
    for (i = 0; i < 1024; i++) {
        if (fs[i].name[0] == '\0') {
            strcpy(fs[i].name, name);
            break;
        }
    }
}

// Function to read a file
void read_file(char *name) {
    int i;
    for (i = 0; i < 1024; i++) {
        if (strcmp(fs[i].name, name) == 0) {
            printf("%s\n", fs[i].contents);
            break;
        }
    }
}

// Function to write to a file
void write_file(char *name, char *contents) {
    int i;
    for (i = 0; i < 1024; i++) {
        if (strcmp(fs[i].name, name) == 0) {
            strcpy(fs[i].contents, contents);
            break;
        }
    }
}

int main() {
    char command[32];
    char name[32];
    char contents[1024];
    while (1) {
        printf("> ");
        scanf("%s", command);
        if (strcmp(command, "create") == 0) {
            scanf("%s", name);
            create_file(name);
        } else if (strcmp(command, "read") == 0) {
            scanf("%s", name);
            read_file(name);
        } else if (strcmp(command, "write") == 0) {
            scanf("%s", name);
            scanf("%s", contents);
            write_file(name, contents);
        } else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}