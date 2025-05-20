#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char buffer[1024];
    fscanf(stdin, "%s", buffer);
    printf("%s", buffer);
    return 0;
}
