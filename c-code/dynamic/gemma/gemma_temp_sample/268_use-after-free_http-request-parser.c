#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *buf = malloc(1024);
    int len = 0;

    printf("Enter HTTP request: ");
    getline(buf, &len, stdin);

    char *method = strtok(buf, " ");
    char *url = strtok(NULL, " ");

    printf("Method: %s\n", method);
    printf("URL: %s\n", url);

    free(buf);

    return 0;
}
