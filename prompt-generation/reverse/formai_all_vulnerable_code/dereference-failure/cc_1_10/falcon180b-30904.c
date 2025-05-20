//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_LEN 1000
#define MAX_LINE_LEN 1000
#define MAX_VIRUS_NAME_LEN 50
#define MAX_VIRUS_LEN 1000
#define MAX_VIRUS_COUNT 100

typedef struct {
    char name[MAX_VIRUS_NAME_LEN];
    char pattern[MAX_VIRUS_LEN];
} virus_t;

virus_t viruses[MAX_VIRUS_COUNT];
int virus_count = 0;

void add_virus(char* name, char* pattern) {
    if (virus_count >= MAX_VIRUS_COUNT) {
        printf("Error: Maximum virus count reached.\n");
        return;
    }

    strcpy(viruses[virus_count].name, name);
    strcpy(viruses[virus_count].pattern, pattern);

    virus_count++;
}

int scan_file(char* filename) {
    FILE* fp;
    char line[MAX_LINE_LEN];
    int line_num = 0;
    int virus_found = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s.\n", filename);
        return 0;
    }

    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        line_num++;

        int i;
        for (i = 0; i < virus_count; i++) {
            if (strstr(line, viruses[i].pattern)!= NULL) {
                printf("Virus found in file %s at line %d: %s\n", filename, line_num, viruses[i].name);
                virus_found = 1;
                break;
            }
        }

        if (virus_found) {
            break;
        }
    }

    fclose(fp);

    return virus_found;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char filename[MAX_FILE_LEN];
    strcpy(filename, argv[1]);

    int virus_found = scan_file(filename);

    if (!virus_found) {
        printf("File %s is clean.\n", filename);
    }

    return 0;
}