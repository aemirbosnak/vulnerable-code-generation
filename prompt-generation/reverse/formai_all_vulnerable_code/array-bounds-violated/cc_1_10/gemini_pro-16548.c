//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIGS 100
#define MAX_SIG_LEN 100

typedef struct {
    char *sig;
    int len;
} sig_t;

sig_t sigs[MAX_SIGS];
int num_sigs;

int load_sigs() {
    FILE *fp = fopen("sigs.txt", "r");
    if (fp == NULL) {
        return -1;
    }

    char line[MAX_SIG_LEN + 1];
    while (fgets(line, sizeof(line), fp) != NULL) {
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }

        sigs[num_sigs].sig = strdup(line);
        sigs[num_sigs].len = strlen(line);
        num_sigs++;
    }

    fclose(fp);

    return 0;
}

int scan_file(FILE *fp) {
    char buf[1024];
    int found = 0;

    while (fread(buf, sizeof(char), sizeof(buf), fp) == sizeof(buf)) {
        for (int i = 0; i < num_sigs; i++) {
            if (strstr(buf, sigs[i].sig) != NULL) {
                printf("Found virus! %s\n", sigs[i].sig);
                found = 1;
            }
        }
    }

    return found;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return -1;
    }

    if (load_sigs() < 0) {
        printf("Error loading signatures.\n");
        return -1;
    }

    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return -1;
    }

    int found = scan_file(fp);

    fclose(fp);

    if (found) {
        printf("File is infected.\n");
    } else {
        printf("File is clean.\n");
    }

    return 0;
}