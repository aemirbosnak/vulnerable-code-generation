//Code Llama-13B DATASET v1.0 Category: File handling ; Style: Donald Knuth
// Donald Knuth style file handling program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

int main() {
    char filename[MAX_SIZE];
    char mode[MAX_SIZE];
    char buffer[MAX_SIZE];

    printf("Enter filename: ");
    fgets(filename, MAX_SIZE, stdin);
    filename[strlen(filename) - 1] = '\0'; // remove newline

    printf("Enter file mode (r/w): ");
    fgets(mode, MAX_SIZE, stdin);
    mode[strlen(mode) - 1] = '\0'; // remove newline

    if (strcmp(mode, "r") == 0) {
        FILE *fp = fopen(filename, "r");
        if (fp == NULL) {
            perror("Error opening file");
            exit(1);
        }

        while (fgets(buffer, MAX_SIZE, fp) != NULL) {
            printf("%s", buffer);
        }

        fclose(fp);
    } else if (strcmp(mode, "w") == 0) {
        FILE *fp = fopen(filename, "w");
        if (fp == NULL) {
            perror("Error opening file");
            exit(1);
        }

        printf("Enter text to write: ");
        fgets(buffer, MAX_SIZE, stdin);
        buffer[strlen(buffer) - 1] = '\0'; // remove newline

        fprintf(fp, "%s", buffer);

        fclose(fp);
    } else {
        printf("Invalid file mode\n");
    }

    return 0;
}