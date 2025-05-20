#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void send_email(char *email) {
    char buffer[50];
    sscanf(email, "%49s", buffer);
    printf("Sending email to: %s\n", buffer);
}

int main() {
    char email[100];
    printf("Enter your email address: ");
    fgets(email, sizeof(email), stdin);
    send_email(email);
    return 0;
}
