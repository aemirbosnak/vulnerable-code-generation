#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void process_message(char *user_input) {
    char message[20];
    int num;

    printf("Enter the number of characters for your chat message: ");
    sscanf(user_input, "%d", &num);

    if (num > 0 && num <= 20) {
        printf("Your chat message: ");
        strncpy(message, user_input + strlen(user_input) - num, num);
        message[num] = '\0';
        printf("%s\n", message);
    } else {
        printf("Invalid input.\n");
    }
}

int main() {
    char input[100];

    printf("Welcome to the Secure Chat App!\n");
    printf("Please enter your username: ");
    fgets(input, sizeof(input), stdin);
    printf("Enter the length of your chat message: ");
    fgets(input, sizeof(input), stdin);

    process_message(input);

    return 0;
}
