//Gemma-7B DATASET v1.0 Category: Password management ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_PASSWORDS 10

typedef struct Password {
    char *name;
    char *password;
    struct Password *next;
} Password;

int main() {
    Password *head = NULL;
    int i = 0;

    // Create a directory for storing passwords
    mkdir("passwords", 0700);

    // Allocate memory for each password
    for (i = 0; i < MAX_PASSWORDS; i++) {
        head = (Password *)malloc(sizeof(Password));
        head->name = (char *)malloc(20);
        head->password = (char *)malloc(20);
        head->next = NULL;

        // Get the password from the user
        printf("Enter a password: ");
        scanf("%s", head->password);

        // Store the password in the directory
        FILE *fp = fopen(head->name, "w");
        fprintf(fp, "%s", head->password);
        fclose(fp);

        // Add the password to the linked list
        if (head->next == NULL) {
            head->next = head;
        } else {
            head->next = head;
        }
    }

    // Print the stored passwords
    head = head->next;
    while (head) {
        printf("Name: %s, Password: %s\n", head->name, head->password);
        head = head->next;
    }

    return 0;
}