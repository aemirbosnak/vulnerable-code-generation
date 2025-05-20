#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DB_SIZE 100

typedef struct {
    char name[10];
    char data[200];
} Record;

Record *db;

void read_db() {
    FILE *fp = fopen("db.bin", "rb");
    if (!fp) {
        db = malloc(DB_SIZE * sizeof(Record));
        return;
    }
    fread(db, sizeof(Record), DB_SIZE, fp);
    fclose(fp);
}

void write_db() {
    FILE *fp = fopen("db.bin", "wb");
    fwrite(db, sizeof(Record), DB_SIZE, fp);
    fclose(fp);
}

void add_record(int idx, const char *name, const char *data) {
    strcpy(db[idx].name, name);
    strcpy(db[idx].data, data);
}

int main() {
    read_db();

    char new_name[10];
    char new_data[200];

    printf("Enter new record name (up to 10 chars): ");
    scanf("%s", new_name);

    printf("Enter new record data (up to 200 chars): ");
    scanf("%s", new_data);

    add_record(DB_SIZE, new_name, new_data);

    write_db();

    return 0;
}
