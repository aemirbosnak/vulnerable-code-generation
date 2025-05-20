#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void transformText(char *input) {
    int i = 0;
    while (input[i] != '\0') {
        if (input[i] >= 'a' && input[i] <= 'z') {
            input[i] -= 32;
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            input[i] += 32;
        }
        i++;
    }
}

int main() {
    char buffer[50];
    printf("Enter some text: ");
    gets(buffer);
    transformText(buffer);
    printf("Transformed text: %s\n", buffer);
    return 0;
}
