//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1024
#define MAX_FILE 100
#define MAX_STRING 100
#define MAX_VIRUS 100

typedef struct {
    char *name;
    int count;
} File;

typedef struct {
    char *name;
    int count;
} Virus;

File files[MAX_FILE];
Virus viruses[MAX_VIRUS];

int main() {
    int i, j, k, count = 0, virus_count = 0;
    char line[MAX_LINE];
    char *filename = "file.txt";
    char *virusname = "virus.txt";
    FILE *file = fopen(filename, "r");
    FILE *virusfile = fopen(virusname, "r");

    if (file == NULL || virusfile == NULL) {
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE, file)!= NULL) {
        char *name = strtok(line, " ");
        for (i = 0; i < count; i++) {
            if (strcmp(name, files[i].name) == 0) {
                files[i].count++;
                break;
            }
        }
        if (i == count) {
            files[count].name = strdup(name);
            files[count].count = 1;
            count++;
        }
    }

    fclose(file);

    while (fgets(line, MAX_LINE, virusfile)!= NULL) {
        char *name = strtok(line, " ");
        for (i = 0; i < virus_count; i++) {
            if (strcmp(name, viruses[i].name) == 0) {
                viruses[i].count++;
                break;
            }
        }
        if (i == virus_count) {
            viruses[virus_count].name = strdup(name);
            viruses[virus_count].count = 1;
            virus_count++;
        }
    }

    fclose(virusfile);

    for (i = 0; i < count; i++) {
        for (j = 0; j < virus_count; j++) {
            if (strcmp(files[i].name, viruses[j].name) == 0) {
                printf("File %s is infected with %s\n", files[i].name, viruses[j].name);
                break;
            }
        }
    }

    return 0;
}