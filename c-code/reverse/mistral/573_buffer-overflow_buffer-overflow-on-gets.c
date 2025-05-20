#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#define MAX_LENGTH 100

int main() {
    char message[MAX_LENGTH];
    int advertising_count = 0, winning_count = 0, watches_count = 0, free_count = 0;

    printf("Enter a message: ");
    gets(message);

    for (int i = 0; message[i] != '\0'; ++i) {
        if (strcmp(&message[i], "advertising") == 0) {
            ++advertising_count;
        }
        else if (strcmp(&message[i], "winning") == 0) {
            ++winning_count;
        }
        else if (strcmp(&message[i], "watches") == 0) {
            ++watches_count;
        }
        else if (strcmp(&message[i], "free") == 0) {
            ++free_count;
        }
    }

    if (advertising_count > 0 || winning_count > 0 || watches_count > 0 || free_count > 0) {
        printf("Warning: Spam keywords detected.\n");
    }

    return 0;
}
