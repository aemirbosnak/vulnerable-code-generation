#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#define MAX_BODY_SIZE 50

int main() {
    char recipient[20];
    char subject[30];
    char body[MAX_BODY_SIZE];

    printf("Email Client\n");
    printf("Enter recipient: ");
    scanf("%s", recipient);
    printf("Enter subject: ");
    scanf("%s", subject);
    printf("Enter body (max %d characters): ", MAX_BODY_SIZE - 1);
    scanf("%s", body);

    printf("\nSending Email:\n");
    printf("To: %s\n", recipient);
    printf("Subject: %s\n", subject);
    printf("Body: %s\n", body);

    return 0;
}
