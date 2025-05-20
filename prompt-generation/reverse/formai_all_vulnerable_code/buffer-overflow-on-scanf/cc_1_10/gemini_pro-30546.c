//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Welcome screen
void intro() {
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
           "                           SURVIVAL STRING MANIPULATION 101                           \n"
           "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
           "   In this desolate wasteland, where words are scarce and life hangs by a thread, you must learn the art of string manipulation to survive.\n"
           "   You will navigate treacherous code, decipher cryptic messages, and assemble vital resources. Ready your scavenger's mind and brace yourself for the challenges ahead...\n"
           "\n");
}

// Function to scavenge for resources
char* scavenge(char* input) {
    char* resources = malloc(strlen(input) + 1);
    int i = 0, j = 0;
    while (input[i]) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            resources[j++] = toupper(input[i]);
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            resources[j++] = input[i];
        } else if (input[i] >= '0' && input[i] <= '9') {
            resources[j++] = input[i];
        }
        i++;
    }
    resources[j] = '\0';
    return resources;
}

// Function to craft a message
char* craft(char* resources) {
    int len = strlen(resources);
    char* message = malloc(len + 1);
    int i = 0, j = 0;
    while (i < len) {
        if (j % 2 == 0) {
            message[j++] = resources[i++];
        } else {
            message[j++] = resources[i--] - 1;
        }
    }
    message[j] = '\0';
    return message;
}

// Function to decipher a message
char* decipher(char* message) {
    int len = strlen(message);
    char* deciphered = malloc(len + 1);
    int i = 0, j = 0;
    while (i < len) {
        if (j % 2 == 0) {
            deciphered[j++] = message[i++];
        } else {
            deciphered[j++] = message[i++] + 1;
        }
    }
    deciphered[j] = '\0';
    return deciphered;
}

// Main function
int main() {
    // Initialize variables
    char input[100];
    char* resources;
    char* message;
    char* deciphered;

    // Welcome the scavenger
    intro();

    // Scavenge for resources
    printf("   [Scavenge] Enter a string of characters to search for resources: ");
    scanf("%s", input);
    resources = scavenge(input);

    // Craft a message
    printf("\n   [Craft] Using the scavenged resources, craft a message for transmission: ");
    message = craft(resources);

    // Decipher a message
    printf("\n   [Decipher] Intercepted message: %s\n", message);
    printf("      Decipher the message to reveal its contents: ");
    deciphered = decipher(message);

    // Display the results
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
           "   SURVIVAL REPORT\n"
           "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
           "   Resources: %s\n"
           "   Crafted Message: %s\n"
           "   Deciphered Message: %s\n"
           "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
           "\n   Remember, in this wasteland, knowledge is power. String manipulation can be your lifeline.\n"
           "   May your scavenging instincts and code-breaking skills lead you to survival.\n"
           "\n");

    // Free allocated memory
    free(resources);
    free(message);
    free(deciphered);

    return 0;
}