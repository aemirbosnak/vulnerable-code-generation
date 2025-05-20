//FormAI DATASET v1.0 Category: Text processing ; Style: surprised
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to convert each word in the given string to lowercase
void convertToLowercase(char *str) {
    int i = 0;
    while(str[i] != '\0') {
        str[i] = tolower(str[i]);
        i++;
    }
}

int main() {
    char str[1000], word[50], replace[50];
    int i = 0, j = 0, k = 0, index = 0, len = 0, wordCount = 0;

    printf("Welcome to the Text Processing Example Program!\n");
    printf("Please input the string to be processed: ");

    // Read the input string from the user
    fgets(str, sizeof(str), stdin);

    // Remove trailing newline character from the input string
    str[strcspn(str, "\n")] = 0;

    // Count the number of words in the input string
    len = strlen(str);
    for(i = 0; i < len; i++) {
        if(str[i] == ' ') {
            wordCount++;
        }
    }
    wordCount++;

    printf("There are %d words in the input string.\n", wordCount);

    printf("Please input the word to be replaced and its replacement: ");
    scanf("%s %s", word, replace);

    // Convert the words to lowercase
    convertToLowercase(word);
    convertToLowercase(replace);

    // Loop over each word in the string and replace the given word
    for(i = 0; i <= len; i++) {
        if(str[i] == ' ' || str[i] == '\0') {
            index = i - j;
            char temp[50];
            strncpy(temp, &str[j], index);
            temp[index] = '\0';
            convertToLowercase(temp);
            j = i + 1;
            if(strcmp(temp, word) == 0) {
                k = j - index - 1;
                while(k < i) {
                    str[k] = replace[k-j+index+1];
                    k++;
                }
            }
        }
    }

    printf("The processed string is: %s\n", str);

    printf("Thank you for using the Text Processing Example Program!\n");
    return 0;
}