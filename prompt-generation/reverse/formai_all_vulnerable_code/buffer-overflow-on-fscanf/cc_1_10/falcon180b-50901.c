//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Message;

int main() {
    // Initialize mailing list
    Message mailingList[10];
    int numMessages = 0;

    // Read in messages from file
    FILE *inputFile = fopen("messages.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    while (fscanf(inputFile, "%s %s %s %s", mailingList[numMessages].name, mailingList[numMessages].email, mailingList[numMessages].subject, mailingList[numMessages].body)!= EOF) {
        numMessages++;
    }
    fclose(inputFile);

    // Sort mailing list by name
    for (int i = 0; i < numMessages - 1; i++) {
        for (int j = i + 1; j < numMessages; j++) {
            if (strcmp(mailingList[i].name, mailingList[j].name) > 0) {
                Message temp = mailingList[i];
                mailingList[i] = mailingList[j];
                mailingList[j] = temp;
            }
        }
    }

    // Print sorted mailing list
    printf("Sorted mailing list:\n");
    for (int i = 0; i < numMessages; i++) {
        printf("Name: %s\nEmail: %s\nSubject: %s\nBody:\n%s\n", mailingList[i].name, mailingList[i].email, mailingList[i].subject, mailingList[i].body);
    }

    return 0;
}