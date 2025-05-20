#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
    char buffer[1024];
    char data[] = "This is a long string that will cause a buffer overflow";

    gets(buffer);
    strcpy(buffer, data);

    printf("The modified string is: %s", buffer);

    return 0;
}
