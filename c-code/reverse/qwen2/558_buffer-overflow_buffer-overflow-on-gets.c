#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
    char statement[256];
    printf("Enter your statement: ");
    gets(statement);

    if (strstr(statement, ":)") != NULL) {
        printf("Happy\n");
    } else if (strstr(statement, ":(") != NULL) {
        printf("Sad\n");
    } else {
        printf("Neutral\n");
    }

    return 0;
}
