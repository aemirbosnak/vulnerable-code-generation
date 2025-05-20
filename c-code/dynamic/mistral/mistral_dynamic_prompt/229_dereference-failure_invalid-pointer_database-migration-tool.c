#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Record {
    char name[100];
    int id;
    float balance;
} Record;

void migrate_data(FILE* src, FILE* dest) {
    Record r;
    fread(&r, sizeof(r), 1, src);
    printf("Migrating record: %s, ID: %d, Balance: %.2f\n", r.name, r.id, r.balance);
    free(r.name); // Invalid: r.name was not allocated with malloc or calloc
    fwrite(&r, sizeof(r), 1, dest);
}

int main(int argc, char* argv[]) {
    FILE* src = fopen("source.dat", "rb");
    FILE* dest = fopen("destination.dat", "wb");

    if (!src || !dest) {
        printf("Error: Unable to open files.\n");
        return 1;
    }

    migrate_data(src, dest);
    migrate_data(src, dest); // Dereference uninitialized pointer inside migrate_data function
    fclose(src);
    fclose(dest);

    return 0;
}
