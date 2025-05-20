//Code Llama-13B DATASET v1.0 Category: File system simulation ; Style: configurable
/*
 * A simple file system simulation program
 *
 * Usage:
 *  ./file_system [command] [arguments]
 *
 * Commands:
 *  create [file name] - create a new file
 *  write [file name] [data] - write data to a file
 *  read [file name] - read data from a file
 *  delete [file name] - delete a file
 *  list - list all files in the file system
 *  exit - exit the program
 *
 * Example:
 *  ./file_system create test.txt
 *  ./file_system write test.txt "Hello, World!"
 *  ./file_system read test.txt
 *  ./file_system delete test.txt
 *  ./file_system list
 *  ./file_system exit
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 256
#define MAX_FILE_SIZE 1024

typedef struct {
    char name[MAX_FILE_NAME];
    char data[MAX_FILE_SIZE];
} File;

File* files[MAX_FILE_NAME];
int num_files = 0;

void create_file(char* name) {
    File* file = malloc(sizeof(File));
    strcpy(file->name, name);
    file->data[0] = '\0';
    files[num_files++] = file;
}

void write_file(char* name, char* data) {
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i]->name, name) == 0) {
            strcpy(files[i]->data, data);
            return;
        }
    }
}

void read_file(char* name) {
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i]->name, name) == 0) {
            printf("%s\n", files[i]->data);
            return;
        }
    }
}

void delete_file(char* name) {
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i]->name, name) == 0) {
            free(files[i]);
            files[i] = files[--num_files];
            return;
        }
    }
}

void list_files() {
    for (int i = 0; i < num_files; i++) {
        printf("%s\n", files[i]->name);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s [command] [arguments]\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "create") == 0) {
        create_file(argv[2]);
    } else if (strcmp(argv[1], "write") == 0) {
        write_file(argv[2], argv[3]);
    } else if (strcmp(argv[1], "read") == 0) {
        read_file(argv[2]);
    } else if (strcmp(argv[1], "delete") == 0) {
        delete_file(argv[2]);
    } else if (strcmp(argv[1], "list") == 0) {
        list_files();
    } else if (strcmp(argv[1], "exit") == 0) {
        return 0;
    } else {
        printf("Invalid command\n");
        return 1;
    }

    return 0;
}