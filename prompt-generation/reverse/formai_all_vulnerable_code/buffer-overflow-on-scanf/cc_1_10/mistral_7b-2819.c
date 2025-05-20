//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

// Function to check if a string is a palindrome
int is_palindrome(char *str, int start, int end) {
    while (start < end) {
        if (str[start] != str[end]) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

int main() {
    char input[101];
    int length;

    // Romeo's plea for a palindrome checker
    printf("Romeo: O sweet Juliet, grant me this boon,\n");
    printf("     To know if thy name is a palindrome,\n");
    printf("     A mirror to thy beauty, if thou art so,\n");
    printf("     That letters, when arranged as they come,\n");
    printf("     Form words the same, in seemly order.\n");

    // Juliet's response, asking for the word
    printf("Juliet: Nay, Romeo, 'tis but a simple thing,\n");
    printf("       To know the length of thy desire,\n");
    printf("       And if thy love's true name is written thus,\n");
    printf("       Speak, I will listen and then reply.\n");

    // Romeo enters the word
    printf("Romeo: 'Art thou Rosalind?' that query lies,\n");
    printf("       Upon thy lips, sweet Juliet, I pray,\n");
    printf("       Speak thou the truth or falseness thereof,\n");
    printf("       Ere I expire in sweet embrace.\n");

    scanf("%s", input);
    length = strlen(input);

    // Checking if the word is a palindrome
    if (is_palindrome(input, 0, length - 1)) {
        printf("Juliet: 'Tis true, sweet Romeo, thy love's name,\n");
        printf("       Is written the same backward as forward,\n");
        printf("       And in this mirror of thy heart,\n");
        printf("       Reflects thine own sweet likeness back.\n");
    } else {
        printf("Juliet: Alas, sweet Romeo, thy love's name,\n");
        printf("       Is not a palindrome, and so,\n");
        printf("       Our love, though deep and everlasting,\n");
        printf("       Shall not be matched in word and deed.\n");
    }

    return 0;
}