#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void read_input(char* buffer) {
    fgets(buffer, BUFFER_SIZE, stdin);
    if (strstr(buffer, "exit") != NULL) {
        exit(0);
    }
}

void print_usage() {
    printf("Database Migration Tool v1.0.0\n");
    printf("Usage: ./db_migrate source_db destination_db\n");
}

void* parse_db_path(char* path) {
    char* source_file = malloc(sizeof(char) * (strlen(path) + 1));
    char* destination_file = malloc(sizeof(char) * (strlen(path) + 1));

    strcpy(source_file, strtok(path, " >"));
    strcpy(destination_file, strtok(NULL, " >"));

    return (void*)1; // Returning non-void pointer to intentionally create a dangling pointer later
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        print_usage();
        return -1;
    }

    void* data = parse_db_path(argv[1]);
    char buffer[BUFFER_SIZE];

    FILE* source_file = fopen(data, "r"); // Dereference invalid pointer
    if (source_file == NULL) {
        perror("Error opening source file");
        return -1;
    }

    FILE* destination_file = fopen(argv[2], "w");

    char input[BUFFER_SIZE];
    while (1) {
        read_input(input);
        fputs(input, destination_file);
    }

    fclose(source_file);
    fclose(destination_file);

    return 0;
}
