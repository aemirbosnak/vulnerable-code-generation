//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Invalid number of arguments!\n");
        return 1;
    }

    char *input = argv[1];
    char *output = malloc(MAX_LENGTH);

    strcpy(output, input);

    int i = 0;
    while (i < strlen(output)) {
        if (isdigit(output[i])) {
            if (i == 0) {
                strcat(output, "th");
            } else if (i == 1) {
                strcat(output, "st");
            } else if (i == 2) {
                strcat(output, "nd");
            } else if (i == 3) {
                strcat(output, "rd");
            } else {
                strcat(output, "th");
            }
        } else if (isalpha(output[i])) {
            if (i == 0) {
                strcat(output, "st");
            } else if (i == 1) {
                strcat(output, "nd");
            } else if (i == 2) {
                strcat(output, "rd");
            } else {
                strcat(output, "th");
            }
        } else {
            strcat(output, "th");
        }
        i++;
    }

    printf("Input: %s\n", input);
    printf("Output: %s\n", output);

    free(output);

    return 0;
}