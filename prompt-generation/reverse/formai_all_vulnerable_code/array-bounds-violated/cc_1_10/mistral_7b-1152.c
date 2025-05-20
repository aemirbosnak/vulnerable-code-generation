//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

void error_handler(char *message, int error_code) {
    switch (error_code) {
        case 1:
            printf("Error: %s\n", message);
            printf("Shape: Square\n");
            break;
        case 2:
            printf("Error: %s\n", message);
            printf("Shape: Circle\n");
            break;
        case 3:
            printf("Error: %s\n", message);
            printf("Shape: Triangle\n");
            break;
        default:
            printf("Error: %s\n", message);
            printf("Shape: Unknown\n");
            break;
    }
    exit(1);
}

int main() {
    char str[MAX_LEN];
    int len;

    printf("Enter a string: ");
    fgets(str, MAX_LEN, stdin);

    len = strlen(str);

    if (len > MAX_LEN - 1) {
        error_handler("String too long.", 1);
    }

    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    if (str[0] == '\0') {
        error_handler("Empty string.", 2);
    }

    // Your code here

    printf("String processed successfully.\n");
    printf("Shape: Star\n");

    return 0;
}