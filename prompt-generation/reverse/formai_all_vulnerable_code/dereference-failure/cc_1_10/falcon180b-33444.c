//Falcon-180B DATASET v1.0 Category: Email Client ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_EMAILS 100
#define SUBJECT_LENGTH 100
#define BODY_LENGTH 1000
#define FROM_LENGTH 100
#define TO_LENGTH 100
#define CC_LENGTH 100
#define DATE_LENGTH 20
#define TIME_LENGTH 10

typedef struct email {
    char subject[SUBJECT_LENGTH];
    char body[BODY_LENGTH];
    char from[FROM_LENGTH];
    char to[TO_LENGTH];
    char cc[CC_LENGTH];
    char date[DATE_LENGTH];
    char time[TIME_LENGTH];
} Email;

int main() {
    Email emails[MAX_EMAILS];
    int num_emails = 0;

    char input_buffer[1000];
    char *token;
    FILE *input_file = fopen("emails.txt", "r");

    if (input_file == NULL) {
        printf("Error: Could not open input file\n");
        return 1;
    }

    while (fgets(input_buffer, sizeof(input_buffer), input_file)!= NULL) {
        token = strtok(input_buffer, ",");
        strcpy(emails[num_emails].subject, token);

        token = strtok(NULL, ",");
        strcpy(emails[num_emails].body, token);

        token = strtok(NULL, ",");
        strcpy(emails[num_emails].from, token);

        token = strtok(NULL, ",");
        strcpy(emails[num_emails].to, token);

        token = strtok(NULL, ",");
        strcpy(emails[num_emails].cc, token);

        token = strtok(NULL, ",");
        strcpy(emails[num_emails].date, token);

        token = strtok(NULL, ",");
        strcpy(emails[num_emails].time, token);

        num_emails++;
    }

    fclose(input_file);

    printf("Subject\tBody\tFrom\tTo\tCC\tDate\tTime\n");
    for (int i = 0; i < num_emails; i++) {
        printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\n", emails[i].subject, emails[i].body, emails[i].from, emails[i].to, emails[i].cc, emails[i].date, emails[i].time);
    }

    return 0;
}