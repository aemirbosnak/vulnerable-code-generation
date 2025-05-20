//FormAI DATASET v1.0 Category: String manipulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char gratitude[] = "Thank you for everything!";
    char name[20];
    char buff[100];

    printf("Hello! What's your name?\n");
    scanf("%s", name);
    printf("Nice to meet you %s!\n", name);
    
    // Count the characters in the gratitude string
    int length = strlen(gratitude);

    // Reverse the gratitude string
    char reversed_gratitude[length+1];
    int i;
    for (i = 0; i < length; i++) 
        reversed_gratitude[length-i-1] = gratitude[i];
    reversed_gratitude[length] = '\0';

    printf("%s, I just want to tell you: ", name);
    printf("%s\n", gratitude);
    printf("You deserve the world and more!\n");

    // Use tokens to split the gratitude string into words
    char *token = strtok(gratitude, " ");
    while(token != NULL) {
        printf("%s ", token);
        token = strtok(NULL, " ");
    }

    printf("\n");

    // Use strncat to add the user's name to the gratitude string
    strncat(gratitude, name, 20);

    printf("%s, you make my day brighter every time we chat!\n", name);
    
    // Use sprintf to format a message with the length of the gratitude string
    sprintf(buff, "Did you know that the gratitude message I wrote for you has %d letters?", length);
    printf("%s\n", buff);

    // Convert the gratitude string to uppercase
    for (i = 0; gratitude[i] != '\0'; i++) {
        if (gratitude[i] >= 'a' && gratitude[i] <= 'z') 
            gratitude[i] = gratitude[i] - 32;
    }
    printf("%s\n", gratitude);

    return 0;
}