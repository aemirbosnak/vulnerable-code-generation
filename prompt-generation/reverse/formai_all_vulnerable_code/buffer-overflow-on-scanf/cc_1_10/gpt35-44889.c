//FormAI DATASET v1.0 Category: Browser Plugin ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define TAB_WIDTH 4

/* Converts a string to all uppercase */
char *string_to_upper(char *str) {
    int len = strlen(str);
    char *result = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        result[i] = toupper(str[i]);
    }
    result[len] = '\0';
    return result;
}

/* Converts a string to all lowercase */
char *string_to_lower(char *str) {
    int len = strlen(str);
    char *result = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        result[i] = tolower(str[i]);
    }
    result[len] = '\0';
    return result;
}

/* Replaces all occurrences of substring with another string */
char *string_replace(char *str, char *sub, char *replace) {
    char *result;
    int i, count = 0;
    int sub_len = strlen(sub);
    int replace_len = strlen(replace);
    for (i = 0; str[i] != '\0'; i++) {
        if (strstr(&str[i], sub) == &str[i]) {
            count++;
            i += sub_len - 1;
        }
    }
    result = malloc(i + count * (replace_len - sub_len) + 1);
    i = 0;
    while (*str) {
        if (strstr(str, sub) == str) {
            strcpy(&result[i], replace);
            i += replace_len;
            str += sub_len;
        }
        else
            result[i++] = *str++;
    }
    result[i] = '\0';
    return result;
}

/* Converts tabs to spaces based on tab width */
char *convert_tabs_to_spaces(char *str) {
    int len = strlen(str);
    char *result = malloc(len * TAB_WIDTH + 1);
    int i = 0, j = 0;
    while (str[i] != '\0') {
        if (str[i] == '\t') {
            int spaces_to_add = TAB_WIDTH - (j % TAB_WIDTH);
            for (int k = 0; k < spaces_to_add; k++) {
                result[j++] = ' ';
            }
        }
        else {
            result[j++] = str[i];
        }
        i++;
    }
    result[j] = '\0';
    return result;
}

/* Calculates the sum of all numbers in a string */
int calculate_sum_of_numbers(char *str) {
    int sum = 0, num = 0;
    int sign = 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i])) {
            num = num * 10 + (str[i] - '0');
        }
        else if (str[i] == '-') {
            sign = -1;
        }
        else {
            sum += num * sign;
            num = 0;
            sign = 1;
        }
    }
    sum += num * sign;
    return sum;
}

int main() {
    char input[100], *output;
    int choice;
    printf("Enter a string:\n");
    fgets(input, 100, stdin);
    printf("1. Convert to Uppercase\n");
    printf("2. Convert to Lowercase\n");
    printf("3. Replace Substring\n");
    printf("4. Convert Tabs to Spaces\n");
    printf("5. Calculate Sum of Numbers\n");
    printf("Choose an option:\n");
    scanf("%d", &choice);
    fflush(stdin);
    switch (choice) {
        case 1:
            output = string_to_upper(input);
            break;
        case 2:
            output = string_to_lower(input);
            break;
        case 3: {
            char sub[100], replace[100];
            printf("Enter substring to replace:\n");
            fgets(sub, 100, stdin);
            printf("Enter replacement string:\n");
            fgets(replace, 100, stdin);
            output = string_replace(input, sub, replace);
            break;
        }
        case 4:
            output = convert_tabs_to_spaces(input);
            break;
        case 5: {
            int sum = calculate_sum_of_numbers(input);
            printf("Sum of all numbers: %d\n", sum);
            return 0;
        }
        default:
            printf("Invalid choice, exiting.");
            return 0;
    }
    printf("Output:\n%s", output);
    free(output);
    return 0;
}