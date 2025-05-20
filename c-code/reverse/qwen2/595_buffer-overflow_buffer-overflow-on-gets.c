#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <ctype.h>

int main() {
    char str[100];
    int i = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    while (str[i] != '\0') {
        switch (tolower(str[i])) {
            case 'a':
                printf("%d", 4);
                break;
            case 'e':
                printf("%d", 3);
                break;
            case 'i':
                printf("%d", 1);
                break;
            case 'o':
                printf("%d", 0);
                break;
            case 's':
                printf("%d", 5);
                break;
            default:
                printf("%c", tolower(str[i]));
                break;
        }
        i++;
    }

    return 0;
}
