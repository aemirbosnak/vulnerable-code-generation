//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to calculate the checksum */
unsigned short calculate_checksum(unsigned char *data, int length) {
    unsigned int i;
    unsigned short sum = 0;

    for (i = 0; i < length - 1; i += 2) {
        sum += (unsigned short) (((unsigned short) data[i] << 8) | (unsigned short) data[i + 1]);
    }

    /* If the length is odd, handle the last byte separately */
    if (length % 2) {
        sum += (unsigned short) ((unsigned short) data[length - 1] << 8);
    }

    /* Fold 32-bit sum to 16 bits */
    while (sum >> 16) {
        sum = (sum & 0xFFFF) + (sum >> 16);
    }

    /* Invert the sum to obtain the checksum */
    return ~sum;
}

int main() {
    printf("Enter the data for which you want to calculate the checksum:\n");
    char input[256];
    fgets(input, sizeof(input), stdin);

    int length = strlen(input);

    /* Remove trailing newline character from fgets */
    if (input[length - 1] == '\n') {
        input[length - 1] = '\0';
        length--;
    }

    /* Convert input to array of unsigned char */
    unsigned char *data = (unsigned char *) malloc(length);
    memcpy(data, input, length);

    /* Calculate the checksum */
    unsigned short checksum = calculate_checksum(data, length);

    printf("The checksum of the input data is: 0x%04X\n", checksum);

    free(data);

    return 0;
}