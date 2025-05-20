//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_INPUT_LENGTH 256

void compress(const char *input, char *output) {
    int count;
    int j = 0; // Index for output

    for (int i = 0; i < strlen(input); i++) {
        // Count occurrences of the current character
        count = 1;
        while (i + 1 < strlen(input) && input[i] == input[i + 1]) {
            count++;
            i++;
        }

        // Append current character and its count to output
        output[j++] = input[i];
        output[j++] = count + '0'; // Convert count to character
    }
    output[j] = '\0'; // Null terminate the output string
}

int main() {
    char *user_input[MAX_USERS];
    char *compressed_output[MAX_USERS];
    int num_users;

    printf("Welcome to the Multiplayer Text Compression Program!\n");
    printf("Please enter the number of users (max %d): ", MAX_USERS);
    scanf("%d", &num_users);

    // Clear newline character left by scanf
    while (getchar() != '\n');

    // Ensure we do not exceed max users
    if (num_users > MAX_USERS) {
        num_users = MAX_USERS;
    }

    // Allocate memory for user inputs and compressed outputs
    for (int i = 0; i < num_users; i++) {
        user_input[i] = (char *)malloc(MAX_INPUT_LENGTH);
        compressed_output[i] = (char *)malloc(MAX_INPUT_LENGTH);
    }

    // Collect input from each user
    for (int i = 0; i < num_users; i++) {
        printf("User %d, please enter your text: ", i + 1);
        fgets(user_input[i], MAX_INPUT_LENGTH, stdin);
        // Remove newline character if it exists
        user_input[i][strcspn(user_input[i], "\n")] = '\0';
    }

    // Compress each user's input
    for (int i = 0; i < num_users; i++) {
        compress(user_input[i], compressed_output[i]);
    }

    // Display compressed outputs
    printf("\nCompressed Results:\n");
    for (int i = 0; i < num_users; i++) {
        printf("User %d: Original: '%s' -> Compressed: '%s'\n", i + 1, user_input[i], compressed_output[i]);
    }

    // Free allocated memory
    for (int i = 0; i < num_users; i++) {
        free(user_input[i]);
        free(compressed_output[i]);
    }

    return 0;
}