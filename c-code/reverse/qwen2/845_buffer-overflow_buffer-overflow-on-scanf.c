#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#define MAX_EMAIL_LENGTH 256

int main() {
    char recipient[MAX_EMAIL_LENGTH];
    char subject[MAX_EMAIL_LENGTH];
    char body[MAX_EMAIL_LENGTH];

    printf("Enter recipient's email: ");
    scanf("%s", recipient);

    printf("Enter subject: ");
    scanf("%s", subject);

    printf("Enter email body: ");
    scanf("%[^\n]", body); // Vulnerable to buffer overflow

    printf("\nEmail Summary:\n");
    printf("To: %s\n", recipient);
    printf("Subject: %s\n", subject);
    printf("Body: %s\n", body);

    return 0;
}
