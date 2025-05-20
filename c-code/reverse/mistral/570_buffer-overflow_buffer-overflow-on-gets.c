#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
    char message[10];
    int advertising_count = 0, winning_count = 0, free_count = 0;

    printf("Enter a message:\n");
    gets(message);

    if (strstr(message, "advertising")) advertising_count++;
    if (strstr(message, "winning")) winning_count++;
    if (strstr(message, "free")) free_count++;

    printf("Advertising: %d\n", advertising_count);
    printf("Winning: %d\n", winning_count);
    printf("Free: %d\n", free_count);

    return 0;
}
