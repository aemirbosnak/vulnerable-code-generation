//FormAI DATASET v1.0 Category: String manipulation ; Style: excited
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the most exciting C String manipulation program ever!\n\n");

    char originalString[100];
    char newString[100];

    printf("Enter a string that you want to manipulate: ");
    scanf("%s", originalString);

    printf("\nOriginal string: \n%s\n\n", originalString);

    // Reversing the string
    int len = strlen(originalString);
    int i;
    for(i = 0; i < len; i++) {
        newString[i] = originalString[len - i - 1];
    }
    newString[len] = '\0';
    printf("The reversed string is: %s\n\n", newString);

    // Capitalizing the string
    char capitalizedString[100];
    for(i = 0; i < len; i++) {
        if(originalString[i] >= 'a' && originalString[i] <= 'z') {
            capitalizedString[i] = originalString[i] - 32;
        } else {
            capitalizedString[i] = originalString[i];
        }
    }
    capitalizedString[len] = '\0';
    printf("The capitalized string is: %s\n\n", capitalizedString);

    // Counting the number of vowels in the string
    int vowelCount = 0;
    for(i = 0; i < len; i++) {
        if(originalString[i] == 'a' || originalString[i] == 'e' || originalString[i] == 'i' || originalString[i] == 'o' || originalString[i] == 'u' || originalString[i] == 'A' || originalString[i] == 'E' || originalString[i] == 'I' || originalString[i] == 'O' || originalString[i] == 'U') {
            vowelCount++;
        }
    }
    printf("The number of vowels in the string is: %d\n\n", vowelCount);

    // Adding a prefix and suffix to the string
    char finalString[150] = "Exciting string manipulation program: ";
    strcat(finalString, originalString);
    strcat(finalString, " is so cool!");
    printf("The final string with prefix and suffix is: %s\n\n", finalString);

    printf("Wow! That was an incredible string manipulation program. Hope you enjoyed it!\n");

    return 0;
}