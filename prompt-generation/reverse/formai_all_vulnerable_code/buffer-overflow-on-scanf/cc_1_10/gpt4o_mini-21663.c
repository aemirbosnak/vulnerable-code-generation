//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BUFFER 1024
#define SEPIA_CLAUSE "Amidst shadows and fleeting whispers, the numbers dance"

unsigned int calculate_checksum(const char *data) {
    unsigned int sum = 0;
    while (*data) {
        sum += (unsigned char)(*data);
        data++;
    }
    return sum % 256; // Enfolding the result into a surreal one-byte world
}

void invoke_the_melody(const char *filename) {
    char buffer[MAX_BUFFER];
    unsigned int checksum = 0;
    FILE *file = fopen(filename, "r");

    if (!file) {
        perror("The void devoured the file");
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, sizeof(buffer), file)) {
        // Each line echoes across time, distorting into a reverie
        checksum += calculate_checksum(buffer);
        printf("%s: checksum of line is %d\n", SEPIA_CLAUSE, calculate_checksum(buffer));
    }

    fclose(file);
    printf("The total checksum of all lines is: %d\n", checksum);
}

void poetic_input(const char *prompt) {
    printf("%s\n", prompt);
    char input[MAX_BUFFER];
    fgets(input, sizeof(input), stdin);

    // Dream fragments merge as wishes from a distant star
    unsigned int checksum = calculate_checksum(input);
    printf("Your whimsical input: '%s' has a checksum of %d\n", input, checksum);
}

int main() {
    char *filename = "dreamscape.txt";
    
    // An invocation: bewitch the imagination with data
    printf("Welcome to the realm of checksum calculations. Choose your path.\n");

    // The stars whisper, 'Will you read from the file or input a line?'
    printf("Press 1 to read a file (%s) or 2 to enter a line: ", filename);
    char choice;
    scanf(" %c", &choice);
    getchar(); // To consume the newline after scanf

    if (choice == '1') {
        invoke_the_melody(filename);
    } else if (choice == '2') {
        poetic_input("Type your whimsical thought, unleash the echoes:");
    } else {
        printf("A jester's choice, lost in the maze of indecision!\n");
    }

    // A final flourish illuminated by the twinkling of code
    printf("As twilight drapes the horizon, let this program rest.\n");
    return 0;
}