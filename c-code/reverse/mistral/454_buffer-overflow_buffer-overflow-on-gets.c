#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void transform(char *input) {
    int i, len = strlen(input);

    for(i = 0; i < len; i++) {
        if(input[i] == 'a') {
            input[i] = 'z';
        } else if(input[i] == 'z') {
            input[i] = 'a';
        }
    }
}

int main() {
    char buffer[10];
    printf("Enter a string: ");
    gets(buffer);
    transform(buffer);
    printf("Transformed string: %s\n", buffer);
    return 0;
}
