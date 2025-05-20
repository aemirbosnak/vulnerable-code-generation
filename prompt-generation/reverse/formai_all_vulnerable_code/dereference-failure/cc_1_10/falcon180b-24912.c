//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_NUM_OF_LINES 1000

typedef struct {
    char *line;
    int length;
} Line;

typedef struct {
    Line *lines;
    int num_of_lines;
    int current_line;
} Ebook;

void init_ebook(Ebook *ebook) {
    ebook->lines = (Line *) malloc(MAX_NUM_OF_LINES * sizeof(Line));
    ebook->num_of_lines = 0;
    ebook->current_line = 0;
}

void destroy_ebook(Ebook *ebook) {
    for (int i = 0; i < ebook->num_of_lines; i++) {
        free(ebook->lines[i].line);
    }
    free(ebook->lines);
}

void add_line(Ebook *ebook, char *line) {
    if (ebook->num_of_lines >= MAX_NUM_OF_LINES) {
        printf("Error: Maximum number of lines reached.\n");
        return;
    }
    ebook->lines[ebook->num_of_lines].line = (char *) malloc(strlen(line) + 1);
    strcpy(ebook->lines[ebook->num_of_lines].line, line);
    ebook->lines[ebook->num_of_lines].length = strlen(line);
    ebook->num_of_lines++;
}

void print_current_line(Ebook *ebook) {
    if (ebook->current_line >= ebook->num_of_lines) {
        printf("Error: No lines available.\n");
        return;
    }
    printf("%s", ebook->lines[ebook->current_line].line);
}

void print_next_line(Ebook *ebook) {
    if (ebook->current_line >= ebook->num_of_lines - 1) {
        printf("\n");
        return;
    }
    ebook->current_line++;
    printf("%s", ebook->lines[ebook->current_line].line);
}

void print_prev_line(Ebook *ebook) {
    if (ebook->current_line <= 0) {
        printf("\n");
        return;
    }
    ebook->current_line--;
    printf("%s", ebook->lines[ebook->current_line].line);
}

int main() {
    Ebook ebook;
    init_ebook(&ebook);

    char input[MAX_LINE_LENGTH];
    while (fgets(input, MAX_LINE_LENGTH, stdin)!= NULL) {
        add_line(&ebook, input);
    }

    int choice;
    while (1) {
        printf("\n");
        printf("1. Print next line\n");
        printf("2. Print previous line\n");
        printf("3. Print current line\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                print_next_line(&ebook);
                break;
            case 2:
                print_prev_line(&ebook);
                break;
            case 3:
                print_current_line(&ebook);
                break;
            case 4:
                destroy_ebook(&ebook);
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}