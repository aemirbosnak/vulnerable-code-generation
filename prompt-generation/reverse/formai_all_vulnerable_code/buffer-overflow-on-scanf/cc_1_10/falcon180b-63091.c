//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

// Function to generate a random string of given length
char *generate_string(int length) {
    char *string = (char *)malloc(length + 1);
    if (string == NULL) {
        printf("Error: Unable to allocate memory.\n");
        exit(1);
    }
    int i;
    for (i = 0; i < length; i++) {
        string[i] = rand() % 26 + 'a';
    }
    string[length] = '\0';
    return string;
}

// Function to check if a string is a palindrome
int is_palindrome(char *string) {
    int length = strlen(string);
    int i;
    for (i = 0; i < length / 2; i++) {
        if (tolower(string[i])!= tolower(string[length - i - 1])) {
            return FALSE;
        }
    }
    return TRUE;
}

// Function to test user's typing speed
void speed_test(char *string) {
    clock_t start, end;
    double cpu_time_used;
    int i;
    printf("Type the following string as fast as you can:\n%s\n", string);
    start = clock();
    for (i = 0; i < strlen(string); i++) {
        char c = string[i];
        char input;
        do {
            input = tolower(getchar());
        } while (input!= c);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Your typing speed is %.2f characters per second.\n", strlen(string) / cpu_time_used);
}

int main() {
    int length;
    char *string;
    int choice;
    do {
        printf("Enter the length of the string to be generated (between 1 and 100):\n");
        scanf("%d", &length);
        if (length < 1 || length > 100) {
            printf("Invalid input. Please enter a number between 1 and 100.\n");
        }
    } while (length < 1 || length > 100);
    string = generate_string(length);
    printf("The generated string is:\n%s\n", string);
    printf("Do you want to test your typing speed? (y/n):\n");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        speed_test(string);
    }
    free(string);
    return 0;
}