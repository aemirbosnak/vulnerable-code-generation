//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIG_LEN 1024
#define MAX_SIG_COUNT 100

typedef struct signature {
    char *pattern;
    int len;
} signature;

signature signatures[MAX_SIG_COUNT];
int sig_count = 0;

void load_signatures(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening signature file: %s\n", filename);
        exit(1);
    }

    char line[MAX_SIG_LEN];
    while (fgets(line, MAX_SIG_LEN, fp) != NULL) {
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';  // remove newline
        }

        signatures[sig_count].pattern = strdup(line);
        signatures[sig_count].len = strlen(line);
        sig_count++;
    }

    fclose(fp);
}

int scan_file(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    unsigned char *buffer = malloc(filesize);
    if (buffer == NULL) {
        fprintf(stderr, "Error allocating memory for file buffer\n");
        fclose(fp);
        return 1;
    }

    fread(buffer, filesize, 1, fp);
    fclose(fp);

    for (int i = 0; i < sig_count; i++) {
        for (int j = 0; j < filesize - signatures[i].len; j++) {
            if (memcmp(&buffer[j], signatures[i].pattern, signatures[i].len) == 0) {
                printf("Found virus signature: %s\n", signatures[i].pattern);
                free(buffer);
                return 1;
            }
        }
    }

    free(buffer);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <signature file> <file to scan>\n", argv[0]);
        return 1;
    }

    // Load virus signatures
    load_signatures(argv[1]);

    // Scan file
    int result = scan_file(argv[2]);

    // Exit
    if (result) {
        printf("File contains a virus!\n");
        return 1;
    } else {
        printf("File is clean\n");
        return 0;
    }
}