//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int is_valid_number(const char* str);
void reverse_string(char* str);
void add_strings(char* str1, char* str2);
void multiply_string_by_int(char* str, int num);

int main() {
    char str1[MAX_LENGTH];
    char str2[MAX_LENGTH];
    char result[MAX_LENGTH];

    // Example usage
    strcpy(str1, "1234567890");
    strcpy(str2, "9876543210");

    add_strings(str1, str2);
    printf("Result: %s\n", str1);

    multiply_string_by_int(str1, 2);
    printf("Result: %s\n", str1);

    return 0;
}

int is_valid_number(const char* str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

void reverse_string(char* str) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void add_strings(char* str1, char* str2) {
    int carry = 0;
    int i = strlen(str1) - 1, j = strlen(str2) - 1, k = strlen(str1) - 1;
    while (i >= 0 || carry!= 0) {
        if (i >= 0) {
            str1[i] += carry + str2[j] - '0';
        }
        else {
            str1[i] += carry;
        }
        carry = str1[i] / 10;
        str1[i] %= 10;
        i--;
        j--;
    }
}

void multiply_string_by_int(char* str, int num) {
    int carry = 0;
    int i = strlen(str) - 1;
    while (i >= 0) {
        str[i] *= num + carry;
        carry = str[i] / 10;
        str[i] %= 10;
        i--;
    }
}