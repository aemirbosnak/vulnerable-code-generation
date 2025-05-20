#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void process_email(char *email) {
    char user[256], domain[256];
    int len_user, len_domain;

    len_user = sscanf(email, "%s@%s", user, domain);
    len_domain = strlen(domain);

    if (len_user > 255 || len_domain > 255) {
        printf("Error: Email address too long\n");
    } else {
        printf("User: %s\n", user);
        printf("Domain: %s\n", domain);
    }
}

int main() {
    char email[1024];

    printf("Enter an email address: ");
    fgets(email, sizeof(email), stdin);

    process_email(email);

    return 0;
}
