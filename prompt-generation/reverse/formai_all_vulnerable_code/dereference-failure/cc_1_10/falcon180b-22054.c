//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000
#define MAX_VIRUSES 100

struct virus {
    char *name;
    char *signature;
};

int main() {
    FILE *file;
    char buffer[MAX_LENGTH];
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int count = 0;
    struct virus viruses[MAX_VIRUSES] = {{"Dummy Virus", "This is a dummy virus."}};

    printf("Welcome to Sherlock Holmes' C Antivirus Scanner!\n");
    printf("Scanning for %d known viruses...\n", MAX_VIRUSES);

    file = fopen("file.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    while ((read = getline(&line, &len, file))!= -1) {
        if (read > 0 && line[read - 1] == '\n') {
            line[--read] = '\0';
        }
        for (int i = 0; i < MAX_VIRUSES; i++) {
            if (strstr(line, viruses[i].signature)) {
                printf("Virus detected: %s\n", viruses[i].name);
                count++;
                break;
            }
        }
    }

    fclose(file);

    if (count == 0) {
        printf("No viruses found.\n");
    } else {
        printf("Total number of viruses found: %d\n", count);
    }

    return 0;
}