//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: excited
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int main(void) {
    char *message;
    int i, n, count;
    float threshold;
    char *tokens[1000];
    char *token;
    struct tm *timeptr;
    time_t now;

    printf("Enter the message: ");
    scanf("%s", message);

    n = strlen(message);
    count = 0;
    for (i = 0; i < n; i++) {
        if (isalpha(message[i])) {
            count++;
        }
    }

    threshold = 0.1 * count;

    now = time(NULL);
    timeptr = localtime(&now);
    strftime(message, 1000, "%A, %d %B %Y %I:%M %p", timeptr);

    printf("The message was sent on %s.\n", message);

    token = strtok(message, ",.?!;:");
    while (token!= NULL) {
        if (strlen(token) > 2) {
            strcpy(tokens[count], token);
            count++;
        }
        token = strtok(NULL, ",.?!;:");
    }

    for (i = 0; i < count; i++) {
        if (isalpha(tokens[i][0])) {
            printf("%s\n", tokens[i]);
        }
    }

    return 0;
}