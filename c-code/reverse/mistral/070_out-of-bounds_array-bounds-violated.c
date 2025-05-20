#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
    char str[1001];
    scanf("%s", str);
    int len = strlen(str);
    for (int i = 0; i < len / 2; ++i)
        if (str[i] != str[len - i - 1]) {
            printf("Not a palindrome\n");
            return 0;
        }
    printf("Palindrome\n");
    return 0;
}
