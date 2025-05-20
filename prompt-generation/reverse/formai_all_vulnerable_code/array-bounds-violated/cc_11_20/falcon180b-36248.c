//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 1000

int main() {
    char input[MAX_LENGTH];
    char *output;
    int i, j, k, n, m;
    int count = 0;
    int flag = 0;
    char delimiter;
    time_t t;
    struct tm *timeinfo;
    char *date;

    // prompt user for input string
    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);

    // remove newline character from input string
    n = strlen(input) - 1;
    if (input[n] == '\n') {
        input[n] = '\0';
    }

    // prompt user for delimiter
    printf("Enter delimiter: ");
    scanf("%c", &delimiter);

    // prompt user for operation
    printf("Enter operation (c = count, r = reverse, u = uppercase, l = lowercase, t = time): ");
    scanf("%c", &m);

    // perform operation
    switch (m) {
        case 'c':
            // count occurrences of delimiter
            for (i = 0; input[i]!= '\0'; i++) {
                if (input[i] == delimiter) {
                    count++;
                }
            }
            printf("Number of occurrences of '%c': %d\n", delimiter, count);
            break;
        case 'r':
            // reverse string
            for (i = strlen(input) - 1, j = 0; i >= 0; i--, j++) {
                input[j] = input[i];
            }
            input[j] = '\0';
            printf("Reversed string: %s\n", input);
            break;
        case 'u':
            // convert string to uppercase
            for (i = 0; input[i]!= '\0'; i++) {
                input[i] = toupper(input[i]);
            }
            printf("Uppercase string: %s\n", input);
            break;
        case 'l':
            // convert string to lowercase
            for (i = 0; input[i]!= '\0'; i++) {
                input[i] = tolower(input[i]);
            }
            printf("Lowercase string: %s\n", input);
            break;
        case 't':
            // get current time
            t = time(NULL);
            timeinfo = localtime(&t);
            date = asctime(timeinfo);
            printf("Current date and time: %s\n", date);
            break;
        default:
            printf("Invalid operation.\n");
            break;
    }

    return 0;
}