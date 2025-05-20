//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void read_file(char *filename, char **buffer) {
    FILE *fp;
    size_t file_size;
    char *file_buffer;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    rewind(fp);

    file_buffer = malloc(file_size + 1);
    if (file_buffer == NULL) {
        printf("Error: could not allocate memory\n");
        exit(1);
    }

    fread(file_buffer, file_size, 1, fp);
    fclose(fp);

    *buffer = file_buffer;
}

int main(int argc, char **argv) {
    char *filename;
    char *buffer;
    char *search_term;
    char *recovery_filename;
    size_t search_term_length;
    size_t recovery_filename_length;
    size_t recovery_file_size;
    FILE *recovery_fp;
    char *recovery_buffer;

    printf("Enter the name of the file to recover data from: ");
    scanf("%s", filename);

    read_file(filename, &buffer);

    printf("Enter the term to search for: ");
    scanf("%s", search_term);
    search_term_length = strlen(search_term);

    printf("Enter the name of the recovery file: ");
    scanf("%s", recovery_filename);
    recovery_filename_length = strlen(recovery_filename);

    recovery_file_size = strlen(buffer) - search_term_length + recovery_filename_length;
    recovery_buffer = malloc(recovery_file_size + 1);
    if (recovery_buffer == NULL) {
        printf("Error: could not allocate memory\n");
        exit(1);
    }

    strcpy(recovery_buffer, buffer);
    strcpy(recovery_buffer + strlen(buffer) - search_term_length, recovery_filename);

    recovery_fp = fopen(recovery_filename, "wb");
    if (recovery_fp == NULL) {
        printf("Error: could not open file '%s'\n", recovery_filename);
        exit(1);
    }

    fwrite(recovery_buffer, recovery_file_size, 1, recovery_fp);
    fclose(recovery_fp);

    printf("Data recovery successful!\n");

    free(buffer);
    free(recovery_buffer);

    return 0;
}