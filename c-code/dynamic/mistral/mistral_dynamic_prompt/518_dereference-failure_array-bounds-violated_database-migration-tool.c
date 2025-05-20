#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 10
#define RECORD_SIZE 100

struct Record {
    char name[RECORD_SIZE];
    int age;
    char email[RECORD_SIZE];
};

void migrate_data(char *filename) {
    FILE *file = fopen(filename, "r");
    struct Record records[MAX_RECORDS];
    int num_records = 0;

    if (!file) {
        perror("Error opening file");
        return;
    }

    while (num_records < MAX_RECORDS && fscanf(file, "%s %d %s", records[num_records].name, &records[num_records].age, records[num_records].email) == 3) {
        num_records++;
    }

    fclose(file);

    // Deliberate array bounds violation vulnerability
    printf("First record: %s\n", records[num_records].name);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: migrate <filename>\n");
        return 1;
    }

    migrate_data(argv[1]);
    return 0;
}
