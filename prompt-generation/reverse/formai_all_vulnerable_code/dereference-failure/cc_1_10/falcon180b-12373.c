//Falcon-180B DATASET v1.0 Category: File handling ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *name;
    FILE *fp;
    struct file_list *next;
} file_list;

file_list *head = NULL;

void add_file(char *filename) {
    file_list *new_file = (file_list *) malloc(sizeof(file_list));
    new_file->name = strdup(filename);
    new_file->fp = fopen(filename, "r");
    new_file->next = NULL;

    if (head == NULL) {
        head = new_file;
    } else {
        file_list *current = head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_file;
    }
}

void close_files() {
    file_list *current = head;
    while (current!= NULL) {
        fclose(current->fp);
        free(current->name);
        current = current->next;
    }
    head = NULL;
}

void read_files(file_list *files, char **buffer, int *size) {
    if (files == NULL) {
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, files->fp)!= NULL) {
        int line_length = strlen(line);
        if (*size + line_length + 1 > *size) {
            *buffer = (char *) realloc(*buffer, *size + line_length + 1);
            *size += line_length + 1;
        }
        strcat(*buffer, line);
    }

    read_files(files->next, buffer, size);
}

void print_files(file_list *files) {
    if (files == NULL) {
        return;
    }

    printf("File: %s\n", files->name);
    char *buffer = NULL;
    int size = 0;
    read_files(files, &buffer, &size);
    printf("Contents:\n%s", buffer);
    free(buffer);

    print_files(files->next);
}

int main() {
    add_file("file1.txt");
    add_file("file2.txt");
    add_file("file3.txt");

    print_files(head);

    close_files();

    return 0;
}