//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define BUFFER_SIZE 4096

void die(const char *msg, int status) {
    perror(msg);
    exit(status);
}

int main(void) {
    char line[MAX_LINE_LENGTH];
    char buffer[BUFFER_SIZE];
    FILE *fp;

    if ((fp = fopen("input.txt", "r")) == NULL) {
        fprintf(stderr, "Could not open file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        size_t len = strlen(line);
        if (line[len - 1] == '\n') line[len - 1] = '\0'; // remove newline character

        int num;
        char *endptr;
        errno = 0;

        num = strtol(line, &endptr, 10);
        if (errno != 0) {
            fprintf(stderr, "Invalid number: %s\n", strerror(errno));
            continue;
        }

        if (endptr == line) {
            fprintf(stderr, "Empty line\n");
            continue;
        }

        int i;
        for (i = 0; line[i] != '\0'; i++) {
            if (!isdigit(line[i])) {
                fprintf(stderr, "Invalid character: %c\n", line[i]);
                break;
            }
        }

        if (i < strlen(line)) {
            fprintf(stderr, "Line '%s' contains non-numeric characters\n", line);
            continue;
        }

        errno = 0;
        int result = scanf("%s%d", buffer, &num);
        if (errno != 0 || result != 2) {
            fprintf(stderr, "Error reading number from line '%s'\n", line);
            continue;
        }

        if (num > 100) {
            sprintf(buffer, "Number '%d' too large\n", num);
            die(buffer, EXIT_FAILURE);
        }

        // process the number here
        printf("Number: %d\n", num);
    }

    if (ferror(fp)) {
        fprintf(stderr, "Error reading file\n");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    fclose(fp);
    return EXIT_SUCCESS;
}