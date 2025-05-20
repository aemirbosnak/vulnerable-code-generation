//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// A noble knight of the realm, this program shall convert decimal to hexadecimal
void convert_to_hexadecimal(int decimal, char *hexadecimal) {
    int temp;
    int index = 0;
    
    // A valiant algorithm to convert decimal to hexadecimal
    while (decimal != 0) {
        temp = decimal % 16;
        if (temp < 10) {
            hexadecimal[index++] = temp + '0'; // Adding digit
        } else {
            hexadecimal[index++] = (temp - 10) + 'A'; // Adding letter
        }
        decimal /= 16; // Proceeding through the numbers
    }
    hexadecimal[index] = '\0'; // End of the string
}

// A quest to reverse a string, a noble undertaking
void reverse_string(char *str) {
    int start = 0;
    int end = 0;

    // Finding the end of string
    while (str[end] != '\0') {
        end++;
    }
    end--; // Set to last valid character

    // Reversing the string to reveal its true form
    char temp;
    while (start < end) {
        temp = str[start]; 
        str[start] = str[end]; 
        str[end] = temp; 
        start++;
        end--;
    }
}

// The grand entrance of the main function
int main() {
    int decimal_number;
    char hexadecimal[100]; // Array to hold the hexadecimal representation

    // A merry welcome to the user
    printf("Greetings, noble traveler of the land of codes!\n");
    printf("Enter a decimal number to convert it to hexadecimal: ");
    
    // As the brave knight, we venture to take input
    if (scanf("%d", &decimal_number) != 1 || decimal_number < 0) {
        printf("Alas! Please enter a valid non-negative integer.\n");
        return 1; // Exit with failure
    }
    
    // The moment of transformation!
    convert_to_hexadecimal(decimal_number, hexadecimal);
    reverse_string(hexadecimal); // The journey is incomplete without reversing it

    // Presenting the results to the precious traveler
    printf("The number %d in hexadecimal is: %s\n", decimal_number, hexadecimal);
    
    // Farewell remarks from the program
    printf("May your day be filled with joy and fruitful endeavors!\n");
    
    return 0; // A safe return from our quest
}