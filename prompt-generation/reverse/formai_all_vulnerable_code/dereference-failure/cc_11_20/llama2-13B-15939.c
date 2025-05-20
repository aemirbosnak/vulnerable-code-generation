//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define GRATITUDE_MESSAGE "Gratitude is the memory of the heart."

int main() {
    char *message = malloc(MAX_LENGTH * sizeof(char));
    int i, j;

    // Ask the user for their message
    printf("Enter a message (%d characters maximum): ", MAX_LENGTH);
    fgets(message, MAX_LENGTH, stdin);

    // Display the message with a gratitude message prepended
    printf(" Gratitude is the memory of the heart. %s\n", GRATITUDE_MESSAGE);

    // Check if the user's message is too long
    if (strlen(message) > MAX_LENGTH) {
        printf("Message too long! Please enter a message with %d characters or less.\n", MAX_LENGTH);
        return 1;
    }

    // Print the message with each word capitalized
    for (i = 0; message[i] != '\0'; i++) {
        if (message[i] == ' ' || message[i] == '\n') {
            message[i] = toupper(message[i]);
        }
    }

    // Print the message with each word separated by a comma
    for (j = 0; message[j] != '\0'; j++) {
        if (message[j] == ' ' || message[j] == '\n') {
            message[j] = ',';
        }
    }

    // Print the message with each word separated by a space
    for (i = 0; message[i] != '\0'; i++) {
        if (message[i] == ' ' || message[i] == '\n') {
            message[i] = ' ';
        }
    }

    // Print a thank you message
    printf("Thank you for sharing your message with us! %s\n", GRATITUDE_MESSAGE);

    return 0;
}