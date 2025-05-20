//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: lively
#include <stdio.h>

// Function to print fun facts about numbers
void printFunFact(int number) {
    switch (number) {
        case 10:
            printf("10 is a decagon! A shape with 10 sides!\n");
            break;
        case 9:
            printf("9 is the highest single-digit number!\n");
            break;
        case 8:
            printf("8 is often associated with luck in Chinese culture!\n");
            break;
        case 7:
            printf("7 is often considered a lucky number!\n");
            break;
        case 6:
            printf("6 is the number of faces on a standard die!\n");
            break;
        case 5:
            printf("5 is the number of human senses: sight, hearing, taste, touch, and smell!\n");
            break;
        case 4:
            printf("4 is the only number with the same number of letters as its value!\n");
            break;
        case 3:
            printf("3 is the number of dimensions we live in: length, width, and height!\n");
            break;
        case 2:
            printf("2 is the first prime number in the world of mathematics!\n");
            break;
        case 1:
            printf("1 is the symbol of unity and the start of everything!\n");
            break;
        default:
            break;
    }
}

// Recursive function for countdown and fun number facts
void magicalCountdown(int number) {
    if (number < 1) {
        printf("Blast off into the magical unknown!\n");
        return; // Base case: if the number is less than 1, return
    }
    
    // Print the current number
    printf("Counting down: %d\n", number);
    
    // Print a fun fact about the current number
    printFunFact(number);
    
    // Recursive call
    magicalCountdown(number - 1);
}

int main() {
    int startNumber;
    
    printf("Welcome to the Magical Countdown Adventure!\n");
    printf("Please enter a number to start your countdown journey: ");
    scanf("%d", &startNumber);
    
    if (startNumber < 1) {
        printf("Please enter a number greater than 0 to join the fun.\n");
    } else {
        magicalCountdown(startNumber);
    }

    return 0;
}