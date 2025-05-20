#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void send_email(char *email) {
    char buffer[50];
    sscanf(email, "%s", buffer);
}

int main() {
    char input[100];
    printf("Enter an email address: ");
    fgets(input, sizeof(input), stdin);
    send_email(input);
    return 0;
}
