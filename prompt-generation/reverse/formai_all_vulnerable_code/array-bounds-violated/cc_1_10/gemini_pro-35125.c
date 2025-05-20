//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_SIGS 1024
#define MAX_SIG_LEN 128

typedef struct {
    uint8_t *sig;
    size_t len;
} signature;

signature sigs[MAX_SIGS];
size_t num_sigs = 0;

int load_sigs(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("fopen");
        return -1;
    }

    char line[MAX_SIG_LEN];
    while (fgets(line, sizeof(line), fp)) {
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }

        sigs[num_sigs].sig = malloc(strlen(line) + 1);
        if (!sigs[num_sigs].sig) {
            perror("malloc");
            return -1;
        }

        strcpy(sigs[num_sigs].sig, line);
        sigs[num_sigs].len = strlen(line);
        num_sigs++;
    }

    fclose(fp);
    return 0;
}

int scan_file(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("fopen");
        return -1;
    }

    fseek(fp, 0, SEEK_END);
    size_t filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    uint8_t *buffer = malloc(filesize);
    if (!buffer) {
        perror("malloc");
        return -1;
    }

    fread(buffer, filesize, 1, fp);
    fclose(fp);

    for (size_t i = 0; i < num_sigs; i++) {
        for (size_t j = 0; j < filesize - sigs[i].len + 1; j++) {
            if (memcmp(&buffer[j], sigs[i].sig, sigs[i].len) == 0) {
                printf("Virus detected: %s\n", sigs[i].sig);
                free(buffer);
                return 1;
            }
        }
    }

    free(buffer);
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <signature file> <file to scan>\n", argv[0]);
        return 1;
    }

    if (load_sigs(argv[1]) < 0) {
        return 1;
    }

    if (scan_file(argv[2]) < 0) {
        return 1;
    }

    printf("No virus detected\n");
    return 0;
}