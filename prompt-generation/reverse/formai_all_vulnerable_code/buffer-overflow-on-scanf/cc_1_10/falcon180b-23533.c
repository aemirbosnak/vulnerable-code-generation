//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: recursive
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX 1000

void reverse(char str[], int start, int end);
void removeSpaces(char str[]);
int countWords(char str[]);
void reverseWords(char str[]);

int main() {
    char str[MAX];
    printf("Enter a string: ");
    scanf("%s", str);

    // Remove spaces from the string
    removeSpaces(str);

    // Reverse the string
    reverse(str, 0, strlen(str)-1);

    // Reverse the words in the string
    reverseWords(str);

    // Count the number of words in the string
    int numWords = countWords(str);

    printf("\nModified string: %s\n", str);
    printf("Number of words: %d\n", numWords);

    return 0;
}

void reverse(char str[], int start, int end) {
    char temp;
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void removeSpaces(char str[]) {
    int len = strlen(str);
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (!isspace(str[i])) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

int countWords(char str[]) {
    int count = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (isspace(str[i])) {
            count++;
        }
    }
    return count + 1;
}

void reverseWords(char str[]) {
    int start = 0;
    int end = strlen(str) - 1;
    while (start < end) {
        if (isspace(str[start])) {
            start++;
        } else if (isspace(str[end])) {
            end--;
        } else {
            char temp = str[start];
            str[start] = str[end];
            str[end] = temp;
            start++;
            end--;
        }
    }
}