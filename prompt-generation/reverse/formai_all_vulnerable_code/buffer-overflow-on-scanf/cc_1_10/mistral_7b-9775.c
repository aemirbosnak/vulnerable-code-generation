//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 100

void reverse(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void concat(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char *result = (char *)malloc((len1 + len2 + 1) * sizeof(char));
    strcpy(result, str1);
    strcat(result, str2);
    printf("Concatenated string: %s\n", result);
    free(result);
}

void print_array(char arr[]) {
    for (int i = 0; i < strlen(arr); i++) {
        printf("%c ", arr[i]);
    }
    printf("\n");
}

void replace_sub_string(char *str, char *substr, char replacement) {
    int len_str = strlen(str);
    int len_substr = strlen(substr);
    int pos = 0;
    int counter = 0;

    while ((pos = strchr(str, substr[0]) - str) != -1) {
        for (int i = 0; i < len_substr; i++) {
            str[pos + i] = replacement;
        }
        counter++;
        str += pos + len_substr;
    }
    printf("Replaced '%s' with '%c' %d times.\n", substr, replacement, counter);
}

int main() {
    char str1[MAX_LENGTH], str2[MAX_LENGTH];
    char substr[MAX_LENGTH];
    char replacement;

    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);
    printf("Enter the sub-string to replace: ");
    scanf("%s", substr);
    printf("Enter the replacement character: ");
    scanf(" %c", &replacement);

    printf("\nString 1: %s\n", str1);
    printf("String 2: %s\n", str2);

    reverse(str1);
    printf("Reversed string 1: %s\n", str1);

    concat(str1, str2);

    printf("String 1: %s\n", str1);

    strcpy(str2, "Hello, World!");
    print_array(str2);

    replace_sub_string(str1, "World", '!');
    printf("String 1 after replacing 'World' with '!': %s\n", str1);

    return 0;
}