//FormAI DATASET v1.0 Category: Text processing ; Style: realistic
#include <stdio.h>
#include <string.h>

// function to tokenize a string and count the number of words
int countWords(char *str) {
    int count = 0;
    char delim[] = " ,.;:\n\t"; // delimiters for tokenizing
    char *token = strtok(str, delim); // tokenize the string

    while(token) { // iterate over all tokens and count them
        count++;
        token = strtok(NULL, delim);
    }

    return count;
}

// function to replace a substring within a string
char * replaceSubstring(char *str, char *old, char *new) {
    int oldLen = strlen(old); // length of the old string
    int newLen = strlen(new); // length of the new string
    char *result; // pointer to hold the result

    // allocate memory for the result
    result = malloc(strlen(str) + (newLen - oldLen) + 1);

    // continue if memory was successfully allocated
    if(result != NULL) {
        char *ptr = str; // pointer to iterate over the original string
        char *temp; // pointer to hold the position of the old substring

        while(temp = strstr(ptr, old)) { // find all occurrences of the old substring
            strncpy(result, ptr, temp - ptr); // copy the part of the original string before the old substring
            result[temp - ptr] = '\0'; // null terminate the result string
            strcat(result, new); // concatenate the new string
            ptr = temp + oldLen; // move the pointer past the old substring
            strcat(result, ptr); // concatenate the rest of the original string
        }

        if(ptr != str + strlen(str)) { // add the remaining characters to the result string
            strcat(result, ptr);
        }
    }

    return result;
}

int main() {
    char str[1000]; // input string
    char oldSub[100]; // old substring
    char newSub[100]; // new substring

    printf("Enter a string: ");
    fgets(str, 1000, stdin);

    printf("Number of words in the string: %d\n", countWords(str)); // count the number of words in the string

    printf("Enter the substring to replace: ");
    fgets(oldSub, 100, stdin);
    oldSub[strlen(oldSub) - 1] = '\0'; // remove the newline character from the input

    printf("Enter the new substring: ");
    fgets(newSub, 100, stdin);
    newSub[strlen(newSub) - 1] = '\0'; // remove the newline character from the input

    char *newStr = replaceSubstring(str, oldSub, newSub); // replace the old substring with the new substring
    printf("Original String: %s", str);
    printf("Modified String: %s", newStr);

    return 0;
}