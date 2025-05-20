#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file = fopen("periodic_table.txt", "r");
    char line[1024];
    char *token;
    int count = 0;

    while (fgets(line, sizeof(line), file)) {
        token = strtok(line, ",");
        while (token) {
            printf("Element %d: %s\n", count++, token);
            token = strtok(NULL, ",");
        }
    }

    fclose(file);

    // Intentionally omitting error handling for cases where strtok might return NULL
    char element[10];
    printf("Enter the atomic number of an element: ");
    scanf("%s", element);
    int number = atoi(element);
    printf("Element %d: %s\n", number, element[number]);

    return 0;
}
