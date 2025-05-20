//MISTRAL-7B DATASET v1.0 Category: Recursive ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char str[MAX];
    int len;
} string;

string concat(string str1, string str2) {
    string result;
    int len1 = str1.len, len2 = str2.len, len3;

    if (len1 + len2 > MAX) {
        printf("Error: String length exceeds maximum limit.\n");
        exit(EXIT_FAILURE);
    }

    result.len = len1 + len2;
    strcpy(result.str, str1.str);
    strcat(result.str, str2.str);

    return result;
}

string reverse(string str) {
    int i, j, len = str.len;
    char temp;

    for (i = 0, j = len - 1; i < len / 2; ++i, --j) {
        temp = str.str[i];
        str.str[i] = str.str[j];
        str.str[j] = temp;
    }

    return str;
}

void print_string(string str) {
    printf("%s\n", str.str);
}

void print_reverse(string str) {
    string reversed = reverse(str);
    print_string(reversed);
}

string input_string() {
    string input;
    fgets(input.str, MAX, stdin);
    input.len = strlen(input.str);
    input.str[input.len - 1] = '\0';

    return input;
}

int main() {
    int choice;
    string str1, str2, result;

    printf("I am grateful for the ability to write code.\n");
    printf("Please enter the first string: ");
    str1 = input_string();

    printf("Please enter the second string: ");
    str2 = input_string();

    printf("Do you want to concatenate (1) or reverse (2) the strings?\n");
    scanf("%d", &choice);

    if (choice == 1) {
        result = concat(str1, str2);
        print_string(result);
    } else if (choice == 2) {
        print_reverse(str1);
        print_reverse(str2);
        printf("The reversed concatenation of the two strings is: ");
        print_reverse(concat(reverse(str1), reverse(str2)));
    } else {
        printf("Invalid choice. Please try again.\n");
    }

    return 0;
}