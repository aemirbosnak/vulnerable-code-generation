//GEMINI-pro DATASET v1.0 Category: Educational ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialize a character array to store the input
    char input[100];

    // Prompt the user to enter a positive integer
    printf("Dear user, please enter a positive integer: ");

    // Read the input from the user
    scanf("%s", input);

    // Check if the input is a valid positive integer
    int number;
    if (sscanf(input, "%d", &number) != 1 || number <= 0) {
        // If the input is not valid, display an error message
        printf("Invalid input. Please enter a valid positive integer.\n");
        return EXIT_FAILURE;
    }

    // Initialize a gratitude counter to keep track of the number of times we express gratitude
    int gratitudeCounter = 0;

    // Iterate over each digit in the input
    for (int i = 0; i < strlen(input); i++) {
        // Convert the digit to an integer
        int digit = input[i] - '0';

        // Express gratitude for the digit
        switch (digit) {
            case 0:
                printf("Thank you for the round and lovely zero.\n");
                gratitudeCounter++;
                break;
            case 1:
                printf("Thank you for the unique and special one.\n");
                gratitudeCounter++;
                break;
            case 2:
                printf("Thank you for the harmonious and cooperative two.\n");
                gratitudeCounter++;
                break;
            case 3:
                printf("Thank you for the dynamic and energetic three.\n");
                gratitudeCounter++;
                break;
            case 4:
                printf("Thank you for the stable and secure four.\n");
                gratitudeCounter++;
                break;
            case 5:
                printf("Thank you for the curious and adventurous five.\n");
                gratitudeCounter++;
                break;
            case 6:
                printf("Thank you for the nurturing and supportive six.\n");
                gratitudeCounter++;
                break;
            case 7:
                printf("Thank you for the wise and introspective seven.\n");
                gratitudeCounter++;
                break;
            case 8:
                printf("Thank you for the infinite and abundant eight.\n");
                gratitudeCounter++;
                break;
            case 9:
                printf("Thank you for the compassionate and selfless nine.\n");
                gratitudeCounter++;
                break;
        }
    }

    // Display a final message expressing gratitude for the entire input
    printf("Thank you for sharing your positive integer with me. I am grateful for the opportunity to express my appreciation for each of its digits.\n");

    // Display the total number of times we expressed gratitude
    printf("Total gratitude expressed: %d\n", gratitudeCounter);

    return EXIT_SUCCESS;
}