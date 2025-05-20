#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse_request(char *buffer) {
    char *method = strtok(buffer, " ");
    char *url = strtok(NULL, " ");

    printf("Method: %s\n", method);
    printf("URL: %s\n", url);

    // Use-after-free vulnerability
    free(url);  // Freeing memory that should not be freed
}

int main() {
    char buffer[256];
    printf("Enter HTTP request:\n");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';

    parse_request(buffer);

    // Accessing freed memory
    printf("%s\n", buffer);  // Undefined behavior

    return 0;
}
