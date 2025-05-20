//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_LINE_LENGTH 500

typedef struct {
    char name[MAX_WORD_LENGTH];
    char address[MAX_LINE_LENGTH];
    char phone[MAX_WORD_LENGTH];
    char email[MAX_LINE_LENGTH];
} Contact;

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    Contact contact;

    fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        memset(&contact, 0, sizeof(contact));

        char *token = strtok(line, " ");
        strncpy(contact.name, token, MAX_WORD_LENGTH - 1);

        token = strtok(NULL, " ");
        strncpy(contact.address, token, MAX_LINE_LENGTH - 1);

        token = strtok(NULL, " ");
        strncpy(contact.phone, token, MAX_WORD_LENGTH - 1);

        token = strtok(NULL, " ");
        strncpy(contact.email, token, MAX_LINE_LENGTH - 1);

        printf("Name: %s\n", contact.name);
        printf("Address: %s\n", contact.address);
        printf("Phone: %s\n", contact.phone);
        printf("Email: %s\n", contact.email);
        printf("\n");
    }

    fclose(fp);
    return 0;
}