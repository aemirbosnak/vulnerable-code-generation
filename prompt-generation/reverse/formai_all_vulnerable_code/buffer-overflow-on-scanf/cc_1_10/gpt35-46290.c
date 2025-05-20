//FormAI DATASET v1.0 Category: String manipulation ; Style: mathematical
#include <stdio.h>
#include <string.h>

// Function to reverse the string
void reverse(char* str) {
    int len = strlen(str);
    char temp;
    for (int i = 0; i < len/2; i++) {
        temp = *(str+i);
        *(str+i) = *(str+len-i-1);
        *(str+len-i-1) = temp;
    }
}

int main() {
    // Input the String
    char str[100];
    printf("Enter a String: ");
    scanf("%s", str);

    // Count number of vowels
    int vowels = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
            str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
            vowels++;
        }
    }

    // Reverse the String
    reverse(str);

    // Calculate the sum of digits
    int sum_of_digits = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (isdigit(str[i])) {
            sum_of_digits += str[i] - '0';
        }
    }

    // Find the first occurence of a character
    int index = -1;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == 'a') {
            index = i;
            break;
        }
    }

    // Output the calculations
    printf("Number of vowels in the String: %d\n", vowels);
    printf("Reversed String: %s\n", str);
    printf("Sum of digits in the String: %d\n", sum_of_digits);
    if (index != -1) {
        printf("The first occurence of 'a' is at index: %d\n", index);
    } else {
        printf("The character 'a' does not occur in the String.\n");
    }
    return 0;
}