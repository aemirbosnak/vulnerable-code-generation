//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

/* Function to perform digital watermarking */
void digitalWatermarking(char* message, char* watermark, char* output) {
    int i, j;
    int messageLength = strlen(message);
    int watermarkLength = strlen(watermark);
    int outputLength = messageLength + watermarkLength;

    /* Initialize output array with null characters */
    for (i = 0; i < outputLength; i++) {
        output[i] = '\0';
    }

    /* Embed watermark into output array */
    for (i = 0, j = 0; i < outputLength; i++) {
        if (i < messageLength) {
            output[i] = message[i];
        } else {
            output[i] = watermark[j++];
        }
    }
}

int main() {
    char message[MAX_SIZE];
    char watermark[MAX_SIZE];
    char output[MAX_SIZE * 2];

    /* Accept the message from user */
    printf("Enter the message:\n");
    fgets(message, MAX_SIZE, stdin);
    message[strlen(message) - 1] = '\0';

    /* Accept the watermark from user */
    printf("Enter the watermark:\n");
    fgets(watermark, MAX_SIZE, stdin);
    watermark[strlen(watermark) - 1] = '\0';

    /* Apply digital watermarking */
    digitalWatermarking(message, watermark, output);

    /* Print the output */
    printf("The output after digital watermarking is:\n");
    printf("%s\n", output);

    return 0;
}