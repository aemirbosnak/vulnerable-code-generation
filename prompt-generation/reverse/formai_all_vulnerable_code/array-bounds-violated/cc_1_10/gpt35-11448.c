//FormAI DATASET v1.0 Category: Firewall ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

int main() {
    char input[MAX_SIZE];
    int index = 0;

    printf("Welcome to the Firewall!\n");
    printf("Enter the IP address you want to block:\n");

    fgets(input, MAX_SIZE, stdin); // Get user input

    // Remove any trailing \n character
    if (input[strlen(input)-1] == '\n') {
        input[strlen(input)-1] = '\0';
    }

    // Check if the IP address is valid
    char *token = strtok(input, ".");
    int count = 0;

    while (token != NULL) {
        int num = atoi(token);

        if (num < 0 || num > 255) {
            printf("Invalid IP address!\n");
            return 1;
        }

        count++;
        token = strtok(NULL, ".");
    }

    if (count != 4) {
        printf("Invalid IP address!\n");
        return 1;
    }

    // Save the IP address to the blacklist
    FILE *fp = fopen("blacklist.txt", "a");

    if (fp == NULL) {
        printf("Error: Unable to open file!\n");
        return 1;
    }

    fprintf(fp, "%s\n", input);
    fclose(fp);

    printf("The IP address %s has been added to the blacklist.\n", input);
    printf("Firewall is now activated.\n");

    // Wait for user input to deactivate firewall
    printf("Press enter to deactivate firewall.");

    while (1) {
        char c = getchar();

        if (c == '\n') {
            printf("Firewall deactivated!\n");
            return 0;
        }
    }

    return 0;
}