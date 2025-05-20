#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_RECIPIENT 100
#define MAX_SUBJECT 256
#define MAX_BODY 1024

int main() {
    char recipient[MAX_RECIPIENT];
    char subject[MAX_SUBJECT];
    char body[MAX_BODY];

    printf("Enter recipient's email: ");
    scanf("%s", recipient);

    printf("Enter subject: ");
    scanf("%s", subject);

    printf("Enter body (max %d characters): ", MAX_BODY - 1);
    getchar(); // Consume newline left-over
    fgets(body, sizeof(body), stdin);

    printf("\nEmail Composed:\n");
    printf("To: %s\n", recipient);
    printf("Subject: %s\n", subject);
    printf("Body: %s", body);

    return 0;
}
