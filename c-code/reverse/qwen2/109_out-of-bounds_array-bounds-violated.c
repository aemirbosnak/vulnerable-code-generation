#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void sanitize(char *input, const char *forbidden) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (strchr(forbidden, input[i]) != NULL) {
            input[i] = ' ';
        }
    }
}

int main() {
    char input1[256], input2[256], input3[256];
    const char *forbidden1 = ";<>|&";
    const char *forbidden2 = ";<>|&\n";

    printf("Enter first string: ");
    fgets(input1, sizeof(input1), stdin);
    sanitize(input1, forbidden1);

    printf("Enter second string: ");
    fgets(input2, sizeof(input2), stdin);
    sanitize(input2, forbidden1);

    printf("Enter third string: ");
    fgets(input3, sizeof(input3), stdin);
    sanitize(input3, forbidden2);

    printf("Sanitized inputs:\n");
    printf("First: %s", input1);
    printf("Second: %s", input2);
    printf("Third: %s", input3);

    return 0;
}
