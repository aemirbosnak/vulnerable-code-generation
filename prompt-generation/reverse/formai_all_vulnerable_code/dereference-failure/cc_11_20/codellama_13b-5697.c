//Code Llama-13B DATASET v1.0 Category: Natural Language Date Converter ; Style: realistic
/*
 * C Natural Language Date Converter
 *
 * This program converts a date from a natural language format to a
 * machine-readable format.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_LENGTH 100
#define MAX_OUTPUT_LENGTH 100

int main() {
    char input[MAX_INPUT_LENGTH];
    char output[MAX_OUTPUT_LENGTH];
    char *token;
    int day, month, year;

    printf("Enter a date in natural language: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    token = strtok(input, " ");
    if (strcmp(token, "today") == 0) {
        time_t now = time(NULL);
        struct tm *current_time = localtime(&now);
        day = current_time->tm_mday;
        month = current_time->tm_mon + 1;
        year = current_time->tm_year + 1900;
    } else {
        token = strtok(NULL, " ");
        if (strcmp(token, "tomorrow") == 0) {
            day = day + 1;
        } else if (strcmp(token, "yesterday") == 0) {
            day = day - 1;
        } else {
            day = atoi(token);
        }

        token = strtok(NULL, " ");
        if (strcmp(token, "january") == 0) {
            month = 1;
        } else if (strcmp(token, "february") == 0) {
            month = 2;
        } else if (strcmp(token, "march") == 0) {
            month = 3;
        } else if (strcmp(token, "april") == 0) {
            month = 4;
        } else if (strcmp(token, "may") == 0) {
            month = 5;
        } else if (strcmp(token, "june") == 0) {
            month = 6;
        } else if (strcmp(token, "july") == 0) {
            month = 7;
        } else if (strcmp(token, "august") == 0) {
            month = 8;
        } else if (strcmp(token, "september") == 0) {
            month = 9;
        } else if (strcmp(token, "october") == 0) {
            month = 10;
        } else if (strcmp(token, "november") == 0) {
            month = 11;
        } else if (strcmp(token, "december") == 0) {
            month = 12;
        } else {
            month = atoi(token);
        }

        token = strtok(NULL, " ");
        year = atoi(token);
    }

    sprintf(output, "%02d/%02d/%04d", day, month, year);
    printf("Machine-readable date: %s\n", output);

    return 0;
}