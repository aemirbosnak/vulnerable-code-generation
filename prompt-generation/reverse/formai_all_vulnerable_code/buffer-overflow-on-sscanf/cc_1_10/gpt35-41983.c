//FormAI DATASET v1.0 Category: Log analysis ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compute the sum of digits in a number recursively
int sum_of_digits(int n) {
    // base case: if n is a single digit number, return it
    if (n / 10 == 0) {
        return n;
    }

    // recursive case: compute the sum of digits in the quotient of n and 10,
    // and add it to the remainder of n divided by 10
    return sum_of_digits(n / 10) + n % 10;
}

int main() {
    // log example strings
    char *logs[] = {"[INFO] User logged in.", 
                   "[ERROR] Incorrect username or password.", 
                   "[INFO] Connection established.", 
                   "[DEBUG] Data received from server.", 
                   "[WARNING] Disk space low.", 
                   "[INFO] Request sent to server."};

    // log analysis
    printf("LOG ANALYSIS REPORT:\n");
    for (int i = 0; i < sizeof(logs)/sizeof(logs[0]); i++) {
        // extract log level from log string
        char level[10];
        sscanf(logs[i], "[%[^]]]", level);
        
        // check if log level is INFO
        if (strcmp(level, "INFO") == 0) {
            printf("%s\n", logs[i]);
        }
        // check if log level is WARNING
        else if (strcmp(level, "WARNING") == 0) {
            printf("%s\n", logs[i]);
        }
        // check if log level is DEBUG
        else if (strcmp(level, "DEBUG") == 0) {
            printf("%s\n", logs[i]);
        }
        // check if log level is ERROR
        else if (strcmp(level, "ERROR") == 0) {
            printf("%s\n", logs[i]);
        }
    }

    // computing sum of digits example
    int num = 12345;
    int sum = sum_of_digits(num);
    printf("Sum of digits in %d is %d\n", num, sum);

    return 0;
}