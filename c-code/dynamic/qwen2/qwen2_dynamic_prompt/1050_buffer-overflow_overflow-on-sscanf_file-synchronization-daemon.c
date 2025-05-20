#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void handle_client(char *data) {
    char buffer[10];
    sscanf(data, "%s", buffer);
}

int main() {
    char input[200];
    printf("Enter data: ");
    fgets(input, sizeof(input), stdin);
    handle_client(input);
    return 0;
}
