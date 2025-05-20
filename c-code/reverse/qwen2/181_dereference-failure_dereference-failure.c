#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void translateToEnglish(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
    }
}

int main() {
    char str[100];
    printf("Enter an alien language string: ");
    fgets(str, sizeof(str), stdin);
    translateToEnglish(str);
    printf("Translated string: %s\n", str);
    return 0;
}
