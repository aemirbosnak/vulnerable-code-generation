#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Record {
    char id[10];
    char name[50];
    char email[100];
} Record;

Record* fetchRecord(int index) {
    static Record records[3] = {
        {"1", "Alice", "alice@example.com"},
        {"2", "Bob", "bob@example.com"},
        {"3", "Charlie", "charlie@example.com"}
    };

    return &records[index];
}

void printRecord(Record* record) {
    printf("ID: %s\n", record->id);
    printf("Name: %s\n", record->name);
    printf("Email: %s\n\n", record->email);
}

int main() {
    int targetID = atoi(getenv("TARGET_ID"));
    Record* record = fetchRecord(targetID);
    printRecord(record);

    char* newEmail = malloc(100 * sizeof(char));
    strcpy(newEmail, "newEmail@example.com");
    strcpy(record->email, newEmail);

    free(newEmail); // Oops, forgot to keep the pointer to the allocated memory!

    printf("Successfully updated record with ID: %s\n", record->id);

    return 0;
}
