#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
    char message[100];
    int spamCount = 0;

    printf("Enter a message: ");
    gets(message);

    if (strstr(message, "advertising") != NULL) spamCount++;
    if (strstr(message, "winning") != NULL) spamCount++;
    if (strstr(message, "watches") != NULL) spamCount++;
    if (strstr(message, "free") != NULL) spamCount++;

    if (spamCount > 0) {
        printf("This message contains %d spam keyword(s).\n", spamCount);
    } else {
        printf("This message does not contain any spam keywords.\n");
    }

    return 0;
}
