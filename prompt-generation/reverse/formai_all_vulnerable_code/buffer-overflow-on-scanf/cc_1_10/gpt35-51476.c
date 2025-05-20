//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME_MAX_LEN 256

void scan_file(char *filename);

int main() {
    char file_name[FILE_NAME_MAX_LEN];

    printf("Welcome to our cheerful C Antivirus!\n");
    printf("Please enter the name of the file you want to scan: ");
    scanf("%s", file_name);

    scan_file(file_name);

    return 0;
}

void scan_file(char *filename) {
    FILE *file = fopen(filename, "r");
    char c;
    int virus_detected = 0;

    if (file == NULL) {
        printf("Could not open file.\n");
        exit(1);
    }

    printf("Scanning %s...\n", filename);

    while ((c = fgetc(file)) != EOF) {
        if (c == 'v') {
            c = fgetc(file);
            if (c == 'i') {
                c = fgetc(file);
                if (c == 'r') {
                    c = fgetc(file);
                    if (c == 'u') {
                        c = fgetc(file);
                        if (c == 's') {
                            virus_detected = 1;
                            break;
                        }
                    }
                }
            }
        }
    }

    if (virus_detected) {
        printf("Virus detected in %s!\n", filename);
    } else {
        printf("%s is virus-free. Hooray!\n", filename);
    }

    fclose(file);
}