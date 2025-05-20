//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

/* Function to convert a date from yyyy-mm-dd format to human-readable format */
char* convert_date(char* date_str) {
    struct tm date;
    strptime(date_str, "%Y-%m-%d", &date);
    setlocale(LC_TIME, "");
    char* formatted_date = asctime(&date);
    return formatted_date;
}

/* Function to convert a date from human-readable format to yyyy-mm-dd format */
char* convert_date_back(char* date_str) {
    struct tm date;
    strptime(date_str, "%a %b %d %H:%M:%S %Y", &date);
    char* formatted_date = asctime(&date);
    return formatted_date;
}

int main() {
    char* date_str;
    char* formatted_date;
    char* formatted_date_back;
    char* input_buffer;
    int input_size;
    int i;

    /* Initialize the input buffer */
    input_buffer = malloc(100);
    if (input_buffer == NULL) {
        printf("Error: Could not allocate memory for input buffer.\n");
        exit(1);
    }

    /* Loop until the user enters a valid date */
    while (1) {
        /* Prompt the user for a date */
        printf("Enter a date in yyyy-mm-dd format: ");
        scanf("%s", input_buffer);

        /* Convert the input buffer to a string */
        input_size = strlen(input_buffer);
        date_str = malloc(input_size + 1);
        if (date_str == NULL) {
            printf("Error: Could not allocate memory for date string.\n");
            exit(1);
        }
        strcpy(date_str, input_buffer);

        /* Convert the date to human-readable format */
        formatted_date = convert_date(date_str);
        printf("The date is: %s\n", formatted_date);

        /* Convert the date back to yyyy-mm-dd format */
        formatted_date_back = convert_date_back(formatted_date);
        printf("The date in yyyy-mm-dd format is: %s\n", formatted_date_back);

        /* Free the memory used by the input buffer and date strings */
        free(input_buffer);
        free(date_str);
        free(formatted_date_back);

        /* Ask the user if they want to continue */
        printf("Do you want to convert another date? (y/n): ");
        scanf(" %c", &i);
        if (i!= 'y') {
            break;
        }
    }

    /* Free any remaining memory */
    free(input_buffer);
    free(date_str);
    free(formatted_date_back);

    return 0;
}