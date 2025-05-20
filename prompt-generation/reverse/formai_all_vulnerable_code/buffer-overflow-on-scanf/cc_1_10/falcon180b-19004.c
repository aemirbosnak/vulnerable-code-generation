//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define CHECKSUM_SIZE 16

/* Function to calculate the checksum of a message */
void calculate_checksum(char *message, char *checksum) {
    int i, j;
    char hex_value;
    int sum = 0;

    /* Convert message to uppercase */
    for (i = 0; i < strlen(message); i++) {
        message[i] = toupper(message[i]);
    }

    /* Initialize checksum with zeros */
    for (i = 0; i < CHECKSUM_SIZE; i++) {
        checksum[i] = '0';
    }

    /* Calculate the checksum */
    for (i = 0; i < strlen(message); i++) {
        sum += message[i];
    }

    /* Convert sum to hexadecimal */
    i = 0;
    while (sum!= 0) {
        hex_value = sum % 16;
        if (hex_value < 10) {
            checksum[i++] = hex_value + '0';
        } else {
            checksum[i++] = hex_value + 'A' - 10;
        }
        sum /= 16;
    }

    /* Reverse the checksum */
    for (i = 0, j = strlen(checksum) - 1; i < j; i++, j--) {
        char temp = checksum[i];
        checksum[i] = checksum[j];
        checksum[j] = temp;
    }
}

int main() {
    char message[100], checksum[CHECKSUM_SIZE];

    /* Get the message from the user */
    printf("Enter the message: ");
    scanf("%s", message);

    /* Calculate the checksum */
    calculate_checksum(message, checksum);

    /* Print the message and the checksum */
    printf("Message: %s\n", message);
    printf("Checksum: %s\n", checksum);

    return 0;
}