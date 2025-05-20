#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

int main() {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), stdin)) {
        if (strstr(line, "int") != NULL) printf("Data Type: int\n");
        if (strstr(line, "float") != NULL) printf("Data Type: float\n");
        if (strstr(line, "char") != NULL) printf("Data Type: char\n");
        if (strstr(line, "for") != NULL) printf("Loop: for\n");
        if (strstr(line, "while") != NULL) printf("Loop: while\n");
        if (strstr(line, "do") != NULL) printf("Loop: do-while\n");
    }
    return 0;
}
