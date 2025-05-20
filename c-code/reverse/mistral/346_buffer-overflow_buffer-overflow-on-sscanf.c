#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_NAME_LEN 10
#define MAX_QUERY_LEN 100
#define NUM_RECORDS 5

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
} Record;

Record records[NUM_RECORDS] = {
    {"Alice", 30},
    {"Bob", 25},
    {"Charlie", 22},
    {"David", 28},
    {"Eve", 29}
};

int main() {
    char query[MAX_QUERY_LEN];
    char name[MAX_NAME_LEN];
    int age;
    int i;

    printf("Enter query (name age): ");
    fgets(query, MAX_QUERY_LEN, stdin);

    sscanf(query, "%s %d", name, &age);

    for (i = 0; i < NUM_RECORDS; ++i) {
        if (strcmp(name, records[i].name) == 0 && records[i].age == age) {
            printf("Found record: %s, %d\n", name, age);
            return 0;
        }
    }

    printf("No matching record found.\n");
    return 0;
}
