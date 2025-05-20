#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
    char input[10];
    int count = 0;
    while (1) {
        printf("Enter text: ");
        gets(input);
        if (strstr(input, "advertising") != NULL) count++;
        if (strstr(input, "winning") != NULL) count++;
        if (strstr(input, "free") != NULL) count++;
        if (count > 0) {
            printf("Warning: Potential spam detected!\n");
            break;
        }
    }
    return 0;
}
