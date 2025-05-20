#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    char *buf = NULL;
    int size = 0;

    scanf("Enter the size of the memory pool: ", &size);
    buf = malloc(size);

    printf("Enter the data to be stored in the memory pool: ");
    scanf("%s", buf);

    // Overflow on sscanf
    scanf("%s", buf);

    free(buf);
    return 0;
}
