#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
    char code[1000];
    printf("Enter C code: ");
    gets(code);

    int dataType = 0, loopStructure = 0;

    if (strstr(code, "int") || strstr(code, "float") || strstr(code, "double") || strstr(code, "char")) {
        dataType++;
    }
    if (strstr(code, "for") || strstr(code, "while") || strstr(code, "do")) {
        loopStructure++;
    }

    printf("Data Types: %d\n", dataType);
    printf("Loop Structures: %d\n", loopStructure);

    return 0;
}
