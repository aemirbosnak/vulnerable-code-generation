//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: happy
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRINGS 10
#define MAX_LENGTH 100

void convertToUpper(char str[]) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

void convertToLower(char str[]) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void reverseString(char str[]) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

void printHappyMessage(char message[]) {
    printf("🎉🎈 Here’s your Happy Sentence: 🎈🎉\n");
    printf("🎊 %s 🎊\n", message);
}

int main() {
    char strings[MAX_STRINGS][MAX_LENGTH];
    char happySentence[MAX_LENGTH * MAX_STRINGS] = "";
    int count = 0;

    printf("🌟 Welcome to the Happy String Manipulator! 🌟\n");
    printf("How many happy strings would you like to combine? (Max %d) ", MAX_STRINGS);
    scanf("%d", &count);
    
    if (count > MAX_STRINGS) {
        count = MAX_STRINGS;
        printf("You can only enter up to %d strings. Proceeding with that amount.\n", MAX_STRINGS);
    }

    // Let's gather some strings!
    for (int i = 0; i < count; i++) {
        printf("Enter happy string #%d: ", i + 1);
        scanf(" %[^\n]", strings[i]); // Read a full line
    }

    // Append all the strings together
    for (int i = 0; i < count; i++) {
        strcat(happySentence, strings[i]);
        if (i < count - 1) {
            strcat(happySentence, " "); // Add a space between words
        }
    }

    // Now let's manipulate the happy sentence!
    char upperSentence[MAX_LENGTH * MAX_STRINGS];
    strcpy(upperSentence, happySentence);
    convertToUpper(upperSentence);

    char lowerSentence[MAX_LENGTH * MAX_STRINGS];
    strcpy(lowerSentence, happySentence);
    convertToLower(lowerSentence);

    char reversedSentence[MAX_LENGTH * MAX_STRINGS];
    strcpy(reversedSentence, happySentence);
    reverseString(reversedSentence);

    // Print everything!
    printHappyMessage(happySentence);
    printHappyMessage(upperSentence);
    printHappyMessage(lowerSentence);
    printHappyMessage(reversedSentence);
    
    // Adding some final blessings
    printf("🌈✨ Thank you for spreading happiness with strings! ✨🌈\n");
    printf("Have a joyful day ahead! 😄😃❤️\n");

    return 0;
}