//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: realistic
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

void print_string_in_reverse(char *str) {
    int len = strlen(str);
    reverse(str, 0, len - 1);
    printf("%s\n", str);
}

int main() {
    char input[MAX_LEN];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    print_string_in_reverse(input);

    int pos;
    char find[3] = "is";
    if ((pos = strstr(input, find)) != NULL) {
        int len_find = strlen(find);
        int i;
        for (i = 0; i < len_find; i++) {
            input[pos + i] = toupper(input[pos + i]);
        }
        printf("String found: %s\n", input);
    } else {
        printf("String not found.\n");
    }

    int count = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == 'a') {
            count++;
        }
    }

    printf("Number of occurrences of character 'a': %d\n", count);

    char output[MAX_LEN];
    int j = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] != 'a') {
            output[j++] = input[i];
        }
    }
    output[j] = '\0';
    printf("String after removing all occurrences of character 'a': %s\n", output);

    return 0;
}