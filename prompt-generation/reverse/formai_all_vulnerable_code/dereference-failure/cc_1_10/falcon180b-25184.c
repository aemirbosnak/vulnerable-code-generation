//Falcon-180B DATASET v1.0 Category: File handling ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000 // Define the maximum length of a line
#define MAX_FILE_SIZE 1000000 // Define the maximum size of the file

struct line {
    char *text;
    int length;
    struct line *next;
};

struct file {
    char *filename;
    FILE *file;
    struct line *head;
    int size;
};

void init_file(struct file *file) {
    file->head = NULL;
    file->size = 0;
}

void append_line(struct file *file, char *text) {
    struct line *new_line = malloc(sizeof(struct line));
    new_line->text = strdup(text);
    new_line->length = strlen(text);
    new_line->next = NULL;

    if (file->head == NULL) {
        file->head = new_line;
    } else {
        struct line *last_line = file->head;
        while (last_line->next!= NULL) {
            last_line = last_line->next;
        }
        last_line->next = new_line;
    }

    file->size++;
}

void print_file(struct file *file) {
    struct line *current_line = file->head;
    while (current_line!= NULL) {
        printf("%s\n", current_line->text);
        current_line = current_line->next;
    }
}

void close_file(struct file *file) {
    fclose(file->file);
    struct line *current_line = file->head;
    while (current_line!= NULL) {
        free(current_line->text);
        current_line = current_line->next;
    }
    free(file->head);
    free(file->filename);
    free(file);
}

int main() {
    struct file file;
    init_file(&file);

    char filename[MAX_LINE_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);
    file.filename = strdup(filename);

    file.file = fopen(filename, "r");

    if (file.file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file.file)!= NULL) {
        append_line(&file, line);
        if (file.size >= MAX_FILE_SIZE) {
            printf("Maximum file size reached.\n");
            break;
        }
    }

    fclose(file.file);
    print_file(&file);

    close_file(&file);

    return 0;
}