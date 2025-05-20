#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

void read_args(int argc, char *argv[]) {
    int i;
    for (i = 1; i < argc; i++)
        printf("Argument %d: %s\n", i, argv[i]);
}

void migrate_data(char *input) {
    FILE *fp = fopen("old_db.dat", "r");
    char buffer[BUFFER_SIZE];
    char new_db[10][BUFFER_SIZE];
    char *token;
    int row = 0;

    if (!fp) {
        printf("Error opening old database file.\n");
        return;
    }

    while (fgets(buffer, BUFFER_SIZE, fp)) {
        token = strtok(buffer, " ");
        strcpy(new_db[row], token);
        row++;
    }

    fclose(fp);

    printf("Data has been read successfully.\n");

    // Here we'll process the data from new_db array and write to new_db.dat

    fp = fopen("new_db.dat", "w");

    for (int i = 0; i < row; i++) {
        fprintf(fp, "%s\n", new_db[i]);
    }

    fclose(fp);

    printf("Migration completed.\n");
}

int main(int argc, char *argv[]) {
    char input[BUFFER_SIZE];

    read_args(argc, argv);

    if (argc < 2) {
        printf("Please provide an input file to read from.\n");
        return 1;
    }

    printf("Reading input from %s\n", argv[1]);

    gets(input); // vulnerable gets call, replace with fgets for a safer implementation
    migrate_data(input);

    return 0;
}
