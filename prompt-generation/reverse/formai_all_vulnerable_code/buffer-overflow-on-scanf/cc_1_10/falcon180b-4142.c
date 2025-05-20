//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE 1000000
#define MAX_VIRUS_NAME_LENGTH 100
#define MAX_FILE_NAME_LENGTH 100

struct virus {
    char name[MAX_VIRUS_NAME_LENGTH];
    char signature[MAX_FILE_SIZE];
};

void read_virus_database(struct virus *virus_database, int num_viruses) {
    FILE *f = fopen("virus_database.txt", "r");
    if (f == NULL) {
        printf("Error: could not open virus database file.\n");
        exit(1);
    }

    for (int i = 0; i < num_viruses; i++) {
        fgets(virus_database[i].name, MAX_VIRUS_NAME_LENGTH, f);
        fgets(virus_database[i].signature, MAX_FILE_SIZE, f);
    }

    fclose(f);
}

int scan_file(char *filename, struct virus *virus_database, int num_viruses) {
    FILE *f = fopen(filename, "rb");
    if (f == NULL) {
        printf("Error: could not open file %s.\n", filename);
        return 0;
    }

    char buffer[MAX_FILE_SIZE];
    int file_size = 0;

    while (fread(buffer, 1, MAX_FILE_SIZE, f) > 0) {
        file_size += fread(buffer, 1, MAX_FILE_SIZE, f);
    }

    fclose(f);

    for (int i = 0; i < num_viruses; i++) {
        if (strstr(buffer, virus_database[i].signature)) {
            printf("Virus found in file %s: %s\n", filename, virus_database[i].name);
            return 1;
        }
    }

    return 0;
}

int main() {
    char filename[MAX_FILE_NAME_LENGTH];
    printf("Enter filename to scan: ");
    scanf("%s", filename);

    struct virus virus_database[10];
    read_virus_database(virus_database, 10);

    int result = scan_file(filename, virus_database, 10);

    if (result == 0) {
        printf("File is clean.\n");
    }

    return 0;
}