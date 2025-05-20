//FormAI DATASET v1.0 Category: String manipulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100

char* concat(const char *s1, const char *s2) { // Concatenates two strings
    char *result = malloc(strlen(s1) + strlen(s2) + 1);
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

char* remove_char(char *str, char c) { // Removes all occurrences of a specific character from a string
    int i, j = 0;
    int len = strlen(str);
    char *result = malloc(len + 1);
    
    for (i = 0; i < len; i++) {
        if (str[i] != c) {
            result[j++] = str[i];
        }
    }
    
    result[j] = '\0';
    return result;
}

void to_upper(char *str) { // Converts a string to uppercase
    int i;
    int len = strlen(str);
    
    for (i = 0; i < len; i++) {
        str[i] = toupper(str[i]);
    }
}

void to_lower(char *str) { // Converts a string to lowercase
    int i;
    int len = strlen(str);
    
    for (i = 0; i < len; i++) {
        str[i] = tolower(str[i]);
    }
}

int count_occurrences(char *str, char c) { // Counts the number of occurrences of a specific character in a string
    int i;
    int len = strlen(str);
    int count = 0;
    
    for (i = 0; i < len; i++) {
        if (str[i] == c) {
            count++;
        }
    }
    
    return count;
}

int main() {
    char str[MAX_STR_LEN];
    printf("Enter a string (max %d characters): ", MAX_STR_LEN-1);
    fgets(str, MAX_STR_LEN, stdin);
    str[strcspn(str, "\n")] = '\0'; // remove newline character
    
    // Configurable options
    int opt1 = 1; // Concatenation enabled
    int opt2 = 1; // Character removal enabled
    int opt3 = 1; // Uppercase conversion enabled
    int opt4 = 1; // Lowercase conversion enabled
    int opt5 = 1; // Occurrence counting enabled
    
    if (opt1) {
        char s1[MAX_STR_LEN];
        char s2[MAX_STR_LEN];
        printf("Enter two strings to concatenate (max %d characters each): ", MAX_STR_LEN-1);
        scanf("%s %s", s1, s2);
        char *result = concat(s1, s2);
        printf("Concatenated string: %s\n", result);
        free(result);
    }
    
    if (opt2) {
        char c;
        printf("Enter a character to remove from the string: ");
        scanf(" %c", &c);
        char *result = remove_char(str, c);
        printf("String with '%c' removed: %s\n", c, result);
        free(result);
    }
    
    if (opt3) {
        char *temp = strdup(str); // Need to make a copy because to_upper and to_lower modify the original string
        to_upper(temp);
        printf("Uppercase string: %s\n", temp);
        free(temp);
    }
    
    if (opt4) {
        char *temp = strdup(str);
        to_lower(temp);
        printf("Lowercase string: %s\n", temp);
        free(temp);
    }
    
    if (opt5) {
        char c;
        printf("Enter a character to count occurrences of: ");
        scanf(" %c", &c);
        int count = count_occurrences(str, c);
        printf("Number of occurrences of '%c': %d\n", c, count);
    }
    
    return 0;
}