#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    char message[10];
    int count = 0;

    printf("Enter a message: ");
    gets(message);

    if (strstr(message, "advertising") != NULL) count++;
    if (strstr(message, "winning") != NULL) count++;
    if (strstr(message, "free") != NULL) count++;

    printf("Spam keyword count: %d\n", count);

    return 0;
}
