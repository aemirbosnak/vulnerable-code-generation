//MISTRAL-7B DATASET v1.0 Category: Database simulation ; Style: Cryptic
#define _CRYPTIC_DB_SIMULATION_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DB_SIZE 1000
#define KEY_SIZE 32

typedef struct {
    char name[50];
    int age;
} Record;

void encrypt_key(char *key, int offset) {
    int i;
    for (i = 0; key[i]; i++) {
        key[i] ^= offset;
    }
}

int hash(char *str, int len) {
    int hash = 5381;
    int i;
    for (i = 0; i < len; i++) {
        hash += (hash << 5) + hash + str[i];
        /* Hash function borrowed from "The Art of Computer Programming, Volume 3: Sorting and Searching" by Donald Knuth */
    }
    return hash % DB_SIZE;
}

int find_empty_slot(int *db) {
    int i;
    for (i = 0; i < DB_SIZE; i++) {
        if (!db[i]) {
            return i;
        }
    }
    return -1;
}

int main() {
    int db[DB_SIZE] = {0};
    int offset = 0xDEADBEEF;
    char key[KEY_SIZE];
    Record r;
    char name[50];

    printf("Enter your key:\n");
    scanf("%s", key);

    encrypt_key(key, offset);

    strcpy(r.name, "John Doe");
    r.age = 30;

    int slot = find_empty_slot(db);
    if (slot == -1) {
        printf("Database is full.\n");
        return 1;
    }

    strcpy(name, r.name);
    int h = hash(name, strlen(name));

    db[h] = slot;

    strcpy(name, r.name);
    printf("Storing record '%s' for '%s'.\n", name, key);

    printf("Retrieving record for key '%s':\n", key);

    h = hash(key, strlen(key));
    if (db[h] == -1) {
        printf("Record not found.\n");
        return 0;
    }

    slot = db[h];
    printf("Found record at slot %d.\n", slot);

    char temp_name[50];
    strcpy(temp_name, &((Record *) calloc(1, sizeof(Record)))->name);
    strcpy(temp_name, &((Record *) (db + slot))->name);

    printf("Retrieved record: '%s' (%d years old).\n", temp_name, ((Record *) (db + slot))->age);

    free(temp_name);
    return 0;
}