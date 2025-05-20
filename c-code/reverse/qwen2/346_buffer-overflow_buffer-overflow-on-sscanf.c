#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_QUERY_LEN 100
#define MAX_RECORDS 5

typedef struct {
    char name[50];
    int age;
} Record;

Record records[MAX_RECORDS] = {
    {"Alice", 30},
    {"Bob", 25},
    {"Charlie", 35}
};

int search_records(const char *query) {
    char cmd[MAX_QUERY_LEN];
    int index;
    if (sscanf(query, "search %d", &index) == 1 && index >= 0 && index < MAX_RECORDS) {
        printf("Name: %s, Age: %d\n", records[index].name, records[index].age);
        return 0;
    }
    strcpy(cmd, query);
    printf("Executing command: %s\n", cmd);
    return -1;
}

int main() {
    char input[MAX_QUERY_LEN];
    while (1) {
        printf("Enter query (or 'exit' to quit): ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        if (strcmp(input, "exit") == 0) break;
        if (search_records(input) != 0) {
            printf("Invalid query.\n");
        }
    }
    return 0;
}
