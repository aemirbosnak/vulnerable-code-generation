//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Function to reverse a string
void reverse_string(char* str) {
    int i = 0, j = strlen(str) - 1;
    char temp;

    while (i < j) {
        temp = *(str + i);
        *(str + i) = *(str + j);
        *(str + j) = temp;
        i++;
        j--;
    }
}

// Function to count the number of vowels in a string
int count_vowels(char* str) {
    int count = 0;
    char vowels[] = "aeiouAEIOU";

    for (int i = 0; str[i]!= '\0'; i++) {
        char c = tolower(str[i]);
        if (strchr(vowels, c)!= NULL) {
            count++;
        }
    }

    return count;
}

int main() {
    char input_string[100];

    // Get input string from user
    printf("Enter a string: ");
    scanf("%s", input_string);

    // Reverse the input string
    reverse_string(input_string);

    // Count the number of vowels in the reversed string
    int vowel_count = count_vowels(input_string);

    // Print the reversed string and the number of vowels
    printf("Reversed string: %s\n", input_string);
    printf("Number of vowels: %d\n", vowel_count);

    return 0;
}