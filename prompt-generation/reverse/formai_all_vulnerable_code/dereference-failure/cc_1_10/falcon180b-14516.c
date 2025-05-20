//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 100
#define MAX_PHONE_LENGTH 20
#define MAX_EMAIL_LENGTH 100
#define MAX_ADDRESS_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
} Contact;

Contact* parseResume(char* resumeText) {
    Contact* contact = (Contact*)malloc(sizeof(Contact));
    char* nameStart = NULL;
    char* phoneStart = NULL;
    char* emailStart = NULL;
    char* addressStart = NULL;

    char* currentLine = strtok(resumeText, "\n");
    while (currentLine!= NULL) {
        if (strstr(currentLine, "Name:")!= NULL) {
            nameStart = strstr(currentLine, ":") + 1;
            strncpy(contact->name, nameStart, MAX_NAME_LENGTH);
        } else if (strstr(currentLine, "Phone:")!= NULL) {
            phoneStart = strstr(currentLine, ":") + 1;
            strncpy(contact->phone, phoneStart, MAX_PHONE_LENGTH);
        } else if (strstr(currentLine, "Email:")!= NULL) {
            emailStart = strstr(currentLine, ":") + 1;
            strncpy(contact->email, emailStart, MAX_EMAIL_LENGTH);
        } else if (strstr(currentLine, "Address:")!= NULL) {
            addressStart = strstr(currentLine, ":") + 1;
            strncpy(contact->address, addressStart, MAX_ADDRESS_LENGTH);
        }
        currentLine = strtok(NULL, "\n");
    }

    return contact;
}

void printContact(Contact* contact) {
    printf("Name: %s\n", contact->name);
    printf("Phone: %s\n", contact->phone);
    printf("Email: %s\n", contact->email);
    printf("Address: %s\n", contact->address);
}

int main() {
    char* resumeText = "Name: John Doe\nPhone: 555-1234\nEmail: john.doe@example.com\nAddress: 123 Main St.\n";
    Contact* contact = parseResume(resumeText);
    printContact(contact);

    free(contact);
    return 0;
}