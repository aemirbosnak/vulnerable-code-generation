#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LEN 1024

void transform_text(char *input) {
    char *output = (char *)malloc(MAX_LEN * sizeof(char));
    if (output == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    int j = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == ' ') {
            strcpy(output + j, "SPACE");
            j += 5;
        } else {
            const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
            int len = rand() % 5 + 3;
            for (int k = 0; k < len; k++) {
                output[j++] = charset[rand() % strlen(charset)];
            }
        }
    }
    output[j] = '\0';
    printf("%s\n", output);
    free(output);
}

int main() {
    srand(time(NULL));
    char input[MAX_LEN];
    printf("Enter text: ");
    fgets(input, MAX_LEN, stdin);
    input[strcspn(input, "\n")] = '\0';
    transform_text(input);
    return 0;
}
