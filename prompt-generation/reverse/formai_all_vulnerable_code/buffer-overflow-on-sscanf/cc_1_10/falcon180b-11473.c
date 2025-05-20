//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50

// Function to check if a string is a valid date
int is_valid_date(const char* date_str) {
    int year, month, day;
    if (sscanf(date_str, "%d-%d-%d", &year, &month, &day)!= 3)
        return 0;
    if (year < 1000 || year > 9999 || month < 1 || month > 12 || day < 1 || day > 31)
        return 0;
    return 1;
}

// Function to convert a string to lowercase
void str_to_lower(char* str) {
    int i;
    for (i = 0; str[i]!= '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to convert a string to uppercase
void str_to_upper(char* str) {
    int i;
    for (i = 0; str[i]!= '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

// Function to reverse a string
void reverse_string(char* str) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to remove leading/trailing whitespace from a string
void trim_string(char* str) {
    int i, j;
    for (i = 0; i < strlen(str); i++) {
        if (!isspace(str[i])) {
            break;
        }
    }
    for (j = strlen(str) - 1; j >= 0; j--) {
        if (!isspace(str[j])) {
            break;
        }
    }
    strncpy(str, str + i, strlen(str) - j - i);
    str[strlen(str) - j - i] = '\0';
}

int main() {
    char input_date[MAX_WORD_LENGTH];
    char output_date[MAX_WORD_LENGTH];
    char* token;
    int i, j;

    // Prompt the user for a date
    printf("Enter a date in MM/DD/YYYY format: ");
    fgets(input_date, MAX_WORD_LENGTH, stdin);
    trim_string(input_date);

    // Convert the date to lowercase
    str_to_lower(input_date);

    // Check if the date is valid
    if (!is_valid_date(input_date)) {
        printf("Invalid date format.\n");
        return 1;
    }

    // Convert the date to uppercase
    str_to_upper(input_date);

    // Reverse the date
    reverse_string(input_date);

    // Extract the day, month, and year
    token = strtok(input_date, "-");
    if (token == NULL) {
        printf("Invalid date format.\n");
        return 1;
    }
    strcpy(output_date, token);
    for (i = 0; i < strlen(output_date); i++) {
        if (output_date[i] == '/') {
            output_date[i] = '-';
        }
    }
    token = strtok(NULL, "-");
    if (token == NULL) {
        printf("Invalid date format.\n");
        return 1;
    }
    strcat(output_date, "-");
    strcat(output_date, token);

    // Output the natural language date
    printf("The natural language date is %s.\n", output_date);

    return 0;
}