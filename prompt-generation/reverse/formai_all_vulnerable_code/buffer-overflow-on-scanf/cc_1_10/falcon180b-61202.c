//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

// Function to remove all whitespaces from a string
void remove_whitespaces(char *s) {
    int i = 0;
    int j = 0;
    while (s[i]) {
        if (!isspace(s[i])) {
            s[j++] = s[i];
        }
        i++;
    }
    s[j] = '\0';
}

// Function to reverse a string
void reverse_string(char *s) {
    int i = 0;
    int j = strlen(s) - 1;
    while (i < j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}

// Function to check if two strings are anagrams
int are_anagrams(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if (len1!= len2) {
        return 0;
    }
    remove_whitespaces(s1);
    remove_whitespaces(s2);
    reverse_string(s1);
    reverse_string(s2);
    if (strcmp(s1, s2) == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Function to read a string from the user
void read_string(char *s) {
    printf("Enter a string: ");
    scanf("%s", s);
}

int main() {
    char string1[MAX_SIZE];
    char string2[MAX_SIZE];
    int result;

    // Read two strings from the user
    read_string(string1);
    read_string(string2);

    // Check if they are anagrams
    result = are_anagrams(string1, string2);

    // Print the result
    if (result == 1) {
        printf("The strings are anagrams.\n");
    } else {
        printf("The strings are not anagrams.\n");
    }

    return 0;
}