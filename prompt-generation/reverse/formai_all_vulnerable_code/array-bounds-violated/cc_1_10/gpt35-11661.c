//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define MAX_LEN 100 // Maximum length of the string

int main() {
    // Intialize variables
    char str1[MAX_LEN], str2[MAX_LEN];
    int i, j, len, count = 0;
    clock_t start, end;
    float time_taken;
    
    printf("\n\nWELCOME TO THE C TYPING SPEED TEST\n\n");

    // Prompt the user to enter the first string
    printf("Enter the string: ");
    fgets(str1, MAX_LEN, stdin); //fgets() is used to take input until newline
    
    // Remove the newline character from the string
    len = strlen(str1);
    if(str1[len-1] == '\n') {
        str1[len-1] = '\0';
    }
    
    // Display the string to the user
    printf("\n\nYour string is:\n");
    printf("%s\n", str1);
    
    // Prompt the user to start the test
    printf("\n\nPress ENTER to start:\n");
    getchar();

    // Get the start time
    start = clock();

    // Prompt the user to enter the second string
    printf("\n\nType the following string:\n");
    printf("%s\n", str1);
    fgets(str2, MAX_LEN, stdin);
    
    // Remove the newline character from the string
    len = strlen(str2);
    if(str2[len-1] == '\n') {
        str2[len-1] = '\0';
    }
    
    // Get the end time
    end = clock();

    // Calculate the time taken
    time_taken = ((float)end - start) / CLOCKS_PER_SEC;

    // Calculate the typing speed
    len = strlen(str1);
    for(i = 0; i < len; i++) {
        if(str1[i] == str2[i]) {
            count++;
        }
    }
    printf("\n\nYour typing speed is: %.2f words per minute\n", (count/time_taken)*60);
    
    return EXIT_SUCCESS;
}