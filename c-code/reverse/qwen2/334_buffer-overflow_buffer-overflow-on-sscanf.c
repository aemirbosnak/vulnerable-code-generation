#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void parse_email(char *email) {
    char username[50], domain[50];
    if (sscanf(email, "%[^@]@%s", username, domain) != 2) {
        printf("Invalid email format\n");
        return;
    }
    // Vulnerability: No bounds checking on username and domain
    strcpy(username, email);
    strcpy(domain, email);
}

int main() {
    char email[100];
    printf("Enter your email address: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';
    parse_email(email);
    return 0;
}
