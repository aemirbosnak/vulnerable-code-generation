//FormAI DATASET v1.0 Category: String manipulation ; Style: interoperable
#include <stdio.h>
#include <string.h>

int main() {
    char first_str[50], second_str[50], combined_str[100];
    int len, i, j; 

    // get input from user for 2 strings
    printf("Enter the first string: ");
    gets(first_str);

    printf("Enter the second string: ");
    gets(second_str);

    // combine 2 strings in alternate fashion
    len = strlen(first_str) + strlen(second_str);
    i = 0, j = 0;
    while (i < strlen(first_str) && j < strlen(second_str)) {
        combined_str[i+j] = first_str[i];
        combined_str[i+j+1] = second_str[j];
        i++;
        j++;
    }

    // add remaining characters of long string
    while (i < strlen(first_str)) {
        combined_str[i+j] = first_str[i];
        i++;
    }

    while (j < strlen(second_str)) {
        combined_str[i+j] = second_str[j];
        j++;
    }

    combined_str[len] = '\0';
    printf("The combined string is: %s\n", combined_str);

    // reverse the characters in combined string
    char temp;
    for (i = 0, j = len-1; i < j; i++, j--) {
        temp = combined_str[i];
        combined_str[i] = combined_str[j];
        combined_str[j] = temp;
    }

    printf("The reversed combined string is: %s\n", combined_str);

    // count and display the number of vowels in combined string
    int vowel_count = 0;
    for (i = 0; i < strlen(combined_str); i++) {
        if (combined_str[i] == 'a' || combined_str[i] == 'e' || combined_str[i] == 'i' || 
            combined_str[i] == 'o' || combined_str[i] == 'u' || combined_str[i] == 'A' || 
            combined_str[i] == 'E' || combined_str[i] == 'I' || combined_str[i] == 'O' || 
            combined_str[i] == 'U') {
            vowel_count++;
        }
    }

    printf("The number of vowels in the combined string is: %d\n", vowel_count);

    return 0;
}