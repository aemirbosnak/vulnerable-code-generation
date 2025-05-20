//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: imaginative
#include <stdio.h>

void convertToHex(int number) {
    char hex[50];
    int i = 0;

    // Handle zero case first
    if (number == 0) {
        printf("Oh look, a magical zero! Its hexadecimal form is also: 0x0\n");
        return;
    }

    while (number != 0) {
        int temp = number % 16;

        // Check for numbers above 9
        if (temp < 10) {
            hex[i] = temp + 48; // 48 is ASCII for '0'
        } else {
            hex[i] = temp + 87; // 87 is ASCII for 'a' (10 -> 'a', 11 -> 'b', ...)
        }
        number = number / 16;
        i++;
    }

    printf("Hold on tight! Converting...\nYour number in hexadecimal is: 0x");
    
    // Print in reverse order
    for (int j = i - 1; j >= 0; j--) {
        putchar(hex[j]);
    }
    puts("");  // Move to a new line
}

int main() {
    printf("Welcome to the Whimsical Hexadecimal Converter!\n");
    printf("Convert your numbers into their magical hex forms!\n");

    int number;
    char choice;

    do {
        printf("\nEnter an integer (you can use negative numbers for extra pizzazz!): ");
        if (scanf("%d", &number) != 1) {
            printf("Oops! That doesn't seem like an integer. Let’s sprinkle some magic dust and try again.\n");
            while(getchar() != '\n'); // clear buffer
            continue;
        }

        convertToHex(number);

        printf("\nWould you like to convert another number? (y/n): ");
        while (getchar() != '\n');  // clear buffer
        scanf("%c", &choice);

        if (choice == 'y' || choice == 'Y') {
            printf("Fantastic! Let's keep the magic rolling!\n");
        } else {
            printf("Thank you for visiting the land of hexadecimal! Farewell!\n");
        }

    } while (choice == 'y' || choice == 'Y');

    return 0;
}