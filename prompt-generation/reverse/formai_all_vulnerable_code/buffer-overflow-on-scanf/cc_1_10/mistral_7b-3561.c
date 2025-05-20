//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int top;
    unsigned capacity;
    char* array;
} stack;

stack string_stack;

void push_char(char c) {
    if (string_stack.top == string_stack.capacity) {
        string_stack.capacity *= 2;
        string_stack.array = realloc(string_stack.array, string_stack.capacity * sizeof(char));
    }
    string_stack.array[string_stack.top++] = c;
}

char pop_char() {
    if (string_stack.top <= 0) {
        fprintf(stderr, "Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return string_stack.array[--string_stack.top];
}

int is_palindrome_string(const char* str, int len) {
    int left = 0;
    int right = len - 1;

    while (left < right) {
        if (tolower(str[left]) != tolower(str[right])) {
            return 0;
        }
        push_char(str[left]);
        left++;
        right--;
    }

    if (len & 1) {
        return tolower(str[0]) == tolower(str[len - 1]);
    }

    return pop_char() == str[0];
}

int main() {
    char str[101];
    int len;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    len = strlen(str);

    if (is_palindrome_string(str, len)) {
        printf("%s is a palindrome\n", str);
    } else {
        printf("%s is not a palindrome\n", str);
    }

    printf("Enter an integer: ");
    int num;
    scanf("%d", &num);

    if (is_palindrome_int(num)) {
        printf("%d is a palindrome number\n", num);
    } else {
        printf("%d is not a palindrome number\n", num);
    }

    int arr[11] = {1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1};

    if (is_palindrome_array(arr, sizeof(arr) / sizeof(arr[0]))) {
        printf("Array is a palindrome\n");
    } else {
        printf("Array is not a palindrome\n");
    }

    return 0;
}

int is_palindrome_int(int num) {
    int reversed_num = 0;
    int original_num = num;

    while (num != 0) {
        int digit = num % 10;
        reversed_num = reversed_num * 10 + digit;
        num /= 10;
    }

    return reversed_num == original_num;
}

int is_palindrome_array(const int* arr, size_t len) {
    int left = 0;
    int right = len - 1;

    while (left < right) {
        if (arr[left] != arr[right]) {
            return 0;
        }
        left++;
        right--;
    }

    return 1;
}