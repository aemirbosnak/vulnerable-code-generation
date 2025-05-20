//FormAI DATASET v1.0 Category: Email Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAILS 100
#define MAX_LENGTH 200

typedef struct {
    char* to;
    char* from;
    char* subject;
    char* message;
} Email;

Email emails[MAX_EMAILS];
int numEmails = 0;

void readEmailsFromFile(char* filename);
void printEmail(Email email);
void printAllEmails();
void deleteEmail(int index);
void searchEmails(char* keyword);
void quitProgram();

int main() {
    char filename[MAX_LENGTH];
    char input[MAX_LENGTH];
    int index;
    char keyword[MAX_LENGTH];
    
    // read emails from file
    printf("Enter emails file name: ");
    fgets(filename, MAX_LENGTH, stdin);
    filename[strlen(filename)-1] = '\0';
    readEmailsFromFile(filename);
    printf("\n%d emails loaded.\n\n", numEmails);
    
    // start main loop
    printf("Enter command (h for help): ");
    while (fgets(input, MAX_LENGTH, stdin)) {
        input[strlen(input)-1] = '\0';
        if (strcmp(input, "h") == 0) {
            printf("Commands: \n");
            printf("p index : print email at index\n");
            printf("a : print all emails\n");
            printf("d index : delete email at index\n");
            printf("s keyword : search emails for keyword\n");
            printf("q : quit program\n\n");
        }
        else if (input[0] == 'p') {
            index = atoi(&input[2]);
            if (index < 0 || index >= numEmails) {
                printf("Invalid index. Please enter an index between 0 and %d.\n", numEmails-1);
            }
            else {
                printEmail(emails[index]);
            }
        }
        else if (strcmp(input, "a") == 0) {
            printAllEmails();
        }
        else if (input[0] == 'd') {
            index = atoi(&input[2]);
            if (index < 0 || index >= numEmails) {
                printf("Invalid index. Please enter an index between 0 and %d.\n", numEmails-1);
            }
            else {
                deleteEmail(index);
            }
        }
        else if (input[0] == 's') {
            strncpy(keyword, &input[2], MAX_LENGTH);
            searchEmails(keyword);
        }
        else if (strcmp(input, "q") == 0) {
            quitProgram();
        }
        else {
            printf("Invalid command. Enter h for help.\n");
        }
        printf("\nEnter command: ");
    }
    return 0;
}

void readEmailsFromFile(char* filename) {
    FILE* fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    char* line = (char*) malloc(MAX_LENGTH * sizeof(char));
    char* field;
    while (fgets(line, MAX_LENGTH, fp)) {
        Email email;
        field = strtok(line, ",");
        email.to = (char*) malloc(strlen(field)+1);
        strcpy(email.to, field);
        field = strtok(NULL, ",");
        email.from = (char*) malloc(strlen(field)+1);
        strcpy(email.from, field);
        field = strtok(NULL, ",");
        email.subject = (char*) malloc(strlen(field)+1);
        strcpy(email.subject, field);
        field = strtok(NULL, "\n");
        email.message = (char*) malloc(strlen(field)+1);
        strcpy(email.message, field);
        emails[numEmails++] = email;
    }
    free(line);
    fclose(fp);
}

void printEmail(Email email) {
    printf("To: %s\n", email.to);
    printf("From: %s\n", email.from);
    printf("Subject: %s\n", email.subject);
    printf("Message:\n%s\n", email.message);
}

void printAllEmails() {
    if (numEmails == 0) {
        printf("There are no emails to print.\n");
    }
    else {
        for (int i = 0; i < numEmails; i++) {
            printf("========== Email %d ==========\n\n", i);
            printEmail(emails[i]);
            printf("\n");
        }
    }
}

void deleteEmail(int index) {
    printf("Are you sure you want to delete this email? (y/n) \n");
    printEmail(emails[index]);
    char input[MAX_LENGTH];
    fgets(input, MAX_LENGTH, stdin);
    input[strlen(input)-1] = '\0';
    if (tolower(input[0]) == 'y') {
        free(emails[index].to);
        free(emails[index].from);
        free(emails[index].subject);
        free(emails[index].message);
        for (int i = index; i < numEmails-1; i++) {
            emails[i] = emails[i+1];
        }
        numEmails--;
        printf("Email deleted.\n");
    }
    else {
        printf("Email not deleted.\n");
    }
}

void searchEmails(char* keyword) {
    int found = 0;
    for (int i = 0; i < numEmails; i++) {
        if (strstr(emails[i].to, keyword) != NULL || strstr(emails[i].from, keyword) != NULL || strstr(emails[i].subject, keyword) != NULL || strstr(emails[i].message, keyword) != NULL) {
            printf("========== Email %d ==========\n\n", i);
            printEmail(emails[i]);
            printf("\n");
            found = 1;
        }
    }
    if (!found) {
        printf("No emails found matching keyword %s.\n", keyword);
    }
}

void quitProgram() {
    for (int i = 0; i < numEmails; i++) {
        free(emails[i].to);
        free(emails[i].from);
        free(emails[i].subject);
        free(emails[i].message);
    }
    printf("Goodbye!\n");
    exit(0);
}