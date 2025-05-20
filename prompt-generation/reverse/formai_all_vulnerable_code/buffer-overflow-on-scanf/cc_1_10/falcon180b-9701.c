//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024
#define VIRUS_SIGNATURE "Virus123"
#define CLEAN_FILE "clean.txt"
#define INFECTED_FILE "infected.txt"

void scan_file(char *filename, char *buffer, int *is_infected);
void write_to_file(char *filename, char *buffer);

int main() {
    char filename[50];
    char buffer[BUFFER_SIZE];
    int is_infected = 0;

    printf("Enter filename to scan: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while (fread(buffer, 1, BUFFER_SIZE, file) > 0) {
        scan_file(filename, buffer, &is_infected);
    }

    fclose(file);

    if (is_infected) {
        write_to_file(INFECTED_FILE, buffer);
        printf("File is infected with a virus.\n");
    } else {
        write_to_file(CLEAN_FILE, buffer);
        printf("File is clean.\n");
    }

    return 0;
}

void scan_file(char *filename, char *buffer, int *is_infected) {
    int i, j;
    for (i = 0; i < strlen(VIRUS_SIGNATURE); i++) {
        for (j = 0; j < strlen(buffer); j++) {
            if (VIRUS_SIGNATURE[i] == buffer[j]) {
                *is_infected = 1;
                return;
            }
        }
    }
}

void write_to_file(char *filename, char *buffer) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }
    fwrite(buffer, 1, strlen(buffer), file);
    fclose(file);
}