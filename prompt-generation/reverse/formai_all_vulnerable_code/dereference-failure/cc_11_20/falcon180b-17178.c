//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME 100
#define MAX_EMAIL 100

typedef struct {
    char name[MAX_NAME];
    char email[MAX_EMAIL];
} Contact;

int main(int argc, char *argv[]) {
    FILE *file;
    Contact contacts[100];
    int count = 0;
    char ch;

    // Open file
    file = fopen("contacts.txt", "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    // Read contacts from file
    while ((ch = fgetc(file))!= EOF) {
        if (ch == '\n') {
            strcpy(contacts[count].email, "");
            count++;
            continue;
        }
        if (count >= 100) {
            printf("Error: Too many contacts.\n");
            exit(1);
        }
        if (isalpha(ch)) {
            strcat(contacts[count].name, tolower(ch));
        } else if (isdigit(ch) || ch == '.' || ch == '_' || ch == '-' || ch == '+') {
            strcat(contacts[count].email, tolower(ch));
        } else {
            printf("Error: Invalid character.\n");
            exit(1);
        }
    }

    // Close file
    fclose(file);

    // Print contacts
    printf("Name\tEmail\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%s\n", contacts[i].name, contacts[i].email);
    }

    return 0;
}