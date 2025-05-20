//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 100

int main() {
    int i, j, k;
    char input[MAX_SIZE];
    float num;
    int count = 0;
    int total = 0;
    int max = 0;
    int min = 999999;
    char *ptr;
    struct tm *tm;
    time_t t;

    // Get current time
    t = time(NULL);
    tm = localtime(&t);

    // Print header
    printf("=== RAM Usage Monitor ===\n");
    printf("Current date and time: %s\n", asctime(tm));
    printf("Process ID: %d\n", getpid());
    printf("Command line: %s\n", input);

    // Loop until user enters "exit"
    while (strcmp(input, "exit")!= 0) {
        // Get user input
        printf("Enter a number or 'exit': ");
        fgets(input, MAX_SIZE, stdin);
        num = strtof(input, &ptr);

        // Check for invalid input
        if (ptr == input) {
            printf("Invalid input\n");
            continue;
        }

        // Update RAM usage statistics
        count++;
        total += num;
        if (num > max) {
            max = num;
        }
        if (num < min) {
            min = num;
        }

        // Print current RAM usage
        printf("Current RAM usage: %.2f MB\n", total / (1024 * 1024));
        printf("Average RAM usage: %.2f MB\n", total / count);
        printf("Minimum RAM usage: %.2f MB\n", min);
        printf("Maximum RAM usage: %.2f MB\n", max);
        printf("\n");
    }

    return 0;
}