//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME 100
#define MAX_LINE_SIZE 1000
#define MAX_VIRUS_NAME 50
#define MAX_VIRUS_SIZE 1000

typedef struct {
    char name[MAX_VIRUS_NAME];
    char pattern[MAX_VIRUS_SIZE];
} Virus;

int load_virus_database(Virus *database, int count) {
    int i;
    FILE *fp;
    char line[MAX_LINE_SIZE];

    fp = fopen("virus_database.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open virus database file.\n");
        exit(1);
    }

    i = 0;
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        if (i >= count) {
            printf("Warning: Virus database is full.\n");
            break;
        }
        if (sscanf(line, "%s %s", database[i].name, database[i].pattern)!= 2) {
            printf("Error: Invalid virus definition in database file.\n");
            exit(1);
        }
        i++;
    }

    fclose(fp);
    return i;
}

int scan_file(char *filename, Virus *database, int count) {
    FILE *fp;
    char line[MAX_LINE_SIZE];
    int i, j, found = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'.\n", filename);
        exit(1);
    }

    i = 0;
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        for (j = 0; j < count; j++) {
            if (strstr(line, database[j].pattern)!= NULL) {
                printf("Virus found: %s\n", database[j].name);
                found = 1;
                break;
            }
        }
        if (found) break;
    }

    fclose(fp);
    return found;
}

int main(int argc, char *argv[]) {
    Virus virus_database[MAX_VIRUS_NAME];
    int virus_count;

    virus_count = load_virus_database(virus_database, MAX_VIRUS_NAME);

    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        exit(1);
    }

    if (scan_file(argv[1], virus_database, virus_count)) {
        exit(1);
    } else {
        printf("No viruses found in '%s'.\n", argv[1]);
        exit(0);
    }
}