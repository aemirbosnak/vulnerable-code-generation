#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *buf = malloc(1024);
    int len = 0;

    // Read HTTP request body
    printf("Enter HTTP request body: ");
    getline(buf, 1024, stdin);

    // Parse integer value
    int num = atoi(buf);

    // Integer overflow
    int overflow = num * num * num;

    // Print result
    printf("Integer overflow: %d", overflow);

    free(buf);
    return 0;
}
