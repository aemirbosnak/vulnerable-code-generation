//FormAI DATASET v1.0 Category: Browser Plugin ; Style: retro
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_INPUT_LENGTH 100

void retroBrowserPlugin(char* input);

int main() {
    char userInput[MAX_INPUT_LENGTH];

    printf("Welcome to Retro Browser Plugin!\n");
    printf("Please enter a URL:\n");

    fgets(userInput, MAX_INPUT_LENGTH, stdin);

     // remove newline character from input
    userInput[strcspn(userInput, "\n")] = 0;

    retroBrowserPlugin(userInput);

    return 0;
}

void retroBrowserPlugin(char* input) {
    int i, j, flag;
    char protocol[10] = "", domain[50] = "", path[50] = "";

    for (i = 0; input[i] != ':'; i++) {
        protocol[i] = input[i];
    }
    protocol[i] = '\0';

    if (strcmp(protocol, "http") != 0 && strcmp(protocol, "https") != 0) {
        printf("\nError: Invalid protocol.\n");
        return;
    }

    for (j = i + 3, i = 0; input[j] != '/' && input[j] != '\0'; j++, i++) {
        domain[i] = input[j];
    }
    domain[i] = '\0';

    if (strlen(domain) == 0) {
        printf("\nError: No domain found.\n");
        return;
    }

    if (input[j] == '/') {
        strcpy(path, &input[j]);
    }

    printf("\nProtocol: %s\n", protocol);
    printf("Domain: %s\n", domain);
    printf("Path: %s\n", path);

    flag = 0;
    for (i = 0; i < strlen(domain); i++) {
        if (!isdigit(domain[i]) && domain[i] != '.') {
            flag = 1;
            break;
        }
    }

    if (flag) {
        printf("\nSorry, cannot connect to IP addresses.\n");
        return;
    }

    printf("\nConnecting to %s...\n", domain);

    if (strlen(path) > 0) {
        printf("Loading resource at %s\n", path);
    }
}