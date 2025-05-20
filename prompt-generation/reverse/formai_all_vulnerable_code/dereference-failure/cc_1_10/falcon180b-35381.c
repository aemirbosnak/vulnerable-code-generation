//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_VIRUS_LENGTH 1024
#define VIRUS_COUNT 5

char viruses[VIRUS_COUNT][MAX_VIRUS_LENGTH] = {
    "virus1",
    "virus2",
    "virus3",
    "virus4",
    "virus5"
};

int main(int argc, char *argv[]) {
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int virus_count = 0;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        exit(1);
    }

    while ((read = getline(&line, &len, file))!= -1) {
        for (int i = 0; i < VIRUS_COUNT; i++) {
            if (strstr(line, viruses[i])!= NULL) {
                printf("Virus found: %s\n", viruses[i]);
                virus_count++;
            }
        }
    }

    if (virus_count == 0) {
        printf("No viruses found.\n");
    } else {
        printf("%d viruses found.\n", virus_count);
    }

    free(line);
    fclose(file);
    return 0;
}