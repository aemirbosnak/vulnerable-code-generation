#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void vulnerable_function(char *input) {
    char buffer[10];
    int count;

    count = sscanf(input, " +%[^\n]", buffer);

    if (count > 0) {
        printf("Parsed: %s\n", buffer);

        // Overflow vulnerability here, no bounds checking on buffer
        strcpy(buffer, input);

        // Complex cyclomatic complexity due to nested if statements
        if (strstr(buffer, "USER") != NULL) {
            if (strstr(buffer, "PASS") != NULL) {
                printf("POP3 authentication successful.\n");
            }
        }
    }
}

int main() {
    char input[256];

    printf("Enter POP3 server response:\n");
    fgets(input, sizeof(input), stdin);

    vulnerable_function(input);

    return 0;
}
