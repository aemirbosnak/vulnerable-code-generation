//FormAI DATASET v1.0 Category: String manipulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char message[] = "Hey, how's it going?";
    char new_message[100];
    int len = strlen(message);

    // Reverse the message and store it in a new variable
    for (int i = len - 1, j = 0; i >= 0; i--, j++) {
        new_message[j] = message[i];
    }
    new_message[len] = '\0';

    printf("Original message: %s\n", message);
    printf("Reversed message: %s\n", new_message);

    // Count the number of vowels in the message
    int vowels = 0;
    for (int i = 0; i < len; i++) {
        char c = message[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vowels++;
        }
    }

    printf("Number of vowels in message: %d\n", vowels);

    // Replace all vowels with a random number between 0 and 9
    char vowels_rep[5] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for (int i = 0; i < len; i++) {
        char c = message[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            int random_num = rand() % 10;
            message[i] = vowels_rep[random_num];
        }
    }

    printf("New message with replaced vowels: %s\n", message);

    // Convert the message to all uppercase
    for (int i = 0; i < len; i++) {
        char c = message[i];
        if ('a' <= c && c <= 'z') {
            message[i] = c - 32;
        }
    }

    printf("Message in all uppercase: %s\n", message);

    return 0;
}