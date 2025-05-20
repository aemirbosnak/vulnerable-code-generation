#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10] = "";
    char data[1024] = "This is a large amount of data that will cause a buffer overflow.";

    gets(buffer);

    if (strlen(buffer) > 10) {
        printf("Error: Buffer overflow.\n");
    } else {
        printf("Data: %s\n", buffer);
    }

    return 0;
}
