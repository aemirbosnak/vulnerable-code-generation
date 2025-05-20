//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: irregular
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

void reverse(char *str, int start, int end) {
 char temp;
 while (start < end) {
 temp = str[start];
 str[start] = str[end];
 str[end] = temp;
 start++;
 end--;
 }
}

void randomize(char *str, int len) {
 int i, j, k;
 char random_char;
 for (i = 0; i < len; i++) {
 j = rand() % len;
 k = rand() % 26;
 random_char = 'a' + k;
 str[i] = (str[j] == str[i]) ? random_char : str[i];
 }
}

int main() {
 char input_str[MAX_LEN];
 char *ptr1, *ptr2, *ptr3;
 int len;
 printf("Enter a string: ");
 fgets(input_str, MAX_LEN, stdin);
 len = strlen(input_str);
 // Randomly shuffle the string
 randomize(input_str, len);
 printf("Randomly shuffled string: %s\n", input_str);
 // Reverse the first half of the string
 reverse(input_str, 0, len / 2);
 // Reverse the last half of the string
 reverse(input_str + (len / 2), len / 2, len);
 printf("String after reversing first and last half: %s\n", input_str);
 // Find and print the first occurrence of the last character in the string
 for (ptr1 = input_str; *ptr1 != '\0'; ptr1++) {
 if (*ptr1 == *(input_str + len - 1)) {
 ptr2 = ptr1;
 break;
 }
 }
 printf("The first occurrence of the last character is at position %d\n", ptr2 - input_str + 1);
 // Find and print the substring that is the reverse of the input string
 for (ptr1 = input_str, ptr3 = input_str + len - 1; *ptr1 != '\0' && *ptr3 != '\0'; ptr1++, ptr3--) {
 if (*ptr1 != *ptr3) {
 printf("Input string is not a palindrome\n");
 goto end;
 }
 }
 printf("Input string is a palindrome\n");
 // Print the string in reverse order
 for (ptr1 = input_str + len; ptr1 > input_str; ptr1--) {
 printf("%c", *ptr1);
 }
 // Clean up and exit
 end:
 free(ptr1);
 free(ptr2);
 free(ptr3);
 return 0;
}