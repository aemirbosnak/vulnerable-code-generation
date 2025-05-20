//FormAI DATASET v1.0 Category: String manipulation ; Style: creative
#include <stdio.h>
#include <string.h>

int main() {
    // Initialize a string
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    // Print the length of the string
    printf("Length of the string is: %d\n", strlen(str));

    // Reverse the string
    printf("The reversed string is: ");
    for(int i = strlen(str) - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");

    // Count number of vowels in the string
    int countVowels = 0;
    for(int i = 0; i < strlen(str); i++) {
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
            countVowels++;
        }
    }
    printf("The string has %d vowels.\n", countVowels);

    // Remove a specific character from the string
    char removeChar;
    printf("Enter a character to remove from the string: ");
    scanf(" %c", &removeChar);
    int j = 0;
    for(int i = 0; i < strlen(str); i++) {
        if(str[i] != removeChar) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
    printf("The new string is: %s\n", str);

    // Replace a specific substring with another substring
    char findStr[50], replaceStr[50], newStr[150];
    printf("Enter the substring to find: ");
    scanf("%s", findStr);
    printf("Enter the substring to replace with: ");
    scanf("%s", replaceStr);
    int findStrLen = strlen(findStr);
    int replaceStrLen = strlen(replaceStr);
    int i = 0;
    while(i < strlen(str)) {
        int k = 0;
        while(str[i + k] == findStr[k] && k < findStrLen) {
            k++;
        }
        if(k == findStrLen) {
            strncpy(&newStr[j], replaceStr, replaceStrLen);
            j += replaceStrLen;
            i += findStrLen;
        } else {
            newStr[j++] = str[i++];
        }
    }
    newStr[j] = '\0';
    printf("The modified string is: %s\n", newStr);

    // Congratulations message
    printf("\nCongratulations! You have successfully manipulated a string!\n");

    return 0;
}
