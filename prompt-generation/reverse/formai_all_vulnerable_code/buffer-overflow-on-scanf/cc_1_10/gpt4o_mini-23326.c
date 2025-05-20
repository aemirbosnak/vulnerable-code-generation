//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 256
#define CONFIG_FILE "config.txt"

typedef struct {
    char filename[MAX_LENGTH];
    int max_lines;
} Config;

void load_config(Config *config) {
    FILE *file = fopen(CONFIG_FILE, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open config file: %s\n", CONFIG_FILE);
        exit(EXIT_FAILURE);
    }

    fscanf(file, "filename: %s\n", config->filename);
    fscanf(file, "max_lines: %d\n", &config->max_lines);

    fclose(file);
}

void write_to_file(const Config *config) {
    FILE *file = fopen(config->filename, "a");
    if (file == NULL) {
        fprintf(stderr, "Could not open file: %s\n", config->filename);
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_LENGTH];
    printf("Enter text to append to the file (type 'exit' to stop):\n");

    int lines_written = 0;
    while (lines_written < config->max_lines) {
        fgets(buffer, sizeof(buffer), stdin);
        if (strcmp(buffer, "exit\n") == 0) {
            break;
        }
        fputs(buffer, file);
        lines_written++;
    }

    fclose(file);
    printf("Successfully wrote %d lines to %s\n", lines_written, config->filename);
}

void read_from_file(const Config *config) {
    FILE *file = fopen(config->filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file: %s\n", config->filename);
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_LENGTH];
    printf("Content of %s:\n", config->filename);
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }

    fclose(file);
}

void display_menu() {
    printf("\nFile Handling Menu:\n");
    printf("1. Write to file\n");
    printf("2. Read from file\n");
    printf("3. Exit\n");
}

int main() {
    Config config;
    load_config(&config);

    int choice;
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character left by scanf

        switch (choice) {
            case 1:
                write_to_file(&config);
                break;
            case 2:
                read_from_file(&config);
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 3);

    return 0;
}