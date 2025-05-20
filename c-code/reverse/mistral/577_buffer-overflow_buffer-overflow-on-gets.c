#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100

int main() {
    char text[MAX_LENGTH];
    int advertising_count = 0, winning_count = 0, watches_count = 0, free_count = 0;

    printf("Enter text: ");
    gets(text);

    if (strstr(text, "advertising") != NULL) advertising_count++;
    if (strstr(text, "winning") != NULL) winning_count++;
    if (strstr(text, "watches") != NULL) watches_count++;
    if (strstr(text, "free") != NULL) free_count++;

    printf("advertising: %d\n", advertising_count);
    printf("winning: %d\n", winning_count);
    printf("watches: %d\n", watches_count);
    printf("free: %d\n", free_count);

    return 0;
}
