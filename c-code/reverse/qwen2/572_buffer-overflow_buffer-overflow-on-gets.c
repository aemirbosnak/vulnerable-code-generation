#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
    char message[256];
    int spamCount = 0;

    printf("Enter your message: ");
    gets(message);

    if (strstr(message, "advertising")) spamCount++;
    if (strstr(message, "winning")) spamCount++;
    if (strstr(message, "watches")) spamCount++;
    if (strstr(message, "free")) spamCount++;

    if (spamCount > 0) {
        printf("Warning: Your message contains potential spam.\n");
    }

    return 0;
}
