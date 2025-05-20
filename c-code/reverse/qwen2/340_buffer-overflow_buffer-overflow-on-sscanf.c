#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_QUERY_LENGTH 256

typedef struct {
    int id;
    char name[50];
    int age;
    char profession[50];
} Record;

Record records[MAX_RECORDS];

int find_record(const char *query) {
    for (int i = 0; i < MAX_RECORDS; i++) {
        if (strcmp(query, records[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    // Initialize some sample records
    strcpy(records[0].name, "Alice");
    strcpy(records[1].name, "Bob");
    strcpy(records[2].name, "Charlie");

    char query[MAX_QUERY_LENGTH];
    printf("Enter query: ");
    fgets(query, sizeof(query), stdin);

    // Remove newline character from fgets
    size_t len = strlen(query);
    if (len > 0 && query[len - 1] == '\n') {
        query[len - 1] = '\0';
    }

    int index = find_record(query);
    if (index != -1) {
        printf("Found record: ID=%d, Name=%s, Age=%d, Profession=%s\n",
               records[index].id, records[index].name, records[index].age,
               records[index].profession);
    } else {
        printf("Record not found.\n");
    }

    return 0;
}
