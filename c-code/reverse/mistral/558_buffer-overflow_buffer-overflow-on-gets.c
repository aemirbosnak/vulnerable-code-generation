#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#define MAX_INPUT 200

int main() {
    char input[MAX_INPUT];
    gets(input);

    if (strstr(input, ":)") || strstr(input, ":-)"))
        printf("Happy\n");
    else if (strstr(input, ":(") || strstr(input, ":-("))
        printf("Sad\n");
    else if (strstr(input, ":|") || strstr(input, ":-|"))
        printf("Neutral\n");
    else
        printf("Neutral\n");

    return 0;
}
