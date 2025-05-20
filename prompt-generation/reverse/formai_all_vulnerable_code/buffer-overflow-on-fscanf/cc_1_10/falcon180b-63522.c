//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Contact;

int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[100], outputFileName[100];
    int numContacts = 0;
    Contact contacts[100];

    printf("Enter the name of the input file: ");
    scanf("%s", inputFileName);
    printf("Enter the name of the output file: ");
    scanf("%s", outputFileName);

    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(inputFile);
        exit(1);
    }

    while (fscanf(inputFile, "%s %s", contacts[numContacts].name, contacts[numContacts].email)!= EOF) {
        numContacts++;
    }

    fclose(inputFile);

    printf("Number of contacts: %d\n", numContacts);

    for (int i = 0; i < numContacts; i++) {
        if (strlen(contacts[i].name) > MAX_NAME_LEN) {
            contacts[i].name[MAX_NAME_LEN - 1] = '\0';
        }
        if (strlen(contacts[i].email) > MAX_EMAIL_LEN) {
            contacts[i].email[MAX_EMAIL_LEN - 1] = '\0';
        }
        fprintf(outputFile, "%s %s\n", contacts[i].name, contacts[i].email);
    }

    fclose(outputFile);

    printf("Mailing list created successfully!\n");

    return 0;
}