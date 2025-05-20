//FormAI DATASET v1.0 Category: System boot optimizer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int seconds) {
    clock_t start = clock();
    while (clock() - start < seconds * CLOCKS_PER_SEC);
}

void optimize() {
    printf("Starting boot optimization...\n");

    delay(2);

    printf("Disabling unnecessary services...\n");

    delay(3);

    printf("Clearing cache and temporary files...\n");

    delay(5);

    printf("Defragmenting disk...\n");

    delay(10);

    printf("Optimizing registry...\n");

    delay(7);

    printf("Cleaning up startup programs...\n");

    delay(4);

    printf("\nBoot optimization complete.\n");
}

int main() {
    printf("Welcome to the C System boot optimizer.\n");
    printf("Would you like to optimize your system boot? (Y/N)\n");

    char response;
    scanf("%c", &response);

    if (response == 'Y' || response == 'y') {
        optimize();
    } else if (response == 'N' || response == 'n') {
        printf("Thank you for using the C System boot optimizer.\n");
    } else {
        printf("Invalid response. Please try again.\n");
    }

    return 0;
}