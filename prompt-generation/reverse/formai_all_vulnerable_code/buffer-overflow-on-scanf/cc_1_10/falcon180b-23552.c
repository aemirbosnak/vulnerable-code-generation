//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAILS 100
#define MAX_NAME 40
#define MAX_SUBJECT 80
#define MAX_MESSAGE 500

struct email {
    char name[MAX_NAME];
    char subject[MAX_SUBJECT];
    char message[MAX_MESSAGE];
};

int main() {
    FILE *file;
    char filename[20];
    int num_emails = 0;
    struct email emails[MAX_EMAILS];

    printf("Enter the name of the mailing list file: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file\n");
        return 1;
    }

    while (fscanf(file, "%s %s %s", emails[num_emails].name, emails[num_emails].subject, emails[num_emails].message)!= EOF) {
        num_emails++;
        if (num_emails == MAX_EMAILS) {
            printf("Error: maximum number of emails reached\n");
            return 1;
        }
    }

    fclose(file);

    printf("Enter the name of the output file: ");
    scanf("%s", filename);

    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: could not create file\n");
        return 1;
    }

    for (int i = 0; i < num_emails; i++) {
        fprintf(file, "Name: %s\nSubject: %s\nMessage:\n%s\n\n", emails[i].name, emails[i].subject, emails[i].message);
    }

    fclose(file);

    printf("Mailing list successfully saved to file\n");

    return 0;
}