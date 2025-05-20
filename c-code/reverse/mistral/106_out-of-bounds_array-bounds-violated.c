#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
    char input[10];
    for(int i = 0; i < 3; ++i) {
        printf("Enter a line: ");
        fgets(input, sizeof(input), stdin);
        for(int j = 0; input[j] != '\n'; ++j) {
            if(input[j] == '*') input[j] = 'X';
            if(j + 1 >= sizeof(input)) break;
        }
        printf("Sanitized input: %s\n", input);
    }
    return 0;
}
