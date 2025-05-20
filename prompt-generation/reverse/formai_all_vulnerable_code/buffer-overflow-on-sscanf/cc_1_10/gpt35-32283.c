//FormAI DATASET v1.0 Category: Firewall ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

// define the maximum input length and IP address length
#define MAX_INPUT 1024
#define IP_LEN 15

// function to check if the IP address is valid
int isValidIP(char *ipAddress) {
    int num, dots = 0;
    char *ptr;
    if (ipAddress == NULL)
        return 0;

    // split the IP address into tokens and check each token
    ptr = strtok(ipAddress, ".");
    if (ptr == NULL)
        return 0;

    while (ptr) {
        // check if the token can be converted to an integer between 0 and 255
        if (!sscanf(ptr, "%d", &num) || num < 0 || num > 255)
            return 0;

        // count number of dots and check if there are four of them
        dots++;
        if (dots > 4)
            return 0;

        ptr = strtok(NULL, ".");
    }

    // return 1 if the IP address is valid, else return 0
    return dots == 4;
}

int main() {
    char input[MAX_INPUT];
    char IP[IP_LEN+1];
    int port;

    printf("Enter a rule in the format <IP address>:<port>\n");
    printf("Example: 192.168.1.1:80\n");
    printf("Enter \"exit\" to quit.\n\n");

    // loop to read input till user enters exit
    while (1) {
        printf("> ");
        fgets(input, MAX_INPUT, stdin);

        // check if user entered exit
        if (strncmp(input, "exit", 4) == 0)
            break;

        // split the input into IP address and port number
        if (sscanf(input, "%15[^:]:%d", IP, &port) != 2) {
            printf("Invalid input!\n");
            continue;
        }

        // validate the IP address
        if (!isValidIP(IP)) {
            printf("Invalid IP address!\n");
            continue;
        }

        // add the rule (firewall implementation goes here)
        printf("Rule added: %s:%d\n", IP, port);
    }

    printf("Exiting...\n");
    return 0;
}