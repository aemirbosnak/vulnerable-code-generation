#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
    char message[256];
    int count = 0;

    printf("Enter your message: ");
    gets(message);

    if (strstr(message, "advertising") != NULL) count++;
    if (strstr(message, "winning") != NULL) count++;
    if (strstr(message, "watches") != NULL) count++;
    if (strstr(message, "free") != NULL) count++;

    if (count > 0) {
        printf("Warning: Your message contains %d spam keyword(s).\n", count);
    } else {
        printf("Your message is safe.\n");
    }

    return 0;
}
