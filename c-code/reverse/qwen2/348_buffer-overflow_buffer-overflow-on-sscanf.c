#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
} Record;

Record records[] = {
    {1, "Alice"},
    {2, "Bob"},
    {3, "Charlie"}
};

int record_count = sizeof(records) / sizeof(records[0]);

void query_database(int id, char *name) {
    int found = 0;
    for (int i = 0; i < record_count; i++) {
        if (records[i].id == id || strcmp(records[i].name, name) == 0) {
            printf("Found: ID=%d, Name=%s\n", records[i].id, records[i].name);
            found = 1;
        }
    }
    if (!found) {
        printf("No record found.\n");
    }
}

int main() {
    int id;
    char name[50];

    printf("Enter ID or name to search: ");
    scanf("%d %s", &id, name);

    query_database(id, name);

    return 0;
}
