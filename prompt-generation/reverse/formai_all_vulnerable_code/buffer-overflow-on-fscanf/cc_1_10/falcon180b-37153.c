//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 100

typedef struct {
    char name[MAX_WORD_LEN];
    char email[MAX_WORD_LEN];
    int phone_number;
} Contact;

void parse_name(char* word, char* name) {
    int i = 0;
    while (i < strlen(word) && word[i]!= ',') {
        name[i] = word[i];
        i++;
    }
    name[i] = '\0';
}

void parse_email(char* word, char* email) {
    int i = 0;
    while (i < strlen(word) && word[i]!= ',') {
        email[i] = word[i];
        i++;
    }
    email[i] = '\0';
}

void parse_phone_number(char* word, int* phone_number) {
    int i = 0;
    while (i < strlen(word) && word[i]!= ',') {
        if (word[i] == '-') {
            i++;
        } else if (word[i] >= '0' && word[i] <= '9') {
            *phone_number = *phone_number * 10 + word[i] - '0';
        }
        i++;
    }
}

int main() {
    FILE* file = fopen("resume.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    Contact contact;
    char word[MAX_WORD_LEN];
    int i = 0;
    while (fscanf(file, "%s", word)!= EOF) {
        if (i == 0) {
            parse_name(word, contact.name);
        } else if (i == 1) {
            parse_email(word, contact.email);
        } else if (i == 2) {
            parse_phone_number(word, &contact.phone_number);
        }
        i++;
    }

    printf("Name: %s\n", contact.name);
    printf("Email: %s\n", contact.email);
    printf("Phone number: %d\n", contact.phone_number);

    fclose(file);
    return 0;
}