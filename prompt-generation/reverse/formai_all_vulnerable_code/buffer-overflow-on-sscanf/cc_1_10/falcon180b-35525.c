//Falcon-180B DATASET v1.0 Category: Database querying ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SIZE 50
#define MAX_VALUE_SIZE 100

typedef struct {
    char name[MAX_NAME_SIZE];
    char value[MAX_VALUE_SIZE];
} pair;

void add_pair(pair *table, int size, char *name, char *value) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(table[i].name, name) == 0) {
            strcpy(table[i].value, value);
            return;
        }
    }
    strcpy(table[size].name, name);
    strcpy(table[size].value, value);
    size++;
}

char *get_value(pair *table, int size, char *name) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(table[i].name, name) == 0) {
            return table[i].value;
        }
    }
    return NULL;
}

int main() {
    FILE *file;
    pair table[100];
    int size = 0;
    char line[MAX_VALUE_SIZE];
    char name[MAX_NAME_SIZE];
    char value[MAX_VALUE_SIZE];

    file = fopen("database.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fgets(line, MAX_VALUE_SIZE, file)!= NULL) {
        sscanf(line, "%s %s", name, value);
        add_pair(table, size, name, value);
        size++;
    }

    fclose(file);

    char *result;
    while (1) {
        printf("Enter a name to search for (or type 'exit' to quit):\n");
        fgets(name, MAX_NAME_SIZE, stdin);

        if (strcmp(name, "exit") == 0) {
            break;
        }

        result = get_value(table, size, name);
        if (result == NULL) {
            printf("No value found for %s\n", name);
        } else {
            printf("%s = %s\n", name, result);
        }
    }

    return 0;
}