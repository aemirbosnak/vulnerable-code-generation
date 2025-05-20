//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
void reverse(char *str, int len) {
    char *start = str;
    char *end = str + len - 1;
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

// Function to check if a string is a palindrome
int isPalindrome(char *str, int len) {
    reverse(str, len);
    int i;
    for (i = 0; i < len / 2; i++) {
        if (str[i]!= str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

// Function to recover deleted data from a file
void recoverData(FILE *file) {
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file)!= NULL) {
        int len = strlen(buffer);
        if (buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
            len--;
        }
        int i;
        for (i = 0; i < len / 2; i++) {
            if (isPalindrome(buffer + i, len - i)) {
                printf("%s\n", buffer + i);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }
    recoverData(file);
    fclose(file);
    return 0;
}