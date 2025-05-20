#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 512

void send_email(const char *recipient) {
    char buffer[BUFFER_SIZE];
    snprintf(buffer, sizeof(buffer), "RCPT TO:<%s>\r\n", recipient);
    printf("%s", buffer);
}

int main() {
    char recipient[BUFFER_SIZE];
    printf("Enter recipient email: ");
    scanf("%s", recipient);
    send_email(recipient);
    return 0;
}
