//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE 1000000
#define MAX_LINE_SIZE 1024
#define MAX_VIRUS_NAME_SIZE 64
#define MAX_VIRUS_PATTERN_SIZE 100

typedef struct {
    char *name;
    char *pattern;
} virus_t;

void load_viruses(virus_t *viruses, int num_viruses) {
    FILE *fp = fopen("viruses.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open viruses.txt\n");
        exit(1);
    }

    for (int i = 0; i < num_viruses; i++) {
        char name[MAX_VIRUS_NAME_SIZE];
        char pattern[MAX_VIRUS_PATTERN_SIZE];

        fscanf(fp, "%s %s\n", name, pattern);
        viruses[i].name = strdup(name);
        viruses[i].pattern = strdup(pattern);
    }

    fclose(fp);
}

void scan_file(FILE *fp, virus_t *viruses, int num_viruses) {
    char line[MAX_LINE_SIZE];
    int line_num = 1;

    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        int match = 0;
        for (int i = 0; i < num_viruses; i++) {
            if (strstr(line, viruses[i].pattern)!= NULL) {
                printf("Virus found on line %d: %s\n", line_num, viruses[i].name);
                match = 1;
                break;
            }
        }

        if (!match) {
            printf("Clean line %d\n", line_num);
        }

        line_num++;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open %s\n", argv[1]);
        exit(1);
    }

    virus_t viruses[10];
    int num_viruses = 0;
    load_viruses(viruses, num_viruses);

    scan_file(fp, viruses, num_viruses);

    fclose(fp);
    return 0;
}