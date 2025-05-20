//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1024
#define MAX_VIRUSES 10
#define VIRUS_NAME_SIZE 20

typedef struct {
    char name[VIRUS_NAME_SIZE];
    char signature[MAX_SIZE];
} virus;

int load_virus_database(virus *database, int size) {
    FILE *file = fopen("virus_database.txt", "r");

    if (file == NULL) {
        printf("Error: could not open virus database file.\n");
        return 0;
    }

    int count = 0;

    while (fscanf(file, "%s %s", database[count].name, database[count].signature)!= EOF) {
        count++;
    }

    fclose(file);

    return count;
}

int scan_file(char *filename, virus *database, int size) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: could not open file %s.\n", filename);
        return 0;
    }

    char buffer[MAX_SIZE];
    char *line = NULL;
    size_t len = 0;
    size_t read = 0;

    while ((read = getline(&line, &len, file))!= -1) {
        int i;
        for (i = 0; i < size; i++) {
            if (strstr(line, database[i].signature)!= NULL) {
                printf("Virus found in file %s: %s\n", filename, database[i].name);
                return 1;
            }
        }
    }

    fclose(file);

    return 0;
}

int main(int argc, char *argv[]) {
    virus database[MAX_VIRUSES];
    int size = load_virus_database(database, MAX_VIRUSES);

    if (size == 0) {
        return 1;
    }

    int i;
    for (i = 0; i < size; i++) {
        printf("Loaded virus signature: %s\n", database[i].name);
    }

    int result;
    char filename[MAX_SIZE];

    while (1) {
        printf("Enter file to scan: ");
        scanf("%s", filename);

        result = scan_file(filename, database, size);

        if (result == 1) {
            break;
        }
    }

    return 0;
}