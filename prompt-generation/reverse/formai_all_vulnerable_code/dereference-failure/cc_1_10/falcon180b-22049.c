//Falcon-180B DATASET v1.0 Category: Text processing ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to trim leading and trailing whitespace from a string
char* trim(char* str) {
    char* end;
    if (str[0]!= '\0') {
        while (isspace(*str)) {
            str++;
        }
        end = str + strlen(str) - 1;
        while (isspace(*end)) {
            end--;
            *end = '\0';
        }
    }
    return str;
}

// Function to split a string into an array of words
char** split(char* str) {
    char* token = strtok(str, " ");
    int count = 0;
    char** words = (char**)malloc(sizeof(char*));
    while (token!= NULL) {
        words[count] = trim(token);
        token = strtok(NULL, " ");
        count++;
    }
    words[count] = NULL;
    return words;
}

// Function to sort an array of words alphabetically
void sort(char** words) {
    int count = 0;
    while (words[count]!= NULL) {
        count++;
    }
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(words[i], words[j]) > 0) {
                char* temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

// Function to print an array of words
void print(char** words) {
    int count = 0;
    while (words[count]!= NULL) {
        printf("%s ", words[count]);
        count++;
    }
    printf("\n");
}

int main() {
    char input[1000];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    char** words = split(input);
    sort(words);
    print(words);
    for (int i = 0; words[i]!= NULL; i++) {
        free(words[i]);
    }
    free(words);
    return 0;
}