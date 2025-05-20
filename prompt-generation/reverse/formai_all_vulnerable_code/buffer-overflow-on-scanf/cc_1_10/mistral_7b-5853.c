//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_LENGTH 100
#define MAX_CHAR 256
#define MAX_SUBSTRINGS 100
typedef struct {
    char str[MAX_STRING_LENGTH];
    int length;
} String;
typedef struct {
    char substr[MAX_STRING_LENGTH];
    int length;
} Substring;
Substring longestSubstring(String str, int start, Substring best) {
    if (start >= str.length) {
        return best;
    }
    Substring temp;
    strcpy(temp.substr, str.str + start);
    temp.length = 1;
    start++;
    while (start < str.length && str.str[start] != '\0') {
        temp.length += 1;
        strcpy(temp.substr + temp.length, str.str + start);
        Substring result = longestSubstring(str, start, temp);
        if (result.length > temp.length) {
            temp = result;
        }
        start++;
    }
    if (temp.length > best.length) {
        best = temp;
    }
    return best;
}
String findLongestSubstringRecursively(String str) {
    Substring best = {""};
    longestSubstring(str, 0, best);
    String result;
    strcpy(result.str, best.substr);
    result.length = best.length;
    return result;
}
int main() {
    String input;
    printf("Enter a string: ");
    scanf("%s", input.str);
    String longestSubstring = findLongestSubstringRecursively(input);
    printf("Longest substring: %s\nLength: %d\n", longestSubstring.str, longestSubstring.length);
    return 0;
}