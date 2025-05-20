//Falcon2-11B DATASET v1.0 Category: Natural Language Date Converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert natural language date to numeric date
void convert_date(char* input, char* output) {
    // Get input and output from the user
    char* input_str = (char*)malloc(sizeof(char) * 255);
    scanf("%s", input_str);

    char* output_str = (char*)malloc(sizeof(char) * 255);
    printf("Enter the output: ");
    scanf("%s", output_str);

    // Check if input string is empty
    if (input_str[0] == '\0') {
        printf("Error: Input string is empty!\n");
        free(input_str);
        return;
    }

    // Split input string into individual words
    char* words[3];
    char* word = strtok(input_str, " ");

    int count = 0;
    while (word!= NULL) {
        words[count] = word;
        count++;
        word = strtok(NULL, " ");
    }

    // Check if number of words is less than or equal to 3
    if (count <= 3) {
        printf("Error: Input string contains less than 3 words!\n");
        free(input_str);
        return;
    }

    // Initialize variables for month, day, and year
    int month = 0;
    int day = 0;
    int year = 0;

    // Convert each word to integer and assign it to respective variable
    for (int i = 0; i < count; i++) {
        month += (int)strtol(words[i], NULL, 10);
    }

    // Check if month is less than or equal to 12
    if (month <= 12) {
        printf("Error: Month is less than or equal to 12!\n");
        free(input_str);
        return;
    }

    // Convert month to string using itoa function
    sprintf(output_str, "%02d", month);

    // Convert day to integer and assign it to variable
    day += (int)strtol(words[count - 1], NULL, 10);

    // Check if day is less than or equal to 31
    if (day <= 31) {
        printf("Error: Day is less than or equal to 31!\n");
        free(input_str);
        return;
    }

    // Convert day to string using itoa function
    sprintf(output_str + strlen(output_str), "%02d", day);

    // Convert year to integer and assign it to variable
    year += (int)strtol(words[count - 2], NULL, 10);

    // Check if year is greater than or equal to 1000
    if (year < 1000) {
        printf("Error: Year is less than or equal to 1000!\n");
        free(input_str);
        return;
    }

    // Convert year to string using itoa function
    sprintf(output_str + strlen(output_str), "%04d", year);

    // Print the numeric date
    printf("Output: %s\n", output_str);

    // Free allocated memory
    free(input_str);
    free(output_str);
}

int main() {
    char input[255];
    char output[255];

    printf("Enter a natural language date: ");
    scanf("%s", input);

    convert_date(input, output);

    return 0;
}