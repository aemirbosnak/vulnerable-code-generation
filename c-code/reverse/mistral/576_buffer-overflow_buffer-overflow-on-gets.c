#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#define MAX_INPUT 1024

int main() {
    char input[MAX_INPUT];
    int counter = 0;
    char keywords[3][10] = {"advertising", "winning", "free"};

    while (1) {
        printf("Enter text: ");
        gets(input);

        for (int i = 0; i < 3; ++i) {
            if (strstr(input, keywords[i]) != NULL) {
                ++counter;
            }
        }

        if (counter > 0) {
            printf("Warning: Possible spam detected.\n");
        }
        counter = 0;
    }

    return 0;
}
