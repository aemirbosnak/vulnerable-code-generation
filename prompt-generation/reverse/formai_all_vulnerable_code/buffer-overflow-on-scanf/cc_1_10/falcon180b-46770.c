//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random string of given length
char* generateRandomString(int length) {
    char* result = (char*)malloc(length * sizeof(char));
    for (int i = 0; i < length; i++) {
        result[i] = 'a' + rand() % 26;
    }
    result[length - 1] = '\0';
    return result;
}

// Function to print a string with given speed
void printStringWithSpeed(char* string, int speed) {
    for (int i = 0; i < strlen(string); i++) {
        printf("%c", string[i]);
        fflush(stdout);
        usleep(speed);
    }
}

// Function to get user input as a string
char* getInput(char* prompt) {
    char input[100];
    printf("%s", prompt);
    scanf("%s", input);
    return strdup(input);
}

// Function to test typing speed
int main() {
    srand(time(NULL));

    int length, speed;
    char* text;

    // Get user preferences
    printf("Welcome to the Typing Speed Test!\n");
    printf("Please enter the length of the text you want to type: ");
    length = atoi(getInput("Length: "));
    printf("Please enter the speed at which you want the text to appear: ");
    speed = atoi(getInput("Speed (in milliseconds): "));

    // Generate random text
    text = generateRandomString(length);

    // Print text with given speed
    printf("\nReady? Set? Type!\n");
    printStringWithSpeed(text, speed);

    // Calculate and display typing speed
    int correctChars = 0, totalChars = 0;
    printf("\nYou typed %d characters correctly out of %d.\n", correctChars, length);
    double speedInWordsPerMinute = (double)length / (5.0 * speed) * 60.0;
    printf("Your typing speed is %.2f words per minute.\n", speedInWordsPerMinute);

    return 0;
}