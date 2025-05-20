//FormAI DATASET v1.0 Category: Error handling ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int input;
    srand(time(NULL)); // seeding random number generator
    int error_code = rand() % 10; // generating a random error code from 0 to 9
    printf("Enter a number: ");
    scanf("%d", &input);
    if (input < 0 || input > 10) { // checking for invalid input
        printf("Input out of range. Terminating program.\n");
        return 1; // exiting program with error code 1
    }
    switch (error_code) {
        case 0:
            printf("ERROR CODE %d: Undefined symbol.\n", error_code);
            break;
        case 1:
            printf("ERROR CODE %d: Out of memory.\n", error_code);
            break;
        case 2:
            printf("ERROR CODE %d: Illegal instruction.\n", error_code);
            break;
        case 3:
            printf("ERROR CODE %d: Bad address.\n", error_code);
            break;
        case 4:
            printf("ERROR CODE %d: Interrupted system call.\n", error_code);
            break;
        case 5:
            printf("ERROR CODE %d: Permission denied.\n", error_code);
            break;
        case 6:
            printf("ERROR CODE %d: Device not configured.\n", error_code);
            break;
        case 7:
            printf("ERROR CODE %d: Argument list too long.\n", error_code);
            break;
        case 8:
            printf("ERROR CODE %d: Exec format error.\n", error_code);
            break;
        case 9:
            printf("ERROR CODE %d: No child processes.\n", error_code);
            break;
        default:
            printf("Unexpected error occurred.\n");
            break;
    }
    printf("Program terminating with error code %d.\n", error_code);
    return error_code; // exiting program with random error code
}