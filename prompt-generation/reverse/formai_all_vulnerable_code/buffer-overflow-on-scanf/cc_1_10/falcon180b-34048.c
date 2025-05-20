//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

void reverse_string(char* str) {
    int length = strlen(str);
    char reverse[MAX_LENGTH];
    int i = 0;
    for(int j = length - 1; j >= 0; j--) {
        reverse[i] = str[j];
        i++;
    }
    reverse[i] = '\0';
    strcpy(str, reverse);
}

void remove_vowels(char* str) {
    int length = strlen(str);
    char vowels[] = "aeiouAEIOU";
    char new_str[MAX_LENGTH];
    int i = 0;
    for(int j = 0; j < length; j++) {
        if(strchr(vowels, str[j]) == NULL) {
            new_str[i] = str[j];
            i++;
        }
    }
    new_str[i] = '\0';
    strcpy(str, new_str);
}

void replace_char(char* str, char old_char, char new_char) {
    int length = strlen(str);
    char new_str[MAX_LENGTH];
    int i = 0;
    for(int j = 0; j < length; j++) {
        if(str[j] == old_char) {
            new_str[i] = new_char;
            i++;
        } else {
            new_str[i] = str[j];
            i++;
        }
    }
    new_str[i] = '\0';
    strcpy(str, new_str);
}

int main() {
    char str[MAX_LENGTH];
    printf("Enter a string: ");
    scanf("%s", str);

    reverse_string(str);
    printf("Reversed string: %s\n", str);

    remove_vowels(str);
    printf("String without vowels: %s\n", str);

    replace_char(str, 'a', '*');
    printf("String with 'a' replaced by '*': %s\n", str);

    return 0;
}