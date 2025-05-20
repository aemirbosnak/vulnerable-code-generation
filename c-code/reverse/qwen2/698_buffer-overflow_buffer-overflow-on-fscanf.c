#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#define MAX_LINE_LENGTH 256

int main() {
    FILE *file = fopen("log.txt", "r");
    if (file == NULL) return 1;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        for (int i = 0; line[i] != '\0'; i++) {
            fscanf(file, "%s", line);
        }
    }

    fclose(file);
    return 0;
}
