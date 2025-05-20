//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define FILENAME "chivalric_log.txt"

typedef struct knight_s {
    char name[MAX_LINE_LENGTH];
    int honor;
    int valor;
} knight_t;

void read_knight_from_file(FILE *file, knight_t *knight) {
    fscanf(file, "%s %d %d", knight->name, &knight->honor, &knight->valor);
}

void write_knight_to_file(FILE *file, knight_t knight) {
    fprintf(file, "%s %d %d\n", knight.name, knight.honor, knight.valor);
}

int main(int argc, char *argv[]) {
    FILE *file;
    knight_t knight;
    char line[MAX_LINE_LENGTH];

    // Open the file in write mode, create it if it doesn't exist
    file = fopen(FILENAME, "w+");
    if (file == NULL) {
        perror("Could not open file");
        return 1;
    }

    // Write a header to the file
    fprintf(file, "Name\tHonor\tValor\n");

    // Add some knights to the file
    strcpy(knight.name, "Sir Lancelot");
    knight.honor = 100;
    knight.valor = 90;
    write_knight_to_file(file, knight);

    strcpy(knight.name, "Sir Gawain");
    knight.honor = 85;
    knight.valor = 88;
    write_knight_to_file(file, knight);

    // Close the file
    fclose(file);

    // Open the file in read mode
    file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Could not open file");
        return 1;
    }

    // Read knights from the file and print their information
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        sscanf(line, "%s %d %d", knight.name, &knight.honor, &knight.valor);
        printf("%s\t%d\t%d\n", knight.name, knight.honor, knight.valor);
    }

    // Close the file
    fclose(file);

    return 0;
}