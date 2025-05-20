//Falcon-180B DATASET v1.0 Category: Recursive ; Style: genious
#include <stdio.h>
#include <stdlib.h>

// Function to count the number of vowels in a string
int countVowels(char *str) {
    int count = 0;
    char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int i, j;

    // Iterate through the string and compare each character with vowels
    for (i = 0; str[i]!= '\0'; i++) {
        for (j = 0; j < 10; j++) {
            if (str[i] == vowels[j]) {
                count++;
                break;
            }
        }
    }

    return count;
}

// Recursive function to reverse a string
void reverseString(char *str, int start, int end) {
    char temp;

    // Base case: if start index is greater than or equal to end index, return
    if (start >= end)
        return;

    // Swap characters at start and end indices
    temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    // Recursive call with incremented start index and decremented end index
    reverseString(str, start + 1, end - 1);
}

int main() {
    char str[100];

    // Prompt user to enter a string
    printf("Enter a string: ");
    scanf("%s", str);

    // Count the number of vowels in the string
    int vowelCount = countVowels(str);

    // Reverse the string
    reverseString(str, 0, strlen(str) - 1);

    // Print the reversed string and vowel count
    printf("Reversed string: %s\n", str);
    printf("Number of vowels: %d\n", vowelCount);

    return 0;
}