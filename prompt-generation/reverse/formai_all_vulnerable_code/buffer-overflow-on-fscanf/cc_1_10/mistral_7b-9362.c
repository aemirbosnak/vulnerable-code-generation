//MISTRAL-7B DATASET v1.0 Category: Antivirus scanner ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIG_LEN 50
#define MAX_FILE_SIZE 1024 * 1024
#define NUM_SIGS 10

char signatures[NUM_SIGS][MAX_SIG_LEN];
int sig_lengths[NUM_SIGS];

void read_signatures() {
    FILE *fp;
    int i = 0;
    fp = fopen("signatures.txt", "r");
    while (fscanf(fp, "%s%n", signatures[i], &i) != EOF) {
        sig_lengths[i] = strlen(signatures[i]);
    }
    fclose(fp);
}

int scan_file(char *filename) {
    FILE *fp;
    char file_content[MAX_FILE_SIZE];
    int i, j;
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    if (fread(file_content, sizeof(char), MAX_FILE_SIZE, fp) > 0) {
        for (i = 0; i < NUM_SIGS; i++) {
            for (j = 0; j < sig_lengths[i]; j++) {
                if (file_content[j] != signatures[i][j]) {
                    break;
                }
                if (j == sig_lengths[i] - 1) {
                    printf("%s found in %s\n", signatures[i], filename);
                    fclose(fp);
                    return 1;
                }
            }
        }
    }

    fclose(fp);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    read_signatures();
    scan_file(argv[1]);
    return 0;
}