#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void main(int argc, char **argv) {
    char input[10];
    char secret[100];
    char flag[256];

    printf("Welcome to Secret Vault v1.0\n");
    printf("Enter the code to open the vault:\n");

    gets(input);
    strcpy(secret, "A0B1C2D3E4F5");

    if (strcmp(input, secret) == 0) {
        printf("Congratulations! You have successfully opened the vault!\n");
        printf("Here is the flag: SECURITY{This_is_an_easy_flag}\n");
    } else {
        printf("Access denied. Wrong combination.\n");
    }

    printf("Vault is closing in 5 seconds...\n");
    sleep(5);
    printf("Vault is now closed.\n");
}
