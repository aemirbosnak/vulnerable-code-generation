#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_FIELDS 4

typedef struct {
    int id;
    char name[50];
    int age;
    char profession[50];
} Record;

Record records[MAX_RECORDS] = {
    {1, "Alice", 30, "Engineer"},
    {2, "Bob", 25, "Doctor"},
    {3, "Charlie", 35, "Artist"}
};

int main() {
    char query[100];
    printf("Enter query: ");
    fgets(query, sizeof(query), stdin);
    query[strcspn(query, "\n")] = '\0';

    char field[50], value[50];
    sscanf(query, "%s %s", field, value);

    for (int i = 0; i < MAX_RECORDS; i++) {
        if ((strcmp(field, "id") == 0 && records[i].id == atoi(value)) ||
            (strcmp(field, "name") == 0 && strcmp(records[i].name, value) == 0) ||
            (strcmp(field, "age") == 0 && records[i].age == atoi(value)) ||
            (strcmp(field, "profession") == 0 && strcmp(records[i].profession, value) == 0)) {
            printf("ID: %d, Name: %s, Age: %d, Profession: %s\n",
                   records[i].id, records[i].name, records[i].age, records[i].profession);
        }
    }

    return 0;
}
