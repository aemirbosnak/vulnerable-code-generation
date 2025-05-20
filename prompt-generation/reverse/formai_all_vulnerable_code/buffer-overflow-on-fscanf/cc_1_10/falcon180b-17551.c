//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1000
#define MAX_VIRUSES 100

typedef struct {
    char name[MAX_LINE_SIZE];
    char signature[MAX_LINE_SIZE];
} virus;

int load_viruses(virus *viruses) {
    FILE *f = fopen("viruses.txt", "r");
    if (f == NULL) {
        printf("Error loading viruses\n");
        return 1;
    }

    int count = 0;
    while (fscanf(f, "%s %s", viruses[count].name, viruses[count].signature) == 2) {
        count++;
        if (count >= MAX_VIRUSES) {
            printf("Too many viruses\n");
            return 1;
        }
    }

    fclose(f);
    return 0;
}

int scan_file(char *filename, virus *viruses) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    char line[MAX_LINE_SIZE];
    int line_number = 1;
    while (fgets(line, MAX_LINE_SIZE, f)!= NULL) {
        int i;
        for (i = 0; i < strlen(line); i++) {
            if (!isprint(line[i])) {
                printf("Suspicious character at line %d\n", line_number);
            }
        }

        int j;
        for (j = 0; j < MAX_VIRUSES; j++) {
            if (strstr(line, viruses[j].signature)!= NULL) {
                printf("Virus found at line %d: %s\n", line_number, viruses[j].name);
            }
        }

        line_number++;
    }

    fclose(f);
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    virus viruses[MAX_VIRUSES];
    if (load_viruses(viruses)!= 0) {
        return 1;
    }

    if (scan_file(argv[1], viruses)!= 0) {
        return 1;
    }

    return 0;
}