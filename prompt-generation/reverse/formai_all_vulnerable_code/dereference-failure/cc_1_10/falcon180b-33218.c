//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME 256
#define MAX_LINE_LENGTH 1024
#define MAX_NUM_VIRUSES 10

typedef struct {
    char name[MAX_FILE_NAME];
    FILE *fp;
} FILE_DATA;

typedef struct {
    char *name;
    int (*scanner)(char *);
} VIRUS_DATA;

int count_viruses = 0;
VIRUS_DATA viruses[MAX_NUM_VIRUSES];

int is_virus(char *line) {
    for (int i = 0; i < count_viruses; i++) {
        if (viruses[i].scanner(line)) {
            return 1;
        }
    }
    return 0;
}

void register_virus(char *name, int (*scanner)(char *)) {
    if (count_viruses >= MAX_NUM_VIRUSES) {
        printf("Error: Too many viruses registered.\n");
        return;
    }
    viruses[count_viruses].name = name;
    viruses[count_viruses].scanner = scanner;
    count_viruses++;
}

int romeo_scanner(char *line) {
    if (strstr(line, "Romeo")!= NULL) {
        return 1;
    }
    return 0;
}

int juliet_scanner(char *line) {
    if (strstr(line, "Juliet")!= NULL) {
        return 1;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE_DATA file_data;
    file_data.name[0] = '\0';
    strncpy(file_data.name, argv[1], MAX_FILE_NAME - 1);

    file_data.fp = fopen(argv[1], "r");
    if (file_data.fp == NULL) {
        printf("Error: Could not open file '%s'.\n", argv[1]);
        return 1;
    }

    register_virus("Romeo", romeo_scanner);
    register_virus("Juliet", juliet_scanner);

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file_data.fp)!= NULL) {
        if (is_virus(line)) {
            printf("Virus found in line: %s\n", line);
        }
    }

    fclose(file_data.fp);
    return 0;
}