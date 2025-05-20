//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECIPIENTS 100

typedef struct {
    char name[100];
    char email[100];
} recipient;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage:./program [list_file]\n");
        return 1;
    }

    FILE* list_file = fopen(argv[1], "r");
    if (list_file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    recipient recipients[MAX_RECIPIENTS];
    int num_recipients = 0;

    char line[100];
    while (fgets(line, 100, list_file)!= NULL) {
        char* name = strtok(line, ",");
        char* email = strtok(NULL, ",");

        strcpy(recipients[num_recipients].name, name);
        strcpy(recipients[num_recipients].email, email);

        num_recipients++;
        if (num_recipients == MAX_RECIPIENTS) {
            printf("Maximum number of recipients reached.\n");
            break;
        }
    }

    fclose(list_file);

    printf("Enter subject: ");
    char subject[100];
    fgets(subject, 100, stdin);
    subject[strcspn(subject, "\n")] = '\0';

    printf("Enter message: ");
    char message[1000];
    fgets(message, 1000, stdin);
    message[strcspn(message, "\n")] = '\0';

    for (int i = 0; i < num_recipients; i++) {
        char to[200];
        sprintf(to, "%s <%s>", recipients[i].name, recipients[i].email);

        char headers[200] = "From: sender@example.com\r\nTo: ";
        strcat(headers, to);
        strcat(headers, "\r\nSubject: ");
        strcat(headers, subject);

        FILE* email_file = fopen(recipients[i].email, "a");
        if (email_file == NULL) {
            printf("Error opening email file.\n");
            continue;
        }

        fprintf(email_file, "%s\n%s\n", headers, message);
        fclose(email_file);

        printf("Email sent to %s.\n", recipients[i].name);
    }

    return 0;
}